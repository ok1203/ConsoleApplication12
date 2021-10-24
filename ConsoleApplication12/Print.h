#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

class Print
{
public:

    void print(char state[3][3]) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (i % 2 == 0) {
                    cout << setfill(' ') << setw(2);
                    cout << state[i / 2][j];
                    cout << setfill(' ') << setw(2);
                }
                else {
                    if (i != 5) {
                        cout << setfill('_') << setw(4);
                    }
                    else {
                        cout << setfill(' ') << setw(4);
                    }
                }
                if (j != 2) {
                    cout << '|';
                }
                else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
};