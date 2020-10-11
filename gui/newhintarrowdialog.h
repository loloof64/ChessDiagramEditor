#ifndef NEWHINTARROWDIALOG_H
#define NEWHINTARROWDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QIntValidator>
#include <QPushButton>

#include "hints/hintarrow.h"

namespace loloof64 {
class NewHintArrowDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewHintArrowDialog(QWidget *parent = nullptr);
    ~NewHintArrowDialog();

signals:
    void newSimpleHintArrowRequested(Cell startcell, Cell endCell, QColor color);

private:
    QColor _selectedColor;
    QVBoxLayout* _mainLayout;

    QHBoxLayout* _startCellLayout;
    QLabel* _startCellFileLabel;
    QSpinBox* _startCellFileLineEdit;
    QLabel* _startCellRankLabel;
    QSpinBox* _startCellRankLineEdit;

    QHBoxLayout* _endCellLayout;
    QLabel* _endCellFileLabel;
    QSpinBox* _endCellFileLineEdit;
    QLabel* _endCellRankLabel;
    QSpinBox* _endCellRankLineEdit;

    QPushButton* _selectColorButton;

    QDialogButtonBox * _validationButtons;
};
}
#endif // NEWHINTARROWDIALOG_H
