#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include <Accessoire.h>

using namespace std;

class Camouflage : public Accessoire {
    
    public :
        double capaciteCamouf; // camouflage 

        Camouflage(double capaciteCamouf);

};

#endif