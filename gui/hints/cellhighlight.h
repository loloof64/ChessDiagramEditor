#ifndef CELLHIGHLIGHT_H
#define CELLHIGHLIGHT_H

#include "chessboardcell.h"
#include <QColor>

namespace loloof64 {
class CellHighlight
{
public:
    CellHighlight();
    CellHighlight(ChessBoardCell relatedCell, QColor backgroundColor);
    virtual ~CellHighlight();

    ChessBoardCell getRelatedCell() const;
    QColor getBackgroundColor() const;

private:
    ChessBoardCell _relatedCell;
    QColor _backgroundColor;
};
}

#endif // CELLHIGHLIGHT_H
