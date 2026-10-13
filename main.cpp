#include <stdio.h>
#include <iostream>

using namespace std;

enum class State {
    Default, White, Black   //　盤面の取りうる全ての状態
};

void game_initialize(State GameBoard[7][7]) {
    for (int i = 0; i < 7; ++i) {               // 盤面の状態の初期化に取り掛かる
        for (int j = 0; j < 7; ++j) {
            GameBoard[i][j] = State::Default;
        }
    }

    GameBoard[3][3] = State::White; // ↓4行　盤面の最初の石の状態
    GameBoard[4][4] = State::White;
    GameBoard[3][4] = State::Black;
    GameBoard[4][3] = State::Black;

    cout << "    a b c d e f g h" << endl;  // 行番号を表示

    int y_scale = 1;

    for (int i = 0; i < 3; ++i) {
        cout << "  " << y_scale << " "; // 列番号を表示　この関数内の同様の記述も同じ意味
        ++y_scale;
        for (int j = 0; j < 8; ++j) {
            cout << "- ";
        }
        cout << endl;
    }

    cout << "  " << y_scale << " ";
    ++y_scale;

    for (int i = 0; i < 3; ++i) {
        cout << "- ";
    }

    cout << "O * ";

    for (int i = 0; i < 3; ++i) {
        cout << "- ";
    }

    cout << endl;

    cout << "  " << y_scale << " ";
    ++y_scale;

    for (int i = 0; i < 3; ++i) {
        cout << "- ";
    }

    cout << "* O ";

    for (int i = 0; i < 3; ++i) {
        cout << "- ";
    }

    cout << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "  " << y_scale << " ";
        ++y_scale;

        for (int j = 0; j < 8; ++j) {
            cout << "- ";
        }
        cout << endl;
    }
}


int main() {
    State GameBoard[7][7];

    game_initialize(GameBoard);  // オセロのゲーム画面を初期化

    return 0;
}
