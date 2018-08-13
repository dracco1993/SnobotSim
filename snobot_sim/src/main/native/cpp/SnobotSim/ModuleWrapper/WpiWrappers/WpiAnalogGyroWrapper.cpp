/*
 * AnalogGyrWrapper.cpp
 *
 *  Created on: May 5, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiAnalogGyroWrapper.h"

#include "MockData/AnalogGyroData.h"

WpiAnalogGyroWrapper::WpiAnalogGyroWrapper(int aPort) :
        AModuleWrapper("Analog Gyro"),
		frc::sim::lowfi::WpiAnalogGyroSim(aPort)
{
}

WpiAnalogGyroWrapper::~WpiAnalogGyroWrapper()
{
}

void WpiAnalogGyroWrapper::SetAngle(double aAngle)
{
	frc::sim::lowfi::WpiAnalogGyroSim::SetAngle(aAngle);
}

double WpiAnalogGyroWrapper::GetAngle()
{
    return frc::sim::lowfi::WpiAnalogGyroSim::GetAngle();
}
