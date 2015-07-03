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
    void printString(Animation a);
    void addKF(Properties p);
    void removeKF(Animation a);
    void editKFValue(Properties p, Animation a, int position, int value);
    void editKFPosition(Properties p, Animation a, int oldPos, int newPos);
    QString getKFType(Animation a, int index);
};

#endif // ANIMATIONMLT

