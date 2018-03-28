#include "main.h"

#ifndef NUMBER_H
#define NUMBER_H


class Number{
public:
    Number() {}
    Number(float x, float y, color_t color,int depth);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    int deep;
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    int i;
private:
    VAO *object;
};

#endif // BALL_H
