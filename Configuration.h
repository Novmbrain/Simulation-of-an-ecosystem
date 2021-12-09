#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Gregaire.h>
#include <Peureuse.h>
#include <Kamikaze.h>
#include <Prevoyante.h>
#include <Comportement.h>

#include <Capteur.h>
#include <Yeux.h>
#include <Oreilles.h>

#include <Accessoire.h>
#include <Nageoires.h>
#include <Carapace.h>
#include <Camouflage.h>

#include <iostream>
#include <list>


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

        // Pour les nageoires :
        double coefVitMax;
        
        // Pour les carapaces :
        double coefMortMax;
        double coefLentMax;

        // Pour les camouflages :
        double capaciteCamoufMin;
        double capaciteCamoufMax;


    public :
        Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax, double coefVitMax, double coefMortMax, double coefLentMax, double capaciteCamoufMin, double capaciteCamoufMax);
        
        Comportement selectComportement(bool* pmixte);
        // mixte doit être false, il sera modifié par la méthode.

        list<Capteur> selectCapteurs();
        
        list<Accessoire> selectAccessoires();

        


};

#endif