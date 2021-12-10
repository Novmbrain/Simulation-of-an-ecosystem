#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "Comportement.h"

using namespace std;

class Peureuse : public Comportement {
    
    public :
        Peureuse(); 

        void direction(list<Bestiole> bestiolesDetectees);  

};

#endif