#include "coderunner.h"          // Fix: was "CodeRunner.h" (wrong case, breaks on Linux)

#include <QProcess>
#include <QFile>
#include <QDir>

QString CodeRunner::compileAndRun(const QString& code)
{
    // 1. Write user code to file
    QFile file("main.cpp");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return "Failed to create file";

    file.write(code.toUtf8());
    file.close();

    // 2. Compile with g++
    QProcess compiler;
    compiler.start("g++", {"main.cpp", "-o", "app.exe"});
    compiler.waitForFinished();

    QString compileErrors = compiler.readAllStandardError();
    if (!compileErrors.isEmpty())
        return "Compile errors:\n" + compileErrors;

    // 3. Run program
    QProcess runner;
    runner.start("app.exe");
    runner.waitForFinished();

    QString output = runner.readAllStandardOutput();
    QString runtimeErrors = runner.readAllStandardError();

    return output + "\n" + runtimeErrors;
}
