#ifndef _NAGEOIRES_H_
#define _NAGEOIRES_H_

#include "Accessoire.h"

using namespace std;

class Nageoires : public Accessoire {
    
    private :
        double coefVit;
    public :
        Nageoires();
        Nageoires(double coefVit);

};

#endif