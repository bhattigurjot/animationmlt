#ifndef ANIMATIONMLT
#define ANIMATIONMLT

#include <QString>
#include <QDebug>
#include <mlt++/Mlt.h>

using namespace Mlt;

class animationMLT
{
public:
    animationMLT();
    void printOutput(Properties p, Animation a);
    void addKF(Properties p);
    void removeKF(Animation a);
    QString getKFType(Animation a, int index);
};

#endif // ANIMATIONMLT

