#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{
   
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   // Boucle de décision
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  /*it->action( *this );
      it->draw( *this );*/

      Bestiole& b0 = *it;

      // Enregistrer si elle meurt de vieillesse
      b0.vieillissement();

      list<Bestiole&> bestiolesDetectees;

      //Pour chaque autre bestiole :
      for ( std::vector<Bestiole>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; ++it1 ){  
         if (!(*it == *it1)) {     

            Bestiole& b1 = *it1;
         
            //Y'a-t-il collision ?
            bool collision = it->collision(b1);

            // QUE FAIRE DE collision ?

            //Est-elle perçue ?  
            if (it->jeTeVois(b1)) {
               bestiolesDetectees.push_back(b1);
            }

         };      
      };

      //Décision
      list<Bestiole&>& rBestiolesDetectees = bestiolesDetectees;
      b0.decision(rBestiolesDetectees);


   } 

   // Boucle d'action
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  //Disparaît si morte
      //Effectue son déplacement
      //Se clone peut-être

   }

   //Les naissances spontanées

}


int Milieu::nbVoisins(Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) ) {
         ++nb;
      }
   return nb;

}
