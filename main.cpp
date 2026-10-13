#include <stdio.h>
#include <iostream>

using namespace std;

void game_initialize(int x_cross, int y_cross) {
    for (int i = 0; i < ((y_cross - 2) / 2); i++) {
       for (int j = 0; j < x_cross; j++) {
           cout << "-";
       }
        cout << endl;
    }

    for (int i = 0; i < ((x_cross - 2) / 2); i++) {
        cout << "-";
    }

    cout << "O" << "*";

    for (int i = 0; i < ((x_cross - 2) / 2); i++) {
        cout << "-";
    }

    cout << endl;

    for (int i = 0; i < ((x_cross - 2) / 2); i++) {
        cout << "-";
    }

    cout << "*" << "O";

    for (int i = 0; i < ((x_cross - 2) / 2); i++) {
        cout << "-";
    }

    cout << endl;

    for (int i = 0; i < ((y_cross - 2) / 2); i++) {
        for (int j = 0; j < x_cross; j++) {
            cout << "-";
        }
        cout << endl;
    }
}

int main() {
    int x_cross = 10;
    int y_cross = 10;

    game_initialize(x_cross, y_cross);
}
