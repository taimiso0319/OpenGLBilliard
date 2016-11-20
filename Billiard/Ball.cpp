//
//  Ball.cpp
//  Billiard
//
//  Created by 安田圭佑 on 11/10/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Ball.h"
#include <math.h>

Ball::Ball()
{
    this->setPosition(0, 0, 0);
    this->setColor(1.0f, 1.0f, 1.0f, 1.0f);
    this->setForward(0, 0, -1);
    this->setDirVec(forward);
    radian = 0.05f;
    speed = 0.0f;
}

Ball::Ball(float init_x, float init_y, float init_z, float init_rad)
{
    this->setPosition(init_x, init_y, init_z);
    this->setColor(1.0f, 1.0f, 1.0f, 1.0f);
    this->setForward(0, 0, -1);
    this->setDirVec(forward);
    radian = init_rad;
    speed = 0.0f;
}

void Ball::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    mat[0] = r;
    mat[1] = g;
    mat[2] = b;
    mat[3] = a;
}

void Ball::setSpeed(float s)
{
    speed = s;
}

float Ball::getSpeed()
{
    return speed;
}

Vector3 Ball::getPosition()
{
    return this->position;
}

void Ball::setDirVec(Vector3 vec)
{
    dirVec = vec;
}

void Ball::setPosition(float x, float y, float z)
{
    this->position = *new Vector3(x,y,z);
}

void Ball::setForward(float x, float y, float z)
{
    forward = *new Vector3(x, y, z);
}

void Ball::setForward(Vector3 vec)
{
    forward = vec;
}

void Ball::moveForward()
{
    position = position + forward * speed;
}

void Ball::moveTo(Vector3 vec)
{
    position = position + vec * speed;
}

void Ball::updateOtherBallsDist(Ball **balls)
{
    Vector3 playerBallPos = this->getPosition();
    for(int i = 0; i < sizeof balls / sizeof balls[0]; i++)
    {
        Vector3 targetBallPos = balls[i]->getPosition();
        float tempX = targetBallPos.x - playerBallPos.x;
        float tempZ = targetBallPos.z - playerBallPos.z;
        float holdist = tempX * tempX + tempZ * tempZ;
        other_balls_dist[i] = holdist;
    }
}

void Ball::Update()
{
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    
    if(speed > 0)
    {
        speed -= 0.002f;
    }else if(speed < 0)
    {
        speed = 0;
    }
    
    moveTo(dirVec);
    
    glPushMatrix();
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
    glutSolidSphere(radian, 32, 16);
    glPopMatrix();
}
