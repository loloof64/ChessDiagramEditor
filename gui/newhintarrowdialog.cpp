#include "newhintarrowdialog.h"
#include<QColorDialog>

loloof64::NewHintArrowDialog::NewHintArrowDialog(QWidget *parent) : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{
    _selectedColor = QColor(Qt::black);
    _mainLayout = new QVBoxLayout(this);

    _startCellLayout = new QHBoxLayout();
    _startCellFileLabel = new QLabel(tr("Start file"));
    _startCellFileLineEdit = new QSpinBox();
    _startCellFileLineEdit->setRange(0, 7);
    _startCellRankLabel = new QLabel(tr("Start rank"));
    _startCellRankLineEdit = new QSpinBox();
    _startCellRankLineEdit->setRange(0, 7);

    _endCellLayout = new QHBoxLayout();
    _endCellFileLabel = new QLabel(tr("End file"));
    _endCellFileLineEdit = new QSpinBox();
    _endCellFileLineEdit->setRange(0, 7);
    _endCellRankLabel = new QLabel("End rank");
    _endCellRankLineEdit = new QSpinBox();
    _endCellRankLineEdit->setRange(0, 7);

    _selectColorButton = new QPushButton(tr("Select the color"));

    _startCellLayout->addWidget(_startCellFileLabel);
    _startCellLayout->addWidget(_startCellFileLineEdit);
    _startCellLayout->addStretch();
    _startCellLayout->addWidget(_startCellRankLabel);
    _startCellLayout->addWidget(_startCellRankLineEdit);
    _mainLayout->addLayout(_startCellLayout);

    _endCellLayout->addWidget(_endCellFileLabel);
    _endCellLayout->addWidget(_endCellFileLineEdit);
    _endCellLayout->addStretch();
    _endCellLayout->addWidget(_endCellRankLabel);
    _endCellLayout->addWidget(_endCellRankLineEdit);
    _mainLayout->addLayout(_endCellLayout);

    _mainLayout->addWidget(_selectColorButton);


    _validationButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    _mainLayout->addWidget(_validationButtons);

    connect(_selectColorButton, &QPushButton::clicked, [this]() {
        auto newSelectedColor = QColorDialog::getColor(_selectedColor, this, tr("Select the color"));
        if (newSelectedColor.isValid()) {
            _selectedColor = newSelectedColor;
            _selectColorButton->setStyleSheet(QString("QPushButton {color: %1;}").arg(_selectedColor.name()));
        }
    });

    connect(_validationButtons, &QDialogButtonBox::accepted, [this]() {
        auto startFile = _startCellFileLineEdit->value();
        auto startRank = _startCellRankLineEdit->value();
        auto endFile = _endCellFileLineEdit->value();
        auto endRank = _endCellRankLineEdit->value();
        Cell startCell(startFile, startRank);
        Cell endCell(endFile, endRank);
        emit newSimpleHintArrowRequested(startCell, endCell, _selectedColor);
        close();
    });

    connect(_validationButtons, &QDialogButtonBox::rejected, [this]()
    {
        close();
    });




    setWindowTitle(tr("Set the arrow values"));
    setModal(true);
}

loloof64::NewHintArrowDialog::~NewHintArrowDialog() {
    delete _validationButtons;

    delete _selectColorButton;

    delete _endCellRankLineEdit;
    delete _endCellRankLabel;
    delete _endCellFileLineEdit;
    delete _endCellFileLabel;
    delete _endCellLayout;

    delete _startCellRankLineEdit;
    delete _startCellRankLabel;
    delete _startCellFileLineEdit;
    delete _startCellFileLabel;
    delete _startCellLayout;

    delete _mainLayout;
}
