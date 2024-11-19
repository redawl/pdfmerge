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
    PdfMerge(QWidget *parent = nullptr);
    ~PdfMerge();

private slots:
    void on_pdfList_entered(const QModelIndex &index);

    void on_addFilesButton_clicked();

    void on_mergeButton_clicked();

private:
    Ui::PdfMerge *ui;
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};
#endif // PDFMERGE_H
