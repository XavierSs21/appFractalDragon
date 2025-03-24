#ifndef MANDEL_H
#define MANDEL_H

#include <QObject>

class Mandel : public QObject
{
    Q_OBJECT
public:
    explicit Mandel(QObject *parent = nullptr);

signals:
};

#endif // MANDEL_H
