#include "logger.h"

Logger* Logger::s_pInstace = NULL;

void Logger::log(int p_mode, const std::string& p_message){
    switch(p_mode){
    case 1:
        std::cout << ANSI_COLOR_RED    << "[ERROR!]: "   << ANSI_COLOR_RESET << p_message << '\n';
        break;
    case 2:
        std::cout << ANSI_COLOR_YELLOW << "[WARNING!]: " << ANSI_COLOR_RESET << p_message << '\n';
        break;
    case 3:
        std::cout << ANSI_COLOR_GREEN  << "[MESSAGE!]: " << ANSI_COLOR_RESET << p_message << '\n';
        break;
    default:
        std::cout << ANSI_COLOR_GREEN  << "[MESSAGE!]: " << ANSI_COLOR_RESET << p_message << '\n';
        break;
    }
}

void Logger::logFormat(int p_mode, const char* p_format, ...){
    va_list args;
    va_start(args, p_format);

    switch (p_mode)
    {
    case 1:
        fprintf(stderr, "%s[ERROR!]:%s ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        vfprintf(stderr, p_format, args);
        fprintf(stderr, "\n");
        break;
    case 2:
        fprintf(stderr, "%s[WARNING!]:%s ", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
        vfprintf(stderr, p_format, args);
        fprintf(stderr, "\n");
        break;
    case 3:
        fprintf(stderr, "%s[MESSAGE!]:%s ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        vfprintf(stderr, p_format, args);
        fprintf(stderr, "\n");
        break;
    default:
        fprintf(stderr, "%s[MESSAGE!]:%s ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        vfprintf(stderr, p_format, args);
        fprintf(stderr, "\n");
        break;
    }

    va_end(args);
} 

Logger::Logger(){ }

Logger* Logger::getInstance(){
    if(s_pInstace == NULL){
        s_pInstace = new Logger;
        return s_pInstace;
    }

    return s_pInstace;
}