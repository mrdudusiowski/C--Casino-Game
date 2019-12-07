#include <iostream>
#include <string>

#ifndef GRA_H
#define GRA_H

using namespace std;

class Gra
{
    public:
        Gra();
        //Rozpoczecie gry
        void NowaGra();
        void Kontunacja();

        //Metody pomocnicze
        int StanKonta();
        int SetBet();
        void Wygrana(int bet, float mnoznik);
		void Przegrana(int bet);
        void Remis();
        bool GameOver();
        void Leaderboard(int kwota, string nick);
        void showLeaderboard();
        void Kody();
    protected:
        string nick;
        int kwota;
        int bet;
};




#endif // GRA_H
