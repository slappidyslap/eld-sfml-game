#include <iostream>
#include <string>

namespace dgrdch {
    inline void logInfo(std::string msg) {
        std::cout << "INFO: " << msg << "\n";
    }

    inline void logWarn(std::string msg) {
        std::cout << "WARN: " << msg << "\n";
    }

    inline void logError(std::string msg) {
        std::cout << "ERROR: " << msg << "\n";
    }
}