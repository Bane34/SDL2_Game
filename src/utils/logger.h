#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdarg>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class Logger{
public:
    enum logModes{
        ERROR     = 1,
        WARNING   = 2,
        BROADCAST = 3
    };

    void log(int p_mode, const std::string& p_message);
    void logFormat(int p_mode, const char* p_format, ...);
    
    static Logger* getInstance();
private:
    Logger();
    Logger(const Logger&){};

    Logger& operator=(const Logger&){return *this;};

    static Logger* s_pInstace;
};

#endif /* LOGGER_H */