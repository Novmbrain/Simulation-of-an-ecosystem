#include "Milieu.h"
#include "math.h"

#include <cstdlib>
#include <ctime>
#include <cmath>


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


    // Naissance spontanée (maximum 1 par step)

    if (static_cast<double>(random()) / RAND_MAX <= config->getTauxDeNaissance()) {
        this->addMember(factory->createBestiole());
    }
    int n = listeBestioles.size();
    for (int it=0; it<n; it++){
        if (static_cast<double>(random()) / RAND_MAX <= config->getTauxDeClonage()){
            Bestiole b = listeBestioles.at(it);
            listeBestioles.push_back(b);
            double posCloneX = (static_cast<double>(random()) / RAND_MAX)*40.;
            double posCloneY = std::sqrt(20*20-(posCloneX-20)*(posCloneX-20));
            int x = static_cast<int>(posCloneX-20);
            int y = 0;
            if ((static_cast<double>(random()) / RAND_MAX)<0.5) {
                y = static_cast<int>(posCloneY);
            } else {
                y = -static_cast<int>(posCloneY);
            }
            listeBestioles.back().shiftCoords(x,y);
        }
    }

    //    collision detect et décision
    for (std::vector<Bestiole>::iterator it1 = listeBestioles.begin(); it1 < listeBestioles.end(); ++it1) {

        // Détection des collisions
        for (std::vector<Bestiole>::iterator it2 = listeBestioles.begin(); it2 < listeBestioles.end(); ++it2) {
            if (it1 != it2) {
                if (it1->ifEncollision(*it2)) {
                    if (static_cast<double>(random()) / RAND_MAX <= config->getProbaMortCollision()) {
                        //set *it1 dureedevie = 0
                        // En cas de collision, chaque bestiole meurt.
                        it1->setDureeVie(0);
                        break;
                    } else {
                        // la bestiole peut survivre à la collision, et adapte sa trajectoire.
                        it1->inverseOrientation();
                    }
                    break;
                }
            }
        }
    }

    //mort
    std::vector<Bestiole>::iterator it = listeBestioles.begin();

    // Mouvement ou disparition de chaque bestiole
    while (it != listeBestioles.end()) {
        if (it->ifDie()) {
            cout << it->getIdentite() << endl;
            // Disparition
            it = listeBestioles.erase(it);
        }
        else {

            // Mouvement

            it->action(*this);
            it->draw(*this);
            ++it;
        }
    }

    // Affichage du nombre de bestioles
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
