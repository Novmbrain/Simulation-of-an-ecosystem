#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <Bestiole.h>

#include <iostream>
#include <list>

using namespace std;

class Comportement {
    
    public :
        Comportement();

        auto direction(list<Bestiole> bestiolesDetectees);

        


};

#endif