/*
 * WpiAccelerometerWrapper.h
 *
 *  Created on: Aug 12, 2018
 *      Author: PJ
 */

#ifndef SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_
#define SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_

#include "SnobotSim/ModuleWrapper/AModuleWrapper.h"
#include "SnobotSim/ModuleWrapper/Interfaces/IAccelerometerWrapper.h"

class WpiAccelerometerWrapper : public AModuleWrapper, public IAccelerometerWrapper
{
public:
	WpiAccelerometerWrapper(const std::string& aName, frc::sim::lowfi::AccelerometerSim& accelerometer);
	virtual ~WpiAccelerometerWrapper();

	  virtual double GetAcceleration();
	  virtual void SetAcceleration(double acceleration);

protected:
	  frc::sim::lowfi::AccelerometerSim& mAccelerometer;
};

#endif /* SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIACCELEROMETERWRAPPER_H_ */
