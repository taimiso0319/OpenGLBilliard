//
//  Cylinder.h
//  Billiard
//
//  Created by 安田圭佑 on 12/13/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#ifndef Cylinder_h
#define Cylinder_h

#include <stdio.h>
#include "Vector3.h"
#include <GLUT/GLUT.h>

class Cylinder{
private:
    Vector3 position;
    float angleX;
    float angleZ;
    float radius;
    float height;
    int sides;
    GLfloat material[4];
    
public:
    Cylinder();
    void setPosition(float x, float y, float z);
    void setPosition(Vector3 vec);
    Vector3 getPosition();
    void RotateRight();
    void RotateLeft();
    void setAngleX(float angle);
    void setAngleZ(float angle);
    void setSides(int sides);
    void setRadius(float rad);
    void setHeight(float height);
    void setMaterial(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void Update();
    void displayPosition();
};

#endif /* Cylinder_h */
