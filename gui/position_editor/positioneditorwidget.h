#ifndef POSITIONEDITORWIDGET_H
#define POSITIONEDITORWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QTabWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPixmap>
#include <QMessageBox>
#include "positioneditor.h"

class PositionEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PositionEditorWidget(QWidget *parent = nullptr);
    virtual ~PositionEditorWidget() override;

signals:
    void newGamePosition(QString positionFen);

private:
    QVBoxLayout * _mainLayout;
    QWidget * _mainEditorZone;
    QHBoxLayout * _mainEditorZoneLayout;
    QVBoxLayout * _piecesButtonsLayout;
    QHBoxLayout * _whitePiecesButtonsLine;
    QHBoxLayout * _blackPiecesButtonsLine;
    QHBoxLayout * _selectedPieceLine;

    loloof64::PositionEditor * _editorComponent;
    QPushButton * _trashCanButton;
    QPushButton * _whitePawnButton;
    QPushButton * _whiteKnightButton;
    QPushButton * _whiteBishopButton;
    QPushButton * _whiteRookButton;
    QPushButton * _whiteQueenButton;
    QPushButton * _whiteKingButton;
    QPushButton * _blackPawnButton;
    QPushButton * _blackKnightButton;
    QPushButton * _blackBishopButton;
    QPushButton * _blackRookButton;
    QPushButton * _blackQueenButton;
    QPushButton * _blackKingButton;
    QLabel * _currentSelectionLabel;
    QLabel * _currentSelectionComponent;

    QTabWidget * _optionsZone;

    QWidget * _generalOptions;
    QVBoxLayout * _generalOptionsLayout;
    QGroupBox * _playerTurnGroup;
    QHBoxLayout * _playerTurnGroupLayout;
    QRadioButton * _whiteTurnButton;
    QRadioButton * _blackTurnButton;
    QHBoxLayout * _easyModificationButtonsLine;
    QPushButton * _eraseAllButton;
    QPushButton * _standardPositionButton;

    QWidget * _fenOptions;
    QVBoxLayout * _fenOptionsLayout;
    QHBoxLayout * _fenValueLineLayout;
    QLabel * _fenValueLabel;
    QLineEdit * _fenValueValue;
    QHBoxLayout * _fenButtonsLine;
    QPushButton * _copyFenButton;
    QPushButton * _pasteFenButton;
    loloof64::PositionBuilder * _positionBuilder;

    char _editingValue = ' ';

    void synchronizeWithBuilder();
    void connectComponents();
    void updateSelectedPiece();
};

#endif // POSITIONEDITORWIDGET_H
