/*
 * GyroFactory.cpp
 *
 *  Created on: Jun 30, 2018
 *      Author: PJ
 */

#include "SnobotSim/ModuleWrapper/Factories/GyroFactory.h"

#include "SnobotSim/Logging/SnobotLogger.h"
#include "SnobotSim/PortUnwrapper.h"
#include "SnobotSim/SensorActuatorRegistry.h"
#include "lowfisim/wpisimulators/WpiAnalogGyroSim.h"

GyroFactory::GyroFactory()
{
}

GyroFactory::~GyroFactory()
{
}

bool GyroFactory::Create(int aHandle, const std::string& aType)
{
    bool success = true;

    if (aType == "WpiAnalogGyroWrapper")
    {
        if (!SensorActuatorRegistry::Get().GetIGyroWrapper(aHandle, false))
        {
            SNOBOT_LOG(SnobotLogging::WARN, "Not set up before loading robot");

            std::shared_ptr<IGyroWrapper> gyroWrapper(new frc::sim::lowfi::WpiAnalogGyroSim(aHandle));
            SensorActuatorRegistry::Get().Register(aHandle, gyroWrapper);

            SensorActuatorRegistry::Get().GetIGyroWrapper(aHandle)->SetDisplayName("Analog Gyro " + std::to_string(UnwrapPort(aHandle)));
        }
    }
    else
    {
        SNOBOT_LOG(SnobotLogging::WARN, "Unknown type " << aType);
        success = false;
    }

    return success;
}
