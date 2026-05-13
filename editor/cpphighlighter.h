#ifndef CPPHIGHLIGHTER_H
#define CPPHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CppHighlighter : public QSyntaxHighlighter
{
public:
    CppHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override;
};

#endif