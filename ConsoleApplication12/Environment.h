#ifndef COSOLEAPPLICATION12_ENVIRONMENT_H
#define COSOLEAPPLICATION12_ENVIRONMENT_H

#include "Player.h"
#include "Print.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

class Environment : public Print{
private:
    char state[3][3] = { {'.','.','.'},{'.','.','.'},{'.','.','.'} };
    Player player1;
    Player player2;

public:

    Environment() {
        player1.setSign('X');
        player2.setSign('O');
    };

    void print() {
        Print::print(state);
    };

    bool inputPlayer(char sign) {
        int input1, input2;
        cin >> input1;
        cin >> input2;
        if (state[input1][input2] == '.') {
            state[input1][input2] = sign;
        }
        else {
            return inputPlayer(sign);
        }
        return true;

    };
    bool inputRandom(char side) {
        int input1 = rand() % 3;
        int input2 = rand() % 3;
        if (state[input1][input2] == '.') {
            state[input1][input2] = side;
        }
        else {
            return inputRandom(side);
        }
        return true;
    };

    bool stateWin() {
        if (state[0][0] == 'X' && state[0][1] == 'X' && state[0][2] == 'X') return true;
        if (state[1][0] == 'X' && state[1][1] == 'X' && state[1][2] == 'X') return true;
        if (state[2][0] == 'X' && state[2][1] == 'X' && state[2][2] == 'X') return true;
        if (state[0][0] == 'X' && state[1][0] == 'X' && state[2][0] == 'X') return true;
        if (state[0][1] == 'X' && state[1][1] == 'X' && state[2][1] == 'X') return true;
        if (state[0][2] == 'X' && state[1][2] == 'X' && state[2][2] == 'X') return true;
        if (state[0][0] == 'X' && state[1][1] == 'X' && state[2][2] == 'X') return true;
        if (state[2][0] == 'X' && state[1][1] == 'X' && state[0][2] == 'X') return true;
        if (state[0][0] == 'O' && state[0][1] == 'O' && state[0][2] == 'O') return true;
        if (state[1][0] == 'O' && state[1][1] == 'O' && state[1][2] == 'O') return true;
        if (state[2][0] == 'O' && state[2][1] == 'O' && state[2][2] == 'O') return true;
        if (state[0][0] == 'O' && state[1][0] == 'O' && state[2][0] == 'O') return true;
        if (state[0][1] == 'O' && state[1][1] == 'O' && state[2][1] == 'O') return true;
        if (state[0][2] == 'O' && state[1][2] == 'O' && state[2][2] == 'O') return true;
        if (state[0][0] == 'O' && state[1][1] == 'O' && state[2][2] == 'O') return true;
        if (state[2][0] == 'O' && state[1][1] == 'O' && state[0][2] == 'O') return true;
        return false;
    };

    void playWithin() {
        player1.setSign('X');
        player2.setSign('O');

        print();
        for (int i = 0; i < 5; i++) {
            while (!inputPlayer('X')) {
                inputPlayer('X');
            }
            print();
            if (stateWin()) {
                cout << "X wins" << endl;
                break;
            }
            if (i == 4) {
                cout << "Tie!" << endl;
                break;
            }
            while (!inputPlayer('O')) {
                inputPlayer('O');
            }
            print();
            if (stateWin()) {
                cout << "O wins!" << endl;
                break;
            }
        }

    };
    void playRandom() {
        player1.setSign('X');
        player1.setSign('O');
        player2.setBot(true);
        print();
        for (int i = 0; i < 5; i++) {
            while (!inputPlayer('X')) {
                inputPlayer('X');
            }
            print();
            if (stateWin()) {
                cout << "X wins!" << endl;
                break;
            }
            if (i == 4) {
                cout << "Tie!" << endl;
                break;
            }
            inputRandom('O');
            print();
            if (stateWin()) {
                cout << "O wins!" << endl;
                break;
            }
        }
    };

    const Player& getPlayer1() const {
        return player1;
    };
    void setPlayer1(const Player& player1) {
        Environment::player1 = player1;
    };

    const Player& getPlayer2() const {
        return player2;
    };
    void setPlayer2(const Player& player2) {
        Environment::player2 = player2;
    };
};


#endif
