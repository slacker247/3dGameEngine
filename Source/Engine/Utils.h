
#include <sys/stat.h>

#include "String.h"

#pragma once

namespace utils
{
    class Utils
    {
    public:
        Utils(void);
        ~Utils(void);

        static bool fileExists(String* strFilename);
    };
}