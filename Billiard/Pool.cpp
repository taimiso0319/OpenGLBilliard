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
    table = Cube();
    table.setPosition(0, 0.5f, 1);
    table.setScale(1, 0.25f, 1.5f);
    table.setMaterial(0.4f, 0.8f, 0.4f, 1.0f);
    
    right = Cube();
    right.setPosition(1, 0.75f, 1);
    right.setScale(0.1f, 0.1f, 1.5f);
    right.setMaterial(0.7f, 0.7f, 0, 1);
    
    left = Cube();
    left.setPosition(-1, 0.75f, 1);
    left.setScale(0.1f, 0.1f, 1.5f);
    left.setMaterial(0.7f, 0.7f, 0, 1);
    
    front = Cube();
    front.setPosition(0, 0.75f, -0.5f);
    front.setScale(1.1f, 0.1f, 0.1f);
    front.setMaterial(0.7f, 0.7f, 0, 1);
    
    back = Cube();
    back.setPosition(0, 0.75f, 2.5f);
    back.setScale(1, 0.1f, 0.1f);
    back.setMaterial(0.7f, 0.7f, 0, 1);
}

void Pool::Update()
{
    table.Update();
    right.Update();
    left.Update();
    front.Update();
    back.Update();
}
