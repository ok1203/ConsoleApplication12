#ifndef COSOLEAPPLICATION12_PLAYER_H
#define COSOLEAPPLICATION12_PLAYER_H

using namespace std;

class Player {
private:
    char sign;
    bool Bot = false;
public:
    char getSign() const {
        return sign;
    };
    void setSign(char sign) {
        Player::sign = sign;
    };

    bool getBot() const {
        return Bot;
    };
    void setBot(bool Bot) {
        Player::Bot = Bot;
    };
};


#endif