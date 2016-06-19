#include"bird2.h"

bird2::bird2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x, y,  radius, timer, pixmap,  world,  scene)
{

}
void bird2::many(){
g_body->SetLinearVelocity(b2Vec2(0,0));
}
