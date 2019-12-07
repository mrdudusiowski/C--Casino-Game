#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Gra.h"

Gra::Gra()
{
    //ctor
}

void Gra::NowaGra(){
fstream plik;
string nick;
int kwota;

plik.open( "save.dat",ios::out);
srand( time( NULL ) );

kwota=( std::rand() % 500 ) + 500;

cout<<"Zacznijmy, jak masz na imie?\n"<<endl;
cin>>nick;

system("cls");

cout<<"Witaj w kasynie "<<nick<<" wylosowalismy dla Ciebie kwote pieniedzy ktora wynosi "<<kwota<<"$.\n\nPieniadze te mozesz wydac na dowolna gre, to od Ciebie zalezy z czym wrocisz do domu!"<<endl;
cout<<"\nNic sie nie martw jezeli chodzi o postep zapisujemy go po kazdej grze, wiec do dziela!\n"<<endl;

Gra::nick=nick;
Gra::kwota=kwota;

plik<<nick<<" "<<kwota;

plik.close();
system("pause");
system("cls");

}

void Gra::Kontunacja(){
fstream plik;
string nick;
int kwota;

plik.open("save.dat", ios::in | ios::out | ios::app);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}

cout<<"Witaj znow w kasynie "<<nick<<" Twoj obecny stan konta to "<<kwota<<"$.\n\nPieniadze te mozesz wydac na dowolna gre, to od Ciebie zalezy z czym wrocisz do domu!"<<endl;

system("pause");
system("cls");

Gra::nick=nick;
Gra::kwota=kwota;

plik.close();
}

int Gra::StanKonta(){
fstream plik;
string nick;
int kwota;

plik.open("save.dat", ios::in | ios::out | ios::app);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}

return kwota;
}

int Gra::SetBet(){
    cin.clear();
    int bet;

system("cls");
cout<<"Wprowadz kwote ktora chcesz postawic, uwazaj by kwota nie byla mniejsza niz posiadana"<<endl;

cin>>bet;

while( !cin.good() || bet>Gra::StanKonta() || bet<=0 ){
    system("cls");
    cout<<"Wprowadzono bledna kwote, podaj jeszcze raz: "<<endl;
    cin.ignore();
    cin.clear();
    cin>>bet;
}
//Gra::bet=bet;
return bet;
}

void Gra::Wygrana(int bet, float mnoznik){
fstream plik;
string nick;
int kwota;
//int bet=Gra::bet;
cout<<"Gratulacje wygrales!\n";


plik.open("save.dat", ios::in | ios::out);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}
plik.close();
if(mnoznik==0){
kwota+=bet;
}
else{
    bet*=mnoznik;
    kwota+=bet;
}

cout<<"Twoja obecna suma na koncie to: "<<kwota<<"$"<<endl;

plik.open("save.dat", ios::in | ios::out | ios::trunc);

plik<<nick<<" "<<kwota;

plik.close();

Gra::Leaderboard(kwota, nick);
		}

void Gra::Przegrana(int bet){
fstream plik;
string nick;
int kwota;

cout<<"Niestety przegrales, moze nastepnym razem sie uda!\n";

plik.open("save.dat", ios::in | ios::out);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}
plik.close();
kwota-=bet;
cout<<"Twoja obecna suma na koncie to: "<<kwota<<"$"<<endl;

plik.open("save.dat", ios::in | ios::out | ios::trunc);

plik<<nick<<" "<<kwota;

plik.close();

		}

void Gra::Remis(){
			cout<<"Remis, powrot do menu!\n";
}

bool Gra::GameOver(){
bool warunek=true;
fstream plik;
string nick;
int kwota;

plik.open("save.dat", ios::in | ios::out);
if(plik.good()){
plik>>nick;
plik>>kwota;
}
plik.close();

if(kwota<=0){
    system("cls");
   cout<<"Przykro mi "<<nick<<" gra skonczona, nie masz juz pieniedzy...\n\n"<<endl;

   cout<<"GAME OVER"<<endl;
    system("pause");
    system("cls");

   warunek=false;

   return warunek;
}
else{
return warunek;
}
}

void Gra::Leaderboard(int kwota, string nick){
//string * nick = new string[100];
//int * kasa = new int[100];
bool onetime=true;
string nazwa;
int kasa;
int liczba=1;

ifstream leaderOld;
    leaderOld.open("leaderboards.txt");
ofstream leaderNew;
    leaderNew.open("temporary.txt");

    while (leaderOld.good() && liczba!=100)
    {
        liczba++;
        leaderOld>>nazwa;
        leaderOld>>kasa;

        if (kasa > kwota)
        {
            if(liczba!=100){
            leaderNew << nazwa << " " << kasa <<endl;
            }
            if(liczba==100){
            leaderNew << nazwa << " " << kasa;
            }
        }
        if(kasa < kwota && onetime){
            if(liczba!=100){
            leaderNew << nick << " " << kwota <<endl;
            }
            if(liczba==100){
            leaderNew << nick << " " << kwota;
            }
            onetime=false;
        }
        if(kasa < kwota && onetime==false){
            if(liczba!=100){
            leaderNew << nazwa << " " << kasa <<endl;
            }
            if(liczba==100){
             leaderNew << nazwa << " " << kasa;
            }
        }
    }
    leaderNew.close();
    leaderOld.close();
    remove("leaderboards.txt");
    rename("temporary.txt","leaderboards.txt");

}


void Gra::showLeaderboard(){
fstream plik;
string linia;
plik.open("leaderboards.txt", ios::in);
int licznik=1;
cout<<"Top 100 graczy: "<<endl;

while(!plik.eof()){
    getline(plik, linia);
    cout<<licznik<<".   "<<linia<<endl;
    licznik++;
}
system("pause");
system("cls");
}

void Gra::Kody(){
fstream plik;

string kod;
system("cls");
cout<<"Podaj kod z wersji premium - UWAGA trafiajac tu mamy nadzieje ze znasz kod inaczej Twoj plik zapisu zostanie usuniety :) "<<endl;
cin>>kod;

if(kod=="MotherLode"){
plik.open("save.dat", ios::in | ios::out | ios::app);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}
kwota+=1000;

plik.close();

plik.open("save.dat", ios::in | ios::out | ios::trunc);

plik<<nick<<" "<<kwota;

plik.close();
}
else{

plik.open("save.dat", ios::in | ios::out | ios::app);

while(plik.good()){
    plik>>nick;
    plik>>kwota;
}

plik.close();

plik.open("save.dat", ios::in | ios::out | ios::trunc);

plik<<nick<<" "<<0;

plik.close();

}
system("cls");
}
