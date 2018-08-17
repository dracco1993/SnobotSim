/*
 * ISolenoidWrapper.h
 *
 *  Created on: Jun 30, 2018
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_INTERFACES_ISOLENOIDWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_INTERFACES_ISOLENOIDWRAPPER_H_

#include "lowfisim/SimulatorComponent.h"

class ISolenoidWrapper : public virtual frc::sim::lowfi::SimulatorComponent
{
public:
    virtual void SetState(bool aOn) = 0;

    virtual bool GetState() = 0;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_INTERFACES_ISOLENOIDWRAPPER_H_
