#include "Yeux.h"
#include "Capteur.h"

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
bool Yeux::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2, double camouflage){
    return(true);
};