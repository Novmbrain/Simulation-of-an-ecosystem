#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>
#include <list>

using namespace std;

class Bestiole;

class Comportement {

public :

    virtual void direction(list<Bestiole> bestiolesDetectees);

    virtual void actionParComportement(list<Bestiole> bestiolesDetectees);

};

#endif