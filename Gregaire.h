#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include <Comportement.h>

using namespace std;

class Gregaire : public Comportement {
    
    public :
        Gregaire(); 

        auto direction(list<Bestiole> bestiolesDetectees);  

};

#endif