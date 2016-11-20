//
//  Camera.h
//  MP2C
//
//  Created by 安田圭佑 on 3/4/16.
//  Copyright © 2016 安田圭佑. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include "Quaternion.h"
#include <GLUT/GLUT.h>

class Camera
{
private:
    // Elements for Camera class
    Quaternion rotation;
    Vector3 position;
    Vector3 lookAt;
    Vector3 up;
    
public:
    Camera(); // Initialize
    void roll(float r); // Rotate function to roll
    void pitch(float r); // Rotate function to pitch
    void updateVectors(); // Update function for vectors
    void updateCamera();
    Quaternion getRotation();
    
    Vector3 getPosition();
    void    setPosition(Vector3 vec);
    void    setPosition(float x, float y, float z);
    
    Vector3 getLookAt();
    void    setLookAt(Vector3 vec);
    void    setLookAt(float x, float y, float z);
    
    Vector3 getUpVector();
    void    setUpVector(Vector3 vec);
    void    setUpVector(float x, float y, float z);
};

#endif /* Camera_h */
