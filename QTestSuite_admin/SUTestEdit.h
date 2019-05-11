#ifndef SUTESTEDIT_H
#define SUTESTEDIT_H

#include <QtWidgets/QDialog>

namespace Ui {
class SUTestEdit;
}

class SUTestEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit SUTestEdit(QWidget *parent = 0);
    ~SUTestEdit();

private:
    void selfUpdateUI();
    void selfUpdateAnswers();
    void saveChanges();

signals:
    void GoToSUTestsList();
    
private slots:
    void updateUI();

    void deleteAnswer( int num );

    void setAnswerPicture( int num );

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_checkBoxQuestionPicture_clicked(bool checked);

private:
    Ui::SUTestEdit *ui;
};

#endif // SUTESTEDIT_H
