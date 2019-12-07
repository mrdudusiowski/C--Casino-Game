#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Gra.h"
#include "BlackJack.h"
#include "JednorekiBandyta.h"
#include "Ruletka.h"

using namespace std;
//Deklaracje globalne

Gra game;
BlackJack black;
JednoRekiBandyta jednoreki;
Ruletka ruletka;


//Menu do gry Ruletka

void MenuRuletka(){
bool Quit = false;
int Wybor;
while(!Quit){
system("cls");
cout<<"Wybierz opcje z ponizszego menu:\n"<<endl;

cout<<"1. Zagraj"<<endl;
cout<<"2. Instrukcja"<<endl;
cout<<"3. Stan konta"<<endl;
cout<<"4. Powrot do wyboru gier"<<endl;

cin>>Wybor;

switch(Wybor){

case 1:
    //Funkcje z klasy Ruletka
    ruletka.Game();
    system("pause");
    system("cls");
    break;

case 2:
    //Funckja pokazujaca stan konta
    ruletka.Instrukcja();
    break;

case 3:
    //Funckja pokazujaca stan konta
    system("cls");
    cout<<"Twoj obecny stan konta to: "<<game.StanKonta()<<"$"<<endl;
    system("pause");
    break;
case 4:
    Quit=true;
    system("cls");
    cout<<"Wracamy do menu!"<<endl;
    system("pause");
    system("cls");
    break;

default:
    cout<<"Wprowadzono bledna wartosc sprobuj jeszcze raz"<<endl;
    break;


}
}
}


//Menu do gry Jednoreki bandyta

void MenuJednorekiBandyta(){
bool Quit = false;
int Wybor;
while(!Quit){
system("cls");
cout<<"Wybierz opcje z ponizszego menu:\n"<<endl;

cout<<"1. Zagraj"<<endl;
cout<<"2. Stan konta"<<endl;
cout<<"3. Powrot do wyboru gier"<<endl;

cin>>Wybor;

switch(Wybor){

case 1:
    //Funkcje z klasy JednorekiBandyta
    system("cls");
    jednoreki.Game();
    system("pause");
    system("cls");
    break;
case 2:
    //Funckja pokazujaca stan konta
    system("cls");
    cout<<"Twoj obecny stan konta to: "<<game.StanKonta()<<"$"<<endl;
    system("pause");
    break;
case 3:
    Quit=true;
    system("cls");
    cout<<"Wracamy do menu!"<<endl;
    system("pause");
    system("cls");
    break;

default:
    cout<<"Wprowadzono bledna wartosc sprobuj jeszcze raz"<<endl;
    break;


}
}
}
//Menu do gry Black Jack

void MenuBlackJack(){
bool Quit = false;
int Wybor;
while(!Quit){
system("cls");
cout<<"Wybierz opcje z ponizszego menu:\n"<<endl;

cout<<"1. Zagraj"<<endl;
cout<<"2. Stan konta"<<endl;
cout<<"3. Powrot do wyboru gier"<<endl;

cin>>Wybor;

switch(Wybor){

case 1:
    //Funkcje z klasy BlackJack
    system("cls");
    black.Game();
    system("pause");
    system("cls");
    break;
case 2:
    //Funckja pokazujaca stan konta
    system("cls");
    cout<<"Twoj obecny stan konta to: "<<game.StanKonta()<<"$"<<endl;
    system("pause");
    break;
case 3:
    Quit=true;
    system("cls");
    cout<<"Wracamy do menu!"<<endl;
    system("pause");
    system("cls");
    break;

default:
    cout<<"Wprowadzono bledna wartosc sprobuj jeszcze raz"<<endl;
    break;


}




}


}



//Wybranie gry przez gracza

void WybierzGre(){
bool Quit = false;
int Wybor;

while(!Quit){

    cin.ignore();
    system("cls");

    cout<<"Wybierz stanowisko do ktorego sie udasz: \n"<<endl;

    cout<<"1. BlackJack"<<endl;

    cout<<"2. Jednoreki bandyta"<<endl;

    cout<<"3. Ruletka"<<endl;

    cout<<"4. Stan konta"<<endl;

    cout<<"5. Powrot do menu"<<endl;

    cin>>Wybor;

    switch(Wybor){

        case 1:
            //BlackJack
            black.Welcome();
            MenuBlackJack();
            break;

        case 2:
            //Jednoreki bandyta
            jednoreki.Welcome();
            MenuJednorekiBandyta();
            break;

        case 3:
            //Ruletka
            ruletka.Welcome();
            MenuRuletka();
            break;

        case 4:
            //Stan konta
            system("cls");
            cout<<"Twoj obecny stan konta wynosi: "<<game.StanKonta()<<"$"<<endl;
            system("pause");
            system("cls");
            break;

        case 5:
            //Wyjscie
            system("cls");
            cout<<"Wracamy do menu!"<<endl;
            system("pause");
            system("cls");
            Quit=true;
            break;

    }}



}

//Posiada sprawdzenie istnienia pliku oraz odpala odpowiednia funkcje z klasy

void nowaGra(){
//Deklaracja zmiennych pytanie i plik
string pytanie;
fstream plik;


//Proba otwarcia pliku

plik.open( "save.dat", ios::in | ios::out );

//Sprawdzenie pliku

if( plik.is_open() ){

//Pytanie o nowa gre

    cout<<"Czy na pewno chcesz rozpoczac nowa przygode w kasynie? TAK/NIE"<<endl;

//Pobranie odpowiedzi

    cin>>pytanie;

//Sprawdzenie czy uzytkownik dal tak

    if(pytanie=="TAK" || pytanie=="tak"){
            cout<<"Okej zaczynamy!"<<endl;
            system("pause");
            system("cls");
            game.NowaGra();
            WybierzGre();
            }

//Sprawdzenie czy uzytkownik dal nie

    else if(pytanie=="NIE" || pytanie=="nie") {
            cout<<"To wracamy do wczesniejszej gry..."<<endl;
            system("pause");
            system("cls");
            game.Kontunacja();
            if(game.GameOver()){
            WybierzGre();}
           }


//Inne wyjatki

    else{
            cout<<"Bledne dane"<<endl;
            cout<<"Powrot do menu...."<<endl;
            system("pause");
            system("cls");
            }

}

//Plik nie istnieje - nowa gra
        else{
        cout<<"Okej zaczynamy bez zbednego ociagania!"<<endl;
        system("pause");
        system("cls");
        game.NowaGra();
        WybierzGre();
        }
}

//Wyswietlanie menu glownego

void ShowMenu(){
//Inicjacja pliku
fstream plik;
plik.open( "save.dat", ios::in | ios::out );

//Sprawdzenie czy plik istnieje - jezeli tak wyswietla inne menu
if( plik.is_open() ){
cout<<"Wybierz opcje z ponzszego menu\n"<<endl;

    cout<<"1. Kontynuacja"<<endl;

    cout<<"2. Nowa Gra"<<endl;

    cout<<"3. Tablica wynikow"<<endl;

    cout<<"4. Kody"<<endl;

    cout<<"5. Wyjscie"<<endl;
}
//Menu bez kontynuacji
else{
    cout<<"Wybierz opcje z ponzszego menu\n"<<endl;

    cout<<"1. Nowa Gra"<<endl;

    cout<<"2. Tablica wynikow"<<endl;

    cout<<"3. Kody"<<endl;

    cout<<"4. Wyjscie"<<endl;

}

}

//Cala struktura menu z wyborem

void Menu(){
//Inicjalizacja zmiennych

bool Quit = false;
char Wybor;

//Dopoki uzytkownik nie bedzie chcial wyjsc trwa nieskonczona petla wyswietlajaca menu
while(!Quit) {

//Wyœwietlenie menu
ShowMenu();

//Pobranie opcji
cin >> Wybor;

//Otwarcie pliku
fstream plik;
plik.open( "save.dat", ios::in | ios::out );

//Je¿eli plik istnieje to te menu dzia³a
if(plik.is_open()){

     switch (Wybor) {
            case '1':
                //Kontunacja
            system("cls");
            if(game.GameOver()){

            game.Kontunacja();
            WybierzGre();
            }

            break;

            case '2':
                //Nowa gra
                system("cls");
                nowaGra();
                break;

            case '3':
                 //Lederboard
                 system("cls");
                 game.showLeaderboard();
                 break;

            case '4':
                 //Kody
                 system("cls");
                 game.Kody();
                 break;
            case '5':
                //Wyjscie
                Quit = true;
                system("cls");
                cout<<"Dziekujemy za gre, mamy nadzieje ze wpadniesz znow!\n\n"<<endl;
                break;

            default:
                  system("cls");
                  cout<<"Uhh...Chyba wybrales zla opcje, sproboj jeszcze raz"<<endl;
                  system("pause");
                  system("cls");
                  break;}
}

//W przeciwnym wypadku te menu

else{
         switch (Wybor) {
            case '1':
                //Nowa gra
                system("cls");
                nowaGra();
                break;

            case '2':
                 //Leaderboard
                 system("cls");
                 game.showLeaderboard();
                 break;

            case '3':
                 //Kody
                 system("cls");
                 game.Kody();
                 break;

            case '4':
                //Wyjscie
                Quit = true;
                system("cls");
                cout<<"Dziekujemy za gre, mamy nadzieje ze wpadniesz znow!\n\n"<<endl;
                system("pause");;
                 break;

            default:
                  system("cls");
                  cout<<"Uhh...Chyba wybrales zla opcje, sproboj jeszcze raz"<<endl;
                  system("pause");
                  system("cls");
                  break;
     }
}}}

//Przywitanie gracza i rozpoczecie funkcji

int main(){
    cout<<"Witamy w grze Kasyno, gra zostala utworzona przez Patryka Dudus z grupy F11.\n\nMilego grania!"<<endl;
    system("pause");
    system("cls");
    Menu();
    return 0;
}
