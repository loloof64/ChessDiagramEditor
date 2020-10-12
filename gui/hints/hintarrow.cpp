#include "hintarrow.h"
#include <cmath>

loloof64::HintArrow::HintArrow(ChessBoardCell start, ChessBoardCell end, QColor color):
    _start(start), _end(end), _color(color)
{

}

loloof64::HintArrow::~HintArrow() {

}

void loloof64::HintArrow::paint(QPainter &painter, int cellsSize) const {
    drawArrowBetweenCells(painter, _color, _start, _end, cellsSize);
}


void loloof64::HintArrow::drawArrowBetweenCells(QPainter &painter, QColor color, ChessBoardCell startCell, ChessBoardCell endCell, int cellsSize) const
{
    QPen pen = color;
    pen.setWidth(int(floor(cellsSize * 0.06)));
    painter.setPen(pen);

    const auto startCol = startCell.file;
    const auto startRow = 7-startCell.rank;
    const auto endCol = endCell.file;
    const auto endRow = 7-endCell.rank;

    const auto deltaX = endCol - startCol;
    const auto deltaY = endRow - startRow;
    const auto baseLineLength = sqrt(deltaX*deltaX + deltaY*deltaY);
    const auto baseLineAngleDegrees = atan2(deltaY, deltaX) * 180.0 / 3.1415927;
    const auto arrowLineLength = int(floor(baseLineLength * cellsSize * 0.3 ));

    const auto baseLineStartX = int(floor(cellsSize * (startCol + 1)));
    const auto baseLineStartY = int(floor(cellsSize * (startRow + 1)));
    const auto baseLineEndX = int(floor(cellsSize * (endCol + 1)));
    const auto baseLineEndY = int(floor(cellsSize * (endRow + 1)));

    const auto arrowAngleRad = 30 * 3.1415926 / 180.0;
    const auto arrowLineEndX = -int(floor(arrowLineLength * cos(arrowAngleRad)));
    const auto arrowLineEndY = int(floor(arrowLineLength * sin(arrowAngleRad)));


    painter.drawLine(
        baseLineStartX, baseLineStartY,
        baseLineEndX, baseLineEndY
    );

    painter.save();
    painter.translate(baseLineEndX, baseLineEndY);
    painter.rotate(baseLineAngleDegrees);

    painter.drawLine(0, 0, arrowLineEndX, arrowLineEndY);
    painter.drawLine(0, 0, arrowLineEndX, -arrowLineEndY);

    painter.restore();
}
