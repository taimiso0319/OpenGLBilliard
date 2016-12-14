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
#include "Vector3.h"
#include <GLUT/GLUT.h>
#include "Cube.h"

class Pool
{
private:
    Cube table;
    Cube left, right, front, back;
    Cube feet[4];
public:
    Pool();
    void Update();
};

#endif /* Pool_h */
