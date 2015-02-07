#ifndef PRODUCTOBJECT_H
#define PRODUCTOBJECT_H

#include <QObject>

class ProductObject : public QObject
{
    Q_OBJECT
public:
    explicit ProductObject(QObject *parent = 0);
    ~ProductObject();

signals:

public slots:
};

#endif // PRODUCTOBJECT_H
