#include <string>
#include <deque>
#include <vector>

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


#include "../src/constants.h"
#include "logger.h"


class Ingot {
public:
    // height, width, depth - linear dimensions of ingot (cm)
    double height, width, depth, density;

    Ingot();
    Ingot(double height, double width, double depth, double density);
    string to_string();

    /**
     * @returns weight of the ingot (kg)
     */
    double getWeight();
};


class UFO {
public:
    // Is UFO on Earth
    bool isActive = true;

    // UFO energy left
    double E = _E0;

    // Used space in the Bulba(c)
    double usedVolume = 0;

    // Capacity of the Bulba(c)
    double totalVolume = min((double)_V, (double)_M/F_DENSITY);

    // Opening height
    double H = _H;

    // Opening width
    double W = _W;

    // Queue of ingots placed onto the conveyor
    std::deque<Ingot> ingots;

    // Command Register
    Logger CR = Logger();

    // Status Register
    Logger SR = Logger();

    /**
     * Puts the ingot on the conveyor and processes it.
     * If there is no space or no energy left - calls UFO::flyAway.
     *
     * @param[in] i Ingot to be placed onto the conveyor
     */
    void putIngot(Ingot ingot);
    /**
     * UFO leaves Earth.
     * Function toggles isActive flag.
     */
    void flyAway();
private:
    // Rotates the first ingot in the queue
    void rotateIngot();

    // Turns the first ingot in the queue
    void turnIngot();

    // Spins the first ingot in the queue
    void spinIngot();

    /**
     * Verifies given ingot's sizes to pass through the opening.
     * Rotates/turns/spins the ingot if needed.
     * In case of absolute unsuitability of the ingot, returns false.
     * Otherwise  - true.
     *
     * @param[in] i Ingot to be processed
     * @return true if ingot is prepared and can be passed through the opening. Otherwise false
     */
    bool placeIngotCorrectly(Ingot *i);

    /**
     * Cuts the first ingot in the queue to the given size.
     * Pushes the remainder to the second position on the conveyor, so it can be processed in the future.
     * @param newDepth  depth of the current ingot to be cut.
     */
    void cutIngot(double newDepth);

    /**
     * Accepts the first ingot in the queue and melts it down.
     * Some energy will be returned thanks to the recuperator.
     */
    void acceptIngot();

    /**
     * Drops the first ingot in the queue from the conveyor.
     */
    void dropIngot();

    /**
     * Calculates optimal dimensions of the ingot to be passed through the opening.
     *
     * @param[in] i  Ingot to be processed
     * @param[out] slots  array of 3 elements into which the new sizes (h, w, d) will be written.
     * @param[out] commands  list of the commands to apply to receive such dimensions.
     * @returns is it possible to
     */
    bool calculateIngotDimensions(Ingot *i, double *slots, std::vector<COMMAND> *commands) const;

    /**
     * Calculates optimal dimensions of the ingot to be passed through the opening.
     *
     * @param[in] i  Ingot to be processed
     * @returns energy costs of melting the ingot down
     */
    static double calculateEnergyCosts(Ingot *i);

    /**
     * Calculates depth of the ingot, so melting it down will satisfy both given conditions:
     * available energy and available space.
     *
     * @param[in] i  Ingot to be processed
     * @param[in] energyLimit  available energy to melt the ingot down
     * @param[in] capacity  available Bulba(c) space
     * @return  new depth of the ingot
     */
    static double calculateDepth(Ingot *i, double energyLimit, double capacity);
};

#endif //UFO_LIBRARY_H

