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
    this->setDirVec(this->forward);
    this->radian = 0.05f;
    this->speed = 0.0f;
}

Ball::Ball(float init_x, float init_y, float init_z, float init_rad)
{
    this->setPosition(init_x, init_y, init_z);
    this->setColor(1.0f, 1.0f, 1.0f, 1.0f);
    this->setForward(0, 0, -1);
    this->setDirVec(this->forward);
    this->radian = init_rad;
    this->speed = 0.0f;
}

float Ball::getRadian()
{
    return this->radian;
}

void Ball::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    this->mat[0] = r;
    this->mat[1] = g;
    this->mat[2] = b;
    this->mat[3] = a;
}

void Ball::setSpeed(float s)
{
    this->speed = s;
}

float Ball::getSpeed()
{
    return this->speed;
}

Vector3 Ball::getPosition()
{
    return this->position;
}

void Ball::setDirVec(Vector3 vec)
{
    this->dirVec = vec;
}

void Ball::setPosition(float x, float y, float z)
{
    this->position = *new Vector3(x,y,z);
}

void Ball::setForward(float x, float y, float z)
{
    this->forward = *new Vector3(x, y, z);
}

void Ball::setForward(Vector3 vec)
{
    this->forward = vec;
}

void Ball::moveForward()
{
    this->position = this->position + this->forward * this->speed;
}

void Ball::moveTo(Vector3 vec)
{
    this->position = this->position + vec * this->speed;
}


void Ball::checkDists(Ball **balls)
{
    Vector3 thisBallPos = this->position;
    for(int i = 0; i < sizeof balls / sizeof balls[0]; i++)
    {
        Vector3 targetBallPos = balls[i]->getPosition();
        float tempX = targetBallPos.x - thisBallPos.x;
        float tempY = targetBallPos.y - thisBallPos.y;
        float tempZ = targetBallPos.z - thisBallPos.z;
        float dist = tempX * tempX + tempY * tempY + tempZ * tempZ;
        float powRad = this->radian * this->radian + balls[i]->getRadian() * balls[i]->getRadian();
        if((dist - powRad) <= 0)
        {
            hitBall(balls[i]);
        }
    }
}

void Ball::hitBall(Ball * targetBall)
{
    Vector3 toTargetVector = targetBall->getPosition() - this->position;
    toTargetVector.normalize();
    float angle = getAngleOfVectors(toTargetVector);
    float tempSpeed = this->speed * angle / 90;
    targetBall->setSpeed(tempSpeed);
    targetBall->setDirVec(toTargetVector);
    this->setSpeed(this->speed - tempSpeed);
    Vector3 tempDir = crossProduct(toTargetVector);
    tempDir.normalize();
    this->setDirVec(tempDir);
    
}

float Ball::getVectorLength(Vector3 vec)
{
    return powf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z), 0.5);
}

float Ball::dotProduct(Vector3 targetVec)
{
    return this->dirVec.x * targetVec.x + this->dirVec.y * targetVec.y + this->dirVec.z * targetVec.z;
}

Vector3 Ball::crossProduct(Vector3 targetVec)
{
    return Vector3(this->dirVec.y * targetVec.z - this->dirVec.z * targetVec.y,
                   this->dirVec.z * targetVec.x - this->dirVec.x * targetVec.z,
                   this->dirVec.x * targetVec.y - this->dirVec.y * targetVec.x
                   );
}

float Ball::getAngleOfVectors(Vector3 targetVec)
{
    float tempLengthThis = getVectorLength(this->dirVec);
    float tempLengthTarget = getVectorLength(targetVec);
    
    float cosSita = dotProduct(targetVec) / (tempLengthThis * tempLengthTarget);
    
    float sita = acos(cosSita);
    sita = sita * 180.0 / PI;
    
    return sita;
}

void Ball::Update()
{
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    
    if(this->speed > 0)
    {
        this->speed -= 0.002f;
    }else if(this->speed < 0)
    {
        this->speed = 0;
    }
    
    moveTo(this->dirVec);
    
    glPushMatrix();
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->mat);
    glutSolidSphere(this->radian, 32, 16);
    glPopMatrix();
}
