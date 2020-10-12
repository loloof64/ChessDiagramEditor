#include "positioneditorwidget.h"
#include "../hints/hintarrow.h"
#include "../hints/numberedhintarrow.h"
#include "../../core/adapters/thcposition.h"

#include <QHeaderView>
#include <QIcon>
#include <QApplication>
#include <QClipboard>
#include <QMessageBox>
#include <QBrush>

PositionEditorWidget::PositionEditorWidget(QWidget *parent) : QWidget(parent)
{
    _mainLayout = new QVBoxLayout(this);
    _mainLayout->setSpacing(10);

    _saveAsImageButton = new QPushButton(tr("Save as image"));

    _mainEditorZone = new QWidget();

    _mainEditorZoneLayout = new QHBoxLayout();
    _mainEditorZoneLayout->setSpacing(10);

    _piecesButtonsLayout = new QVBoxLayout();
    _piecesButtonsLayout->setSpacing(10);

    _whitePiecesButtonsLine = new QHBoxLayout();
    _whitePiecesButtonsLine->setSpacing(10);

    _blackPiecesButtonsLine = new QHBoxLayout();
    _blackPiecesButtonsLine->setSpacing(10);

    _selectedPieceLine = new QHBoxLayout();
    _selectedPieceLine->setSpacing(10);

    _editorComponent = new loloof64::PositionEditor(42, this);

    _trashCanButton = new QPushButton();
    _trashCanButton->setIcon(QIcon(":/icons/trashCan.svg"));
    _trashCanButton->setIconSize(QSize(50, 50));

    _whitePawnButton = new QPushButton();
    _whitePawnButton->setIcon(QIcon(":/chess_vectors/pl.svg"));
    _whitePawnButton->setIconSize(QSize(50, 50));

    _whiteKnightButton = new QPushButton();
    _whiteKnightButton->setIcon(QIcon(":/chess_vectors/nl.svg"));
    _whiteKnightButton->setIconSize(QSize(50, 50));

    _whiteBishopButton = new QPushButton();
    _whiteBishopButton->setIcon(QIcon(":/chess_vectors/bl.svg"));
    _whiteBishopButton->setIconSize(QSize(50, 50));

    _whiteRookButton = new QPushButton();
    _whiteRookButton->setIcon(QIcon(":/chess_vectors/rl.svg"));
    _whiteRookButton->setIconSize(QSize(50, 50));

    _whiteQueenButton = new QPushButton();
    _whiteQueenButton->setIcon(QIcon(":/chess_vectors/ql.svg"));
    _whiteQueenButton->setIconSize(QSize(50, 50));

    _whiteKingButton = new QPushButton();
    _whiteKingButton->setIcon(QIcon(":/chess_vectors/kl.svg"));
    _whiteKingButton->setIconSize(QSize(50, 50));

    _blackPawnButton = new QPushButton();
    _blackPawnButton->setIcon(QIcon(":/chess_vectors/pd.svg"));
    _blackPawnButton->setIconSize(QSize(50, 50));

    _blackKnightButton = new QPushButton();
    _blackKnightButton->setIcon(QIcon(":/chess_vectors/nd.svg"));
    _blackKnightButton->setIconSize(QSize(50, 50));

    _blackBishopButton = new QPushButton();
    _blackBishopButton->setIcon(QIcon(":/chess_vectors/bd.svg"));
    _blackBishopButton->setIconSize(QSize(50, 50));

    _blackRookButton = new QPushButton();
    _blackRookButton->setIcon(QIcon(":/chess_vectors/rd.svg"));
    _blackRookButton->setIconSize(QSize(50, 50));

    _blackQueenButton = new QPushButton();
    _blackQueenButton->setIcon(QIcon(":/chess_vectors/qd.svg"));
    _blackQueenButton->setIconSize(QSize(50, 50));

    _blackKingButton = new QPushButton();
    _blackKingButton->setIcon(QIcon(":/chess_vectors/kd.svg"));
    _blackKingButton->setIconSize(QSize(50, 50));

    _currentSelectionLabel = new QLabel(tr("Current selection"));
    _currentSelectionComponent = new QLabel();
    QPixmap selectionImage(":/icons/trashCan.svg");
    _currentSelectionComponent->setPixmap(selectionImage.scaled(30, 30));

    _optionsZone = new QTabWidget();

    _generalOptions = new QWidget();
    _generalOptionsLayout = new QVBoxLayout();
    _generalOptionsLayout->setSpacing(10);
    _playerTurnGroup = new QGroupBox(tr("Turn"));
    _playerTurnGroupLayout = new QHBoxLayout();
    _playerTurnGroupLayout->setSpacing(10);
    _whiteTurnButton = new QRadioButton(tr("White"));
    _blackTurnButton = new QRadioButton(tr("Black"));
    _whiteTurnButton->setChecked(true);

    _easyModificationButtonsLine = new QHBoxLayout();
    _easyModificationButtonsLine->setSpacing(10);
    _eraseAllButton = new QPushButton(tr("Erase board"));
    _standardPositionButton = new QPushButton(tr("Standard position"));

    _fenOptions = new QWidget();
    _fenOptionsLayout = new QVBoxLayout();
    _fenOptionsLayout->setSpacing(10);
    _fenValueLineLayout = new QHBoxLayout();
    _fenValueLineLayout->setSpacing(10);
    _fenValueLabel = new QLabel(tr("FEN"));
    _fenValueValue = new QLineEdit();
    _fenValueValue->setReadOnly(true);
    _fenButtonsLine = new QHBoxLayout();
    _fenButtonsLine->setSpacing(10);
    _copyFenButton = new QPushButton(tr("Copy FEN"));
    _pasteFenButton = new QPushButton(tr("Paste FEN"));

    _arrowsListOptions = new QWidget();
    _arrowsListOptionsLayout = new QVBoxLayout();
    _arrowsListOptionsLabel = new QLabel(tr("Arrows"));
    _newArrowListOptionsButtonsNewLayout = new QHBoxLayout();
    _addNewSimpleArrow = new QPushButton(tr("Add simple arrow"));
    _addNewNumberedArrow = new QPushButton(tr("Add numbered arrow"));
    _arrowsListOptionsMainWidget = new QListWidget();
    _arrowsListOptionsDeleteButton = new QPushButton(tr("Delete"));
    _arrowsListOptionDeleteAllButton = new QPushButton(tr("Delete all"));

    _highlightsListOptions = new QWidget();
    _highlightsListOptionsLayout = new QVBoxLayout();
    _highlightsListOptionsLabel = new QLabel(tr("Highlights"));
    _addNewHighlightButton = new QPushButton(tr("New highlight"));
    _highlightsListOptionsMainWidget = new QListWidget();
    _highlightsListOptionsDeleteButton = new QPushButton(tr("Delete"));
    _highlightsListOptionsDeleteAllButton = new QPushButton(tr("Delete all"));

    _positionBuilder = new loloof64::PositionBuilder();

    _newSimpleHintArrowDialog = new loloof64::NewHintArrowDialog(this);
    _newNumberedHintArrowDialog = new loloof64::NewHintArrowDialog(this, true);
    _newCellHighlightingDialog = new loloof64::NewCellHighlightDialog(this);

    _mainLayout->addWidget(_saveAsImageButton);

    _highlightsListOptionsLayout->addWidget(_highlightsListOptionsLabel);
    _highlightsListOptionsLayout->addWidget(_addNewHighlightButton);
    _highlightsListOptionsLayout->addWidget(_highlightsListOptionsMainWidget);
    _highlightsListOptionsLayout->addWidget(_highlightsListOptionsDeleteButton);
    _highlightsListOptionsLayout->addWidget(_highlightsListOptionsDeleteAllButton);
    _highlightsListOptions->setLayout(_highlightsListOptionsLayout);

    _arrowsListOptionsLayout->addWidget(_arrowsListOptionsLabel);
    _newArrowListOptionsButtonsNewLayout->addWidget(_addNewSimpleArrow);
    _newArrowListOptionsButtonsNewLayout->addWidget(_addNewNumberedArrow);
    _arrowsListOptionsLayout->addLayout(_newArrowListOptionsButtonsNewLayout);
    _arrowsListOptionsLayout->addWidget(_arrowsListOptionsMainWidget);
    _arrowsListOptionsLayout->addWidget(_arrowsListOptionsDeleteButton);
    _arrowsListOptionsLayout->addWidget(_arrowsListOptionDeleteAllButton);
    _arrowsListOptions->setLayout(_arrowsListOptionsLayout);

    _fenButtonsLine->addWidget(_copyFenButton);
    _fenButtonsLine->addWidget(_pasteFenButton);
    _fenButtonsLine->addStretch();
    _fenValueLineLayout->addWidget(_fenValueLabel);
    _fenValueLineLayout->addWidget(_fenValueValue);
    _fenValueLineLayout->addStretch();
    _fenOptionsLayout->addLayout(_fenValueLineLayout);
    _fenOptionsLayout->addLayout(_fenButtonsLine);
    _fenOptions->setLayout(_fenOptionsLayout);

    _easyModificationButtonsLine->addWidget(_eraseAllButton);
    _easyModificationButtonsLine->addWidget(_standardPositionButton);
    _easyModificationButtonsLine->addStretch();
    _playerTurnGroupLayout->addWidget(_whiteTurnButton);
    _playerTurnGroupLayout->addWidget(_blackTurnButton);
    _playerTurnGroupLayout->addStretch();
    _playerTurnGroup->setLayout(_playerTurnGroupLayout);
    _playerTurnGroup->setStyleSheet("QGroupBox::title {position: left; margin: 5px;}");

    _generalOptionsLayout->addWidget(_playerTurnGroup);
    _generalOptionsLayout->addLayout(_easyModificationButtonsLine);
    _generalOptions->setLayout(_generalOptionsLayout);

    _optionsZone->addTab(_arrowsListOptions, tr("Arrows", "Arrows list options of position editor"));
    _optionsZone->addTab(_highlightsListOptions, tr("Highlights", "Highlights options of position editor"));
    _optionsZone->addTab(_generalOptions, tr("General", "General options of position editor"));
    _optionsZone->addTab(_fenOptions, tr("FEN", "Fen options of position editor"));

    _whitePiecesButtonsLine->addWidget(_whitePawnButton);
    _whitePiecesButtonsLine->addWidget(_whiteKnightButton);
    _whitePiecesButtonsLine->addWidget(_whiteBishopButton);
    _whitePiecesButtonsLine->addWidget(_whiteRookButton);
    _whitePiecesButtonsLine->addWidget(_whiteQueenButton);
    _whitePiecesButtonsLine->addWidget(_whiteKingButton);

    _blackPiecesButtonsLine->addWidget(_blackPawnButton);
    _blackPiecesButtonsLine->addWidget(_blackKnightButton);
    _blackPiecesButtonsLine->addWidget(_blackBishopButton);
    _blackPiecesButtonsLine->addWidget(_blackRookButton);
    _blackPiecesButtonsLine->addWidget(_blackQueenButton);
    _blackPiecesButtonsLine->addWidget(_blackKingButton);

    _selectedPieceLine->addWidget(_currentSelectionLabel);
    _selectedPieceLine->addWidget(_currentSelectionComponent);
    _selectedPieceLine->addStretch();

    _piecesButtonsLayout->addStretch();
    _piecesButtonsLayout->addWidget(_trashCanButton);
    _piecesButtonsLayout->addLayout(_whitePiecesButtonsLine);
    _piecesButtonsLayout->addLayout(_blackPiecesButtonsLine);
    _piecesButtonsLayout->addLayout(_selectedPieceLine);
    _piecesButtonsLayout->addStretch();

    _mainEditorZoneLayout->addWidget(_editorComponent);
    _mainEditorZoneLayout->addLayout(_piecesButtonsLayout);
    _mainEditorZone->setLayout(_mainEditorZoneLayout);

    _mainLayout->addWidget(_mainEditorZone);
    _mainLayout->addWidget(_optionsZone);

    connectComponents();

    synchronizeWithBuilder();
}

PositionEditorWidget::~PositionEditorWidget() {
    delete _newCellHighlightingDialog;
    delete _newNumberedHintArrowDialog;
    delete _newSimpleHintArrowDialog;

    delete _positionBuilder;

    delete _highlightsListOptionsDeleteAllButton;
    delete _highlightsListOptionsDeleteButton;
    delete _highlightsListOptionsMainWidget;
    delete _addNewHighlightButton;
    delete _highlightsListOptionsLabel;
    delete _highlightsListOptionsLayout;
    delete _highlightsListOptions;

    delete _arrowsListOptionDeleteAllButton;
    delete _arrowsListOptionsDeleteButton;
    delete _arrowsListOptionsMainWidget;
    delete _addNewNumberedArrow;
    delete _addNewSimpleArrow;
    delete _newArrowListOptionsButtonsNewLayout;
    delete _arrowsListOptionsLabel;
    delete _arrowsListOptionsLayout;
    delete _arrowsListOptions;

    delete _pasteFenButton;
    delete _copyFenButton;
    delete _fenButtonsLine;
    delete _fenValueValue;
    delete _fenValueLabel;
    delete _fenValueLineLayout;
    delete _fenOptionsLayout;
    delete _fenOptions;

    delete _standardPositionButton;
    delete _eraseAllButton;
    delete _easyModificationButtonsLine;
    delete _blackTurnButton;
    delete _whiteTurnButton;
    delete _playerTurnGroupLayout;
    delete _playerTurnGroup;
    delete _generalOptionsLayout;
    delete _generalOptions;
    delete _optionsZone;

    delete _currentSelectionComponent;
    delete _currentSelectionLabel;

    delete _blackKingButton;
    delete _blackQueenButton;
    delete _blackRookButton;
    delete _blackBishopButton;
    delete _blackKnightButton;
    delete _blackPawnButton;

    delete _whiteKingButton;
    delete _whiteQueenButton;
    delete _whiteRookButton;
    delete _whiteBishopButton;
    delete _whiteKnightButton;
    delete _whitePawnButton;

    delete _trashCanButton;

    delete _editorComponent;

    delete _selectedPieceLine;
    delete _blackPiecesButtonsLine;
    delete _whitePiecesButtonsLine;

    delete _piecesButtonsLayout;
    delete _mainEditorZoneLayout;
    delete _mainEditorZone;

    delete _saveAsImageButton;
    delete _mainLayout;
}

void PositionEditorWidget::synchronizeWithBuilder() {
    _editorComponent->setFromFen(_positionBuilder->getFen());

    _whiteTurnButton->setChecked(_positionBuilder->isWhiteTurn());
    _blackTurnButton->setChecked(! _positionBuilder->isWhiteTurn());

    _fenValueValue->setText(_positionBuilder->getFen());
}

void PositionEditorWidget::connectComponents()
{
    connect(_saveAsImageButton, &QPushButton::clicked, [this]() {
        _editorComponent->letUserSaveToJPG();
    });

    connect(_addNewSimpleArrow, &QPushButton::clicked, [this]() {
        _newSimpleHintArrowDialog->exec();
    });

    connect(_addNewNumberedArrow, &QPushButton::clicked, [this]() {
       _newNumberedHintArrowDialog->exec();
    });

    connect(_addNewHighlightButton, &QPushButton::clicked, [this]() {
       _newCellHighlightingDialog->exec();
    });

    connect(_editorComponent, &loloof64::PositionEditor::cellSelected, [this](int file, int rank) {
        _positionBuilder->setPieceAtSquare(_editingValue, loloof64::BoardSquare(file, rank));
        synchronizeWithBuilder();
    });

    connect(_whiteTurnButton, &QRadioButton::clicked, [this]() {
        _positionBuilder->setTurn(true);
        synchronizeWithBuilder();
    });

    connect(_blackTurnButton, &QRadioButton::clicked, [this]() {
        _positionBuilder->setTurn(false);
        synchronizeWithBuilder();
    });

    connect(_eraseAllButton, &QPushButton::clicked, [this]() {
        _positionBuilder->setFromFen("8/8/8/8/8/8/8/8 w - - 0 1");
        synchronizeWithBuilder();
    });

    connect(_standardPositionButton, &QPushButton::clicked, [this]() {
        _positionBuilder->setFromFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        synchronizeWithBuilder();
    });

    connect(_copyFenButton, &QPushButton::clicked, [this]() {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(_positionBuilder->getFen());
    });

    connect(_trashCanButton, &QPushButton::clicked, [this]() {
        _editingValue = ' ';
        updateSelectedPiece();
    });

    connect(_whitePawnButton, &QPushButton::clicked, [this]() {
        _editingValue = 'P';
        updateSelectedPiece();
    });

    connect(_whiteKnightButton, &QPushButton::clicked, [this]() {
        _editingValue = 'N';
        updateSelectedPiece();
    });

    connect(_whiteBishopButton, &QPushButton::clicked, [this]() {
        _editingValue = 'B';
        updateSelectedPiece();
    });

    connect(_whiteRookButton, &QPushButton::clicked, [this]() {
        _editingValue = 'R';
        updateSelectedPiece();
    });

    connect(_whiteQueenButton, &QPushButton::clicked, [this]() {
        _editingValue = 'Q';
        updateSelectedPiece();
    });

    connect(_whiteKingButton, &QPushButton::clicked, [this]() {
        _editingValue = 'K';
        updateSelectedPiece();
    });

    connect(_blackPawnButton, &QPushButton::clicked, [this]() {
        _editingValue = 'p';
        updateSelectedPiece();
    });

    connect(_blackKnightButton, &QPushButton::clicked, [this]() {
        _editingValue = 'n';
        updateSelectedPiece();
    });

    connect(_blackBishopButton, &QPushButton::clicked, [this]() {
        _editingValue = 'b';
        updateSelectedPiece();
    });

    connect(_blackRookButton, &QPushButton::clicked, [this]() {
        _editingValue = 'r';
        updateSelectedPiece();
    });

    connect(_blackQueenButton, &QPushButton::clicked, [this]() {
        _editingValue = 'q';
        updateSelectedPiece();
    });

    connect(_blackKingButton, &QPushButton::clicked, [this]() {
        _editingValue = 'k';
        updateSelectedPiece();
    });

    connect(_newSimpleHintArrowDialog, &loloof64::NewHintArrowDialog::newSimpleHintArrowRequested,
            [this](loloof64::ChessBoardCell startCell, loloof64::ChessBoardCell endCell, QColor color) {
        auto arrowToAdd = new loloof64::HintArrow(startCell, endCell, color);
        auto startCellStr = startCell.toStdString();
        auto endCellStr = endCell.toStdString();
        auto arrowText = QString::asprintf("%s => %s", startCellStr.c_str(), endCellStr.c_str());
        _editorComponent->addHintArrow(arrowToAdd);
        _arrowsListOptionsMainWidget->addItem(arrowText);
        const auto itemsCount = _arrowsListOptionsMainWidget->count();
        QBrush brush(color);
        _arrowsListOptionsMainWidget->item(itemsCount - 1)->setForeground(brush);
    });

    connect(_newNumberedHintArrowDialog, &loloof64::NewHintArrowDialog::newNumberedHintArrowRequested,
            [this](loloof64::ChessBoardCell startCell, loloof64::ChessBoardCell endCell, QColor color, int number) {
       auto arrowToAdd = new loloof64::NumberedHintArrow(startCell, endCell, color, number);
       auto startCellStr = startCell.toStdString();
       auto endCellStr = endCell.toStdString();
       auto arrowText = QString::asprintf("%s => %s (%d)", startCellStr.c_str(), endCellStr.c_str(), number);
       _editorComponent->addHintArrow(arrowToAdd);
       _arrowsListOptionsMainWidget->addItem(arrowText);
       const auto itemsCount = _arrowsListOptionsMainWidget->count();
       QBrush brush(color);
       _arrowsListOptionsMainWidget->item(itemsCount - 1)->setForeground(brush);
    });

    connect(_newCellHighlightingDialog, &loloof64::NewCellHighlightDialog::newCellHighlight,
            [this](loloof64::ChessBoardCell cell, QColor color) {
        auto highlightToAdd = new loloof64::CellHighlight(cell, color);
        auto cellStr = cell.toStdString();
        auto highlightText = QString::asprintf("%s", cellStr.c_str());
        _editorComponent->addCellHighlight(highlightToAdd);
        _highlightsListOptionsMainWidget->addItem(highlightText);
        const auto itemsCount = _highlightsListOptionsMainWidget->count();
        QBrush brush(color);
        _highlightsListOptionsMainWidget->item(itemsCount - 1)->setForeground(brush);
    });

    connect(_pasteFenButton, &QPushButton::clicked, [this]() {
        const QClipboard *clipboard = QApplication::clipboard();
        try {
            _positionBuilder->setFromFen(clipboard->text());
            synchronizeWithBuilder();
        } catch (loloof64::IllegalPositionException & /* e */) {

        }
    });

    connect(_copyFenButton, &QPushButton::clicked, [this]() {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(_positionBuilder->getFen());
    });

    connect(_arrowsListOptionsDeleteButton, &QPushButton::clicked, [this]() {
        const auto selectedArrowIndex = _arrowsListOptionsMainWidget->currentRow();
        const auto hasASelection = selectedArrowIndex >= 0;
        if (hasASelection) {
          _editorComponent->removeHintArrow(selectedArrowIndex);
          _arrowsListOptionsMainWidget->takeItem(selectedArrowIndex);
        }
    });

    connect(_arrowsListOptionDeleteAllButton, &QPushButton::clicked, [this]() {
        const auto notNeeded = _arrowsListOptionsMainWidget->count() == 0;
        if (notNeeded) return;

        const auto confirmed = QMessageBox::question(this, tr("Confirm clearing ?"), tr("Do you really want to delete all ?"))
                == QMessageBox::StandardButton::Yes;
        if (confirmed) {
           _editorComponent->removeAllHintArrows();
           _arrowsListOptionsMainWidget->clear();
        }
    });

    connect(_highlightsListOptionsDeleteButton, &QPushButton::clicked, [this]() {
       const auto selectedHighlightIndex = _highlightsListOptionsMainWidget->currentRow();
       const auto hasASelection = selectedHighlightIndex >= 0;
       if (hasASelection) {
           _editorComponent->removeHighlight(selectedHighlightIndex);
           _highlightsListOptionsMainWidget->takeItem(selectedHighlightIndex);
       }
    });

    connect(_highlightsListOptionsDeleteAllButton, &QPushButton::clicked, [this]() {
        const auto notNeeded = _highlightsListOptionsMainWidget->count() == 0;
        if (notNeeded) return;

        const auto confirmed = QMessageBox::question(this, tr("Confirm clearing ?"), tr("Do you really want to delete all ?"))
                == QMessageBox::StandardButton::Yes;
        if (confirmed) {
            _editorComponent->removeAllHighlights();
            _highlightsListOptionsMainWidget->clear();
        }
    });
}

void PositionEditorWidget::updateSelectedPiece()
{
    auto image = ":/icons/trashCan.svg";
    switch (_editingValue) {
    case 'P': image = ":/chess_vectors/pl.svg"; break;
    case 'N': image = ":/chess_vectors/nl.svg"; break;
    case 'B': image = ":/chess_vectors/bl.svg"; break;
    case 'R': image = ":/chess_vectors/rl.svg"; break;
    case 'Q': image = ":/chess_vectors/ql.svg"; break;
    case 'K': image = ":/chess_vectors/kl.svg"; break;

    case 'p': image = ":/chess_vectors/pd.svg"; break;
    case 'n': image = ":/chess_vectors/nd.svg"; break;
    case 'b': image = ":/chess_vectors/bd.svg"; break;
    case 'r': image = ":/chess_vectors/rd.svg"; break;
    case 'q': image = ":/chess_vectors/qd.svg"; break;
    case 'k': image = ":/chess_vectors/kd.svg"; break;
    }

    QPixmap selectionImage(image);
    _currentSelectionComponent->setPixmap(selectionImage.scaled(30, 30));
}
