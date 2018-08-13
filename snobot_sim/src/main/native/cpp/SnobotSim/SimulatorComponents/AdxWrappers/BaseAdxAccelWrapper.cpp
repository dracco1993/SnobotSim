/*
 * BaseAdxAccelWrapper.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: PJ
 */

#include "SnobotSim/SimulatorComponents/AdxWrappers/BaseAdxAccelWrapper.h"

#include "SnobotSim/SensorActuatorRegistry.h"

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiAccelerometerWrapper.h"

BaseAdxAccelWrapper::BaseAdxAccelWrapper(int aBasePort, const std::shared_ptr<hal::ThreeAxisAccelerometerData>& aAccel) :
	frc::sim::lowfi::ADXLThreeAxisAccelerometerSim(*aAccel),
	mCachedAccel(aAccel)
{
	std::shared_ptr<WpiAccelerometerWrapper>  xWrapper(new WpiAccelerometerWrapper("DoesntMatter", GetXWrapper()));
	std::shared_ptr<WpiAccelerometerWrapper>  yWrapper(new WpiAccelerometerWrapper("DoesntMatter", GetYWrapper()));
	std::shared_ptr<WpiAccelerometerWrapper>  zWrapper(new WpiAccelerometerWrapper("DoesntMatter", GetZWrapper()));

    SensorActuatorRegistry::Get().Register(aBasePort + 0, xWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 1, yWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 2, zWrapper);
}

BaseAdxAccelWrapper::~BaseAdxAccelWrapper()
{
}
