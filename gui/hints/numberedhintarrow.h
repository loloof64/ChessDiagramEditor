#ifndef NUMBEREDHINTARROW_H
#define NUMBEREDHINTARROW_H

#include "hintarrow.h"

namespace loloof64 {
class NumberedHintArrow : public HintArrow
{
public:
    NumberedHintArrow() : HintArrow(){};
    NumberedHintArrow(ChessBoardCell start, ChessBoardCell end, QColor color, int number = 1);
    virtual void paint(QPainter &painter, int cellsSize) const;

private:
    int _number;
};
}

#endif // NUMBEREDHINTARROW_H
