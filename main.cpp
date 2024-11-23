#include "pdfmerge.h"
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>

QtMessageHandler originalHandler = nullptr;

void logToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString message = qFormatLogMessage(type, context, msg);
    static FILE *f = fopen("log.txt", "a");
    fprintf(f, "%s\n", qPrintable(message));
    fflush(f);

    if (originalHandler)
        originalHandler(type, context, msg);
}

int main(int argc, char *argv[])
{
    originalHandler = qInstallMessageHandler(logToFile);
    QApplication a(argc, argv);
    PdfMerge w(argc, argv);
    w.show();
    return a.exec();
}
