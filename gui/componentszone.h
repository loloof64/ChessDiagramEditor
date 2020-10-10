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
#include "chessboard/chessboard.h"
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
        ChessBoard *_chessBoard;
    };
}

#endif // COMPONENTSZONE_H
