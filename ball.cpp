#include "ball.h"
#include "main.h"
#include "math.h"

#define M_PI 3.14159265358979323846

Ball::Ball(float x, float y, color_t color,float r , int slab) {
    
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 0.5;
    upspeed=0.0;
    acceleration=0.0;
    rect=slab;
    h=r;
   
    int i;
    float vertex_buffer_data[380*9];
    
    for(i=0;i<360;i++)
    {
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i+1] = 0.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = r*cos((3.1457*i/180));
        vertex_buffer_data[9*i+4] = r*sin(3.1457*i/180);
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = r*cos(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+7] = r*sin(3.1457*(i+1)/180);
        vertex_buffer_data[9*i+8] = 0.0f;

   
    }

    if(slab==1)
    {
        vertex_buffer_data[9*i] = -r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (10-r)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (10+r)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (5-r)/sqrt(2);
        vertex_buffer_data[9*i+7] = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;        

        i++;

        vertex_buffer_data[9*i] = -r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (-10-r)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (-10+r)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (-15-r)/sqrt(2);
        vertex_buffer_data[9*i+7] = (-5+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;

        i++;

        vertex_buffer_data[9*i] = -r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (5-r)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (-15-r)/sqrt(2);
        vertex_buffer_data[9*i+7] = (-5+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;                
 
    }

    if(slab==2)
    {
        vertex_buffer_data[9*i] = r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (r-10)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (r+10)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (r-5)/sqrt(2);
        vertex_buffer_data[9*i+7] = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;        

        i++;

        vertex_buffer_data[9*i] = r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (10+r)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (-10+r)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+7] = (-5+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;

        i++;

        vertex_buffer_data[9*i] = r/sqrt(2);
        vertex_buffer_data[9*i+1] = r/sqrt(2);
        vertex_buffer_data[9*i+2] = 0.0f;        
        
        vertex_buffer_data[9*i+3] = (r-5)/sqrt(2);
        vertex_buffer_data[9*i+4]  = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+5] = 0.0f;        
 
        vertex_buffer_data[9*i+6] = (15+r)/sqrt(2);
        vertex_buffer_data[9*i+7] = (-5+r)/sqrt(2);
        vertex_buffer_data[9*i+8] = 0.0f;                      
    }
    
    int p;
    if(slab==1 || slab==2)
        p=363;
    else
        p=360;


    this->object = create3DObject(GL_TRIANGLES, p*3  , vertex_buffer_data, color, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ball::tick() {
  
     this->position.x+= speed;


}
void Ball::water()
{
        float x_angle=acos(this->position.x/33);
        float y_pos=-177-33*sin(x_angle);        
       
        if(y_pos<this->position.y)   
            this->position.y-=0.5;
        
        else if(this->position.x<0)
        {
            x_angle-=M_PI/360;
            this->position.x=33*cos(x_angle);
            this->position.y=-177-33*sin(x_angle);
        }
        else if(this->position.x>0)
        {
            x_angle+=M_PI/360;
            this->position.x=33*cos(x_angle);
            this->position.y=-177-33*sin(x_angle);
        }
   //     printf("%f %f\n",x_angle,y_pos,);
}



void Ball::tick2() {

if(this->position.x>=193 || this->position.x<=-193)
xspeed=0;

this->position.x+=xspeed;


this->position.y +=  upspeed;
upspeed=upspeed-acceleration;
    
      
    if(this->position.y<=-170 && upspeed<0)
    {   
        upspeed=0;
        xspeed=0;
        acceleration=0;
    }
    
}



void Ball::tick1(int flag, float pos) {
    
    if(this->position.y<=-170)
    {  
       // upspeed=2*1.6;
        printf("%f\n",upspeed );
        acceleration=20*0.0019*2;
    }
    if(flag==1)
    {
        xspeed=-upspeed;
        xacceleration=20*0.0019*2;
        pos_ball=pos;
        //info=flag;
    }
    if(flag==2)
    {
        xspeed=upspeed;
        xacceleration=-20*0.0019*2;
        pos_ball=pos;
        //info=flag;
    }

    // this->position.y -= speed;
}


bounding_box_t Ball::bounding_box() {
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y ,h,0.4};
    return bbox;
}
