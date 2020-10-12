#include "cellhighlight.h"

loloof64::CellHighlight::CellHighlight()
{
    _backgroundColor = QColor(Qt::white);
}

loloof64::CellHighlight::CellHighlight(ChessBoardCell relatedCell, QColor backgroundColor) {
    _relatedCell = relatedCell;
    _backgroundColor = backgroundColor;
}

loloof64::CellHighlight::~CellHighlight() {

}

loloof64::ChessBoardCell loloof64::CellHighlight::getRelatedCell() const {
    return _relatedCell;
}


QColor loloof64::CellHighlight::getBackgroundColor() const {
    return _backgroundColor;
}
