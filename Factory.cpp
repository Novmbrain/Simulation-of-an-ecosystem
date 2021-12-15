#include "Factory.h"
#include "vector"

using namespace std;

Factory::Factory(Configuration& c) : configuration(c) {}

Bestiole Factory::createBestiole() {

    // Déterminer un comportement
    bool mixte = false;
    pair<Comportement,string> couple = this->configuration.selectComportement(&mixte);
    Comportement comportement = couple.first;
    string couleur = couple.second;
    
    // Déterminer ses capteurs
    list<Capteur> listCapteurs = this->configuration.selectCapteurs();

    // Déterminer ses accessoires
    list<Accessoire> listAccessoires = this->configuration.selectAccessoires();

    // Créer la bestiole
    Bestiole bestiole = Bestiole(comportement, mixte, listCapteurs, listAccessoires, couleur);
    

    return bestiole;
}

