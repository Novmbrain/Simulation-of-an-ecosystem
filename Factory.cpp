#include "Factory.h"
#include "vector"

using namespace std;

Factory::Factory(Configuration& c) {
    this->configuration = c;
}

Bestiole& Factory::createBestiole() {

    // Déterminer un comportement
    bool mixte = false;
    Comportement& comportement = this->configuration->selectComportement(&mixte);
    
    // Déterminer ses capteurs et accessoires
    
}

