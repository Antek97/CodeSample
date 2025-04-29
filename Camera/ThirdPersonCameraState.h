#pragma once

#include "CameraState.h"

class IsometricPersonCameraState : public CameraState
{
private:
	float isoAngle = 45.0f;

public:
	IsometricPersonCameraState()
	{
		cameraMode = ISOMETRIC;
	}

	CameraMode GetCameraMode() { return cameraMode; }

	void SetMode() override
	{
		std::cout << "[Camera] Zmieniono tryb na Izometryczny.\n";
		//... Dalsza nieistotna logika
	}

	void Update(float deltaTime) override
	{
		std::cout << "[Camera] Aktualizacja Izometryczna z deltaTime: " << deltaTime << "\n";
		//... Dalsza nieistotna logika
		isoAngle += 0.02f * deltaTime;
	}

	void MoveForward(float distance) override
	{
		std::cout << "[Camera] ISO MOVE" << distance << "\n";
		//... Dalsza nieistotna logika
	}
};