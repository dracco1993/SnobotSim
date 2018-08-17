/*
 * AnalogSourceWrapper.h
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIANALOGOUTWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIANALOGOUTWRAPPER_H_

#include "SnobotSim/ModuleWrapper/Interfaces/IAnalogOutWrapper.h"
#include "lowfisim/SimulatorComponentBase.h"

class WpiAnalogOutWrapper : public frc::sim::lowfi::SimulatorComponentBase, public IAnalogOutWrapper
{
public:
    explicit WpiAnalogOutWrapper(int aPort);
    virtual ~WpiAnalogOutWrapper();

    bool IsWrapperInitialized() const override;

    void SetVoltage(double aVoltage) override;
    double GetVoltage() override;

protected:
    const int mHandle;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIANALOGOUTWRAPPER_H_
