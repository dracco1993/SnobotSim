/*
 * WpiAccelerometerWrapper.cpp
 *
 *  Created on: Aug 12, 2018
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiAccelerometerWrapper.h"

WpiAccelerometerWrapper::WpiAccelerometerWrapper(const std::string& aName, frc::sim::lowfi::AccelerometerSim& accelerometer) :
        mAccelerometer(accelerometer)
{
}

WpiAccelerometerWrapper::~WpiAccelerometerWrapper()
{
}

double WpiAccelerometerWrapper::GetAcceleration()
{
    return mAccelerometer.GetAcceleration();
}

void WpiAccelerometerWrapper::SetAcceleration(double acceleration)
{
    mAccelerometer.SetAcceleration(acceleration);
}
