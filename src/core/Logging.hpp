#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#define DEBUG // Remove to stop debug

// Ensures debug and distribution aren't both on
#ifdef DEBUG
#ifdef DISTRIBUTION
throw std::invalid_argument("Both DEBUG and DISTRIBUTION cannot be defined.");
#endif // DISTRIBUTION
#endif // DEBUG

// If DEBUG is defigned, enable all logging
#ifdef DEBUG
#define GAME_CONSOLE_ERROR_LOG
#define GAME_CONSOLE_LOG
#define GAME_FILE_LOG
#endif

#ifdef GAME_CONSOLE_ERROR_LOG
#define gameConsoleErrorLog(p_err)                                             \
    do {                                                                       \
        auto now = std::chrono::system_clock::now();                           \
        auto time = std::chrono::system_clock::to_time_t(now);                 \
        std::cerr << "["                                                       \
                  << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") \
                  << "] GAME ERR: " << p_err << std::endl;                     \
    } while (0)
#else // GAME_CONSOLE_ERROR_LOG not defined
#define gameConsoleErrorLog(p_err)
#endif // GAME_CONSOLE_ERROR_LOG

#ifdef GAME_CONSOLE_LOG
#define gameConsoleLog(p_log)                                                  \
    do {                                                                       \
        auto now = std::chrono::system_clock::now();                           \
        auto time = std::chrono::system_clock::to_time_t(now);                 \
        std::cout << "["                                                       \
                  << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") \
                  << "] GAME OUT: " << p_log << std::endl;                     \
    } while (0)
#else // GAME_CONSOLE_LOG not defined
#define gameConsoleLog(p_log)
#endif // GAME_CONSOLE_LOG

// File logging
#ifdef GAME_FILE_LOG
#define gameConsoleFileLog(p_log)                                              \
    do {                                                                       \
        std::string logFileName = "game.log";                                  \
        std::ofstream logFile(logFileName, std::ios::out | std::ios::app);     \
        if (logFile.is_open()) {                                               \
            auto now = std::chrono::system_clock::now();                       \
            auto time = std::chrono::system_clock::to_time_t(now);             \
            logFile << "["                                                     \
                    << std::put_time(std::localtime(&time),                    \
                                     "%Y-%m-%d %H:%M:%S")                      \
                    << "] " << p_log << std::endl;                             \
            logFile.close();                                                   \
        } else {                                                               \
            std::cerr << "GAME ERR: Failed to open log file: " << logFileName  \
                      << std::endl;                                            \
        }                                                                      \
    } while (0)
#else // GAME_FILE_LOG not defined
#define gameConsoleFileLog(p_log)
#endif // GAME_FILE_LOG

// This must be at the end of the file
// Add every debug log here
#ifdef DISTRIBUTION
#define gameConsoleErrorLog(p_err)
#define gameConsoleLog(p_log)
#define gameConsoleFileLog(p_log)
#endif