#include "Yeux.h"
#include "Capteur.h"

#include <cmath>
#include <math.h>
#include <iostream>

Yeux::Yeux(){
    champAngulaire = 0;
    distance = 0;
    capaciteDetection = 0;
}
Yeux::Yeux(double champAngulaire, double distance, double capaciteDetection){
    champAngulaire = champAngulaire;
    distance = distance;
    capaciteDetection = capaciteDetection;
} 
bool Yeux::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation, double camouflage){
    double ecartDistance = sqrt((xposb1-xposb2)*(xposb1-xposb2)+(yposb1-yposb2)*(yposb1-yposb2));
    double ecartAngle = abs(acos((xposb2-xposb1)/ecartDistance)-orientation);
    return((capaciteDetection>camouflage)&&(ecartDistance<distance)&&(ecartAngle<champAngulaire));
};