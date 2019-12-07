#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "BlackJack.h"



void BlackJack::Welcome(){

if(Gra::GameOver()){

system("cls");

cout<<"Udajesz sie do stanowiska do gry: Black Jack"<<endl;

system("pause");
system("cls");
}

}


void BlackJack::Game(){
if(Gra::GameOver()){
srand( time( NULL ) );
int talia1[52];
int talia2[52];
int ilosckart1=0, karta1, ilosckart2=0, karta2;
int SumaGracz, SumaCpu;
int zestawkart1[13]={1,1,1,1,1,1,1,1,1,1,1,1,1};
int zestawkart2[13]={1,1,1,1,1,1,1,1,1,1,1,1,1};
float mnoznik=0;

while(ilosckart1!=52){

karta1=( std::rand() % 13 ) + 2;

//Losowanie talii kart gracza

if(karta1==2 && zestawkart1[0]<=4){

talia1[ilosckart1]=2;

zestawkart1[0]+=1;

ilosckart1++;
}
if(karta1==3 && zestawkart1[1]<=4){

talia1[ilosckart1]=3;

zestawkart1[1]+=1;

ilosckart1++;
}
if(karta1==4 && zestawkart1[2]<=4){

talia1[ilosckart1]=4;

zestawkart1[2]+=1;

ilosckart1++;
}
if(karta1==5 && zestawkart1[3]<=4){

talia1[ilosckart1]=5;

zestawkart1[3]+=1;

ilosckart1++;
}
if(karta1==6 && zestawkart1[4]<=4){

talia1[ilosckart1]=6;

zestawkart1[4]+=1;

ilosckart1++;
}
if(karta1==7 && zestawkart1[5]<=4){

talia1[ilosckart1]=7;

zestawkart1[5]+=1;

ilosckart1++;
}
if(karta1==8 && zestawkart1[6]<=4){

talia1[ilosckart1]=8;

zestawkart1[6]+=1;

ilosckart1++;
}
if(karta1==9 && zestawkart1[7]<=4){

talia1[ilosckart1]=9;

zestawkart1[7]+=1;

ilosckart1++;
}
if(karta1==10 && zestawkart1[8]<=4){

talia1[ilosckart1]=10;

zestawkart1[8]+=1;

ilosckart1++;
}
if(karta1==11 && zestawkart1[9]<=4){

talia1[ilosckart1]=2;

zestawkart1[9]+=1;

ilosckart1++;
}
if(karta1==12 && zestawkart1[10]<=4){

talia1[ilosckart1]=3;

zestawkart1[10]+=1;

ilosckart1++;
}
if(karta1==13 && zestawkart1[11]<=4){

talia1[ilosckart1]=4;

zestawkart1[11]+=1;

ilosckart1++;
}
if(karta1==14 && zestawkart1[12]<=4){

talia1[ilosckart1]=11;

zestawkart1[12]+=1;

ilosckart1++;
}
}

while(ilosckart2!=52){

//Losowanie talii CPU
karta2=( std::rand() % 13 ) + 2;

if(karta2==2 && zestawkart2[0]<=4){

talia2[ilosckart2]=2;

zestawkart2[0]+=1;

ilosckart2++;
}
if(karta2==3 && zestawkart2[1]<=4){

talia2[ilosckart2]=3;

zestawkart2[1]+=1;

ilosckart2++;
}
if(karta2==4 && zestawkart2[2]<=4){

talia2[ilosckart2]=4;

zestawkart2[2]+=1;

ilosckart2++;
}
if(karta2==5 && zestawkart2[3]<=4){

talia2[ilosckart2]=5;

zestawkart2[3]+=1;

ilosckart2++;
}
if(karta2==6 && zestawkart2[4]<=4){

talia2[ilosckart2]=6;

zestawkart2[4]+=1;

ilosckart2++;
}
if(karta2==7 && zestawkart2[5]<=4){

talia2[ilosckart2]=7;

zestawkart2[5]+=1;

ilosckart2++;
}
if(karta2==8 && zestawkart2[6]<=4){

talia2[ilosckart2]=8;

zestawkart2[6]+=1;

ilosckart2++;
}
if(karta2==9 && zestawkart2[7]<=4){

talia2[ilosckart2]=9;

zestawkart2[7]+=1;

ilosckart2++;
}
if(karta2==10 && zestawkart2[8]<=4){

talia2[ilosckart2]=10;

zestawkart2[8]+=1;

ilosckart2++;
}
if(karta2==11 && zestawkart2[9]<=4){

talia2[ilosckart2]=2;

zestawkart2[9]+=1;

ilosckart2++;
}
if(karta2==12 && zestawkart2[10]<=4){

talia2[ilosckart2]=3;

zestawkart2[10]+=1;

ilosckart2++;
}
if(karta2==13 && zestawkart2[11]<=4){

talia2[ilosckart2]=4;

zestawkart2[11]+=1;

ilosckart2++;
}
if(karta2==14 && zestawkart2[12]<=4){

talia2[ilosckart2]=11;

zestawkart2[12]+=1;

ilosckart2++;
}

}

//Sprawdzenie wylosowanych talii
/*
cout<<"Talia Gracza"<<endl;
for(int i=0; i<52; i++){
cout<<i+1<<" "<<talia1[i]<<endl;
}
cout<<"Talia CPU"<<endl;
for(int j=0; j<52; j++){
cout<<j+1<<" "<<talia2[j]<<endl;
}

*/
SumaGracz=talia1[0]+talia1[1];
SumaCpu=talia2[0]+talia2[1];

bool Quit=false;
int Wybor, numerKarty=2;
int bet = Gra::SetBet();

while(!Quit){
cout<<"Suma Twoich kart wynosi: "<<SumaGracz<<endl;
cout<<"\n Co zamierzasz zrobic: "<<endl;
cout<<"1. Dobierz karte"<<endl;
cout<<"2. Pass"<<endl;

cin>>Wybor;

switch(Wybor){

case 1:
    if(SumaCpu<=15){
        SumaCpu+=talia2[numerKarty];
    }

    if(SumaGracz<=21){
    system("cls");
    cout<<"Dobierasz karte.."<<endl;
    cout<<"Wartosc dobranej karty wynosi: "<<talia1[numerKarty]<<endl;
    system("pause");
    system("cls");
    SumaGracz+=talia1[numerKarty];
    numerKarty++;
    break;
    }
    else{
        system("cls");
        cout<<"Przekroczyles wartosc 21, przechodzimy do sprawdzenia"<<endl;
        Quit=true;
        break;
    }

case 2:
    cout<<"Sprawdzenie wyniku...\n"<<endl;
    system("pause");
    Quit=true;
    break;

default:
    cout<<"Wprowadzono nie poprawna wartosc, podaj jeszcze raz.."<<endl;
    cin.ignore();
    break;
}

if(SumaGracz>SumaCpu && SumaGracz<=21 && Quit==true){
    system("cls");
    Gra::Wygrana(bet, mnoznik);
}
if(SumaGracz<SumaCpu  && SumaCpu <=21 && Quit==true){
    system("cls");
    Gra::Przegrana(bet);
}
if(SumaGracz>21 && SumaCpu <=21 && Quit==true){
    system("cls");
    Gra::Przegrana(bet);
}
if(SumaGracz==SumaCpu && Quit==true){
    system("cls");
    Gra::Remis();
}
if(SumaGracz>21 && SumaCpu>21){
    system("cls");
    Gra::Remis();
}

}
}

}

