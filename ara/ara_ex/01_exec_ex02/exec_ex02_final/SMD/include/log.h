/* log.h */

/// JaeHeon.Kim@hyundai-autoever.com
/// 27oct20 : init creation

#ifndef CALCULATION_ENGINES_LOG_H
#define CALCULATION_ENGINES_LOG_H

#include <iostream>
#include <string>

using namespace std::string_literals;

//  Trace level definitions
#define TRACE_LEVEL_OFF     (0)
#define TRACE_LEVEL_FATAL   (1)
#define TRACE_LEVEL_ERROR   (2)
#define TRACE_LEVEL_WARNING (3)
#define TRACE_LEVEL_INFO    (4)
#define TRACE_LEVEL_DEBUG   (5)

//  Default trace level
#ifndef TRACE_LOG_LEVEL
#define TRACE_LOG_LEVEL TRACE_LEVEL_DEBUG
#endif // TRACE_LOG_LEVEL

#define NULLOUT() do { } while (false)

#define STDCOUT(str) do {           \
    std::cout << __func__ << " : " << str << std::endl;  \
    } while (false)

#define STDCERR(str) do {           \
    std::cerr << "ERROR : "s << str << std::endl;  \
    } while (false)

//  Debugging macros
#if (TRACE_LOG_LEVEL >= TRACE_LEVEL_FATAL)
#define TRACE_FATAL(str) STDCERR(str)
#else
#define TRACE_FATAL(str) NULLOUT()
#endif // (TRACE_LOG_LEVEL >= TRACE_LEVEL_FATAL)

#if (TRACE_LOG_LEVEL >= TRACE_LEVEL_ERROR)
#define TRACE_ERROR(str) STDCERR(str)
#else
#define TRACE_ERROR(str) NULLOUT()
#endif // (TRACE_LOG_LEVEL >= TRACE_LEVEL_ERROR)

#if (TRACE_LOG_LEVEL >= TRACE_LEVEL_WARNING)
#define TRACE_WARNING(str) STDCOUT(str)
#else
#define TRACE_WARNING(str) NULLOUT()
#endif // (TRACE_LOG_LEVEL >= TRACE_LEVEL_WARN)

#if (TRACE_LOG_LEVEL >= TRACE_LEVEL_INFO)
#define TRACE_INFO(str) STDCOUT(str)
#else
#define TRACE_INFO(str) NULLOUT()
#endif // (TRACE_LOG_LEVEL >= TRACE_LEVEL_INFO)

#if (TRACE_LOG_LEVEL >= TRACE_LEVEL_DEBUG)
#define TRACE_DEBUG(str) STDCOUT(str)
#else
#define TRACE_DEBUG(str) NULLOUT()
#endif // (TRACE_LOG_LEVEL >= TRACE_LEVEL_DEBUG)


#endif //CALCULATION_ENGINES_LOG_H
