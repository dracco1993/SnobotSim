/*
 * AnalogSourceWrapper.cpp
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiAnalogOutWrapper.h"

#include "mockdata/AnalogOutData.h"

WpiAnalogOutWrapper::WpiAnalogOutWrapper(int aPort) :
        mHandle(aPort)
{
}

WpiAnalogOutWrapper::~WpiAnalogOutWrapper()
{
}

bool WpiAnalogOutWrapper::IsWrapperInitialized() const
{
    return HALSIM_GetAnalogOutInitialized(mHandle);
}

void WpiAnalogOutWrapper::SetVoltage(double aVoltage)
{
    HALSIM_SetAnalogOutVoltage(mHandle, aVoltage);
}

double WpiAnalogOutWrapper::GetVoltage()
{
    return HALSIM_GetAnalogOutVoltage(mHandle);
}
