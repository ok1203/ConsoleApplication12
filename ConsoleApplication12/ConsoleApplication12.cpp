#include "Environment.h";
#include <ctime>

int main() {
    srand(time(0));
    Environment main;
    main.playRandom();
}