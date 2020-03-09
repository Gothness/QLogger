#ifndef QLOGGER_CONSOLE_H
#define QLOGGER_CONSOLE_H

#include <iostream>
#include "QLogger.h"

class Q_SHARED logging::Console : public QObject {

  Q_OBJECT

 private:
  Console();
  ~Console() override = default;

 public:
  static Console& Instance() { static Console s; return s; }

 public:
  static void messageHandler(QtMsgType, const QMessageLogContext &, const QString &);

 public:
  Console(Console const&) = delete;
  Console& operator= (Console const&) = delete;

};

#endif //QLOGGER_CONSOLE_H
