#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Factory.h"

#include <cstdlib>

#include <iostream>

using namespace std;


int main()
{
   
   Aquarium       ecosysteme( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i ){
       Bestiole bestiole = ecosysteme.getFactory().createBestiole();
       ecosysteme.getMilieu().addMember(bestiole);
   }

   ecosysteme.run();
   



   cout << "Test" ;

   return 0;


}
