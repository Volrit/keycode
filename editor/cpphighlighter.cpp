#include "cpphighlighter.h"

#include <QTextCharFormat>
#include <QRegularExpression>

CppHighlighter::CppHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
}

void CppHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(QColor("#CE9178"));

    QStringList keywords = {
        "int", "return", "if", "else",
        "while", "for", "class"
    };

    for (const QString &word : keywords) {

        QRegularExpression expression("\\b" + word + "\\b");

        auto it = expression.globalMatch(text);

        while (it.hasNext()) {

            auto match = it.next();

            setFormat(
                match.capturedStart(),
                match.capturedLength(),
                keywordFormat
                );
        }
    }
}