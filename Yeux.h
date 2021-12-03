#ifndef _YEUX_H_
#define _YEUX_H_

#include "Capteur.h"
#include <iostream>

class Bestiole;

class Yeux : public Capteur {

    private :
        double champAngulaire;
        double distance;
        double capaciteDetection;
    public :
        Yeux();
        Yeux(double champAngulaire, double distance, double capaciteDetection);
};

#endif