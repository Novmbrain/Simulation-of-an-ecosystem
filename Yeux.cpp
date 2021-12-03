#include "Yeux.h"
#include "Bestiole.h"
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
bool Yeux::jeTeVois(Bestiole &bestiole){
    return(true);
};