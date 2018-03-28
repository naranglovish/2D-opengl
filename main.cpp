#include "main.h"
#include "timer.h"
#include "ball.h"
#include "pond.h"
#include "math.h"
#include <cstdlib>
#include "GL/freeglut.h"
#include "GL/glut.h"
#include "GL/glu.h"
#include "GL/gl.h"
#include "GL/glx.h"
#include "ground.h"
#include "kante.h"
#include "trampoline.h"
#include "magnet.h"
#include "number.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/
int score=0,flag=0,flag1=0;
Ball ball[45];
Pond lake;

Ground grass;
Ground grass1;
Ground screen;

Kante spike1;
Kante spike2;

Magnet m1;
Magnet m2;

Trampoline tramp; 
int water_flag=0,move_flag=0;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;

Timer t60(1.0 / 60);


//void scoredisplay (int posx, int posy, int posz, int space_char, int scorevar);

//}

Number ones,tens,hund,level1,level2,level3;


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    // glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    // glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    int i;
    screen.draw(VP);
    // Scene render
    for(i=1;i<=39;i++)
    ball[i].draw(VP);
    grass1.draw(VP);
    grass.draw(VP);
    lake.draw(VP);
    tramp.draw(VP);
    spike2.draw(VP);
    spike1.draw(VP);
    ball[0].draw(VP);

    
     m1.draw(VP);
     m2.draw(VP);

     hund.draw(VP);
     tens.draw(VP);
     ones.draw(VP);
     if(score>=0 && score<=65)
     {
            level1.draw(VP);  
     }
     if(score>=70 && flag1==0)
     {
        level2.draw(VP);
     }
     if(score>=120)
     {  
        flag1=1;
        level3.draw(VP);
     //   for(i=40;i<=45;i++)
       //     ball[i].draw(VP);

     }

     
   // // ball[2].draw(VP);
}

void tick_input(GLFWwindow *window) {

            int key_a = glfwGetKey(window, GLFW_KEY_A);
            int key_s = glfwGetKey(window, GLFW_KEY_S);
            int key_d = glfwGetKey(window, GLFW_KEY_D);
            int key_w = glfwGetKey(window, GLFW_KEY_W);
            int left  = glfwGetKey(window, GLFW_KEY_LEFT);
            int right = glfwGetKey(window, GLFW_KEY_RIGHT);
            int up = glfwGetKey(window, GLFW_KEY_SPACE);
            int mouse_clicked = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
            
              if (key_a && screen_center_x - 200/screen_zoom > -200) {
                  screen_center_x -= 1;
                  reset_screen();
              }
              if (key_d && screen_center_x + 200/screen_zoom < 200) {
                  screen_center_x += 1;
                  reset_screen();
              }
              if (key_s && screen_center_y - 250/screen_zoom > -250) {
                  screen_center_y -= 1;
                  reset_screen();
              }
              if (key_w && screen_center_y + 200/screen_zoom < 200) {
                  screen_center_y += 1;
                  reset_screen();
              }

     if (left && ball[0].position.x!=-193) {
            ball[0].set_position(ball[0].position.x-1,ball[0].position.y);
            if(ball[0].position.x<-33 && ball[0].position.y<=-177)
            {ball[0].set_position(-40,-170);}

            
     }
 
     if (right && ball[0].position.x!=193){
            ball[0].set_position(ball[0].position.x+1,ball[0].position.y);
            if(ball[0].position.x>=33 && ball[0].position.y<=-177)
            {ball[0].set_position(40,-170);}
     }

     if(up && ball[0].position.y<=-170){
        if(water_flag==1)
        ball[0].upspeed=2.5*1.6;
        else
            ball[0].upspeed=3.5*1.6;
         ball[0].tick1(0,ball[0].position.y);
     
     }


}


void tick_elements() {
      
      int i,magnet_flag=0;
      for(i=1;i<=39;i++)
      {
        if(ball[i].position.x>=207)
            ball[i].set_position(-193,ball[i].position.y);
            
            ball[i].tick();
            if(score>=70 && score <120)
            {
                ball[i].speed=0.7;
            }
            if(score>=120)
            {
                ball[i].speed=0.9;
            }

      }

     magnet_flag=m1.Appear();

     if(magnet_flag==1 && score>=70)
     {  
            //tens=Number(165,180,COLOR_ORANGE,5);
            m1.set_position(165 , 110);
            m2.set_position(160 , 110);
            if(ball[0].position.y>=80 && ball[0].position.y<=145 && ball[0].position.x<=152)
            {
                ball[0].set_position(ball[0].position.x+2,ball[0].position.y);
            }
            float y_angle=asin((ball[0].position.y-175)/20);
            float x_pos=160+20*cos(y_angle);
           if(ball[0].position.x>=x_pos+0.5 || ball[0].position.x>=x_pos-0.5)
                ball[0].xspeed=0;
            

     }
     else
     {
            m1.set_position(1650000 , 175);
            m2.set_position(160000 , 175);

     }
     if(score==120 && flag==0)
     {
        flag=1;
        spike1=Kante(-160,-167 ,COLOR_YELLOW,-10,5);
        spike2=Kante(80,-167,COLOR_YELLOW,-10,3);
    }

     ball[0].tick2();
    spike1.move();
    spike2.move();
    if(spike1.position.x<=-175 || spike1.position.x>=-65)
        spike1.kspeed=-spike1.kspeed;
    if(spike2.position.x<=55 || spike2.position.x>=95)
        spike2.kspeed=-spike2.kspeed;
    

      for(i=1;i<=39;i++)
      {
        bounding_box_t a=ball[0].bounding_box();
        bounding_box_t b=ball[i].bounding_box();
         if(detect_collision(ball[0].bounding_box() , ball[i].bounding_box(), ball[i].rect))
         {

            if(ball[0].upspeed<0 && ball[i].rect>0)
            {
                score+=5;
                int temp=score;
                ones=Number(180,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                tens=Number(165,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                hund=Number(150,180,COLOR_ORANGE,temp%10);
                ball[0].upspeed=2.75;
                ball[i].set_position(100000,1000000);
                ball[0].tick1(ball[i].rect,ball[0].position.y);
            } 
            if(ball[0].upspeed<0 && ball[i].rect==0)
            {
                score+=5;
                int temp=score;
                ones=Number(180,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                tens=Number(165,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                hund=Number(150,180,COLOR_ORANGE,temp%10);
                ball[i].set_position(100000,1000000);
                ball[0].upspeed=2.75;
                ball[0].xspeed=0;
            }
            else
            {   
                if(a.x < b.x && ball[i].speed>0) 
                 {   ball[i].speed=2*ball[i].speed;
                    ball[i].tick();
                    ball[i].speed=ball[i].speed/2; }
                else if(a.x < b.x && ball[i].speed<0)
                    {
                     ball[i].speed=-2*ball[i].speed;
                     ball[i].tick();
                    ball[i].speed=-ball[i].speed/2;
                }
                else if(a.x > b.x && ball[i].speed>0)
                    { ball[i].speed=-2*ball[i].speed;
                        ball[i].tick();
                    ball[i].speed=-ball[i].speed/2;}
                else if(a.x > b.x && ball[i].speed<0)
                    {ball[i].speed=2*ball[i].speed;
                        ball[i].tick();
                    ball[i].speed=ball[i].speed/2;}

                    
            }
        }  
    }

   

    if(abs(ball[0].position.y-spike1.position.y)<=7 &&  abs(ball[0].position.x-spike1.position.x)<=20)
    {
                score-=10;
                int temp=score;
                ones=Number(180,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                tens=Number(165,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                hund=Number(150,180,COLOR_ORANGE,temp%10);
        spike1.set_position(10000000,100000000);
    }
    if(abs(ball[0].position.y-spike2.position.y)<7 &&  abs(ball[0].position.x-spike2.position.x)<=10)
    {
                score-=10;
                int temp=score;
                ones=Number(180,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                tens=Number(165,180,COLOR_ORANGE,temp%10);
                temp=temp/10;
                hund=Number(150,180,COLOR_ORANGE,temp%10);
        spike2.set_position(10000000,100000000);
    }
    if(abs(ball[0].position.y-tramp.position.y)<=7 &&  abs(ball[0].position.x-tramp.position.x)<=35)
    {
                ball[0].upspeed=10;
                ball[0].acceleration=0.174;
    }
    if(abs(lake.position.x-ball[0].position.x)<=33 && ball[0].position.y<=-170)
    {
        water_flag=1;
       // printf("%f\n",ball[0].position.x);
        if(ball[0].position.x<-0.3  || ball[0].position.x>0.3 )
        {ball[0].water();}
        else if(ball[0].position.x<=0.3 && ball[0].position.x>=-0.3 && ball[0].position.y>-209.99994)
            ball[0].water();
        
    }
    else
        water_flag=0;
}


void initGL(GLFWwindow *window, int width, int height) {

int x,y,i,temp,z;
    
    ball[0]=Ball(-100,-170,COLOR_BLUE,7,0);
    ball[1]=Ball(-130,60+75-30,COLOR_DARKGREEN,5,0);
    ball[2]=Ball(-83,60+75-30,COLOR_GREEN,4,1);
    ball[3]=Ball(20,60+75-30,COLOR_DARKGREEN,3,0);
    ball[4]=Ball(-40,60+75-30,COLOR_RED,5,0);
    ball[5]=Ball(100,60+75-30,COLOR_GREEN,4,0);
    ball[6]=Ball(160,60+75-30,COLOR_BLACK,4,0);
    ball[7]=Ball(-130,28+75-30,COLOR_RED,3,0);
    ball[8]=Ball(-70,28+75-30,COLOR_DARKGREEN,5,0);
    ball[9]=Ball(-10,28+75-30,COLOR_BLACK,3,0);
    ball[10]=Ball(50,28+75-30,COLOR_RED,4,0);
    ball[11]=Ball(110,28+75-30,COLOR_GREEN,4,0);
    ball[12]=Ball(170,28+75-30,COLOR_BLACK,3,0);
    ball[13]=Ball(-140,-5+75-30,COLOR_RED,5,0);
    ball[14]=Ball(-80,-5+75-30,COLOR_GREEN,3,0);
    ball[15]=Ball(-20,-5+75-30,COLOR_BLACK,5,0);
    ball[16]=Ball(40,-5+75-40,COLOR_RED,4,0);
    ball[17]=Ball(100,-5+75-24,COLOR_GREEN,4,0);
    ball[18]=Ball(160,-5+75-13,COLOR_BLACK,4,2);
    ball[19]=Ball(-95,55-14,COLOR_MAGNET,4,0);
    ball[20]=Ball(-50,46-15,COLOR_BLACK,6,0);
    ball[21]=Ball(20,50,COLOR_DARKGREEN,5,0);
    ball[22]=Ball(45,43-5,COLOR_BROWN,4,0);
    ball[23]=Ball(70,60-20,COLOR_MAGNET, 7,0);
    ball[24]=Ball(100,50-30,COLOR_ORANGE,6,0);
    ball[25]=Ball(130,45-30,COLOR_BLACK,4,2);
    ball[26]=Ball(-50,-46,COLOR_BLACK,6,0);
    ball[27]=Ball(10,-20,COLOR_DARKGREEN,5,0);
    ball[28]=Ball(35,-10,COLOR_BROWN,4,0);
    ball[29]=Ball(73,-60,COLOR_MAGNET, 7,0);
    ball[30]=Ball(134,50-20,COLOR_ORANGE,6,0);
    ball[31]=Ball(156,-45,COLOR_BLACK,4,0);
    ball[32]=Ball(45,-33-5,COLOR_BROWN,4,0);
    ball[33]=Ball(70,40-20,COLOR_MAGNET, 7,0);
    ball[34]=Ball(100,-30,COLOR_ORANGE,6,0);
    ball[35]=Ball(30,45-30,COLOR_BLACK,4,0);
    ball[36]=Ball(180,-20,COLOR_BLACK,6,0);
    ball[37]=Ball(190,-40,COLOR_DARKGREEN,5,0);
    ball[38]=Ball(185,-53,COLOR_BROWN,4,0);
    ball[39]=Ball(173,25,COLOR_MAGNET, 7,0);

  

    ones=Number(180,180,COLOR_ORANGE,0);
    tens=Number(165,180,COLOR_ORANGE,0);
    hund=Number(150,180,COLOR_ORANGE,0);
    level1=Number(-180,180,COLOR_ORANGE,1);
    level2=Number(-180,180,COLOR_ORANGE,2);
    level3=Number(-180,180,COLOR_ORANGE,3);
   
    //ball[40]=Ball(134,50-20,COLOR_ORANGE,6,0);
    //ball[31]=Ball(156,45-16,COLOR_BLACK,4,
    screen=Ground(0,200,COLOR_SCREEN,-377);

    lake=Pond(0,-177,COLOR_SKYBLUE,40);
    grass=Ground(0,-177,COLOR_DARKGREEN,-20);
    grass1=Ground(0,-177,COLOR_BROWN,-80);

    spike1=Kante(-1600000,-167 ,COLOR_YELLOW,-10,5);
    spike2=Kante(80000000,-167,COLOR_YELLOW,-10,3);

    tramp=Trampoline(145,-143,COLOR_ORANGE,25);
    m1=Magnet(165 , 110 , COLOR_MAGNET , 30);
    m2=Magnet(160 , 110 , COLOR_SCREEN , 25);

    //ball[1]=Ball(0,0,COLOR_RED);
    //ball[2]=Ball(20,0,COLOR_RED);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 2160;
    int height = 2160;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            tick_elements();
            tick_input(window);
            //glutMouseWheelFunc(MouseWheel);

        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

  bool detect_collision(bounding_box_t a, bounding_box_t b , int flag) {
      // return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
      //        (abs(a.y - b.y) * 2 < (a.height + b.height));
    if(flag==0)
    {
        if(sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)))<=a.h+b.h)
            return true;
    }
    else if(flag==1 || flag==2)
    {
        if( abs(a.x-b.x)<=10 && abs(a.y-b.y)<=16 )
            return true;
    }
    return false;    
  
  }


void reset_screen() {
    float top    = screen_center_y + 200 / screen_zoom;
    float bottom = screen_center_y - 250 / screen_zoom;
    float left   = screen_center_x - 200 / screen_zoom;
    float right  = screen_center_x + 200 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
