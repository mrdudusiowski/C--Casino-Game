#include <iostream>
#include <string>
#include "Gra.h"


using namespace std;

class BlackJack : public Gra{
public:
void Welcome();
void Game();



protected:
string nick;
int kwota;
};
