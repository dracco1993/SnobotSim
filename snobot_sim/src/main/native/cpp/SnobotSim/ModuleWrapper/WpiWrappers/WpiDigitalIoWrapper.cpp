/*
 * DigitalSourceWrapper.cpp
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiDigitalIoWrapper.h"

#include "mockdata/DIOData.h"

WpiDigitalIoWrapper::WpiDigitalIoWrapper(int aPort) :
        mHandle(aPort)
{
}

WpiDigitalIoWrapper::~WpiDigitalIoWrapper()
{
}

bool WpiDigitalIoWrapper::IsWrapperInitialized() const
{
    return HALSIM_GetDIOInitialized(mHandle);
}

bool WpiDigitalIoWrapper::Get()
{
    return HALSIM_GetDIOValue(mHandle);
}

void WpiDigitalIoWrapper::Set(bool aState)
{
    HALSIM_SetDIOValue(mHandle, aState);
}
