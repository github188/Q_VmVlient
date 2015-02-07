#ifndef MAINOBJECT_H
#define MAINOBJECT_H

//负责与QML界面交互的主接口

#include <QObject>

class MainObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int vmcState READ getVmcState WRITE setVmcState NOTIFY vmcStateChanged)
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

    void setVmcState(const int state);
    int getVmcState()const {return vmcState;}




signals:
    void vmcStateChanged();
public slots:
    void vmcpaySlot(int cabinet,int column,int type,long cost);
private:


    int vmcState;




};

#endif // MAINOBJECT_H
