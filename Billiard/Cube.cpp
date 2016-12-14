//
//  Cube.cpp
//  Billiard
//
//  Created by 安田圭佑 on 12/10/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Cube.h"

Cube::Cube()
{
    this->setPosition(0, 0, 0);
    this->setScale(1, 1, 1);
    this->setMaterial(1.0f,1.0f,1.0f,1.0f);
}

void Cube::setPosition(float x, float y, float z)
{
    this->position = Vector3(x, y, z);
}

Vector3 Cube::getPosition()
{
    return this->position;
}

void Cube::setScale(float x, float y, float z)
{
    this->scale = Vector3(x, y ,z);
}

void Cube::setMaterial(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    material[0] = r;
    material[1] = g;
    material[2] = b;
    material[3] = a;
}

void Cube::displayPosition()
{
    position.display_test();
}

void Cube::Update()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->material);

    // front
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z * 1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z * 1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z * 1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z * 1 + position.z);
    
    // left
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z *  1 + position.z);
    
    // right
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    
    // back
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    
    // top
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y *  1 + position.y, scale.z * -1 + position.z);
    
    // bottom
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z *  1 + position.z);
    glVertex3f(scale.x * -1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    glVertex3f(scale.x *  1 + position.x, scale.y * -1 + position.y, scale.z * -1 + position.z);
    
    glEnd();
    
    glPopMatrix();

    
}
