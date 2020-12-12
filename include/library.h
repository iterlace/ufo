#include <string>
#include <deque>

#ifndef _H
#define _H 40
#endif

#ifndef _W
#define _W 100
#endif

#ifndef _V
#define _V 10000
#endif

#ifndef _M
#define _M 10000
#endif

#ifndef _E0
#define _E0 10000
#endif

#ifndef _EF
#define _EF 100
#endif

#ifndef UFO_LIBRARY_H
#define UFO_LIBRARY_H


#include "src/constants.h"


class Ingot {
public:
    // height, width, depth - linear dimensions of ingot (cm)
    double height, width, depth, density;

    Ingot();
    Ingot(double height, double width, double depth, double density);
    std::string to_string();

    double getWeight();

    // TODO: string representation
};


class UFO {
public:
    double E = _E0;
    double H = _H;  // Opening height
    double W = _W;  // Opening width
    std::deque<Ingot> ingots;

    void putIngot(Ingot ingot);
    void flyAway();
private:
    void rotateIngot();
    void turnIngot();
    void spinIngot();
    bool isIngotValid(Ingot *i);
    void cutIngot(double newDepth);
    void acceptIngot();
    void dropIngot();

    bool calculateIngotPosition(Ingot *i, double *slots, std::vector<COMMAND> *commands) const;
    static double calculateEnergyCosts(Ingot *i);
    static double calculateDepth(Ingot *i, double energyLimit);
};

#endif //UFO_LIBRARY_H

