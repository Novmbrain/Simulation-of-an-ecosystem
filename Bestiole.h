#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

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

using namespace std;


class Milieu;



class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            camouflage;

   T               * couleur;
   //Oreilles          oreilles;
   //Yeux              yeux;
   list<Capteur>     listCapteurs;
   list<Accessoires> listAccessoires;

   Comportement      comportement;
   bool              multiple;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut

   Bestiole(Comportement comportement, bool multiple, list<Capteurs> listCapteurs, list<Accessoires> listAccessoires);  
                                                   // Constructeur donnant comportement, capteurs et accessoires

   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) ;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
