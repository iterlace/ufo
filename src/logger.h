
#include <fstream>
#include <string>

using namespace std;

#ifndef UFO_LOGGER_H
#define UFO_LOGGER_H


class Logger {
public:
    void log(string &message);

    Logger(string &filename);
    ~Logger();
private:
    ofstream logFile;
};


#endif //UFO_LOGGER_H
