/*
 * WpiSolenoidWrapper.cpp
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/WpiWrappers/WpiSolenoidWrapper.h"

#include "mockdata/PCMData.h"

WpiSolenoidWrapper::WpiSolenoidWrapper(int aPort) :
        mModule(aPort / 8),
        mChannel(aPort % 8)
{
}

WpiSolenoidWrapper::~WpiSolenoidWrapper()
{
}

bool WpiSolenoidWrapper::IsWrapperInitialized() const
{
    return HALSIM_GetPCMSolenoidInitialized(mModule, mChannel);
}

void WpiSolenoidWrapper::SetState(bool aOn)
{
    HALSIM_SetPCMSolenoidOutput(mModule, mChannel, aOn);
}

bool WpiSolenoidWrapper::GetState()
{
    return HALSIM_GetPCMSolenoidOutput(mModule, mChannel);
}
