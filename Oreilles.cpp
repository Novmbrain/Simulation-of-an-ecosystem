#include "Oreilles.h"
#include "Capteur.h"

Oreilles::Oreilles(){
    champAngulaire = 0;
    distance = 0;
    capaciteDetection = 0;
}
Oreilles::Oreilles(double champAngulaire, double distance, double capaciteDetection){
    this -> distance = distance;
    this -> capaciteDetection = capaciteDetection;
} 
bool Oreilles::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2, double camouflage){
    return(true);
};