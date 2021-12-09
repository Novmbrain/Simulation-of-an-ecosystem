#include "Configuration.h"
#include "vector"

using namespace std;

Configuration::Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax, double coefVitMax, double coefMortMax, double coefLentMax, double capaciteCamoufMin, double capaciteCamoufMax) {
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

    this->coefVitMax = coefVitMax;

    this->coefMortMax = coefMortMax;
    this->coefLentMax = coefLentMax;

    this->capaciteCamoufMin = capaciteCamoufMin;
    this->capaciteCamoufMax = capaciteCamoufMax;
}

Comportement Configuration::selectComportement(bool* pmixte){
    double alea = rand();
    if (alea < this->probaGregaire) {
        Gregaire comportement = Gregaire();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse) {
        Peureuse comportement = Peureuse();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze){
        Kamikaze comportement = Kamikaze();
        return comportement;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze +this->probaPrevoyante) {
        Prevoyante comportement = Prevoyante();
        return comportement;
    }
    else {
        // Comportement mixte, initialement sur grégaire. mixte vaut true.
        Gregaire comportement = Gregaire();
        *pmixte = true;
        return comportement;
    }
}

list<Capteur> Configuration::selectCapteurs() {
    list<Capteur> listeCapteurs;

    // Mettre des yeux :
    if(rand() < this->probaYeux) {
        
        double champAng = this->champAngMin + rand()*(this->champAngMax-this->champAngMin);
        double distVue = this->distVueMin + rand()*(this->distVueMax-this->distVueMin);
        double capaciteVue = this->capaciteVueMin + rand()*(this->capaciteVueMax-this->capaciteVueMin);

        Yeux yeux = Yeux(champAng, distVue, capaciteVue);
        listeCapteurs.push_back(yeux);
    }

    // Mettre des oreilles :
    if(rand() < this->probaOreilles){
        
        double distOuie = this->distOuieMin + rand()*(this->distOuieMax-this->distOuieMin);
        double capaciteOuie = this->capaciteOuieMin + rand()*(this->capaciteOuieMax-this->capaciteOuieMin);

        Oreilles oreilles = Oreilles(distOuie, capaciteOuie);
        listeCapteurs.push_back(oreilles);
    }

    return listeCapteurs;
}

list<Accessoire> Configuration::selectAccessoires() {
    list<Accessoire> listeAccessoires;

    // Mettre des nageoires :
    if(rand() < this->probaNageoires) {
        
        double coefVit = 1 + rand()*(this->coefVitMax-1);

        Nageoires nageoires = Nageoires(coefVit);
        listeAccessoires.push_back(nageoires);
    }

    // Mettre une carapace :
    if(rand() < this->probaCarapace){
        double coefMort = 1 + rand()*(this->coefMortMax-1);
        double coefLent = 1 + rand()*(this->coefLentMax-1);

        Carapace carapace = Carapace(coefMort, coefLent);
        listeAccessoires.push_back(carapace);
    }

    // Mettre un camouflage :
    if(rand() < this->probaCamouflage){
        double capaciteCamouf = this->capaciteCamoufMin + rand()*(this->capaciteCamoufMax-this->capaciteCamoufMin);

        Camouflage camouflage = Camouflage(capaciteCamouf);
        listeAccessoires.push_back(camouflage);
    }    

    return listeAccessoires;
}
