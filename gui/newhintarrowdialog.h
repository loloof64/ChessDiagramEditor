#ifndef NEWHINTARROWDIALOG_H
#define NEWHINTARROWDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QIntValidator>
#include <QPushButton>
#include <QLineEdit>

#include "hints/hintarrow.h"

namespace loloof64 {
class NewHintArrowDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewHintArrowDialog(QWidget *parent = nullptr, bool withNumberEditor = false);
    ~NewHintArrowDialog();

signals:
    void newSimpleHintArrowRequested(ChessBoardCell startcell, ChessBoardCell endCell, QColor color);
    void newNumberedHintArrowRequested(ChessBoardCell startCell, ChessBoardCell endCell, QColor _selectedColor, int number);

private:
    bool _withNumberEditor;
    int _startFileIndex, _startRankIndex;
    int _endFileIndex, _endRankIndex;
    QColor _selectedColor;
    QVBoxLayout* _mainLayout;

    QHBoxLayout* _numberEditorLayout;
    QLabel* _numberEditorLabel;
    QLineEdit* _numberEditorLineEdit;
    QIntValidator* _numberValidator;

    QHBoxLayout* _startCellLayout;
    QLabel* _startCellFileLabel;
    QComboBox* _startCellFileCombo;
    QLabel* _startCellRankLabel;
    QComboBox* _startCellRankCombo;

    QHBoxLayout* _endCellLayout;
    QLabel* _endCellFileLabel;
    QComboBox* _endCellFileCombo;
    QLabel* _endCellRankLabel;
    QComboBox* _endCellRankCombo;

    QPushButton* _selectColorButton;

    QDialogButtonBox * _validationButtons;
};
}
#endif // NEWHINTARROWDIALOG_H
