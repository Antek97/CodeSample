#pragma once

#include "CameraState.h"
#include "ICameraStateFactory.h"

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

struct Vector3
{
	Vector3() : x(0), y(0), z(0) {}
	float x, y, z;
};

class Camera
{
private:
	std::vector<std::unique_ptr<CameraState>> cameraStates;
	CameraState* currentCameraState = nullptr;

	Vector3 position;
	Vector3 rotation;

	float zoomLevel = 1.0f;

public:
	Camera(ICameraStateFactory& cameraFactory)
	{
		cameraStates = cameraFactory.CreateAllStates();

		if (!cameraStates.empty())
		{
			currentCameraState = cameraStates[0].get();
			currentCameraState->SetMode();
		}

		assert(currentCameraState != nullptr && "currentCameraState cannot be nullptr");
	}

	void SetMode(CameraMode mode)
	{
		if (currentCameraState && currentCameraState->GetCameraMode() == mode) return;

		for (const auto& state : cameraStates)
		{
			if (state->GetCameraMode() == mode)
			{
				currentCameraState = state.get();
				currentCameraState->SetMode();
				return;
			}
		}

		std::cout << "[Camera] Nieznany tryb.\n";
	}

	void Update(float deltaTime) const
	{
		if (!currentCameraState) return;
		currentCameraState->Update(deltaTime);
	}

	void MoveForward(float distance) const
	{
		if (!currentCameraState) return;
		currentCameraState->MoveForward(distance);
	}

	void SetZoom(float amount)
	{
		zoomLevel += amount;
		std::cout << "[Camera] Zoom: " << zoomLevel << "\n";
	}

	void SetPosition(Vector3 newPosition)
	{
		position = newPosition;
		std::cout << "[Camera] (" << position.x << ", " << position.y << ", " << position.z << ")\n";
	}

	~Camera() = default;
};
