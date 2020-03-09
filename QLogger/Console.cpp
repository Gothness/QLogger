#include "Console.h"

using namespace logging;

Console::Console() {
  qInstallMessageHandler(messageHandler);
}

void Console::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

  static QMutex mutex;

  std::wostream *out;

  switch (type) {
    case QtInfoMsg:
    case QtDebugMsg:
      out = &std::wcout; break;
    default:
      out = &std::wcerr; break;
  }

  QMutexLocker locker(&mutex);

  *out << (const wchar_t*) QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ").utf16();

  switch (type) {
    case QtInfoMsg:     *out << L"INF "; break;
    case QtDebugMsg:    *out << L"DBG "; break;
    case QtWarningMsg:  *out << L"WRN "; break;
    case QtCriticalMsg: *out << L"CRT "; break;
    case QtFatalMsg:    *out << L"FTL "; break;
  }

  *out  << (const wchar_t*) QString(context.category).utf16() << L": "
        << (const wchar_t*) msg.utf16() << L"\r\n";

  out->flush();
}

