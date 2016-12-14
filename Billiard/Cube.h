//
//  Cube.h
//  Billiard
//
//  Created by 安田圭佑 on 12/10/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#ifndef Cube_h
#define Cube_h

#include <stdio.h>
#include "Vector3.h"
#include <GLUT/GLUT.h>

class Cube{
private:
    Vector3 position;
    Vector3 scale;
    GLfloat material[4];
    
public:
    Cube();
    void setPosition(float x, float y, float z);
    Vector3 getPosition();
    void setScale(float x, float y, float z);
    void setMaterial(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void Update();
    void displayPosition();
};

#endif /* Cube_h */
