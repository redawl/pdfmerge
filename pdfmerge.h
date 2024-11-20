#ifndef PDFMERGE_H
#define PDFMERGE_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class PdfMerge;
}
QT_END_NAMESPACE

class PdfMerge : public QMainWindow
{
    Q_OBJECT

public:
    PdfMerge(int argc, char ** argv);
    ~PdfMerge();

private slots:
    void on_addFilesButton_clicked();

    void on_mergeButton_clicked();

    void on_errorClose_clicked();

    void on_abouteQtButton_clicked();

private:
    Ui::PdfMerge *ui;

    void showError (char * msg);
};
#endif // PDFMERGE_H
