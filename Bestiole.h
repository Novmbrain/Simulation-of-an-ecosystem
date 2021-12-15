#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

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

#include <iostream>
#include <list>


using namespace std;


class Milieu;


class Bestiole {

private :
    static const double AFF_SIZE;
    static const double MAX_VITESSE;
    static const double LIMITE_VUE;

    static int next;

    static const double MAX_AGE; // max of dureeVie

private :
    int identite;

    int dureeVie;
    //bool morte;

    int x, y;
    double cumulX, cumulY;
    double orientation;
    double vitesse;
    double camouflage;

    T *couleur;
    //Oreilles          oreilles;
    //Yeux              yeux;
    list<Capteur> listCapteurs;
    list<Accessoire> listAccessoires;

    Comportement comportement;
    bool multiple;

    list<Bestiole> bestioleDetectees;

private :
    void bouge(int xLim, int yLim);

public :                                           // Forme canonique :
    Bestiole(void);                               // Constructeur par defaut

    Bestiole(Comportement comportement, bool multiple, list<Capteur> listCapteurs, list<Accessoire> listAccessoires, string couleur);
    // Constructeur donnant comportement, capteurs et accessoires

    Bestiole(const Bestiole &b);                 // Constructeur de copies
    ~Bestiole(void);                              // Destructeur
    // Operateur d'affectation binaire par defaut
    void action(Milieu &monMilieu);

    void draw(UImg &support);

    bool jeTeVois(const Bestiole &b);           // Renvoie si this détecte b

    const list<Bestiole> &getBestioleDetectees() const;

    void initCoords(int xLim, int yLim);

    void setDureeVie(int dureeVie);

    void inverseOrientation();

    bool ifDie();
    bool ifEncollision(const Bestiole & b);

//    int calculateNX() const;
//    int calculateNY() const;

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

    int getIdentite() const;

    Bestiole &operator=(const Bestiole &b);

    void shiftCoords(int x, int y);

};


#endif
