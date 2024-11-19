#include "pdfmerge.h"
#include "./ui_pdfmerge.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include <podofo/podofo.h>

PdfMerge::PdfMerge(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PdfMerge)
{
    ui->setupUi(this);
    ui->pdfList->setDragDropMode(QAbstractItemView::InternalMove);
}

PdfMerge::~PdfMerge()
{
    delete ui;
}

void PdfMerge::on_addFilesButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Add pdfs"), "", tr("Portable Document Format (*.pdf)"));
    ui->pdfList->addItems(fileNames);
}


void PdfMerge::on_mergeButton_clicked()
{
    const int count = ui->pdfList->count();

    PoDoFo::PdfMemDocument mergedDoc;

    for(int i = 0; i < count; i++){
        const QListWidgetItem * item = ui->pdfList->item(i);
        PoDoFo::PdfMemDocument doc;
        doc.Load(item->text().toLatin1().data());
        mergedDoc.GetPages().AppendDocumentPages(doc);
    }

    const char * mergedFileName = ui->mergeFileName->text().toLatin1().data();
    mergedDoc.Save(mergedFileName);
}

