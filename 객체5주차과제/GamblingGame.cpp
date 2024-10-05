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
    cout << "***** �׺� ������ �����մϴ�. *****" << endl;
    string name;

    cout << "ù��° ���� �̸� : ";
    cin >> name;
    p[0].setName(name);

    cout << "\n�ι�° ���� �̸� : ";
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
        cout << p[idx].getName() << "�� �¸�!!" << endl;
        fin = true;
    }
    else {
        cout << "�ƽ�����!" << endl;
    }
}