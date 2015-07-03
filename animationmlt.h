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
    void editKFType(Properties p, Animation a, int position, mlt_keyframe_type type);
    QString getKFType(Animation a, int index);
    QString getKFType(mlt_keyframe_type type);
};

#endif // ANIMATIONMLT

