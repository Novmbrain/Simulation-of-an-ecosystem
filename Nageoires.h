#ifndef _NAGEOIRES_H_
#define _NAGEOIRES_H_

#include "Accessoire.h"

using namespace std;

class Nageoires : public Accessoire {
    
    public :
        double coefVit;

        Nageoires(double coefVit);

};

#endif