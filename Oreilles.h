#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "Capteur.h"
#include <iostream>


class Oreilles : public Capteur {

    private :
        double champAngulaire;
        double distance;
        double capaciteDetection;
    public :
        Oreilles();
        Oreilles(double champAngulaire, double distance, double capaciteDetection);
        bool jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2, double camouflage);
};

#endif