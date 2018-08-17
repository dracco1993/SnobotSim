/*
 * DigitalSourceWrapper.h
 *
 *  Created on: May 3, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIDIGITALIOWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIDIGITALIOWRAPPER_H_

#include "SnobotSim/ExportHelper.h"
#include "SnobotSim/ModuleWrapper/Interfaces/IDigitalIoWrapper.h"
#include "lowfisim/SimulatorComponentBase.h"

class EXPORT_ WpiDigitalIoWrapper : public frc::sim::lowfi::SimulatorComponentBase, public IDigitalIoWrapper
{
public:
    explicit WpiDigitalIoWrapper(int aPort);
    virtual ~WpiDigitalIoWrapper();

    bool IsWrapperInitialized() const override;

    bool Get() override;
    void Set(bool aState) override;

protected:
    const int mHandle;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIDIGITALIOWRAPPER_H_
