/*
 * BaseNavxWrapper.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: PJ
 */

#include "SnobotSim/SimulatorComponents/NavxWrappers/BaseNavxWrapper.h"

#include "SnobotSim/SensorActuatorRegistry.h"
#include "lowfisim/SimpleAccelerometerSim.h"

BaseNavxWrapper::BaseNavxWrapper(int aBasePort, const std::shared_ptr<NavxSimulator>& aNavx) :
        mNavx(aNavx),
        mXWrapper(new frc::sim::lowfi::SimpleAccelerometerSim(
                std::function<bool(void)>(
                        std::bind(&NavxSimulator::GetInitialized,
                                mNavx.get())),
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetX,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetX,
                                mNavx.get())))),
        mYWrapper(new frc::sim::lowfi::SimpleAccelerometerSim(
                std::function<bool(void)>(
                        std::bind(&NavxSimulator::GetInitialized,
                                mNavx.get())),
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetY,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetY,
                                mNavx.get())))),
        mZWrapper(new frc::sim::lowfi::SimpleAccelerometerSim(
                std::function<bool(void)>(
                        std::bind(&NavxSimulator::GetInitialized,
                                mNavx.get())),
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetZ,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetZ,
                                mNavx.get())))),

        mYawWrapper(new GyroWrapper(mNavx,
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetYaw,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetYaw,
                                mNavx.get())))),

        mPitchWrapper(new GyroWrapper(mNavx,
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetPitch,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetPitch,
                                mNavx.get())))),
        mRollWrapper(new GyroWrapper(mNavx,
                std::function<void(double)>(
                        std::bind(&NavxSimulator::SetRoll,
                                mNavx.get(), std::placeholders::_1)),
                std::function<double(void)>(
                        std::bind(&NavxSimulator::GetRoll,
                                mNavx.get()))))
{
    SensorActuatorRegistry::Get().Register(aBasePort + 0, mXWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 1, mYWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 2, mZWrapper);

    SensorActuatorRegistry::Get().Register(aBasePort + 0, mYawWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 1, mPitchWrapper);
    SensorActuatorRegistry::Get().Register(aBasePort + 2, mRollWrapper);
}

BaseNavxWrapper::~BaseNavxWrapper()
{
}

BaseNavxWrapper::GyroWrapper::GyroWrapper(
        const std::shared_ptr<NavxSimulator>& aNavx,
        const std::function<void(double)>& setterFunction,
        const std::function<double(void)>& getterFunction) :
        mNavx(aNavx),
        m_setAngleFunction(setterFunction),
        m_getAngleFunction(getterFunction)
{
}

bool BaseNavxWrapper::GyroWrapper::IsWrapperInitialized() const
{
    return mNavx->GetInitialized();
}
