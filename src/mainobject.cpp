#include "mainobject.h"
#include <QtDebug>
MainObject::MainObject(QObject *parent) : QObject(parent)
{
    vmcState = 0;
}

MainObject::~MainObject()
{

}

void MainObject::vmcpaySlot(int cabinet,int column,int type,long cost)
{
    qDebug()<<"cabinet:"<<cabinet
           <<" column:"<<column
          <<" type:"<<type<<" cost:"<<cost;
}

void MainObject::setVmcState(const int state)
{
    qDebug()<<"MainObject::setVmcState="<<state<<this;
    vmcState = state;
    emit vmcStateChanged();
}
