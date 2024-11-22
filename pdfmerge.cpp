#include "pdfmerge.h"
#include "./ui_pdfmerge.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include <podofo/podofo.h>
#include <filesystem>
#include <string.h>

PdfMerge::PdfMerge(int argc, char ** argv)
    : QMainWindow(nullptr)
    , ui(new Ui::PdfMerge)
{
    ui->setupUi(this);
    ui->pdfList->setDragDropMode(QAbstractItemView::InternalMove);
    ui->errorMessage->hide();

    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i]+(strlen(argv[i])-4), ".pdf", 4) == 0){
            printf("Adding %s to list\n", argv[i]);
            ui->pdfList->addItem(argv[i]);
        } else {
            printf("Argument %s is not a pdf, ignoring\n", argv[i]);
        }
    }
}

void PdfMerge::showError (char * msg) {
    char error[500];
    snprintf(error, 500, "Error: %s", msg);
    printf("%s\n", error);
    ui->message->setText(error);
    ui->errorMessage->show();
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
    char * mergedFileName = ui->mergeFileName->text().toLatin1().data();
    printf("Merging files ");
    if (std::filesystem::exists(mergedFileName)) {
        char msg[500];
        snprintf(msg, 500, "%s already exists.", mergedFileName);
        this->showError(msg);
    } else {
        const int count = ui->pdfList->count();

        PoDoFo::PdfMemDocument mergedDoc;

        for(int i = 0; i < count; i++){
            const QListWidgetItem * item = ui->pdfList->item(i);
            printf("%s ", item->text().toLatin1().data());
            PoDoFo::PdfMemDocument doc;
            doc.Load(item->text().toLatin1().data());
            mergedDoc.GetPages().AppendDocumentPages(doc);
        }
        printf("\n Saving to %s\n", mergedFileName);

        mergedDoc.Save(mergedFileName);
    }
}


void PdfMerge::on_errorClose_clicked()
{
    ui->errorMessage->hide();
}


void PdfMerge::on_abouteQtButton_clicked()
{
    QApplication::aboutQt();
}

