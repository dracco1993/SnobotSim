/*
 * RelayWrapper.cpp
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiRelayWrapper.h"

#include "mockdata/RelayData.h"

WpiRelayWrapper::WpiRelayWrapper(int aPort) :
        mHandle(aPort)
{
}

WpiRelayWrapper::~WpiRelayWrapper()
{
}

bool WpiRelayWrapper::IsWrapperInitialized() const
{
    return HALSIM_GetRelayInitializedReverse(mHandle);
}

bool WpiRelayWrapper::GetRelayForwards()
{
    return HALSIM_GetRelayForward(mHandle);
}

bool WpiRelayWrapper::GetRelayReverse()
{
    return HALSIM_GetRelayReverse(mHandle);
}
