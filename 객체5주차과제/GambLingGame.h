#include "Player.h"

class GamblingGame {
    Player* p;
    int Num[3];
    bool fin;
    string enter;

public:
    GamblingGame();
    ~GamblingGame();
    void Start();
    void pressEnter();
    void playerTurn(int idx);
    void Jackpot(int idx);
};