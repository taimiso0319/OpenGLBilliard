//
//  Pool.cpp
//  Billiard
//
//  Created by 安田圭佑 on 11/12/16.
//  Copyright © 2016 Keisuke Yasuda. All rights reserved.
//

#include "Pool.h"

Pool::Pool()
{
    table = Cube();
    table.setPosition(0, 0.6f, 1);
    table.setScale(1, 0.15f, 1.5f);
    table.setMaterial(0.4f, 0.8f, 0.4f, 1.0f);
    
    right = Cube();
    right.setPosition(1, 0.75f, 1);
    right.setScale(0.1f, 0.1f, 1.5f);
    right.setMaterial(0.7f, 0.7f, 0, 1);
    rightf = 0.9f;
    
    left = Cube();
    left.setPosition(-1, 0.75f, 1);
    left.setScale(0.1f, 0.1f, 1.5f);
    left.setMaterial(0.7f, 0.7f, 0, 1);
    leftf = -0.8f;
    
    front = Cube();
    front.setPosition(0, 0.75f, -0.5f);
    front.setScale(1.1f, 0.1f, 0.1f);
    front.setMaterial(0.7f, 0.7f, 0, 1);
    frontf = -0.3f;
    
    back = Cube();
    back.setPosition(0, 0.75f, 2.4f);
    back.setScale(1, 0.1f, 0.1f);
    back.setMaterial(0.7f, 0.7f, 0, 1);
    backf = 2.3f;
}

void Pool::Update()
{
    table.Update();
    //table.displayPosition();
    right.Update();
    left.Update();
    front.Update();
    back.Update();
}
