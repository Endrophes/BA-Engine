#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

#define log_d(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Debug);\
}

#define log_w(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Warn);\
}

#define log_e(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Error);\
}

#define log_a(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::ALL);\
}

namespace BA_Engine
{

    /// <summary>
    /// 
    /// </summary>
    class Logger
    {

    public:

        enum class LogLevel
        {
            Debug,
            Warn,
            Error,
            ALL
        };


        void log(std::string pMsg, LogLevel pLevel)
        {
            if (pLevel >= minThresh)
            {
                std::cout << pMsg << std::endl;
            }
        }

    private:
        LogLevel minThresh = LogLevel::Debug;

    };

    static Logger log;

}

#endif //LOGGER_H