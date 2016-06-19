#ifndef BIRD2_H
#define BIRD2_H
#include "bird.h"
class bird2 : public Bird
{
public:
    bird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void many();
};

#endif // BIRD2_H
