#ifndef POSITIONEDITOR_H
#define POSITIONEDITOR_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QVector>
#include "../../core/positionbuilder.h"
#include "../../core/adapters/thcposition.h"
#include "../hints/hintarrow.h"
#include "../hints/cellhighlight.h"

namespace loloof64 {
    class PositionEditor : public QWidget
    {
        Q_OBJECT
    public:
        explicit PositionEditor(int cellsSize, QWidget *parent = nullptr);
        virtual ~PositionEditor() override;

        void setFromFen(QString positionValue);
        void setCurrentEditingPiece(char pieceFen);
        void letUserSaveToJPG();

        void addHintArrow(HintArrow *arrow);
        void removeHintArrow(int arrowIndex);
        void removeAllHintArrows();

        void addCellHighlight(CellHighlight *highlight);
        void removeHighlight(int highlightIndex);
        void removeAllHighlights();

    signals:
        void cellSelected(int file, int rank);

    private:
        int _cellsSize;
        loloof64::ThcPosition _position;
        QString _fileDialogPath;
        QVector<HintArrow *> _hintArrows;
        QVector<CellHighlight *> _cellsHighlightings;

        void corePaint(QPainter &painter, int wholeSizePx) const;
        void paintEvent(QPaintEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
    };
}
#endif // POSITIONEDITOR_H
