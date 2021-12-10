#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include "Bestiole.h"

#include <iostream>
#include <list>

using namespace std;

class Bestiole;

class Comportement {
    
    public :
        Comportement();

        void direction(list<Bestiole> bestiolesDetectees);

        


};

#endif