//
//  Pool.cpp
//  Billiard
//
//  Created by 安田圭佑 on 11/14/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Pool.h"

Pool::Pool()
{
    this->setPosition(0, 1, 1);
    this->setScale(1, 0.75, 1.5);
}

Pool::Pool(float x, float y, float z)
{
    this->setPosition(x, y, z);
}

void Pool::setPosition(float x, float y, float z)
{
    position = Vector3(x,y,z);
}

void Pool::setScale(float x, float y, float z)
{
    scale = Vector3(x,y,z);
}

void Pool::Update()
{
    glPushMatrix();
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
    
    // front
    glBegin(GL_QUADS);
    glNormal3f(position.x + 0.0, position.y + 0.0, position.z + -1.0);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z * 1);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z * 1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z * 1);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z * 1);
    
    // left
    glNormal3f(position.x + 1.0, position.y + 0.0, position.z + 0.0);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z *  1);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z * -1);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z * -1);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z *  1);
    
    // right
    glNormal3f(position.x + -1.0, position.y + 0.0, position.z + 0.0);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z * -1);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z * -1);
    
    // back
    glNormal3f(position.x + 0.0, position.y + 0.0, position.z + 1.0);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z * -1);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z * -1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z * -1);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z * -1);
    
    // top
    glNormal3f(position.x + 0.0, position.y + 1.0, position.z + 0.0);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y *  1, scale.z * -1);
    glVertex3f(scale.x *  1, scale.y *  1, scale.z * -1);
    
    // bottom
    glNormal3f(position.x + 0.0, position.y + -1.0, position.z + 0.0);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z *  1);
    glVertex3f(scale.x * -1, scale.y * -1, scale.z * -1);
    glVertex3f(scale.x *  1, scale.y * -1, scale.z * -1);
    
    glEnd();
    
    glPopMatrix();
}
