#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Ruletka.h"

Gra gra;

void RuletkaTablice(int wybor, int bet){
                srand( time( NULL ) );


				int numer=(rand()%37);

				int czarne[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
				int czerwone[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};

				float mnoznik;

				cout<<"Wylosowana liczba: "<<numer<<"\n";
				if(wybor==1){
					bool IsRed=false;

					for(int i=0;i<=17;i++){
						if(numer==czerwone[i]){
							IsRed=true;
						}
					}

					if(IsRed==true){
                        mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(IsRed==false){
						gra.Przegrana(bet);
					}
				}
				if(wybor==2){
					bool IsBlack=false;
					for(int i=0;i<=17;i++){
						if(numer==czarne[i]){
							IsBlack=true;
						}
					}
					if(IsBlack==true){
						mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(IsBlack==false){
						gra.Przegrana(bet);
					}
				}
				if(wybor==4){
					if(numer%2==0){
						mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer%2==1){
						gra.Przegrana(bet);
					}
				}
				if(wybor==5){
					if(numer%2==1){
						mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer%2==0){
						gra.Przegrana(bet);
					}
				}

				if(wybor==6){
					if(numer>=1 && numer<=18){
						mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer<1 || numer>18){
						gra.Przegrana(bet);
					}
				}
				if(wybor==7){
					if(numer>=19 && numer<=36){
						mnoznik=0;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer<19 || numer>36){
						gra.Przegrana(bet);
					}
				}
				if(wybor==8){
					if(numer>=1 && numer<=12){
						mnoznik=4;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer<1 || numer>12){
						gra.Przegrana(bet);
					}
				}
				if(wybor==9){
					if(numer>=13 && numer<=24){
						mnoznik=4;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer<13 || numer>24){
						gra.Przegrana(bet);
					}
				}
				if(wybor==10){
					if(numer>=25 && numer<=36){
						mnoznik=4;
						gra.Wygrana(bet, mnoznik);
					}
					if(numer<25 || numer>36){
						gra.Przegrana(bet);
					}
				}
			}

void RuletkaNumery(int numer, int bet){
				int wylosowany=(rand()%37);
				float mnoznik;

				cout<<"Wylosowana liczba: "<<wylosowany<<endl;

				if(numer==wylosowany){
                    if(wylosowany==0){
					mnoznik=16;}
					else{
                    mnoznik=35;
					}
                    gra.Wygrana(bet, mnoznik);
				}
				if(numer!=wylosowany){
					gra.Przegrana(bet);
				}

			}





void Ruletka::Welcome(){

if(Gra::GameOver()){

system("cls");

cout<<"Udajesz sie do stanowiska do gry: Ruletka"<<endl;

system("pause");
system("cls");

}
}

void Ruletka::Instrukcja(){

system("cls");
cout<<"Instrukcja\n";
			cout<<"Krok 1: Wprowadz stawke"<<endl;
			cout<<"Krok 2: Wybierasz na co chcesz postawic"<<endl;
			cout<<"Krok 3: Nastepuje losowanie liczby"<<endl;
			cout<<"Krok 4: Wyplaty"<<endl;
			cout<<"\n\nMnoznik wygranych:\n1) Wybrany kolor - bet x2\n2) Wybrany numer - bet x35\n3) Postawienie na parzystosc - bet x2\n4) Postawienie na polowke 1:18 / 19:36 - bet x2";
			cout<<"\n5) Postawienie na 0 -  bet x16\n6) Postawienie na cwiartke 1:12 / 13:24 / 25:36 - bet x4\n"<<endl;

			system("pause");

			}


void Ruletka::Game(){

int bet, wybor;

system("cls");

bet=Gra::SetBet();

cout<<"Wybierz co obstawiasz: "<<endl;
cout<<"1) Czerwony"<<endl;
cout<<"2) Czarny"<<endl;
cout<<"3) Zielony"<<endl;
cout<<"4) Parzyste"<<endl;
cout<<"5) Nieparzyste"<<endl;
cout<<"6) Numery od 1 do 18"<<endl;
cout<<"7) Numery od 19 do 36"<<endl;
cout<<"8) Numery od 1 do 12"<<endl;
cout<<"9) Numery od 13 do 24"<<endl;
cout<<"10) Numery od 25 do 36"<<endl;
cout<<"11) Liczbe"<<endl;
cout<<"12) Powrot"<<endl;

cin.ignore();
cin.clear();

cin>>wybor;

while(!cin.good()){
cin.ignore();
cin.clear();
cout<<"Podaj jeszcze raz poprawna wartosc: "<<endl;
cin>>wybor;
}

if(wybor==1 || wybor==2 || wybor==4 || wybor==5 || wybor==6 || wybor==7 || wybor==8 || wybor==9 || wybor==10)
    {
					RuletkaTablice(wybor, bet);
    }

if(wybor==3){
RuletkaNumery(0, bet);
}

if(wybor==11){

                system("cls");
                cout<<"Wybierz liczbe z przedzialu od 1 do 36"<<endl;

                int numer;

                cin.ignore();
                cin.clear();

                cin>>numer;

                if(cin.good() && numer<=36 && numer>=0){
                       RuletkaNumery(numer, bet);
                    }
                if(!cin.good()){
                        cin.ignore();
                        cin.clear();

                        }
                }


}
