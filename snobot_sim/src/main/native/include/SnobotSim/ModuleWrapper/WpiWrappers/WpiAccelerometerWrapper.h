/*
 * WpiAccelerometerWrapper.h
 *
 *  Created on: Aug 12, 2018
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_

#include <string>

#include "lowfisim/SimpleAccelerometerSim.h"
#include "lowfisim/SimulatorComponentBase.h"

class WpiAccelerometerWrapper : public frc::sim::lowfi::SimulatorComponentBase, public frc::sim::lowfi::AccelerometerSim
{
public:
    WpiAccelerometerWrapper(const std::string& aName, frc::sim::lowfi::AccelerometerSim& accelerometer);
    virtual ~WpiAccelerometerWrapper();

    virtual double GetAcceleration();
    virtual void SetAcceleration(double acceleration);

protected:
    frc::sim::lowfi::AccelerometerSim& mAccelerometer;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_
