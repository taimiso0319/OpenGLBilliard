//
//  Ball.h
//  Billiard
//
//  Created by 安田圭佑 on 11/10/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#ifndef Ball_h
#define Ball_h

#include <stdio.h>
#include "Vector3.h"
#include <GLUT/glut.h>

class Ball{
private:
    Vector3 position;
    Vector3 forward;
    Vector3 dirVec;
    Vector3 speedVec;
    float speed;
    float radian;
    GLfloat mat[4];
    double other_balls_dist[15];
public:
    Ball();
    Ball(float init_x, float init_y, float init_z, float init_rad);
    void Update();
    Vector3 getPosition();
    void setSpeed(float s);
    void setDirVec(Vector3 vec);
    float getSpeed();
    float getRadian();
    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setPosition(float x, float y, float z);
    void setPosition(Vector3 vec);
    void setForward(float x, float y, float z);
    void setForward(Vector3 vec);
    void moveForward();
    void moveTo(Vector3 vec);
    void checkDists(Ball * balls[]);
    void hitBall(Ball * targetBall);
};

#endif /* Ball_h */
