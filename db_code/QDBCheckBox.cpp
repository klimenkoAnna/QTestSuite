#include "qtestsuite_shareddefs.h"
#include "QDBCheckBox.h"

QDBCheckBox::QDBCheckBox( QWidget *parent, int number, QString text, QRect geometry )
    : QCheckBox( text, parent ),
      checkboxNumber( number )
{
    //QCheckBox::setObjectName( QString().sprintf( "dbCheckBox%d", number ) );
    QCheckBox::setContextMenuPolicy(Qt::CustomContextMenu);
    QCheckBox::setGeometry( geometry );
    QCheckBox::show();
    QObject::connect( this, SIGNAL( clicked() ), this, SLOT( slot_emitNum() ) );
    QObject::connect( this, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( click(QPoint) ) );
}

QDBCheckBox::~QDBCheckBox()
{
    QObject::disconnect( this, SIGNAL( clicked() ), this, SLOT( slot_emitNum() ) );
    QObject::disconnect( this, SIGNAL( customContextMenuRequested(QPoint) ), this, SLOT( click(QPoint) ) );
}

void QDBCheckBox::slot_emitNum()
{
    emit clickedNum( checkboxNumber );
}

void QDBCheckBox::click( const QPoint &pos )
{
    if( checkboxNumber < 0 || checkboxNumber >= (int)testAnswers.size() )
    {
        return;
    }
    try
    {
        setChecked( testAnswers[ checkboxNumber ].isRight.value() );
    }
    catch(...)
    {
    }
}
