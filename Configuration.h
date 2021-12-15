#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "Comportement/Gregaire.h"
#include "Comportement/Peureuse.h"
#include "Comportement/Kamikaze.h"
#include "Comportement/Prevoyante.h"
#include "Comportement/Comportement.h"

#include "Capteur/Capteur.h"
#include "Capteur/Yeux.h"
#include "Capteur/Oreilles.h"

#include "Accessoire/Accessoire.h"
#include "Accessoire/Nageoires.h"
#include "Accessoire/Carapace.h"
#include "Accessoire/Camouflage.h"

#include <memory>
#include <iostream>
#include <list>
#include <map>


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

        // taux de naissance en cours de simulation
        double tauxDeNaissance;


    public :
//        Configuration(double probaGregaire, double probaPeureuse, double probaKamikaze, double probaPrevoyante,  double probaYeux, double probaCarapace, double probaOreilles, double probaNageoires, double probaCamouflage,  double champAngMin, double champAngMax, double distVueMin, double distVueMax, double capaciteVueMin, double capaciteVueMax,  double distOuieMin, double distOuieMax, double capaciteOuieMin, double capaciteOuieMax, double coefVitMax, double coefMortMax, double coefLentMax, double capaciteCamoufMin, double capaciteCamoufMax);
        Configuration(void);    
    
        pair<Comportement,string> selectComportement(bool* pmixte);
        // mixte doit être false, il sera modifié par la méthode.

        list<Capteur> selectCapteurs();
        
        map<string,Accessoire*> selectAccessoires();

    double getTauxDeNaissance() const;


};

#endif