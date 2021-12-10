#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "Comportement.h"

using namespace std;

class Gregaire : public Comportement {
    
    public :

        void direction(list<Bestiole> bestiolesDetectees);  

};

#endif