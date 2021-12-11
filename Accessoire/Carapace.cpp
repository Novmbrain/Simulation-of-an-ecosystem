#include "Accessoire.h"
#include "Carapace.h"

Carapace::Carapace(){
    this->coefMort = 0.5;
    this->coefLent = 0.5;

};
Carapace::Carapace(double coefMort, double coefLent){
    this-> coefMort = coefMort;
    this ->coefLent = coefLent;
};
