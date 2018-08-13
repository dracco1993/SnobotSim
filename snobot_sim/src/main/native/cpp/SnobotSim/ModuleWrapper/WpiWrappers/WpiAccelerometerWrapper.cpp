/*
 * WpiAccelerometerWrapper.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: PJ
 */

#include <SnobotSim/ModuleWrapper/WpiWrappers/WpiAccelerometerWrapper.h>
#include <iostream>

WpiAccelerometerWrapper::WpiAccelerometerWrapper(const std::string& aName, frc::sim::lowfi::AccelerometerSim& accelerometer) :
	AModuleWrapper(aName),
	mAccelerometer(accelerometer)
{

}

WpiAccelerometerWrapper::~WpiAccelerometerWrapper() {

}


double WpiAccelerometerWrapper::GetAcceleration()
{
	std::cout << "GetAcceleration" << std::endl;
	return mAccelerometer.GetAcceleration();
}

void WpiAccelerometerWrapper::SetAcceleration(double acceleration)
{
	std::cout << "SetAcceleration" << std::endl;
	mAccelerometer.SetAcceleration(acceleration);
}
