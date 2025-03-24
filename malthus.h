#ifndef MALTHUS_H
#define MALTHUS_H

#include <QObject>

class malthus : public QObject
{
    Q_OBJECT
public:
    explicit malthus(QObject *parent = nullptr);

signals:
};

#endif // MALTHUS_H
