#pragma once

#include "CameraState.h"

#include <vector>
#include <memory>

class ICameraStateFactory
{
public:
	virtual std::vector<std::unique_ptr<CameraState>> CreateAllStates() = 0;
	virtual ~ICameraStateFactory() = default;
};