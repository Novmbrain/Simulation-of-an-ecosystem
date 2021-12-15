#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "Comportement.h"

using namespace std;

class Peureuse : public Comportement {

public :

    void direction(list<Bestiole> bestiolesDetectees);

    void actionParComportement(list<Bestiole> bestiolesDetectees) override;

};

#endif