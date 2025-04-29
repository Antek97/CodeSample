#pragma once

#include "CameraState.h"

class ThirdPersonCameraState : public CameraState
{
private:
	float tppDistanceFromTarget = 5.0f;

public:
	ThirdPersonCameraState()
	{
		cameraMode = TPP;
	}

	CameraMode GetCameraMode() { return cameraMode; }

	void SetMode() override
	{
		std::cout << "[Camera] Zmieniono tryb na TPP.\n";
		//... Dalsza nieistotna logika
	}

	void Update(float deltaTime) override
	{
		std::cout << "[Camera] Aktualizacja TPP z deltaTime: " << deltaTime << "\n";
		//... Dalsza nieistotna logika
		tppDistanceFromTarget -= 0.05f * deltaTime;
		if (tppDistanceFromTarget < 2.0f) tppDistanceFromTarget = 2.0f;
	}

	void MoveForward(float distance) override
	{
		std::cout << "[Camera] TPP MOVE" << distance << "\n";
		//... Dalsza nieistotna logika
	}
};