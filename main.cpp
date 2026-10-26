#include <stdio.h>
#include <iostream>

using namespace std;

enum class State {
    blank, white, black
};

void draw_game_board(State game_board[19][19], State turn) {
    cout << endl;

    cout << "    1 2 3 4 5 6 7 8 9 a b c d e f g h i j";

    cout << endl;

    const char y_scale[19] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    for (int y = 0; y < 19; ++y) {         //　このループで、game_boardをもとに19路盤を描画
        cout << "  " << y_scale[y] << " ";
       for (int x = 1; x < 19; ++x) {
           switch (game_board[y][x]) {
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
        cout << "+" << endl;
    }

    cout << endl;

    switch (turn) {
        case State::white:
            cout << "  White Turn" << endl;
            break;

        case State::black:
            cout << "  Black Turn" << endl;
            break;
    }
    cout << endl;
}


int main() {
    State game_board[19][19];                   // ↓碁盤の状態を初期化
    for (int y = 0; y < 19; ++y) {
        for (int x = 0; x < 19; ++x) {
            game_board[y][x] = State::blank;
        }
    }                                          // ↑ここまで

    State turn = State::black;    // 最初は黒手番に設定
    State winner = State::blank;  //　試合を開始した時点では勝者は未定

    struct vector {
        int x;
        int y;
    };

    draw_game_board(game_board, turn);  // 碁盤を描画

    while (winner == State::blank) {
        vector last_move = wait_user_move(game_board, turn);

        check_winner(game_board, turn, last_move);

        draw_game_board(game_board, turn);

        switch (turn) {
            case State::white:
                turn = State::black;
                break;

            case State::black:
                turn = State::white;
                break;
        }
    }
}
