//
//  Cylinder.cpp
//  Billiard
//
//  Created by 安田圭佑 on 12/13/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Cylinder.h"

Cylinder::Cylinder()
{
    this->setPosition(0, 0, 0);
    this->setAngleX(90);
    this->setAngleZ(0);
    this->setSides(48);
    this->setRadius(0.05f);
    this->setHeight(1);
    this->setMaterial(1.0f,1.0f,1.0f,1.0f);
}

void Cylinder::setAngleX(float angle)
{
    angleX = angle;
}

void Cylinder::setAngleZ(float angle)
{
    angleZ = angle;
}

void Cylinder::setPosition(float x, float y, float z)
{
    this->position = Vector3(x, y, z);
}

void Cylinder::setPosition(Vector3 vec)
{
    this->position = vec;
}

Vector3 Cylinder::getPosition()
{
    return this->position;
}

void Cylinder::setSides(int sides)
{
    this->sides = sides;
}

void Cylinder::setRadius(float rad)
{
    this->radius = rad;
}

void Cylinder::setHeight(float height)
{
    this->height = height;
}

void Cylinder::RotateRight()
{
    angleZ+=2;
}

void Cylinder::RotateLeft()
{
    angleZ-=2;
}

void Cylinder::setMaterial(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    material[0] = r;
    material[1] = g;
    material[2] = b;
    material[3] = a;
}

void Cylinder::displayPosition()
{
    position.display_test();
}

void Cylinder::Update()
{
    glPushMatrix();
    glTranslatef(position.x, position.y-1.5f, position.z);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->material);
    
    //top
    glNormal3b(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for(double i = 0; i < sides; i++)
    {
        double t = PI*2/sides * (double)i;
        glVertex3d(radius * cos(t), height, radius * sin(t));
    }
    glEnd();
    
    //side
    glBegin(GL_QUAD_STRIP);
    for(double i=0;i<=sides;i=i+1){
        double t = i*2*PI/sides;
        glNormal3f((GLfloat)cos(t),0.0,(GLfloat)sin(t));
        glVertex3f((GLfloat)(radius*cos(t)),-height,(GLfloat)(radius*sin(t)));
        glVertex3f((GLfloat)(radius*cos(t)),height,(GLfloat)(radius*sin(t)));
    }
    glEnd();
 
    //bottom
    glNormal3d(0.0, -1.0, 0.0);
    glBegin(GL_POLYGON);
    for(double i = sides; i >= 0; --i) {
        double t = PI*2/sides * (double)i;
        glVertex3d(radius * cos(t), -height, radius * sin(t));
    }
    glEnd();
    
    glPopMatrix();
    
    
}
