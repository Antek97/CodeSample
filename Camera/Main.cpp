#pragma once

#include "Camera.h"
#include "CameraStateFactory.h"

int main()
{
	CameraStateFactory cameraStateFactory;
	Camera camera(cameraStateFactory);

	camera.SetZoom(0.1f);

	camera.SetMode(FPP);
	camera.Update(0.016f);
	camera.MoveForward(5.0f);

	camera.SetMode(TPP);
	camera.Update(0.016f);
	camera.MoveForward(10.0f);

	camera.SetMode(ISOMETRIC);
	camera.Update(0.016f);
	camera.MoveForward(3.0f);

	return 0;
}
