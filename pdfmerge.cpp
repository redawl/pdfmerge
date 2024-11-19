#include "pdfmerge.h"
#include "./ui_pdfmerge.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileDialog>
#include <QListWidget>
#include <QAbstractItemView>
#include <stdio.h>

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

void PdfMerge::on_pdfList_entered(const QModelIndex &index)
{
}

void PdfMerge::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat("*/*")) {
        event->acceptProposedAction();
    }
}

void PdfMerge::dropEvent(QDropEvent *event)
{
    QByteArray text = event->mimeData()->data("*/*");
    printf("data: %s\n", text.data());
    event->acceptProposedAction();
}

void PdfMerge::on_addFilesButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Add pdfs"), "", tr("Portable Document Format (*.pdf)"));
    ui->pdfList->addItems(fileNames);
}


void PdfMerge::on_mergeButton_clicked()
{

}

