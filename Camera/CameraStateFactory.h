#pragma once

#include "CameraState.h"
#include "ICameraStateFactory.h"

#include "FirstPersonCameraState.h"
#include "ThirdPersonCameraState.h"
#include "IsometricPersonCameraState.h"

#include <vector>
#include <memory>

class CameraStateFactory : public ICameraStateFactory
{
public:
	std::vector<std::unique_ptr<CameraState>> CreateAllStates() override
	{
		std::vector<std::unique_ptr<CameraState>> result;

		result.push_back(std::make_unique<FirstPersonCameraState>());
		result.push_back(std::make_unique<ThirdPersonCameraState>());
		result.push_back(std::make_unique<IsometricPersonCameraState>());

		return result;
	}
};