
#include <iostream>
#include <fstream>
#include <string>

#include "include/logger.h"

using namespace std;

Logger::Logger(string &filename) {
    this->logFile.open(filename);
}

Logger::~Logger() {
    this->logFile.close();
}

void Logger::log(string &message) {
    if (message.length() == 0)
        return;

    cerr << message + '\n';
    this->logFile << message + '\n';
}
