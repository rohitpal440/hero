#include <iostream>
#include <vector>

using namespace std;

bool placeQueenIn(int row, vector< pair<int, int> > &alreadyPlacedQueens, int boardSize) {
    if (row == boardSize)
        return true;
    auto canPlaceQueenAt = [] (int row, int col, const vector< pair<int, int> > &alreadyPlacedQueens) -> bool const {
        for (auto queenPosition: alreadyPlacedQueens) {
            if (queenPosition.first == row || queenPosition.second == col || row + col == queenPosition.first + queenPosition.second || col - row == queenPosition.second - queenPosition.first)
                return false;
        }
        return true;
    };
    bool queenPlaced = false;
    for (int col = 0; col < boardSize; col++) {
        if (canPlaceQueenAt(row, col, alreadyPlacedQueens) &&  queenPlaced == false) {
            alreadyPlacedQueens.push_back({row, col});
            queenPlaced = placeQueenIn(row + 1, alreadyPlacedQueens, boardSize);
            if (queenPlaced) {
                return queenPlaced;
            }
            alreadyPlacedQueens.pop_back();
        }
    }
    return queenPlaced;
}

pair<bool, vector< pair<int,int> > > placeQueens(int boardSize) {
    vector< pair<int, int> > alreadyPlacedQueens;
    bool canPlaceQueens = placeQueenIn(0, alreadyPlacedQueens, boardSize);
    return {canPlaceQueens, alreadyPlacedQueens};
}

void printBoard(int boardSize, const vector< pair<int, int> > &queensPositions) {
    for (auto queen: queensPositions) {
        for (int i = 0; i < boardSize; i++ ) {
            if (i == queen.second)
                cout << " * ";
            else
                cout << " - ";
        }
        cout << endl;
    }
}

int main() {
    int boardSize = 2;
    auto result = placeQueens(boardSize);
    if (result.first)
        printBoard(boardSize, result.second);
    else
        cout << "No combination possible" << endl;
}
