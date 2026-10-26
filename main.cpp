#include <stdio.h>
#include <iostream>

using namespace std;

enum class State {
    blank, white, black
};

struct board_vector {
    int x;
    int y;
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
        switch (game_board[y][19]) {        // XXX なぜか座標jjだけ、初期状態でも白石が置かれてる　なんで〜？
           case State::blank:
                cout << "+" <<endl;
                break;

           case State::white:
                cout << "○" << endl;
                break;

           case State::black:
                cout << "●" << endl;
                break;
        }
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
}

board_vector wait_user_move(State game_board[19][19], State turn) {
   cout << "  X-coordinate:";
    char x_coordinate = 0;
   cin >> x_coordinate;

    cout << "  Y-coordinate:";
    char y_coordinate = 0;
    cin >> y_coordinate;

    switch (x_coordinate) {
        case '1':
            x_coordinate = 1;
            break;

        case '2':
            x_coordinate = 2;
            break;

        case '3':
            x_coordinate = 3;
            break;

        case '4':
            x_coordinate = 4;
            break;

        case '5':
            x_coordinate = 5;
            break;

        case '6':
            x_coordinate = 6;
            break;

        case '7':
            x_coordinate = 7;
            break;

        case '8':
            x_coordinate = 8;
            break;

        case '9':
            x_coordinate = 9;
            break;

        case 'a':
            x_coordinate = 10;
            break;

        case 'b':
            x_coordinate = 11;
            break;

        case'c':
            x_coordinate = 12;
            break;

        case 'd':
            x_coordinate = 13;
            break;

        case 'e':
            x_coordinate = 14;
            break;

        case 'f':
            x_coordinate = 15;
            break;

        case 'g':
            x_coordinate = 16;
            break;

        case 'h':
            x_coordinate = 17;
            break;

        case 'i':
            x_coordinate = 18;
            break;

        case 'j':
            x_coordinate = 19;
            break;
    }

    switch (y_coordinate) {
        case '1':
            y_coordinate = 1;
            break;

        case '2':
            y_coordinate = 2;
            break;

        case '3':
            y_coordinate = 3;
            break;

        case '4':
            y_coordinate = 4;
            break;

        case '5':
            y_coordinate = 5;
            break;

        case '6':
            y_coordinate = 6;
            break;

        case '7':
            y_coordinate = 7;
            break;

        case '8':
            y_coordinate = 8;
            break;

        case '9':
            y_coordinate = 9;
            break;

        case 'a':
            y_coordinate = 10;
            break;

        case 'b':
            y_coordinate = 11;
            break;

        case'c':
            y_coordinate = 12;
            break;

        case 'd':
            y_coordinate = 13;
            break;

        case 'e':
            y_coordinate = 14;
            break;

        case 'f':
            y_coordinate = 15;
            break;

        case 'g':
            y_coordinate = 16;
            break;

        case 'h':
            y_coordinate = 17;
            break;

        case 'i':
            y_coordinate = 18;
            break;

        case 'j':
            y_coordinate = 19;
            break;
    }

    switch (turn) {
        case State::white:
            game_board[y_coordinate - 1][x_coordinate] = State::white;
            break;

        case State::black:
            game_board[y_coordinate - 1][x_coordinate] = State::black;
            break;
    }

    board_vector last_move;
    last_move.x = x_coordinate;
    last_move.y = y_coordinate;

    return last_move;
}


int main() {
    State game_board[19][19];                   // ↓碁盤の状態を初期化
    for (int y = 0; y < 19; ++y) {
        for (int x = 0; x < 19; ++x) {
            game_board[y][x] = State::blank;
        }
    }                                           // ↑ここまで

    State turn = State::black;    // 最初は黒手番に設定
    State winner = State::blank;  //　試合を開始した時点では勝者は未定

    draw_game_board(game_board, turn);  // 碁盤を描画

    while (winner == State::blank) {
        board_vector last_move = wait_user_move(game_board, turn);

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
