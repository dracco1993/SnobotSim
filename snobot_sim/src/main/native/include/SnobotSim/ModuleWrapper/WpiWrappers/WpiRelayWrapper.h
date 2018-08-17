/*
 * RelayWrapper.h
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIRELAYWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIRELAYWRAPPER_H_

#include "SnobotSim/ModuleWrapper/Interfaces/IRelayWrapper.h"
#include "lowfisim/SimulatorComponentBase.h"

class WpiRelayWrapper : public frc::sim::lowfi::SimulatorComponentBase, public IRelayWrapper
{
public:
    explicit WpiRelayWrapper(int aPort);
    virtual ~WpiRelayWrapper();

    bool IsWrapperInitialized() const override;

    bool GetRelayForwards() override;
    bool GetRelayReverse() override;

protected:
    const int mHandle;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIRELAYWRAPPER_H_
