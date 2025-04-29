#pragma once

#include <iostream>
#include <numbers>

enum CameraMode
{
    FPP,
    TPP,
    ISOMETRIC,
};

class CameraState
{
protected:
	CameraMode cameraMode = FPP;

public:
	virtual void SetMode() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void MoveForward(float distanceX) = 0;

	CameraMode GetCameraMode() { return cameraMode; }
};