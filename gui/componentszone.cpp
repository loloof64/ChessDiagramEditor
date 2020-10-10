#include "componentszone.h"
#include "../core/adapters/thcposition.h"

loloof64::ComponentsZone::ComponentsZone(QWidget *parent) : QWidget(parent)
{
    _mainLayout = new QHBoxLayout();
    _mainLayout->setSpacing(20);
    _positionEditor = new PositionEditorWidget(this);

    QFont font;
    font.setPointSize(20);

    _mainLayout->addWidget(_positionEditor);
    setLayout(_mainLayout);
}

loloof64::ComponentsZone::~ComponentsZone()
{
    delete _positionEditor;
    delete _mainLayout;
}
