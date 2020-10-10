#ifndef COMPONENTSZONE_H
#define COMPONENTSZONE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QVector>
#include <QFrame>
#include <QScrollArea>
#include <QListWidget>
#include <QPushButton>
#include <QList>
#include "position_editor/positioneditorwidget.h"
#include "../libs/chessx-pgn/database/pgndatabase.h"

namespace loloof64 {
    class ComponentsZone : public QWidget
    {
        Q_OBJECT
    public:
        explicit ComponentsZone(QWidget *parent = nullptr);
        ~ComponentsZone();

    public slots:

    private:
        QHBoxLayout *_mainLayout;
        PositionEditorWidget *_positionEditor;
    };
}

#endif // COMPONENTSZONE_H
