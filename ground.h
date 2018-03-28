#include "main.h"

#ifndef GROUND_H
#define GROUND_H


class Ground {
public:
    Ground() {}
    Ground(float x, float y, color_t color,int depth);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    int deep;
    // void tick();
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
