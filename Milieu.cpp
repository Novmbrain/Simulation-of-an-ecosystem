#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = {(T) 255, (T) 255, (T) 255};


Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          width(_width), height(_height) {

    cout << "const Milieu" << endl;

    std::srand(time(NULL));

    config = new Configuration();
    factory = new Factory(*config);

}


Milieu::~Milieu(void) {

    cout << "dest Milieu" << endl;

}


void Milieu::step(void) {

    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    if (static_cast<double>(random()) / RAND_MAX >= config->getTauxDeNaissance()) {
        this->addMember(factory->createBestiole());
    }

    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it < listeBestioles.end(); ++it) {

        if (it->ifDie()) {
            cout << it->getIdentite() << endl;
            listeBestioles.erase(it);
        }

        it->action(*this);
        it->draw(*this);

    }


}


int Milieu::nbVoisins(Bestiole &b) {

    int nb = 0;


//    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it < listeBestioles.end(); ++it)

            if (!(b == *it) && b.jeTeVois(*it)) {
            ++nb;
        }
    return nb;

}

Factory *Milieu::getFactory() const {
    return factory;
}

Configuration *Milieu::getConfig() const {
    return config;
}
