#include "kante.h"
#include "main.h"
#include "math.h"


Kante::Kante(float x, float y, color_t color,int dept,int numb) {

    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    dee=dept;
    num=numb;
    kspeed=0.5;    // };
    int i=0;
    float vertex_buffer_data[9*num];
    
    
    for(i=0;i<num;i++)
    {
        vertex_buffer_data[9*i+0] = 10*(i-num/2)+0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 5.0f+10*(i-num/2);
        vertex_buffer_data[9*i+4] = dee;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -5.0f+10*(i-num/2);
        vertex_buffer_data[9*i+7] = dee;
        vertex_buffer_data[9*i+8] = 0.0f;

     }
    
    this->object = create3DObject(GL_TRIANGLES, 3*num  , vertex_buffer_data, color, GL_FILL);
}

void Kante::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Kante::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Kante::move(){
    this->position.x+=kspeed;
}