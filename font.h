#ifndef FONT_H
#define FONT_H

#include <QtCore>

class Font
{
    QVector<QVector<QVector<bool>>> drawableMatrix;

public:
    static const int charX, charY;
    Font();
    void constructCharacterFonts();
    QVector<QVector<bool>> & getDrawableMatrix(char ch);
};

#endif // FONT_H
