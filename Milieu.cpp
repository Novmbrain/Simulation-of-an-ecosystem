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

    //    collision detect
    for (std::vector<Bestiole>::iterator it1 = listeBestioles.begin(); it1 < listeBestioles.end(); ++it1) {
        for (std::vector<Bestiole>::iterator it2 = listeBestioles.begin(); it2 < listeBestioles.end(); ++it2) {
            if(it1 != it2){
                if(it1->ifEncollision(*it2)){
                    //set *it1 dureedevie = 0
                    it1->setDureeVie(0);
                    break;
                 }
            }
        }
    }

//    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it < listeBestioles.end(); ++it) {
//
//        if (it->ifDie()) {
//            cout << it->getIdentite() << endl;
//            listeBestioles.erase(it);
//        }
//
//        it->action(*this);
//        it->draw(*this);
//
//    }

    std::vector<Bestiole>::iterator it = listeBestioles.begin();

    while (it != listeBestioles.end()) {
        if (it->ifDie()) {
            cout << it->getIdentite() << endl;
            it = listeBestioles.erase(it);
        }
        else {

            it->action(*this);
            it->draw(*this);
            ++it;
        }
    }

    cout<<"size of listBestiole " << listeBestioles.size() << endl;

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
