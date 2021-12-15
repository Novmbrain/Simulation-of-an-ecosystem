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


<<<<<<< HEAD
void Milieu::step( void )
{
   
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );

   // Boucle de décision
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  /*it->action( *this );
      it->draw( *this );*/

      Bestiole& b0 = *it;

      // Enregistrer si elle meurt de vieillesse
      b0.vieillissement();

      list<Bestiole*> bestiolesDetectees;

      //Pour chaque autre bestiole :
      for ( std::vector<Bestiole>::iterator it1 = listeBestioles.begin() ; it1 != listeBestioles.end() ; ++it1 ){  
         if (!(*it == *it1)) {     

            Bestiole& b1 = *it1;
         
            //Y'a-t-il collision ?
            //bool collision = it->collision(b1);

            // QUE FAIRE DE collision ?

            //Est-elle perçue ?  
            if (it->jeTeVois(b1)) {
               bestiolesDetectees.push_back(&(*it1));
            }

         };      
      };

      //Décision
      list<Bestiole*>& rBestiolesDetectees = bestiolesDetectees;
      b0.decision(rBestiolesDetectees);


   } 

   // Boucle d'action
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {  //Disparaît si morte
      //Effectue son déplacement
      //Se clone peut-être

   }

   //Les naissances spontanées
=======
void Milieu::step(void) {

    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);

    // Naissance spontanée (maximum 1 par step)
    if (static_cast<double>(random()) / RAND_MAX <= config->getTauxDeNaissance()) {
        this->addMember(factory->createBestiole());
    }

    //    collision detect et décision
    for (std::vector<Bestiole>::iterator it1 = listeBestioles.begin(); it1 < listeBestioles.end(); ++it1) {

        // Détection des collisions
        for (std::vector<Bestiole>::iterator it2 = listeBestioles.begin(); it2 < listeBestioles.end(); ++it2) {
            if(it1 != it2){
                if(it1->ifEncollision(*it2)){
                    //set *it1 dureedevie = 0
                    // En cas de collision, chaque bestiole meurt.
                    it1->setDureeVie(0);

                    // À MODIFIER : la bestiole peut survivre à la collision, et adapte sa trajectoire.
                    break;
                 }
            }
        }

        // Décision
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
>>>>>>> master

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
