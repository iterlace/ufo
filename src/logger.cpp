
#include <iostream>
#include <fstream>
#include <string>

#include "include/logger.h"
//#include "utils.h"

using namespace std;


//Logger::Logger() {
//
//}
//
//Logger::Logger(string &filename) {
//    this->logFile->open(filename);
//}
//
//Logger::~Logger() {
//    if (this->logFile != nullptr)
//        this->logFile->close();
//}

void Logger::log(const std::string& message) {
    if (message.length() == 0)
        return;

    cerr << message << endl;

//    if (this->logFile->good())
//        *this->logFile << message + '\n';
}

//template<typename ... Args>
//void Logger::log(const std::string& message, Args ... args) {
//    return log(format(message, args...));
//}
