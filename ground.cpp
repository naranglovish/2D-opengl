#include "ground.h"
#include "main.h"
#include "math.h"

Ground::Ground(float x, float y, color_t color,int depth) {
    
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    deep=depth;
       // };
    int i;
    float vertex_buffer_data[3*9];
    
    
    
        vertex_buffer_data[0] = 0.0f;
        vertex_buffer_data[1] = 0.0f;
        vertex_buffer_data[2] = 0.0f;

        vertex_buffer_data[3] = 200.0f;
        vertex_buffer_data[4] = 0.0f;
        vertex_buffer_data[5] = 0.0f;

        vertex_buffer_data[6] = 200.0f;
        vertex_buffer_data[7] = deep;
        vertex_buffer_data[8] = 0.0f;

        vertex_buffer_data[9] = 0.0f;
        vertex_buffer_data[10] = 0.0f;
        vertex_buffer_data[11] = 0.0f;

        vertex_buffer_data[12] = -200.0f;
        vertex_buffer_data[13] = 0.0f;
        vertex_buffer_data[14] = 0.0f;

        vertex_buffer_data[15] = -200.0f;
        vertex_buffer_data[16] = deep;
        vertex_buffer_data[17] = 0.0f;

        vertex_buffer_data[18] = 0.0f;
        vertex_buffer_data[19] = 0.0f;
        vertex_buffer_data[20] = 0.0f;

        vertex_buffer_data[21] = 200.0f;
        vertex_buffer_data[22] = deep;
        vertex_buffer_data[23] = 0.0f;

        vertex_buffer_data[24] = -200.0f;
        vertex_buffer_data[25] = deep;
        vertex_buffer_data[26] = 0.0f;
   
    

    
    this->object = create3DObject(GL_TRIANGLES, 3*3  , vertex_buffer_data, color, GL_FILL);
}

void Ground::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ground::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

// void Ball::tick() {
  
//   //if(this->position.y<=0.07)
//     //    {speed=0.00;}

//      this->position.x+= speed;
// }

// void Ball::tick2() {

// //if(info==1 && this->position.y>pos_ball)
// //xspeed=-upspeed;
// //if(info==2 && this->position.y>pos_ball)
// //xspeed=upspeed;
// if(this->position.x>=193 || this->position.x<=-193)
// xspeed=0;

// this->position.x+=xspeed;
// //xspeed=xspeed+xacceleration/2;


// this->position.y +=  upspeed;
// upspeed=upspeed-acceleration;
    
//     // if(this->position.y<=pos_ball-10 )
//     // {
//     //     xspeed=0;
//     //     //xacceleration=0;    
//     //    // info=0;
//     // }

//     if(this->position.y<=-170)
//     {   
//         upspeed=0;
//         acceleration=0;
//         this->position.y==-170;
//     }

// }



// void Ball::tick1(int flag, float pos) {
    
//     if(this->position.y<=-170)
//     {  
//         upspeed=1.6;
//         acceleration=0.0019*2;
//     }
//     if(flag==1)
//     {
//         xspeed=-upspeed;
//         xacceleration=0.0019*2;
//         pos_ball=pos;
//         //info=flag;
//     }
//     if(flag==2)
//     {
//         xspeed=upspeed;
//         xacceleration=-0.0019*2;
//         pos_ball=pos;
//         //info=flag;
//     }

//     // this->position.y -= speed;
// }


// bounding_box_t Ball::bounding_box() {
//     float x = this->position.x, y = this->position.y;
//     bounding_box_t bbox = { x, y ,0.4,0.4};
//     return bbox;
// }
