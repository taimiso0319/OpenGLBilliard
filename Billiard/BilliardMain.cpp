//
//  main.cpp
//  Billiard
//
//  Created by 安田圭佑 on 9/27/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Ball.h"
#include "Pool.h"
#include "DrawString.h"
#include "Camera.h"

bool Key_UP = false;
bool Key_DOWN = false;
bool Key_RIGHT = false;
bool Key_LEFT = false;
bool isShowingHelp = false;

Ball *balls[1] = {
    new Ball( 0    , 0.81f, 0.3f, 0.05f), //1
    /*
    new Ball(-0.05f, 0.81f, 0.2f, 0.05f), //8
    new Ball( 0.05f, 0.81f, 0.2f, 0.05f), //7
    
    new Ball(-0.1f , 0.81f, 0.1f, 0.05f), //13
    new Ball( 0    , 0.81f, 0.1f, 0.05f), //12
    new Ball( 0.1f , 0.81f, 0.1f, 0.05f), //11
    
    new Ball(-0.15f, 0.81f, 0.0f, 0.05f), //10
    new Ball(-0.05f, 0.81f, 0.0f, 0.05f), //15
    new Ball( 0.05f, 0.81f, 0.0f, 0.05f), //14
    new Ball( 0.15f, 0.81f, 0.0f, 0.05f), //9
    
    new Ball(-0.2f , 0.81f,-0.1f, 0.05f), //3
    new Ball(-0.1f , 0.81f,-0.1f, 0.05f), //6
    new Ball( 0    , 0.81f,-0.1f, 0.05f), //5
    new Ball( 0.1f , 0.81f,-0.1f, 0.05f), //4
    new Ball( 0.2f , 0.81f,-0.1f, 0.05f)  //2
    */
    };
Ball *player_ball = new Ball(0, 0.81f, 1.2f, 0.05f);
Pool pool;
Camera Cam;
DrawString ds;

void ballColorInitialize()
{
    balls[0] ->setColor(0.8f, 0.8f, 0.4f, 1.0f);
    /*
    balls[1] ->setColor(0.0f, 0.0f, 0.0f, 1.0f);
    balls[2] ->setColor(0.4f, 0.4f, 0.1f, 1.0f);
    balls[3] ->setColor(0.9f, 0.6f, 0.4f, 1.0f);
    balls[4] ->setColor(0.8f, 0.4f, 0.8f, 1.0f);
    balls[5] ->setColor(0.8f, 0.4f, 0.4f, 1.0f);
    balls[6] ->setColor(0.4f, 0.4f, 0.8f, 1.0f);
    balls[7] ->setColor(0.4f, 0.4f, 0.1f, 1.0f);
    balls[8] ->setColor(0.4f, 0.8f, 0.4f, 1.0f);
    balls[9] ->setColor(0.8f, 0.8f, 0.4f, 1.0f);
    balls[10]->setColor(0.8f, 0.4f, 0.4f, 1.0f);
    balls[11]->setColor(0.4f, 0.8f, 0.4f, 1.0f);
    balls[12]->setColor(0.6f, 0.6f, 0.2f, 1.0f);
    balls[13]->setColor(0.8f, 0.4f, 0.8f, 1.0f);
    balls[14]->setColor(0.4f, 0.4f, 0.8f, 1.0f);
     */
}

// for recognizing each arrow keys are pushed down;
void arrowkeysDown(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            Key_UP = true;
            break;
            
        case GLUT_KEY_DOWN:
            Key_DOWN = true;
            break;
            
        case GLUT_KEY_LEFT:
            Key_LEFT = true;
            break;
            
        case GLUT_KEY_RIGHT:
            Key_RIGHT = true;
            break;
            
        default:
            break;
    }
}

// for recognizing each arrow keys are released;
void arrowKeysUp(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            Key_UP = false;
            break;
            
        case GLUT_KEY_DOWN:
            Key_DOWN = false;
            break;
            
        case GLUT_KEY_LEFT:
            Key_LEFT = false;
            break;
            
        case GLUT_KEY_RIGHT:
            Key_RIGHT = false;
            break;
            
        default:
            break;

    }
}

// basic keybord function.
// you can feel free to add any key actions.
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case ' ':
            // TODO: do something for pushing a space bar;
            player_ball->setSpeed(0.1f);
            break;
        case 'h':
            isShowingHelp = !isShowingHelp;
            break;
        default:
            break;
    }
}


void init(void)
{
    GLfloat amb[] = {0.2,0.2,0.2};
    GLfloat diff[] = {1.0,1.0,1.0};
    GLfloat spec[] = {1.0,1.0,1.0};
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spec);
    
    glClearColor (0.5, 0.5, 1.0, 0.0);	// sky
    ballColorInitialize();
    glEnable(GL_DEPTH_TEST);
}

void updateBalls(){
    player_ball->checkDists(balls);
    for(int i = 0; i < sizeof balls / sizeof balls[0]; i++)
    {
        //balls[i]->checkDists(balls);
        balls[i]->Update();
    }
    player_ball->Update();
}

void drawStrings(){
    glColor3d(0.2, 0.2, 0.2);
    ds.draw("  h   key to show/hide help",  GLUT_WINDOW_WIDTH, GLUT_WINDOW_HEIGHT, 1, 5);
    if(isShowingHelp){
        ds.draw("  Space  key to move player's ball",      GLUT_WINDOW_WIDTH, GLUT_WINDOW_HEIGHT, 1, 10);
    }
}

// it works when the flags are true;
void keyboardFlag(void)
{
    if(Key_UP)
    {
    }
    if(Key_DOWN)
    {
    }
    if(Key_LEFT)
    {
    }
    if(Key_RIGHT)
    {
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    
    keyboardFlag();
    Cam.updateCamera();
    // if you need it, activate it
    drawStrings();
    
    // put the staffs that you want to show here
    glNormal3f(0.0, 0.0, 1.0);
    
    pool.Update();
    updateBalls();
    
    glutSwapBuffers();
    glFlush();
    
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (float)w/h, 0.01, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    // here should have init func
    init();
    
    // this func updates the items that you wanna change, prob;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkeysDown);
    glutSpecialUpFunc(arrowKeysUp);
    
    glutMainLoop();
    return 0;
}
