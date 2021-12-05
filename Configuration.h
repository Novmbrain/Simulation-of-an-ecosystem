#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Gregaire.h>
#include <Peureuse.h>
#include <Kamikaze.h>
#include <Prevoyante.h>
#include <Comportement.h>

#include <iostream>

using namespace std;

class Configuration {
    /*
    Tire au sort et crée un comportement.
    Tire au sort et crée des capteurs/accessoires.
    Factory vient les chercher.
    */


    private :
        // Pour les comportements :
        double probaGregaire;
        double probaPeureuse;
        double probaKamikaze;
        double probaPrevoyante;
        // probaMixte = 1 - (somme des autres probas)

        double probaYeux;
        double probaCarapace;
        double probaOreilles;
        double probaNageoires;
        double probaCamouflage;

        // Pour les yeux :
        double champAngMin;
        double champAngMax;
        double distVueMin;
        double distVueMax;
        double capaciteVueMin;
        double capaciteVueMax;

        // Pour les oreilles :
        double distOuieMin;
        double distOuieMax;
        double capaciteOuieMin;
        double capaciteOuieMax;

    public :
        Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax);
        
        Comportement& selectComportement(bool* pmixte);
        // mixte doit être false, il sera modifié par la méthode.

};

#endif