#include "animationmlt.h"

animationMLT::animationMLT()
{
    Properties pr;
    pr.set("foo", "50=100; 60|=60; 100~=0; 120=20");
    pr.anim_get_int("foo", 0);

    Animation an = pr.get_animation("foo");

    qDebug() << "Original Animation String" << an.serialize_cut(-1, -1);

    printOutput(pr, an);

    addKF(pr);

    printString(an);

    removeKF(an);

    editKFValue(pr, an, 99, 122);

    editKFPosition(pr, an, 50, 49);

    editKFType(pr, an, 120, mlt_keyframe_smooth);
}

void animationMLT::addKF(Properties p)
{
    // Adds new keyframe
    p.anim_set("foo", 10, 88, 0, mlt_keyframe_discrete);
    qDebug() << "Discrete KF added";

    p.anim_set("foo", 5, 99, 0, mlt_keyframe_smooth);
    qDebug() << "Smooth KF added";
}

void animationMLT::removeKF(Animation a)
{
    // Removes keyframe
    int position = a.key_get_frame(2);

    a.remove(position);
    qDebug() << "KF at Index 2 removed";

    printString(a);
}

void animationMLT::editKFValue(Properties p, Animation a, int position, int value)
{
    // Edits the value of keyframe
    int oldValue = p.anim_get_int("foo", position);

    p.anim_set("foo", value, position, 0, mlt_keyframe_smooth);
    qDebug() << "KF at" << position << ", its value changed from " << oldValue << "to " << p.anim_get_int("foo", position);

    printString(a);
}

void animationMLT::editKFPosition(Properties p, Animation a, int oldPos, int newPos)
{
    // Edits the position of keyframe
    p.anim_set("foo", p.anim_get_int("foo", oldPos), newPos, 0, a.keyframe_type(oldPos));
    qDebug() << "KF at" << oldPos << "shifted to" << newPos;

    a.remove(oldPos);

    printString(a);
}

void animationMLT::editKFType(Properties p, Animation a, int position, mlt_keyframe_type type)
{
    // Edits the keyframe type
    QString oldType = getKFType(a.keyframe_type(position));
    p.anim_set("foo", p.anim_get_int("foo", position), position, 0, type);
    qDebug() << "KF at" << position << "type changed from" << oldType << "to" << getKFType(a.keyframe_type(position));

    printString(a);
}

QString animationMLT::getKFType(Animation a, int index)
{
    // Returns KF type
    QString KFtype;

    if (a.key_get_type(index) == mlt_keyframe_smooth)
        KFtype = "~ smooth";
    if (a.key_get_type(index) == mlt_keyframe_linear)
        KFtype = "= linear";
    if (a.key_get_type(index) == mlt_keyframe_discrete)
        KFtype = "| discrete";

    return KFtype;
}

QString animationMLT::getKFType(mlt_keyframe_type type)
{
    // Returns KF type
    QString KFtype;

    if (type == mlt_keyframe_smooth)
        KFtype = "~ smooth";
    if (type == mlt_keyframe_linear)
        KFtype = "= linear";
    if (type == mlt_keyframe_discrete)
        KFtype = "| discrete";

    return KFtype;
}

void animationMLT::printOutput(Properties p, Animation a)
{
    // Prints Info

    qDebug() << "Total Length of Animation:" << a.length();
    qDebug() << "No. of KFs:" <<a.key_count();

    int pos = 0;

    while (pos!=a.key_count()) {
        qDebug() << "frame:"<< a.key_get_frame(pos) << "value:" << p.anim_get_int("foo", a.key_get_frame(pos));
        qDebug() << "index:" << pos << "type:" << getKFType(a, pos);

        pos++;
    }


}

void animationMLT::printString(Animation a)
{
    qDebug() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    qDebug() << "New Animation String" << a.serialize_cut(-1, -1);
    qDebug() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}
