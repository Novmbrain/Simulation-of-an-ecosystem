#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include <Comportement.h>

using namespace std;

class Prevoyante : public Comportement {
    
    public :
        Prevoyante(); 

        auto direction(list<Bestiole> bestiolesDetectees);  

};

#endif