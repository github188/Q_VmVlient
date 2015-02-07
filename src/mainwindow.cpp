#include "mainwindow.h"
#include <QtDebug>
#include <QQmlContext>
MainWindow::MainWindow(QWindow *parent) :
    QQuickView(parent)
{
   // setTitle(QString(""));
    mainObject = new MainObject();
    QQmlContext *context = rootContext();
    context->setContextProperty("vm",mainObject);




    //注册组件到QML
   // qmlRegisterType<MainObject>("MainObject", 1, 0, "MainObject");
    setSource(QUrl::fromLocalFile("../../qml/main.qml"));


    setMinimumSize(QSize(768*0.5,1366*0.5));
    //setOpacity(0.8);
    show();
    mainItem = qobject_cast<QQuickItem *>(this->rootObject());
    mainItem->setProperty("sd",1);




    setUiState(EV_STATE_DISCONNECT);






    //启动后台通信
    qDebug()<<"Start vmc ...COM7"<<mainItem;
    vmcMainFlow = new VmcMainFlow(0,QString("COM1"));
    connect(vmcMainFlow,SIGNAL(EV_callBackSignal(quint8,const void*)),
            this,SLOT(EV_callBackSlot(quint8,const void*)),Qt::QueuedConnection);
    vmcMainFlow->vmcStart();




}

MainWindow::~MainWindow()
{
    vmcMainFlow->deleteLater();
    mainObject->deleteLater();

}

void MainWindow::EV_callBackSlot(const quint8 type,const void *ptr)
{
    qDebug()<<"MainWindow:EV_back type="<<QString("%1").arg(type,2,16,QLatin1Char('0')).toUpper();
    if(type == EV_STATE_RPT)
    {
       ST_STATE *state = (ST_STATE *)ptr;
       if(mainObject->getVmcState() != state->vmcState)
       {
          mainObject->setVmcState(state->vmcState);
          setUiState(state->vmcState);
       }

       if(state->vmcState == EV_STATE_DISCONNECT)
       {

       }
       else if(state->vmcState == EV_STATE_NORMAL)
       {

       }
       else if(state->vmcState == EV_STATE_FAULT)
       {

       }

    }
}



void MainWindow::setUiState(quint8 state)
{
    QVariant returnVar;
    QVariant s = state;
    if(mainItem == NULL) return;
    QMetaObject::invokeMethod(mainItem,"vmcStatehandle",
                         Q_RETURN_ARG(QVariant, returnVar),
                         Q_ARG(QVariant, s));

}


void MainWindow::qmlCreateProduct()
{
    QVariant product;
    if(mainItem == NULL) return;
    QMetaObject::invokeMethod(mainItem,"vmCreateProduct",
                         Q_RETURN_ARG(QVariant, product));

    productList.append(product);
}


void MainWindow::qmlDeleteProduct()
{
    QVariant product;
    if(mainItem == NULL) return;
    QMetaObject::invokeMethod(mainItem,"vmDeleteProduct",
                         Q_ARG(QVariant, product));

}


