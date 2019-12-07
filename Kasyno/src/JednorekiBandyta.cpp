#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "JednoRekiBandyta.h"

void JednoRekiBandyta::Welcome(){

if(Gra::GameOver()){

system("cls");

cout<<"Udajesz sie do stanowiska do gry: Jednoreki Bandyta"<<endl;

system("pause");
system("cls");

}
}

void JednoRekiBandyta::Game(){
if(Gra::GameOver()){
srand( time( NULL ) );

int bet = Gra::SetBet();

int slot1, slot2, slot3;

float mnoznik;

slot1=( std::rand() % 10 ) + 1;

slot2=( std::rand() % 10 ) + 1;

slot3=( std::rand() % 10 ) + 1;

cout<<"Wylosowano nastepujace wartosci: \n\n"<<endl;

cout<<"1) "<<slot1<<endl;
cout<<"2) "<<slot2<<endl;
cout<<"3) "<<slot3<<endl;

system("pause");
system("cls");

if((slot1==1 && slot2==1) || (slot2==1 && slot3==1) ){
    system("cls");
    mnoznik=1.1;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==2 && slot2==2) || (slot2==2 && slot3==2) ){
    system("cls");
    mnoznik=1.2;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==3 && slot2==3) || (slot2==3 && slot3==3) ){
    system("cls");
    mnoznik=1.3;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==4 && slot2==4) || (slot2==4 && slot3==4) ){
    system("cls");
    mnoznik=1.4;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==5 && slot2==5) || (slot2==5 && slot3==5) ){
    system("cls");
    mnoznik=1.5;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==6 && slot2==6) || (slot2==6 && slot3==6) ){
    system("cls");
    mnoznik=1.6;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==7 && slot2==7) || (slot2==7 && slot3==7) ){
    system("cls");
    mnoznik=1.7;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==8 && slot2==8) || (slot2==8 && slot3==8) ){
    system("cls");
    mnoznik=1.8;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==9 && slot2==9) || (slot2==9 && slot3==9) ){
    system("cls");
    mnoznik=1.9;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==10 && slot2==10) || (slot2==10 && slot3==10) ){
    system("cls");
    mnoznik=2.0;
    Gra::Wygrana(bet, mnoznik);
}

else if((slot1==1 && slot2==1 && slot3==1) ){
    system("cls");
    mnoznik=2.1;
    Gra::Wygrana(bet, mnoznik);
}

else if((slot1==2 && slot2==2 && slot3==2) ){
    system("cls");
    mnoznik=2.2;
    Gra::Wygrana(bet, mnoznik);
}

else if((slot1==3 && slot2==3 && slot3==3) ){
    system("cls");
    mnoznik=2.3;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==4 && slot2==4 && slot3==4) ){
    system("cls");
    mnoznik=2.4;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==5 && slot2==5 && slot3==5) ){
    system("cls");
    mnoznik=2.5;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==6 && slot2==6 && slot3==6) ){
    system("cls");
    mnoznik=2.6;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==7 && slot2==7 && slot3==7) ){
    system("cls");
    mnoznik=2.7;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==8 && slot2==8 && slot3==8) ){
    system("cls");
    mnoznik=2.8;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==9 && slot2==9 && slot3==9) ){
    system("cls");
    mnoznik=2.9;
    Gra::Wygrana(bet, mnoznik);
}
else if((slot1==10 && slot2==10 && slot3==10) ){
    system("cls");
    mnoznik=3.0;
    Gra::Wygrana(bet, mnoznik);
}
else{
    system("cls");
    Gra::Przegrana(bet);
}
}
}

