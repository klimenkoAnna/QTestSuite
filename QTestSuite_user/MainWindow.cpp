#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QtWidgets/QMessageBox>
#include <QCryptographicHash>

#include "qtestsuite_shareddefs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI()
{
    ui->lineEdit_3->clear(); /// TODO:decomment
    ui->lineEdit_4->clear();
}

#include <QtWidgets/QFileDialog>

void MainWindow::on_pushButton_clicked()
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
//    if (!fileName.isEmpty())
//    {
//        QString fileName = ".\\win_8_style_2.png";
//        QPixmap pixmap(fileName);
//        if( pixmap.isNull() )
//        {
//            QMessageBox::information(this, tr("Image Viewer"), tr("Cannot load %1.").arg(fileName));
//            return;
//        }
//        ui->imageLabel->setPixmap(pixmap);
//    }
//    return;



    if( ui->lineEdit_3->text().length() == 4 && ui->lineEdit_4->text().length() )
    {
        int grNum = 0;
        try
        {
            grNum = ui->lineEdit_3->text().toInt();
        }
        catch(...)
        {
            QMessageBox::warning( NULL, "QTestSuite",
                                  QString::fromLocal8Bit("Неправильный номер группы."),
                                  QMessageBox::Ok, QMessageBox::Ok );
            return;
        }

        std::string surname = qstr_to_stdstr( ui->lineEdit_4->text() );

        if( curStud )
        {
            delete curStud;
            curStud = NULL;
        }

        try
        {
            Student stud = select<Student>( *pDB, Student::GroupNum == grNum
                                            && Student::Surname == surname
                                            && Student::NumClasses == 20).one();
            curStud = new Student( stud );
        }
        catch( Except e )
        {
            curStud = new Student( *pDB );
            curStud->groupNum = grNum;
            curStud->surname = surname;
            curStud->numClasses = 20;
//            curStud->visitedClasses = 7;
//            curStud->bonuses = 10;
//            curStud->presentation = 1;
            curStud->update();
        }
        if( curStud )
        {
            emit GoToTestSelectWnd();
        }
    }
}

void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    if( arg2 > ui->lineEdit_4->text().length() )
    {
        ui->lineEdit_4->setCursorPosition( ui->lineEdit_4->text().length() );
    }
}

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{
    if( arg2 > ui->lineEdit_3->text().length() )
    {
        ui->lineEdit_3->setCursorPosition( ui->lineEdit_3->text().length() );
    }
}

void MainWindow::on_lineEdit_4_returnPressed()
{
    on_pushButton_clicked();
}
