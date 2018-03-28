#include "number.h"
#include "main.h"
#include "math.h"

float vertex_buffer_data[300];


Number::Number(float x, float y, color_t color,int depth) {
        
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    deep=depth;
    i=0;   // };
        
    if(depth==1)
    {two();i++;four();}
    if(depth==2)
    {six();i++;two();i++;one();i++;seven();i++;five();}
    if(depth==3)
    {six();i++;two();i++;four();i++;five();i++;one();}
    if(depth==4)
    {three();i++;one();i++;two();i++;four();}
    if(depth==5)
    {six();i++;three();i++;one();i++;four();i++;five();}
    if(depth==6)
    {six();i++;one();i++;three();i++;seven();i++;five();i++;four();}
    if(depth==7)
    {six();i++;two();i++;four();}
    if(depth==8)
    {one();i++;two();i++;three();i++;four();i++;five();i++;six();i++;seven();}
    if(depth==9)
    {one();i++;two();i++;three();i++;four();i++;five();i++;six();}
    if(depth==0)
    {two();i++;three();i++;four();i++;five();i++;six();i++;seven();}

    this->object = create3DObject(GL_TRIANGLES, 3*(i+1), vertex_buffer_data, color, GL_FILL);
}

void Number::one()
{

    vertex_buffer_data[9*i+0] = 5.0f;
    vertex_buffer_data[9*i+1] = 1.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = 5.0f;
    vertex_buffer_data[9*i+4] = -1.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = -5.0f;
    vertex_buffer_data[9*i+7] = -1.0f;
    vertex_buffer_data[9*i+8] = 0.0f;
    
    i++;    

    vertex_buffer_data[9*i+0] = -5.0f;
    vertex_buffer_data[9*i+1] = -1.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = 5.0f;
    vertex_buffer_data[9*i+4] = 1.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = -5.0f;
    vertex_buffer_data[9*i+7] = 1.0f;
    vertex_buffer_data[9*i+8] = 0.0f;
}
void Number::two()
{        
        vertex_buffer_data[9*i+0] = 5.0f;
        vertex_buffer_data[9*i+1] = -1.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 3.0f;
        vertex_buffer_data[9*i+4] = -1.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 5.0f;
        vertex_buffer_data[9*i+7] = 9.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
   
        i++;
        
        vertex_buffer_data[9*i+0] = 5.0f;
        vertex_buffer_data[9*i+1] = 9.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 3.0f;
        vertex_buffer_data[9*i+4] = 9.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 3.0f;
        vertex_buffer_data[9*i+7] = -1.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
}
        
void Number::three()
{
    vertex_buffer_data[9*i+0] = -5.0f;
    vertex_buffer_data[9*i+1] = 9.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = -3.0f;
    vertex_buffer_data[9*i+4] = 9.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = -5.0f;
    vertex_buffer_data[9*i+7] = 1.0f;
    vertex_buffer_data[9*i+8] = 0.0f;
   
    i++;
    vertex_buffer_data[9*i+0] = -5.0f;
    vertex_buffer_data[9*i+1] = 1.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = -3.0f;
    vertex_buffer_data[9*i+4] = 1.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = -3.0f;
    vertex_buffer_data[9*i+7] = 9.0f;
    vertex_buffer_data[9*i+8] = 0.0f;

}
      
void Number::four()
{
 
    vertex_buffer_data[9*i+0] = 5.0f;
    vertex_buffer_data[9*i+1] = 1.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = 5.0f;
    vertex_buffer_data[9*i+4] = -9.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = 3.0f;
    vertex_buffer_data[9*i+7] = -9.0f;
    vertex_buffer_data[9*i+8] = 0.0f;
   
    i++;
    vertex_buffer_data[9*i+0] = 3.0f;
    vertex_buffer_data[9*i+1] = -9.0f;
    vertex_buffer_data[9*i+2] = 0.0f;

    vertex_buffer_data[9*i+3] = 5.0f;
    vertex_buffer_data[9*i+4] = 1.0f;
    vertex_buffer_data[9*i+5] = 0.0f;

    vertex_buffer_data[9*i+6] = 3.0f;
    vertex_buffer_data[9*i+7] = 1.0f;
    vertex_buffer_data[9*i+8] = 0.0f;
     //   printf("%d\n",i);

}

void Number::five()
{
        vertex_buffer_data[9*i+0] = -5.0f;
        vertex_buffer_data[9*i+1] = -7.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = -5.0f;
        vertex_buffer_data[9*i+4] = -9.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 5.0f;
        vertex_buffer_data[9*i+7] = -7.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
   
        i++;

        vertex_buffer_data[9*i+0] = 5.0f;
        vertex_buffer_data[9*i+1] = -7.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 5.0f;
        vertex_buffer_data[9*i+4] = -9.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -5.0f;
        vertex_buffer_data[9*i+7] = -9.0f;
        vertex_buffer_data[9*i+8] = 0.0f;

}
void Number::six()
{
        vertex_buffer_data[9*i+0] = 5.0f;
        vertex_buffer_data[9*i+1] = 9.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = 5.0f;
        vertex_buffer_data[9*i+4] = 7.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -5.0f;
        vertex_buffer_data[9*i+7] = 7.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
   
        i++;
        
        vertex_buffer_data[9*i+0] = -5.0f;
        vertex_buffer_data[9*i+1] = 9.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = -5.0f;
        vertex_buffer_data[9*i+4] = 7.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = 5.0f;
        vertex_buffer_data[9*i+7] = 9.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
}
void Number::seven()
{
        vertex_buffer_data[9*i+0] = -5.0f;
        vertex_buffer_data[9*i+1] = 1.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = -3.0f;
        vertex_buffer_data[9*i+4] = 1.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -5.0f;
        vertex_buffer_data[9*i+7] = -9.0f;
        vertex_buffer_data[9*i+8] = 0.0f;
   
        i++;
        vertex_buffer_data[9*i+0] = -5.0f;
        vertex_buffer_data[9*i+1] = -9.0f;
        vertex_buffer_data[9*i+2] = 0.0f;

        vertex_buffer_data[9*i+3] = -3.0f;
        vertex_buffer_data[9*i+4] = 1.0f;
        vertex_buffer_data[9*i+5] = 0.0f;

        vertex_buffer_data[9*i+6] = -3.0f;
        vertex_buffer_data[9*i+7] = -9.0f;
        vertex_buffer_data[9*i+8] = 0.0f;

}

void Number::draw(glm::mat4 VP) {
    
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Number::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

