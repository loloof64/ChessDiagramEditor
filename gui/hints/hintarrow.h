#ifndef HINTARROW_H
#define HINTARROW_H

#include <QColor>
#include <QPainter>

#include "chessboardcell.h"

namespace loloof64 {
class HintArrow
{
public:
    HintArrow(){};
    HintArrow(ChessBoardCell start, ChessBoardCell end, QColor color);
    virtual ~HintArrow();
    virtual void paint(QPainter &painter, int cellsSize) const;

protected:
    ChessBoardCell _start, _end;
    QColor _color;

private:
    void drawArrowBetweenCells(QPainter &painter, QColor color, ChessBoardCell startCell, ChessBoardCell endCell, int cellsSize) const;
};
}

#endif // HINTARROW_H
