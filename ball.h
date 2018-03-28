#include "main.h"

#ifndef BALL_H
#define BALL_H


class Ball {
public:
    Ball() {}
    Ball(float x, float y, color_t color,float r,int slab);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    void tick2();
    void tick1(int flag,float pos);
    void water();
    void move_water_left();
    void move_water_right();
    double speed;
    double upspeed;
    double acceleration;
    double xspeed;
    double xacceleration;
    double pos_ball;
    int rect;
    float h;
    int info;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // BALL_H
