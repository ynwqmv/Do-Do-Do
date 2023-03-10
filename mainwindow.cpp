#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->radioButton->setChecked(true);

    connect(ui->pushButton, &QPushButton::clicked, this,&MainWindow::addBtn);
    connect(ui->checkBox, &QCheckBox::toggled,this, &MainWindow::checkBtn);
    connect(ui->checkBox_2, &QCheckBox::toggled,this, &MainWindow::checkBtn2);
    connect(ui->radioButton, &QRadioButton::toggled, this, &MainWindow::radioBtn);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &MainWindow::radioBtn);
    connect(ui->radioButton_3, &QRadioButton::toggled, this, &MainWindow::radioBtn);
    connect(ui->commandLinkButton, &QCommandLinkButton::clicked, this, &MainWindow::on_commandLinkButton_clicked);

    connect(ui->checkBox_3 , &QCheckBox::toggled,[=](bool checked){
        if(checked)
        {
            ui->textEdit->setReadOnly(false);
        }else
        {
            ui->textEdit->setReadOnly(true);
        }
    });

    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, [=](const QFont &font) {
        ui->label->setFont(font);
        ui->label_2->setFont(font);
        ui->label_3->setFont(font);
        ui->pushButton->setFont(font);
        ui->pushButton_2->setFont(font);
        ui->pushButton_3->setFont(font);
        ui->textEdit->setFont(font);
        ui->lineEdit->setFont(font);
        ui->checkBox->setFont(font);
        ui->checkBox_2->setFont(font);
        ui->checkBox_3->setFont(font);
        ui->radioButton->setFont(font);
        ui->radioButton_2->setFont(font);
        ui->radioButton_3->setFont(font);
    });



    ui->pushButton_2->hide();
    ui->pushButton_3->hide();



    setWindowTitle("Do-Do-Do!");


}


void MainWindow::addBtn()
{
    if (!ui->lineEdit->text().isEmpty())
    {
        ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
        QString text = ui->lineEdit->text();
        QDateTime dateTime = ui->dateTimeEdit->dateTime();
        QString dt = dateTime.toString();
        ui->textEdit->insertPlainText(dt + " - " + text + "\n");
        ui->lineEdit->clear();
    }else
    {

        QMessageBox::information(this,tr("Empty fields"), tr("Please, check all fields and fill them"));
    }

}

void MainWindow::checkBtn(bool checked) { ui->pushButton_2->setVisible(checked); }
void MainWindow::checkBtn2(bool checked) { ui->pushButton_3->setVisible(checked); }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export As");
        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Cannot export file: " + file.errorString());
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();



}


void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import File");
        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Cannot import file: " + file.errorString());
            return;
        }

        QTextStream in(&file);
        QString data = in.readAll();
        file.close();

        ui->textEdit->setPlainText(data);
}



void MainWindow::radioBtn(bool checked)
{

    if (checked)
    {
        if (ui->radioButton->isChecked())
        {
            ui->label->setText("Text :");
            ui->label_2->setText("Time :");
            ui->label_3->setText("Font :");
            ui->pushButton->setText("Add");
            ui->pushButton_2->setText("Export");
            ui->pushButton_3->setText("Import");
            ui->checkBox->setText("Export");
            ui->checkBox_2->setText("Import");
            ui->checkBox_3->setText("Edit");
            ui->groupBox_2->setTitle("Languages");
            ui->radioButton->setText("English");
            ui->radioButton_2->setText("Russian");
            ui->radioButton_3->setText("Georgian");
            ui->groupBox->setTitle("Tools");
            ui->commandLinkButton_2->setText("MIT License");
            ui->commandLinkButton->setText("View GitHub");
        }else if (ui->radioButton_2->isChecked())
        {
            ui->label->setText("?????????? :");
            ui->label_2->setText("?????????? :");
            ui->label_3->setText("?????????? :");
            ui->pushButton->setText("????????????????");
            ui->pushButton_2->setText("??????????????");
            ui->pushButton_3->setText("????????????");
            ui->checkBox->setText("??????????????");
            ui->checkBox_2->setText("????????????");
            ui->checkBox_3->setText("??????????????????????????");
            ui->groupBox_2->setTitle("??????????");
            ui->groupBox->setTitle("??????????????????????");
            ui->radioButton->setText("????????????????????");
            ui->radioButton_2->setText("??????????????");
            ui->radioButton_3->setText("????????????????????");
            ui->commandLinkButton->setText("?????????????? ?? GitHub");
            ui->commandLinkButton_2->setText("MIT ????????????????");
        }else if (ui->radioButton_3->isChecked())
        {
            ui->label->setText("?????????????????? :");
            ui->label_2->setText("????????? :");
            ui->label_3->setText("?????????????????? :");
            ui->pushButton->setText("????????????????????????");
            ui->pushButton_2->setText("????????????????????????");
            ui->pushButton_3->setText("?????????????????????");
            ui->checkBox->setText("????????????????????????");
            ui->checkBox_2->setText("?????????????????????");
            ui->checkBox_3->setText("?????????????????????????????????");
            ui->groupBox_2->setTitle("???????????????");
            ui->groupBox->setTitle("???????????????????????????????????????");
            ui->commandLinkButton->setText("???????????????????????? GitHub-??????");
            ui->commandLinkButton_2->setText("MIT ????????????????????????");
            ui->radioButton->setText("???????????????????????????");
            ui->radioButton_2->setText("??????????????????");
            ui->radioButton_3->setText("?????????????????????");
        }
    }


}

void MainWindow::on_commandLinkButton_clicked()
{

    QDesktopServices::openUrl(QUrl("https://github.com/ynwqmv"));

}






void MainWindow::on_commandLinkButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.mit.edu/~amini/LICENSE.md"));

}

