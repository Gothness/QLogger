#ifndef QLOGGER_QLOGGER_H
#define QLOGGER_QLOGGER_H

#include <QtCore>

namespace logging {
class Console;
class File;
}

#if defined(SHARED_LIBRARY)
#  define Q_SHARED Q_DECL_EXPORT
#else
#  define Q_SHARED Q_DECL_IMPORT
#endif

#include "File.h"
#include "Console.h"

#ifndef DEBUG
#define LOGGER logging::File::Instance();
#else
#define LOGGER logging::Console::Instance();
#endif // DEBUG

#endif // QLOGGER_QLOGGER_H