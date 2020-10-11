#include "newhintarrowdialog.h"
#include<QColorDialog>

loloof64::NewHintArrowDialog::NewHintArrowDialog(QWidget *parent, bool withNumberEditor) : QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    _withNumberEditor(withNumberEditor), _startFileIndex(0), _startRankIndex(0), _endFileIndex(0), _endRankIndex(0)
{
    _selectedColor = QColor(Qt::black);
    _mainLayout = new QVBoxLayout(this);

    _numberEditorLayout = new QHBoxLayout();
    _numberEditorLabel = new QLabel(tr("Number"));
    _numberEditorLineEdit = new QLineEdit();
    _numberValidator = new QIntValidator();
    _numberValidator->setBottom(1);
    _numberEditorLineEdit->setValidator(_numberValidator);

    _startCellLayout = new QHBoxLayout();
    _startCellFileLabel = new QLabel(tr("Start file"));
    _startCellFileCombo = new QComboBox();
    for (auto i = 0; i <= 7; i++) {
        _startCellFileCombo->addItem(QString::asprintf("%c", 'a' + i));
    }
    _startCellFileCombo->setEditable(false);
    _startCellFileCombo->setCurrentIndex(_startFileIndex);
    _startCellRankLabel = new QLabel(tr("Start rank"));
    _startCellRankCombo = new QComboBox();
    for (auto i = 0; i <= 7; i++) {
        _startCellRankCombo->addItem(QString::number(i+1));
    }
    _startCellRankCombo->setEditable(false);
    _startCellRankCombo->setCurrentIndex(_startRankIndex);

    _endCellLayout = new QHBoxLayout();
    _endCellFileLabel = new QLabel(tr("End file"));
    _endCellFileCombo = new QComboBox();
    for (auto i = 0; i <= 7; i++) {
        _endCellFileCombo->addItem(QString::asprintf("%c", 'a' + i));
    }
    _endCellFileCombo->setEditable(false);
    _endCellFileCombo->setCurrentIndex(_endFileIndex);
    _endCellRankLabel = new QLabel(tr("End rank"));
    _endCellRankCombo = new QComboBox();
    for (auto i = 0; i <= 7; i++) {
        _endCellRankCombo->addItem(QString::number(i+1));
    }
    _endCellRankCombo->setEditable(false);
    _endCellRankCombo->setCurrentIndex(_endRankIndex);

    _selectColorButton = new QPushButton(tr("Select the color"));

    _numberEditorLayout->addWidget(_numberEditorLabel);
    _numberEditorLayout->addWidget(_numberEditorLineEdit);
    if (_withNumberEditor) {
        _mainLayout->addLayout(_numberEditorLayout);
    }

    _startCellLayout->addWidget(_startCellFileLabel);
    _startCellLayout->addWidget(_startCellFileCombo);
    _startCellLayout->addStretch();
    _startCellLayout->addWidget(_startCellRankLabel);
    _startCellLayout->addWidget(_startCellRankCombo);
    _mainLayout->addLayout(_startCellLayout);

    _endCellLayout->addWidget(_endCellFileLabel);
    _endCellLayout->addWidget(_endCellFileCombo);
    _endCellLayout->addStretch();
    _endCellLayout->addWidget(_endCellRankLabel);
    _endCellLayout->addWidget(_endCellRankCombo);
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

    connect(_startCellFileCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _startFileIndex = newIndex;
    });

    connect(_startCellRankCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _startRankIndex = newIndex;
    });

    connect(_endCellFileCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _endFileIndex = newIndex;
    });

    connect(_endCellFileCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int newIndex) {
       _endFileIndex = newIndex;
    });

    connect(_validationButtons, &QDialogButtonBox::accepted, [this]() {
        auto startFile = _startCellFileCombo->currentIndex();
        auto startRank = _startCellRankCombo->currentIndex();
        auto endFile = _endCellFileCombo->currentIndex();
        auto endRank = _endCellRankCombo->currentIndex();
        Cell startCell(startFile, startRank);
        Cell endCell(endFile, endRank);
        if (_withNumberEditor) {
            auto number = _numberEditorLineEdit->text().toInt();
            emit newNumberedHintArrowRequested(startCell, endCell, _selectedColor, number);
        }
        else {
            emit newSimpleHintArrowRequested(startCell, endCell, _selectedColor);
        }
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

    delete _endCellRankCombo;
    delete _endCellRankLabel;
    delete _endCellFileCombo;
    delete _endCellFileLabel;
    delete _endCellLayout;

    delete _startCellRankCombo;
    delete _startCellRankLabel;
    delete _startCellFileCombo;
    delete _startCellFileLabel;
    delete _startCellLayout;

    delete _numberValidator;
    delete _numberEditorLineEdit;
    delete _numberEditorLabel;
    delete _numberEditorLayout;

    delete _mainLayout;
}
