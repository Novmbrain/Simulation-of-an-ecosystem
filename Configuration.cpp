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

Comportement& Configuration::selectComportement(bool* pmixte){
    double alea = rand();
    if (alea < this->probaGregaire) {
        Gregaire& comportement = Gregaire();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse) {
        Peureuse& comportement = Peureuse();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze){
        Kamikaze& comportement = Kamikaze();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze +this->probaPrevoyante) {
        Prevoyante& comportement = Prevoyante();
        return Prevoyante;
    }
    else {
        // Comportement mixte, initialement sur grégaire. mixte vaut true.
        Prevoyante& comportement = Gregaire();
        *pmixte = true;
        return comportement;
    }
}