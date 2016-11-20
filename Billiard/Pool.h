//
//  Pool.hpp
//  Billiard
//
//  Created by 安田圭佑 on 11/14/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#ifndef Pool_h
#define Pool_h

#include <stdio.h>
#include "Quaternion.h"
#include "Vector3.h"
#include <GLUT/GLUT.h>

class Pool
{
private:
    GLfloat mat[4] = {0.4f, 0.8f, 0.4f, 1.0f};
    Vector3 position;
    Vector3 scale;
public:
    Pool();
    Pool(float init_x, float init_y, float init_z);
    void setPosition(float x, float y, float z);
    void setScale(float x, float y, float z);
    void Update();
};

#endif /* Pool_h */
