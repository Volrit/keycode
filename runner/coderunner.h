#ifndef CODERUNNER_H
#define CODERUNNER_H

#include <QString>

class CodeRunner
{
public:
    QString compileAndRun(const QString& code);
};

#endif