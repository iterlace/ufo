
#include <fstream>
#include <string>

#include "../src/utils.h"

using namespace std;

#ifndef UFO_LOGGER_H
#define UFO_LOGGER_H


class Logger {
public:
//    Logger();
//    Logger(string &filename);
//    ~Logger();

    void log(const std::string& message);

    template<typename ... Args>
    void log(const std::string& message, Args ... args) { return log(format(message, args...)); };
private:
//    mutable ofstream *logFile;
};


#endif //UFO_LOGGER_H
