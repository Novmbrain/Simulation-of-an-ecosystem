#include "Oreilles.h"
#include "Capteur.h"

#include <cmath>
#include <iostream>

Oreilles::Oreilles(){
    distance = 100;
    capaciteDetection = 1;
}
Oreilles::Oreilles(double distance, double capaciteDetection){
    this -> distance = distance;
    this -> capaciteDetection = capaciteDetection;
}

bool Oreilles::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation){
    double ecartDistance = sqrt((xposb1-xposb2)*(xposb1-xposb2)+(yposb1-yposb2)*(yposb1-yposb2));
    return ecartDistance<distance;
};

bool Oreilles::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation, double camouflage){
    double ecartDistance = sqrt((xposb1-xposb2)*(xposb1-xposb2)+(yposb1-yposb2)*(yposb1-yposb2));
    return((capaciteDetection>camouflage)&&(ecartDistance<distance));
};
