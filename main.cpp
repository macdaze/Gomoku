#include <stdio.h>
#include <iostream>

using namespace std;

enum class State {
    blank, white, black
};

void draw_game_board(State game_board[8][8]) {
    for (int i = 0; i < 8; ++i) {               // ↓ここから、オセロの盤を最初の石の状態に初期化
        for (int j = 0; j < 8; ++j) {
            game_board[i][j] = State::blank;
        }
    }
    game_board[3][3] = State::white;
    game_board[4][4] = State::white;
    game_board[3][4] = State::black;
    game_board[4][3] = State::black;            // ↑ここまでで初期化完了

    cout << "    a b c d e f g h" << endl;

    for (int y_scale = 0; y_scale < 8; ++y_scale) {         //　このループで、game_boardをもとにゲーム画面を描画
        cout << "  " << y_scale << " ";
       for (int x_scale = 0; x_scale < 8; ++x_scale) {
           switch (game_board[y_scale][x_scale]) {
               case State::blank:
                   cout << "- ";
                   break;

               case State::white:
                   cout << "O ";
                   break;

               case State::black:
                   cout << "* ";
                   break;
           }
       }
        cout << endl;
    }
}


int main() {
    State game_board[8][8];
    draw_game_board(game_board);  // オセロのゲームを初期化
}
