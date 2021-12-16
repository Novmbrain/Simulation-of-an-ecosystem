#include "Prevoyante.h"


void
Prevoyante::change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole &bestiole) {
    double count = 0;
    for(auto it = orientationList.begin(); it != orientationList.end(); it++){
        count += *it;
    }
    bestiole.setNextOrientation(count / orientationList.size() + M_PI);
}
