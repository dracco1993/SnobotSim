/*
 * SolenoidWrapper.h
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPISOLENOIDWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPISOLENOIDWRAPPER_H_

#include "SnobotSim/ModuleWrapper/Interfaces/ISolenoidWrapper.h"
#include "lowfisim/SimulatorComponentBase.h"

class WpiSolenoidWrapper : public frc::sim::lowfi::SimulatorComponentBase, public ISolenoidWrapper
{
public:
    explicit WpiSolenoidWrapper(int aPort);
    virtual ~WpiSolenoidWrapper();

    bool IsWrapperInitialized() const override;

    void SetState(bool aOn) override;

    bool GetState() override;

protected:
    const int mModule;
    const int mChannel;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPISOLENOIDWRAPPER_H_
