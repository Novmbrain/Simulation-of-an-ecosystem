#include "Configuration.h"
#include "vector"

using namespace std;

Configuration::Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax) {
    this->probaGregaire = probaGregaire; 
    this->probaPeureuse = probaPeureuse; 
    this->probaKamikaze = probaKamikaze; 
    this->probaPrevoyante = probaPrevoyante;  
    this->probaYeux = probaYeux; 
    this->probaCarapace = probaCarapace; 
    this->probaOreilles = probaOreilles; 
    this->probaNageoires = probaNageoires; 
    this->probaCamouflage = probaCamouflage;  
    this->champAngMin = champAngMin; 
    this->champAngMax = champAngMax; 
    this->distVueMin = distVueMin; 
    this->distVueMax = distVueMax; 
    this->capaciteVueMin = capaciteVueMin; 
    this->capaciteVueMax = capaciteVueMax;  
    this->distOuieMin = distOuieMin; 
    this->distOuieMax = distOuieMax; 
    this->capaciteOuieMin = capaciteOuieMin; 
    this->capaciteOuieMax = capaciteOuieMax;
}

Bestiole Factory::createBestiole() {
    //vector<double> probas = this->configuration->getProbas();

    // Déterminer un comportement

    // Déterminer ses capteurs et accessoires
}