#ifndef CHESSBOARDCELL_H
#define CHESSBOARDCELL_H

#include <QString>
#include <string.h>

namespace loloof64 {
struct ChessBoardCell
{
public:
    ChessBoardCell();
    ChessBoardCell(int file, int rank);
    int file, rank;
    const std::string toStdString() const;
};
}

#endif // CHESSBOARDCELL_H
