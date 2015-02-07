#include "vmsql.h"
#include <QSql>
#include <QtDebug>

#include <QSqlRecord>

VmSql::VmSql(QThread *parent) : QThread(parent)
{
    stopped = true;
    sqlConnected = false;
    m_model = NULL;

}

VmSql::~VmSql()
{

}



void VmSql::run()
{
    bool ok = sqlConnection();
    if(ok)
    {
        sqlConnected = true;
        tabelModelInit();
        productTableCheck();
        emit sqlRptSignal(SQL_CONNECT_OK);
    }
    else
        emit sqlRptSignal(SQL_CONNECT_FAIL);
    qDebug()<<"VmSql::VmSql"<<ok;
    while(!stopped)
    {
        qDebug()<<"Sql thread runing";
        msleep(1000);
    }

    qDebug()<<"Sql Thread stopped...";
}


void VmSql::stopThread()
{
    stopped = true;
}

void VmSql::startThread()
{
    stopped = false;
    this->start();
}




bool VmSql::sqlConnection()
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setUserName("root");
    m_db.setPassword("123456");
    m_db.setDatabaseName("vmc");
    return m_db.open();
}

void VmSql::tabelModelInit()
{

    m_model = new QSqlTableModel(this,m_db);


    m_modelCabinet = new QSqlTableModel(this,m_db);
    m_modelCabinet->setTable("vmc_cabinet1");
    m_modelCabinet->setEditStrategy(QSqlTableModel::OnManualSubmit);
}


void VmSql::productTableCheck()
{
    m_model->setTable("vmc_product");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

   // QString filter = QString("productNo = '%1'").arg("jp0001");
   // qDebug()<<filter;
   // m_model->setFilter(filter);
    m_model->select();

    qDebug()<<"productTableCheck:"<<m_model->columnCount()
           <<m_model->rowCount();
    bool ok;
    int key = m_model->record().indexOf("productNo");
    for(int i = 0;i < m_model->rowCount();i++)
    {
        QSqlRecord record = m_model->record(i);
        QString productNo = record.value("productNo").toString();
        qDebug()<<"productNo:"<<productNo;

        //第二种方式通过索引搜索 使用大数据 推荐
        QString productNo1 = record.value(key).toString();
        qDebug()<<"productNo1:"<<productNo1;
        //处理数据

    }



}



