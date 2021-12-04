#include "Factory.h"
#include "vector"

using namespace std;

Factory::Factory(Configuration& c) {
    this->configuration = c;
}

Bestiole Factory::createBestiole() {
    vector<double> probas = this->configuration->getProbas();
}