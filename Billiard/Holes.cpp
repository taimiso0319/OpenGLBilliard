//
//  Hole.cpp
//  Billiard
//
//  Created by 安田圭佑 on 12/15/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Holes.h"

Holes::Holes()
{
    for(int i = 0; i < 6; i++)
    {
        holes[i] = Cylinder();
        holes[i].setAngleX(0);
        holes[i].setRadius(0.1f);
        holes[i].setHeight(0.05f);
        holes[i].setMaterial(0, 0, 0, 1);
    }
    holes[0].setPosition(-0.88f, 2.2001f, -0.38f);
    holes[1].setPosition(-0.88f, 2.2001f, 1);
    holes[2].setPosition(-0.88f, 2.2001f, 2.28f);
    holes[3].setPosition(0.88f, 2.2001f, -0.38f);
    holes[4].setPosition(0.88f, 2.2001f, 1);
    holes[5].setPosition(0.88f, 2.2001f, 2.28f);
}

void Holes::Update()
{
    for(int i = 0; i < 6; i++)
    {
        holes[i].Update();
    }
}

void Holes::checkHit(Ball ** balls)
{
    Vector3 tempVec;
    for(int i = 0; i < 15; i++)
    {
        tempVec = balls[i]->getPosition();
        if(tempVec.x <= -0.78f)
        {
            if(tempVec.z <= -0.28f)
            {
               MoveBall(balls[i]);
            }
            else if(0.9f < tempVec.z && tempVec.z < 1.1f)
            {
               MoveBall(balls[i]);
            }
            else if(2.18f <= tempVec.z)
            {
               MoveBall(balls[i]);
            }
        }
        else if(0.78f <= tempVec.x)
        {
            if(tempVec.z <= -0.28f)
            {
                MoveBall(balls[i]);
            }
            else if(0.9f < tempVec.z && tempVec.z < 1.1f)
            {
                MoveBall(balls[i]);
            }
            else if(2.18f <= tempVec.z)
            {
                MoveBall(balls[i]);
            }
        }
    }
}

void Holes::MoveBall(Ball *ball)
{
    ball->setPosition(100, 100, 100);
}

