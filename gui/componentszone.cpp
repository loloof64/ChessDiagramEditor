#include "componentszone.h"
#include "../core/adapters/thcposition.h"

loloof64::ComponentsZone::ComponentsZone(QWidget *parent) : QWidget(parent)
{
    _mainLayout = new QHBoxLayout();
    _mainLayout->setSpacing(20);
    _chessBoard = new ChessBoard(45, this);

    QFont font;
    font.setPointSize(20);

    _mainLayout->addWidget(_chessBoard);
    setLayout(_mainLayout);
    resize(800, 540);
}

loloof64::ComponentsZone::~ComponentsZone()
{
    delete _chessBoard;
    delete _mainLayout;
}
