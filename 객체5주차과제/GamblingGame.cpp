#include "GamblingGame.h"
#include <iostream>
#include <cstdlib>
using namespace std;

GamblingGame::GamblingGame() {
    p = new Player[2];
    fin = false;
}

GamblingGame::~GamblingGame() {
    delete[] p;
}

void GamblingGame::Start() {
    cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
    string name;

    cout << "첫번째 선수 이름 : ";
    cin >> name;
    p[0].setName(name);

    cout << "\n두번째 선수 이름 : ";
    cin >> name;
    p[1].setName(name);

    cin.ignore();

    srand((unsigned)time(0));

    while (!fin) {
        playerTurn(0);
        if (fin) break;
        playerTurn(1);
    }
}

void GamblingGame::pressEnter() {
    getline(cin, enter);
}

void GamblingGame::playerTurn(int j) {
    cout << "\n"<< p[j].getName() << ": ";
    pressEnter();
    cout << "\t\t";

    for (int i = 0; i < 3; i++) {
        Num[i] = rand() % 3;
        cout << Num[i] << '\t';
    }
    Jackpot(j);
}

void GamblingGame::Jackpot(int idx) {
    if (Num[0] == Num[1] && Num[1] == Num[2]) {
        cout << p[idx].getName() << "님 승리!!" << endl;
        fin = true;
    }
    else {
        cout << "아쉽군요!" << endl;
    }
}