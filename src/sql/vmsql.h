#ifndef VMSQL_H
#define VMSQL_H
#include <QObject>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlTableModel>

class VmSql : public QThread
{
    Q_OBJECT
public:
    explicit VmSql(QThread *parent = 0);
    ~VmSql();

    void stopThread();
    void startThread();

    bool sqlConnection();

    bool isSqlConnected(){this->sqlConnected;}

    void productTableCheck();

    enum{
        SQL_CONNECT_FAIL = 0,
        SQL_CONNECT_OK
    };


signals:
    void sqlRptSignal(quint32 type);
    void sqlProductChanged();
protected:
    virtual void run();

public slots:
    void tabelModelInit();

private:
    bool stopped;
    bool sqlConnected;
    QSqlDatabase m_db;
    QSqlTableModel *m_model;
    QSqlTableModel *m_modelCabinet;
    QList<QSqlTableModel *> m_modelCabinetList;
};

#endif // VMSQL_H
