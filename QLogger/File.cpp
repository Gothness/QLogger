#include "File.h"

using namespace logging;


File::File() {
  auto currentDir = QCoreApplication::applicationDirPath();
  static QDir path(currentDir + "/logs");
  if (!path.exists()) path.mkpath(".");
  file = new QFile(path.absolutePath() + "/application.log");
  file->open(QFile::Append | QFile::Text);
  qInstallMessageHandler(messageHandler);
}

File::~File() {
  file->close();
  delete file;
}

void File::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

  static QMutex mutex;

  QMutexLocker locker(&mutex);

  QTextStream out(Instance().file);

  out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");

  switch (type) {
    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
  }

  out  << QString(context.category) << ": "
        << msg << "\n";

  out.flush();
}
