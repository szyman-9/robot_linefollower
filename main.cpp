#include "mbed.h"

// Łukasz Szymański
// 18929, grupa 4
// PWSZ w Elblągu
// Instytut Informatyki Stosowanej
// Robot 'line-follower'

// Czujniki
DigitalOut czujPrawyNapiecie(D15), czujLewyNapiecie(D14);
DigitalIn czujLewy(D13), czujPrawy(D12);

// Sterowanie silnikiem
DigitalOut silnikPrawyNapiecie(D7), silnikLewyNapiecie(D6);
DigitalOut silnikPrawySter1(D5), silnikPrawySter2(D4); 
DigitalOut silnikLewySter1(D3), silnikLewySter2(D2);


void jedzProsto(){
    silnikPrawyNapiecie = 1;
    silnikLewyNapiecie = 1;
    silnikPrawySter1 = 0; // sterowanie, aby jechał prosto
    silnikPrawySter2 = 1;
    silnikLewySter1 = 0;
    silnikLewySter2 = 1;
}

void jedzLewo(){
    silnikLewyNapiecie = 0;
    silnikPrawyNapiecie = 1;
} 

void jedzPrawo(){
    silnikPrawyNapiecie = 0;    
    silnikLewyNapiecie = 1;
}

void stoj(){
    silnikPrawyNapiecie = 0;
    silnikLewyNapiecie = 0;
}

int main() {
    czujPrawyNapiecie = 1;
    czujLewyNapiecie = 1;
    wait(5); //Przed jazdą robot czeka 5 sekund
    while(1) {
        if(!czujLewy && !czujPrawy) stoj(); // czujniki nie widzą taśmy
        else if (!czujLewy) jedzPrawo(); // lewy czujnik nie widzi taśmy
        else if (!czujPrawy) jedzLewo(); // prawy czujnik nie widzi taśmy
        else jedzProsto(); //obydwa czujniki widzą taśmę
        wait(0.01);
    }
}
