/*
 * AnalogSourceWrapper.cpp
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiAnalogInWrapper.h"

#include "mockdata/AnalogInData.h"

WpiAnalogInWrapper::WpiAnalogInWrapper(int aPort) :
        mHandle(aPort)
{
}

WpiAnalogInWrapper::~WpiAnalogInWrapper()
{
}

bool WpiAnalogInWrapper::IsWrapperInitialized() const
{
    return HALSIM_GetAnalogInInitialized(mHandle);
}

void WpiAnalogInWrapper::SetVoltage(double aVoltage)
{
    HALSIM_SetAnalogInVoltage(mHandle, aVoltage);
}

double WpiAnalogInWrapper::GetVoltage()
{
    return HALSIM_GetAnalogInVoltage(mHandle);
}
