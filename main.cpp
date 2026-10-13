#include <stdio.h>
#include <iostream>

using namespace std;

void game_initialize() {
    cout << "    a b c d e f g h" << endl;

    int y_scale = 1;

    for (int i = 0; i < 3; i++) {
        cout << "  " << y_scale << " ";
        ++y_scale;
        for (int j = 0; j < 8; j++) {
            cout << "- ";
        }
        cout << endl;
    }

    cout << "  " << y_scale << " ";
    ++y_scale;

    for (int i = 0; i < 3; i++) {
        cout << "- ";
    }

    cout << "O * ";

    for (int i = 0; i < 3; i++) {
        cout << "- ";
    }

    cout << endl;

    cout << "  " << y_scale << " ";
    ++y_scale;

    for (int i = 0; i < 3; i++) {
        cout << "- ";
    }

    cout << "* O ";

    for (int i = 0; i < 3; i++) {
        cout << "- ";
    }

    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "  " << y_scale << " ";
        ++y_scale;

        for (int j = 0; j < 8; j++) {
            cout << "- ";
        }
        cout << endl;
    }
}


int main() {
    game_initialize();  // オセロのゲームを初期化
}
