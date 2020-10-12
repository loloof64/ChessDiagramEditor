#include "chessboardcell.h"

loloof64::ChessBoardCell::ChessBoardCell()
{

}

loloof64::ChessBoardCell::ChessBoardCell(int file, int rank) {
    if (file < 0 || file > 7) throw "File not in range [0,7].";
    if (rank < 0 || rank > 7) throw "Rank not in range [0,7].";

    this->file = file;
    this->rank = rank;
}

const std::string loloof64::ChessBoardCell::toStdString() const {
    auto result = QString::asprintf("%c%c", 'a' + file, '1' + rank);
    return result.toStdString();
}
