// Clang, GCC, and MSVC supports this. Maybe OK? https://en.wikipedia.org/wiki/Pragma_once
#pragma once

#define Tutorial_VERSION_MAJOR "@Tutorial_VERSION_MAJOR@"
#define Tutorial_VERSION_MINOR "@Tutorial_VERSION_MINOR@"

#include <string>
#include <iostream>
#include <charconv>
#include <utility>

// This is header-only

namespace Config {

    struct Version {
        int major;
        int minor;

        // NOTE: implicit conversions are not recommended.
        // https://google.github.io/styleguide/cppguide.html#Implicit_Conversions
        operator double() const {
            return 1.0 * major + 0.001 * minor;
        }

        operator std::string() const {
            return std::to_string(major) + "." + std::to_string(minor);
        }
    };

    static Version GetVersion() {
        std::string majorS = Tutorial_VERSION_MAJOR;
        std::string minorS = Tutorial_VERSION_MINOR;

        // locale-independent and exception-free (C++17)
        // I might be a little bit too nervous about locale problems and exceptions...
        // https://cpprefjp.github.io/reference/charconv/from_chars.html
        int major;
        int minor;
        std::from_chars(majorS.data(), majorS.data() + majorS.size(), major);
        std::from_chars(minorS.data(), minorS.data() + minorS.size(), minor);

        Version version{major, minor};
        return version;
    }
}
