#include "Configuration.h"
#include "vector"

#define _USE_MATH_DEFINES
#include <math.h>
#include <utility>

using namespace std;

//Configuration::Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax, double coefVitMax, double coefMortMax, double coefLentMax, double capaciteCamoufMin, double capaciteCamoufMax) {
//    this->probaGregaire = probaGregaire;
//    this->probaPeureuse = probaPeureuse;
//    this->probaKamikaze = probaKamikaze;
//    this->probaPrevoyante = probaPrevoyante;
//
//    this->probaYeux = probaYeux;
//    this->probaCarapace = probaCarapace;
//    this->probaOreilles = probaOreilles;
//    this->probaNageoires = probaNageoires;
//    this->probaCamouflage = probaCamouflage;
//
//    this->champAngMin = champAngMin;
//    this->champAngMax = champAngMax;
//    this->distVueMin = distVueMin;
//    this->distVueMax = distVueMax;
//    this->capaciteVueMin = capaciteVueMin;
//    this->capaciteVueMax = capaciteVueMax;
//
//    this->distOuieMin = distOuieMin;
//    this->distOuieMax = distOuieMax;
//    this->capaciteOuieMin = capaciteOuieMin;
//    this->capaciteOuieMax = capaciteOuieMax;
//
//    this->coefVitMax = coefVitMax;
//
//    this->coefMortMax = coefMortMax;
//    this->coefLentMax = coefLentMax;
//
//    this->capaciteCamoufMin = capaciteCamoufMin;
//    this->capaciteCamoufMax = capaciteCamoufMax;
//
//
//}

Configuration::Configuration(void) {
    this->probaGregaire = 0.2;
    this->probaPeureuse = 0.2;
    this->probaKamikaze = 0.2;
    this->probaPrevoyante = 0.2;

    this->probaYeux = 0.5; 
    this->probaCarapace = 0.5; 
    this->probaOreilles = 0.5; 
    this->probaNageoires = 0.5; 
    this->probaCamouflage = 0.5;  

    this->champAngMin = M_PI/4; 
    this->champAngMax = M_PI; 
    this->distVueMin = 1; 
    this->distVueMax = 200;
    this->capaciteVueMin = 0.1; 
    this->capaciteVueMax = 1; 

    this->distOuieMin = 1; 
    this->distOuieMax = 100;
    this->capaciteOuieMin = 0.1; 
    this->capaciteOuieMax = 1;

    this->coefVitMax = 2;

    this->coefMortMax = 8;
    this->coefLentMax = 3;

    this->capaciteCamoufMin = 0.2;
    this->capaciteCamoufMax = 1;

    this->tauxDeNaissance = 0.05;
    this->tauxDeClonage = 0.005;

    this->nombreInit = 50;
}

pair<Comportement,string> Configuration::selectComportement(bool* pmixte){
    double alea = static_cast<double>(rand())/RAND_MAX;
    if (alea < this->probaGregaire) {
        Gregaire comportement = Gregaire();
        pair<Comportement,string> rep = make_pair(comportement,"marron");
        return rep;

    }
    else if (alea < this->probaGregaire + this->probaPeureuse) {
        Peureuse comportement = Peureuse();
        pair<Comportement,string> rep = make_pair(comportement,"bleu");
        return rep;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze){
        Kamikaze comportement = Kamikaze();
        pair<Comportement,string> rep = make_pair(comportement,"rouge");
        return rep;
    }
    else if (alea < this->probaGregaire + this->probaPeureuse + this->probaKamikaze +this->probaPrevoyante) {
        Prevoyante comportement = Prevoyante();
        pair<Comportement,string> rep = make_pair(comportement,"vert");
        return rep;
    }
    else {
        // Comportement mixte, initialement sur grégaire. mixte vaut true.
        Gregaire comportement = Gregaire();
        *pmixte = true;
        pair<Comportement,string> rep = make_pair(comportement,"rose");
        return rep;
    }
}

list<shared_ptr<Capteur>> Configuration::selectCapteurs() {
    list<shared_ptr<Capteur>> listCapteurs;

    // Mettre des yeux :
    if((static_cast<double>(rand())/RAND_MAX) < this->probaYeux) {
        
        double champAng = this->champAngMin + (static_cast<double>(rand())/RAND_MAX)*(this->champAngMax-this->champAngMin);
        double distVue = this->distVueMin + (static_cast<double>(rand())/RAND_MAX)*(this->distVueMax-this->distVueMin);
        double capaciteVue = this->capaciteVueMin + (static_cast<double>(rand())/RAND_MAX)*(this->capaciteVueMax-this->capaciteVueMin);

        shared_ptr<Capteur> pyeux (new Yeux(champAng, distVue, capaciteVue));
        listCapteurs.push_back(pyeux);
    }

    // Mettre des oreilles :
    if((static_cast<double>(rand())/RAND_MAX) < this->probaOreilles){
        
        double distOuie = this->distOuieMin + (static_cast<double>(rand())/RAND_MAX)*(this->distOuieMax-this->distOuieMin);
        double capaciteOuie = this->capaciteOuieMin + (static_cast<double>(rand())/RAND_MAX)*(this->capaciteOuieMax-this->capaciteOuieMin);

        shared_ptr<Capteur> poreilles(new Oreilles(distOuie, capaciteOuie));
        listCapteurs.push_back(poreilles);
    }

    return listCapteurs;
}

list<Accessoire> Configuration::selectAccessoires() {
    list<Accessoire> listeAccessoires;

    // Mettre des nageoires :
    if((static_cast<double>(rand())/RAND_MAX) < this->probaNageoires) {
        
        double coefVit = 1 + (static_cast<double>(rand())/RAND_MAX)*(this->coefVitMax-1);

        Nageoires nageoires = Nageoires(coefVit);
        listeAccessoires.push_back(nageoires);
    }

    // Mettre une carapace :
    if((static_cast<double>(rand())/RAND_MAX) < this->probaCarapace){
        double coefMort = 1 + (static_cast<double>(rand())/RAND_MAX)*(this->coefMortMax-1);
        double coefLent = 1 + (static_cast<double>(rand())/RAND_MAX)*(this->coefLentMax-1);

        Carapace carapace = Carapace(coefMort, coefLent);
        listeAccessoires.push_back(carapace);
    }

    // Mettre un camouflage :
    if((static_cast<double>(rand())/RAND_MAX) < this->probaCamouflage){
        double capaciteCamouf = this->capaciteCamoufMin + (static_cast<double>(rand())/RAND_MAX)*(this->capaciteCamoufMax-this->capaciteCamoufMin);

        Camouflage camouflage = Camouflage(capaciteCamouf);
        listeAccessoires.push_back(camouflage);
    }    

    return listeAccessoires;
}

double Configuration::getTauxDeNaissance() const {
    return tauxDeNaissance;
}
double Configuration::getTauxDeClonage() const {
    return tauxDeClonage;
}
int Configuration::getNombreInit() const {
    return nombreInit;
}
