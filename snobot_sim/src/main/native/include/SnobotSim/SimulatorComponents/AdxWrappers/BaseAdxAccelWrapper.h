/*
 * BaseAdxAccelWrapper.h
 *
 *  Created on: Nov 23, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_ADXWRAPPERS_BASEADXACCELWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_ADXWRAPPERS_BASEADXACCELWRAPPER_H_

#include <memory>

#include "SnobotSim/ModuleWrapper/AModuleWrapper.h"
#include "SnobotSim/ModuleWrapper/Interfaces/IAccelerometerWrapper.h"
#include "lowfisim/wpisimulators/ADXLThreeAxisAccelerometerSim.h"

class BaseAdxAccelWrapper : public frc::sim::lowfi::ADXLThreeAxisAccelerometerSim
{
public:
    BaseAdxAccelWrapper(int aBasePort, const std::shared_ptr<hal::ThreeAxisAccelerometerData>& aAccel);
    virtual ~BaseAdxAccelWrapper();

protected:
    std::shared_ptr<hal::ThreeAxisAccelerometerData> mCachedAccel;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_ADXWRAPPERS_BASEADXACCELWRAPPER_H_
