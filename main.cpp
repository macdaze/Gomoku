#include <stdio.h>
#include <iostream>

using namespace std;

enum class State {
    blank, white, black
};

void draw_game_board(State game_board[18][18]) {
    cout << "    ";
    for (int i = 1; i < 19; ++i) {
        cout << i << " " << endl;
    }

    for (int y_scale = 1; y_scale < 19; ++y_scale) {         //　このループで、game_boardをもとに盤面を描画
        cout << "  " << y_scale << " ";
       for (int x_scale = 1; x_scale < 19; ++x_scale) {
           switch (game_board[y_scale][x_scale]) {
               case State::blank:
                   cout << "+-";
                   break;

               case State::white:
                   cout << "◯-";
                   break;

               case State::black:
                   cout << "●-";
                   break;
           }
       }
        cout << endl;
        for (int i = 1; i < 19; ++i) {
            cout << "|";
        }
    }
}


int main() {
    State game_board[8][8];
    draw_game_board(game_board);  // 五目並べを初期化
}
