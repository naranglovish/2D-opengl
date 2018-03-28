#include "main.h"

#ifndef KANTE_H
#define KANTE_H


class Kante {
public:
    Kante() {}
    Kante(float x, float y, color_t color,int dept,int numb);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    int dee;
    int num; 
    float kspeed;   // void tick();
    void move();
    // void tick2();
    // void tick1(int flag,float pos);
    // double speed;
    // double upspeed;
    // double acceleration;
    // double xspeed;
    // double xacceleration;
    // double pos_ball;
    // int rect;
    // int info;
    // bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // BALL_H
