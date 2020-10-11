#ifndef HINTARROW_H
#define HINTARROW_H

#include <QColor>
#include <QPainter>

namespace loloof64 {
struct Cell {
    Cell(){};
    Cell(int file, int rank);
    int file, rank;
};

class HintArrow
{
public:
    HintArrow(){};
    HintArrow(Cell start, Cell end, QColor color);
    virtual ~HintArrow();
    virtual void paint(QPainter &painter, int cellsSize) const;

protected:
    Cell _start, _end;
    QColor _color;

private:
    void drawArrowBetweenCells(QPainter &painter, QColor color, Cell startCell, Cell endCell, int cellsSize) const;
};
}

#endif // HINTARROW_H
