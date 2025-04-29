#pragma once

#include "CameraState.h"

class FirstPersonCameraState : public CameraState
{
private:
	float fppSpecificValue = 0.0f;

public:
	FirstPersonCameraState()
	{
		cameraMode = FPP;
	};

	void SetMode() override
	{
		std::cout << "[Camera] Zmieniono tryb na FPP.\n";
		//... Dalsza nieistotna logika
	}

	void Update(float deltaTime) override
	{
		std::cout << "[Camera] Aktualizacja FPP z deltaTime: " << deltaTime << "\n";
		//... Dalsza nieistotna logika
		float fppHeadBobTimer = 0.0f;
		float fppHeadBobIntensity = 0;

		fppHeadBobTimer += fppHeadBobIntensity * deltaTime;

		constexpr float NUM_PI = 3.14159265f;
		if (fppHeadBobTimer > 2 * NUM_PI)
			fppHeadBobTimer -= 2 * NUM_PI;

		float headBobOffset = std::sin(fppHeadBobTimer) * 0.05f;
	}

	void MoveForward(float distance) override
	{
		std::cout << "[Camera] FPP MOVE" << distance << "\n";
		//... Dalsza nieistotna logika
	}
};