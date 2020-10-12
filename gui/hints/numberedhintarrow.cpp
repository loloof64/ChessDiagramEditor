#include "numberedhintarrow.h"
#include <cmath>

loloof64::NumberedHintArrow::NumberedHintArrow(ChessBoardCell start, ChessBoardCell end, QColor color, int number):
    HintArrow(start, end, color),  _number(number)
{

}

void loloof64::NumberedHintArrow::paint(QPainter &painter, int cellsSize) const {
    HintArrow::paint(painter, cellsSize);
    // drawing number

    QPen pen(_color);
    const auto fontSize = int(floor(cellsSize * 0.8));
    painter.setFont(QFont("Serif", fontSize));
    painter.setPen(pen);

    const auto text = QString::number(_number);

    const auto startCol = _start.file;
    const auto startRow = 7-_start.rank;
    const auto endCol = _end.file;
    const auto endRow = 7-_end.rank;

    const auto deltaX = endCol - startCol;
    const auto deltaY = endRow - startRow;
    const auto baseLineLength = sqrt(deltaX*deltaX + deltaY*deltaY);
    const auto baseLineAngleDegrees = atan2(deltaY, deltaX) * 180.0 / 3.1415927;
    const auto arrowLineLength = int(floor(baseLineLength * cellsSize * 0.3 ));

    const auto baseLineEndX = int(floor(cellsSize * (endCol + 1)));
    const auto baseLineEndY = int(floor(cellsSize * (endRow + 1)));

    const auto x = int(floor(baseLineEndX + arrowLineLength * 0.02 * cos(baseLineAngleDegrees)));
    const auto y = int(floor(baseLineEndY + arrowLineLength * 0.02 * sin(baseLineAngleDegrees)));
    painter.drawText(x, y, text);
}
