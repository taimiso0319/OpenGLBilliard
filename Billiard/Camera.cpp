//
//  Camera.cpp
//  MP2C
//
//  Created by 安田圭佑 on 3/4/16.
//  Copyright © 2016 安田圭佑. All rights reserved.
//

/* Some of this class functions referenced http://content.gpwiki.org/OpenGL:Tutorials:Using_Quaternions_to_represent_rotation#Rotating_vectors
   and http://www.cprogramming.com/tutorial/3d/quaternions.html */

#include "Camera.h"
/* Initialize a Camera class */
Camera::Camera()
{
    position = Vector3(0, 2,2);
    lookAt = Vector3(0, 0, 0);
    up = Vector3(0,1,0);
}

/* Calculate and update lookAt and up vectors. */
void Camera::updateCamera()
{
    gluLookAt(position.x, position.y, position.z,
              lookAt.x,   lookAt.y,   lookAt.z,
              up.x,       up.y,       up.z);
}

Vector3 Camera::getPosition()
{
    return position;
}

void Camera::setPosition(Vector3 vec)
{
    position = vec;
}

void Camera::setPosition(float x, float y, float z)
{
    position = Vector3(x, y, z);
}

Vector3 Camera::getLookAt()
{
    return lookAt;
}

void Camera::setLookAt(Vector3 vec)
{
    lookAt = vec;
}

void Camera::setLookAt(float x, float y, float z)
{
    lookAt = Vector3(x, y, z);
}

Vector3 Camera::getUpVector()
{
    return up;
}

void Camera::setUpVector(Vector3 vec)
{
    up = vec;
}

void Camera::setUpVector(float x, float y, float z)
{
    up = Vector3(x, y, z);
}
