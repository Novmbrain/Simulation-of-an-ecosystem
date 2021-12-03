#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_


#include <iostream>

class Bestiole;

class Capteur {

    public:
        Capteur(void);
        bool jeTeVois(Bestiole &bestiole);
};

#endif