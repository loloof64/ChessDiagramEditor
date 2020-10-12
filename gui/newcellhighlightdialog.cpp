#include "newcellhighlightdialog.h"
#include <QString>
#include <QColorDialog>

loloof64::NewCellHighlightDialog::NewCellHighlightDialog(QWidget *parent) : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    _selectedFile(0), _selectedRank(0), _selectedColor(QColor(Qt::black))
{
    _mainLayout = new QVBoxLayout(this);

    _fileLayout = new QHBoxLayout();
    _fileLabel = new QLabel(tr("File"));
    _fileValue = new QComboBox();
    _fileValue->setEditable(false);
    _fileValue->setCurrentIndex(_selectedFile);
    for (int i = 0; i < 8; i++) {
        const auto text = QString::asprintf("%c", 'a' + i);
        _fileValue->addItem(text);
    }

    _rankLayout = new QHBoxLayout();
    _rankLabel = new QLabel(tr("Rank"));
    _rankValue = new QComboBox();
    _rankValue->setEditable(false);
    _rankValue->setCurrentIndex(_selectedRank);
    for (int i = 0; i < 8; i++) {
        const auto text = QString::asprintf("%c", '1' + i);
        _rankValue->addItem(text);
    }

    _colorLayout = new QHBoxLayout();
    _colorLabel = new QLabel(tr("Color"));
    _selectColorButton = new QPushButton(tr("Select"));

    _fileLayout->addWidget(_fileLabel);
    _fileLayout->addWidget(_fileValue);

    _rankLayout->addWidget(_rankLabel);
    _rankLayout->addWidget(_rankValue);

    _colorLayout->addWidget(_colorLabel);
    _colorLayout->addWidget(_selectColorButton);

    _mainLayout->addLayout(_fileLayout);
    _mainLayout->addLayout(_rankLayout);
    _mainLayout->addLayout(_colorLayout);

    _validationButtons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    _mainLayout->addWidget(_validationButtons);

    connect(_fileValue, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _selectedFile = newIndex;
    });

    connect(_rankValue, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _selectedRank = newIndex;
    });

    connect(_selectColorButton ,&QPushButton::clicked, [this]() {
       auto newSelectedColor = QColorDialog::getColor(_selectedColor, this, tr("Select the color"));
       if (newSelectedColor.isValid()) {
           _selectedColor = newSelectedColor;
           _selectColorButton->setStyleSheet(QString("QPushButton {color: %1;}").arg(_selectedColor.name()));
       }
    });

    connect(_validationButtons, &QDialogButtonBox::accepted, [this]() {
        auto file = _fileValue->currentIndex();
        auto rank = _rankValue->currentIndex();
        auto cell = ChessBoardCell(file, rank);
        emit newCellHighlight(cell, _selectedColor);
        close();
    });

    connect(_validationButtons, &QDialogButtonBox::rejected, [this]()
    {
        close();
    });

    setWindowTitle(tr("Set the highlight values"));
    setModal(true);
}

loloof64::NewCellHighlightDialog::~NewCellHighlightDialog() {
    delete _validationButtons;

    delete _selectColorButton;
    delete _colorLabel;
    delete _colorLayout;

    delete _rankValue;
    delete _rankLabel;
    delete _rankLayout;

    delete _fileValue;
    delete _fileLabel;
    delete _fileLayout;

    delete _mainLayout;
}
