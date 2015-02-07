#ifndef MAINOBJECT_H
#define MAINOBJECT_H

//负责与QML界面交互的主接口

#include <QObject>
#include <QCache>
#include <vmsql.h>
#include <productobject.h>

class MainObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int vmcState READ getVmcState WRITE setVmcState NOTIFY vmcStateChanged)
    Q_PROPERTY(QList<ProductObject *> productList READ getProductList WRITE setProductList NOTIFY vmProductListChanged)



public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

    void setVmcState(const int state);
    int getVmcState()const {return vmcState;}

    QList<ProductObject *> getProductList(){return productList;}
    void setProductList(QList<ProductObject *> list){productList = list;}


signals:
    void vmcStateChanged();
    void vmProductListChanged();
public slots:
    void vmcpaySlot(int cabinet,int column,int type,long cost);
private:

    int vmcState;

    QList<ProductObject *> productList;

};

#endif // MAINOBJECT_H
