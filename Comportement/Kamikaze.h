#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "Comportement.h"

using namespace std;

class Kamikaze : public Comportement {

public :

    void direction(list<Bestiole> bestiolesDetectees);

    void actionParComportement(list<Bestiole> bestiolesDetectees) override;

};

#endif