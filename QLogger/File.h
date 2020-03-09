#ifndef QLOGGER_FILE_H
#define QLOGGER_FILE_H

#include <iostream>
#include "QLogger.h"

class Q_SHARED logging::File : public QObject {

 Q_OBJECT

 private:
  QFile *file;

 private:
  File();
  ~File() override;

 public:
  static File& Instance() { static File s; return s; }

 public:
  static void messageHandler(QtMsgType, const QMessageLogContext &, const QString &);

 public:
  File(File const&) = delete;
  File& operator= (File const&) = delete;

};

#endif //QLOGGER_FILE_H
