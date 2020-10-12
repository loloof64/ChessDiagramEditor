#ifndef NEWCELLHIGHLIGHTDIALOG_H
#define NEWCELLHIGHLIGHTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>

#include "hints/chessboardcell.h"

namespace loloof64 {
class NewCellHighlightDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewCellHighlightDialog(QWidget *parent = nullptr);
    ~NewCellHighlightDialog();

signals:
    void newCellHighlight(ChessBoardCell cell, QColor color);

private:
    int _selectedFile, _selectedRank;
    QColor _selectedColor;

    QVBoxLayout* _mainLayout;

    QHBoxLayout* _fileLayout;
    QLabel* _fileLabel;
    QComboBox* _fileValue;

    QHBoxLayout* _rankLayout;
    QLabel* _rankLabel;
    QComboBox* _rankValue;

    QHBoxLayout* _colorLayout;
    QLabel* _colorLabel;
    QPushButton* _selectColorButton;

    QDialogButtonBox * _validationButtons;
};
}

#endif // NEWCELLHIGHLIGHTDIALOG_H
