#include "logger.h"

Logger* Logger::s_pInstace = NULL;

void Logger::log(int p_mode, const char* p_message){
    switch(p_mode){
    case 1:
        fprintf(stderr, "%s[ERROR!]:%s %s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, p_message);
        break;
    case 2:
        fprintf(stdout, "%s[WARNING!]:%s %s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET, p_message);
        break;
    case 3:
        fprintf(stdout, "%s[MESSAGE!]: %s %s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET, p_message);
        break;
    case 4:
        fprintf(stdout, "%s[DEBUG!]: %s %s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET, p_message);
        break;
    default:
        fprintf(stdout, "%s[MESSAGE!]: %s %s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET, p_message);
        break;
    }
}

void Logger::logFormat(int p_mode, const char* p_format, ...){
    va_list args;
    va_start(args, p_format);

    switch (p_mode) {
    case 1:
        fprintf(stderr, "%s[ERROR!]:%s ", ANSI_COLOR_RED, ANSI_COLOR_RESET);
        vfprintf(stderr, p_format, args);
        fprintf(stderr, "\n");
        break;
    case 2:
        fprintf(stdout, "%s[WARNING!]:%s ", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
        vfprintf(stdout, p_format, args);
        fprintf(stdout, "\n");
        break;
    case 3:
        fprintf(stdout, "%s[MESSAGE!]:%s ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        vfprintf(stdout, p_format, args);
        fprintf(stdout, "\n");
        break;
    case 4:
        fprintf(stdout, "%s[DEBUG!]:%s ", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
        vfprintf(stdout, p_format, args);
        fprintf(stdout, "\n");
        break;
    default:
        fprintf(stdout, "%s[MESSAGE!]:%s ", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
        vfprintf(stdout, p_format, args);
        fprintf(stdout, "\n");
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