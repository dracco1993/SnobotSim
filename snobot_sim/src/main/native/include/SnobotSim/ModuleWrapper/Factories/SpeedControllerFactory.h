/*
 * SpeedControllerFactory.h
 *
 *  Created on: Jun 30, 2018
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_FACTORIES_SPEEDCONTROLLERFACTORY_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_FACTORIES_SPEEDCONTROLLERFACTORY_H_

#include <string>

#include "SnobotSim/ExportHelper.h"

class EXPORT_ SpeedControllerFactory
{
public:
    SpeedControllerFactory();
    virtual ~SpeedControllerFactory();

    virtual bool Create(int aHandle, const std::string& aType);
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_FACTORIES_SPEEDCONTROLLERFACTORY_H_