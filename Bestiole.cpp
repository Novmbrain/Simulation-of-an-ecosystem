#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 3.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole(void) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;

    //dureeVie =
    morte = false;

    x = y = 0;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;

    couleur = new T[3];
    couleur[0] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
    couleur[1] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
    couleur[2] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );

}


Bestiole::Bestiole(Comportement comportement, bool multiple, list<Capteur> listCapteurs, map<string, Accessoire*> mapAccessoires, string couleur)
{
   // Ajout de ces attributs : 
   this->listCapteurs = listCapteurs;
   this->mapAccessoires = mapAccessoires;

    this->comportement = comportement;
    this->multiple = multiple;
    // ***
    dureeVie = 500;

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par factory" << endl;

    x = y = 0;

    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;


   this-> couleur = new T[ 3 ];
   if (couleur== "marron") {
       this->couleur[ 0 ] = 96;
       this->couleur[ 1 ] = 64;
       this->couleur[ 2 ] = 32;
   };
    if (couleur== "rouge") {
        this->couleur[ 0 ] = 230;
        this->couleur[ 1 ] = 20;
        this->couleur[ 2 ] = 20;
    };
    if (couleur== "bleu") {
        this->couleur[ 0 ] = 20;
        this->couleur[ 1 ] = 20;
        this->couleur[ 2 ] = 230;
    };
    if (couleur== "vert") {
        this->couleur[ 0 ] = 20;
        this->couleur[ 1 ] = 230;
        this->couleur[ 2 ] = 20;
    };
    if (couleur== "rose") {
        this->couleur[ 0 ] = 220;
        this->couleur[ 1 ] = 0;
        this->couleur[ 2 ] = 200;
    };


}

Bestiole::Bestiole(const Bestiole &b) {

    this->listCapteurs = b.listCapteurs;
    this->mapAccessoires = b.mapAccessoires;
    this->comportement = b.comportement;
    this->multiple = b.multiple;
    dureeVie = b.dureeVie;
    identite = next;


    cout << "const Bestiole (" << identite << ") par copie" << endl;

    x = b.x;
    y = b.y;
    cumulX = cumulY = 0.;
    orientation = b.orientation;
    vitesse = b.vitesse;
    couleur = new T[3];

    memcpy(couleur, b.couleur, 3 * sizeof(T));


}


Bestiole::~Bestiole(void) {

    delete[] couleur;

    cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords(int xLim, int yLim) {

    x = rand() % xLim;
    y = rand() % yLim;

}


void Bestiole::bouge(int xLim, int yLim) {

    double coefVitesse  = mapAccessoires.at("nageoires")->getCoefVit();

    // Déplace la bestiole sur le graphe, suivant sa vitesse et son orientation.


    double nx, ny;
    double dx = cos(orientation) * vitesse * coefVitesse;
    double dy = -sin(orientation) * vitesse * coefVitesse;
    int cx, cy;

    cx = static_cast<int>( cumulX );
    cumulX -= cx;
    cy = static_cast<int>( cumulY );
    cumulY -= cy;

    nx = x + dx + cx; // nouveau x
    ny = y + dy + cy; // nouveau y

    if ((nx < 0) || (nx > xLim - 1)) {
        // Contact avec un bord
        orientation = M_PI - orientation;
        cumulX = 0.;
    } else {
        // Déplacement sur x
        x = static_cast<int>( nx );
        cumulX += nx - x;
    }

    if ((ny < 0) || (ny > yLim - 1)) {
        // Contact avec un bord
        orientation = -orientation;
        cumulY = 0.;
    } else {
        // Déplacement sur y
        y = static_cast<int>( ny );
        cumulY += ny - y;
    }

}


void Bestiole::action(Milieu &monMilieu) {

    bouge(monMilieu.getWidth(), monMilieu.getHeight());

}


void Bestiole::draw(UImg &support) {

    double xt = x + cos(orientation) * AFF_SIZE / 2.1;
    double yt = y - sin(orientation) * AFF_SIZE / 2.1;


    support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
    support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);

}


bool operator==(const Bestiole &b1, const Bestiole &b2) {

    return (b1.identite == b2.identite);

}


bool Bestiole::jeTeVois(const Bestiole &b) {
    // Antoine la réécrit, en utilisant listCapteurs

    bool vue = false;
    for (list<Capteur>::iterator it = listCapteurs.begin(); it != listCapteurs.end(); it++) {
        vue = vue || it->jeTeVois(x, y, b.x, b.y, orientation, b.mapAccessoires.at("camouflage")->getCapaciteCamouf()); // C'est b.camouflage plutôt ?
    }
    return vue;
}

bool Bestiole::ifDie() {
    if (dureeVie == 0) {
        return true;
    } else {
        dureeVie--;
        return false;
    }
}

int Bestiole::getIdentite() const {
    return identite;
}

Bestiole &Bestiole::operator=(const Bestiole & b) {
    if(!(b == *this)){
        this->listCapteurs = b.listCapteurs;
        this->mapAccessoires = b.mapAccessoires;

        this->comportement = b.comportement;
        this->multiple = b.multiple;
        dureeVie = b.dureeVie;
        identite = b.identite;

        cout << "const Bestiole (" << identite << ") par copie" << endl;

        x = b.x;
        y = b.y;
        cumulX = b.cumulX;
        cumulY = b.cumulY;
        orientation = b.orientation;
        vitesse = b.vitesse;

        memcpy( this->couleur, b.couleur, 3*sizeof(T) );
    }

    return *this;
}

bool Bestiole::ifEncollision(const Bestiole &b) {


    double difX = calculateNX() - b.calculateNX();
    double difY = calculateNY() - b.calculateNY();
    if(fabs(difX) <= 5 && fabs(difY) <= 5){
        cout<<"collision!!!!!!!!!"<<endl;
        return true;
    }

    return false;
}

void Bestiole::setDureeVie(int dureeVie) {
    Bestiole::dureeVie = dureeVie;
}

int Bestiole::calculateNX() const{
    double nx, ny;
    double dx = cos(orientation) * vitesse;
//    double dy = -sin(orientation) * vitesse;
    int cx;

    cx = static_cast<int>( cumulX );
//    cy = static_cast<int>( cumulY );
//    cumulY -= cy;

    nx = x + dx + cx;
//    ny = y + dy + cy;

    return nx;
}

int Bestiole::calculateNY() const{
    double nx, ny;
//    double dx = cos(orientation) * vitesse;
    double dy = -sin(orientation) * vitesse;
    int cy;

//    cx = static_cast<int>( cumulX );
//    cumulX -= cx;
    cy = static_cast<int>( cumulY );

//    nx = x + dx + cx;
    ny = y + dy + cy;

    return ny;
}
