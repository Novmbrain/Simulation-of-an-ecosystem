#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include <Accessoire.h>

using namespace std;

class Carapace : public Accessoire {
    
    public :
        double coefMort; // coefficientResistante   
        double coefLent; // vitesseReduit

        Carapace(double coefMort, double coefLent);

};

#endif