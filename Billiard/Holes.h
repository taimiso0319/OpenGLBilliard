//
//  Hole.h
//  Billiard
//
//  Created by 安田圭佑 on 12/15/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#ifndef Hole_hpp
#define Hole_hpp

#include <stdio.h>
#include "Vector3.h"
#include "Cylinder.h"
#include "Ball.h"

class Holes
{
private:
    Cylinder holes[6];
public:
    Holes();
    void checkHit(Ball ** balls);
    void Update();
    void MoveBall(Ball * ball);
};

#endif /* Hole_h */
