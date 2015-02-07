#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QQuickView>
#include <QQuickItem>
#include "vmcmainflow.h"
#include "mainobject.h"


class MainWindow : public QQuickView
{
    Q_OBJECT
public:
    explicit MainWindow(QWindow *parent = 0);
    ~MainWindow();

signals:

public slots:
    void setUiState(quint8 state);
    void qmlCreateProduct();
    void qmlDeleteProduct();

    void EV_callBackSlot(const quint8 type,const void *ptr);
private:
    VmcMainFlow *vmcMainFlow;
    MainObject *mainObject;
    QQuickItem *mainItem;



    QVariantList productList;

};

#endif // MAINWINDOW_H
