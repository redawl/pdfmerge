#include "pdfmerge.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PdfMerge w(argc, argv);
    w.show();
    return a.exec();
}
