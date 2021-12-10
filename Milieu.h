#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );
   /* POUR CHAQUE BESTIOLE :
         Enregistrer si elle meurt de vieillesse
         Pour chaque autre bestiole :
            Y'a-t-il collision ?
            Est-elle perçue ?
         Décision

      POUR CHAQUE BESTIOLE :
         Disparaît si morte
         Effectue son déplacement
         Se clone peut-être

      Les naissances spontanées
   */

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   int nbVoisins(Bestiole & b );

};


#endif
