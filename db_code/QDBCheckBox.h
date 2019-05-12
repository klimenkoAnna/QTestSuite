#ifndef QDBCHECKBOX_H
#define QDBCHECKBOX_H

#include <QtWidgets/QCheckBox>

class QDBCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    QDBCheckBox( QWidget *parent, int number, QString text, QRect geometry );
    ~QDBCheckBox();

private:
    int checkboxNumber;

signals:
    void clickedNum( int num );

public slots:
    void click( const QPoint &pos );
    void slot_emitNum();
};


#endif
