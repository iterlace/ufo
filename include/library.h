#ifndef H
#define H 40
#endif

#ifndef W
#define W 100
#endif

#ifndef V
#define V 10000
#endif

#ifndef M
#define M 10000
#endif

#ifndef E0
#define E0 100000
#endif

#ifndef EF
#define EF 100
#endif

#ifndef UFO_LIBRARY_H
#define UFO_LIBRARY_H


class Ingot {
public:
    double height, width, depth, density;

    Ingot();
    Ingot(double height, double width, double depth, double density);
};


class UFO {
public:
    unsigned long long E;
    Ingot currentIngot;

    void putIngot(Ingot ingot);
    void flyAway();
private:
    void rotateIngot();
    void turnIngot();
    void spinIngot();
    void verifyIngot();
    void cutIngot();
    void acceptIngot();
    void dropIngot();
};

#endif //UNTITLED_LIBRARY_H

