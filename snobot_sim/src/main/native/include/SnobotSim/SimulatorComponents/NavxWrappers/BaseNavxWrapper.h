/*
 * BaseNavxWrapper.h
 *
 *  Created on: Nov 23, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_NAVXWRAPPERS_BASENAVXWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_NAVXWRAPPERS_BASENAVXWRAPPER_H_

#include <memory>

#include "NavxSim/NavxSimulator.h"
#include "lowfisim/AccelerometerSim.h"
#include "lowfisim/SimpleGyroSim.h"
#include "lowfisim/SimulatorComponentBase.h"

class BaseNavxWrapper
{
public:
    BaseNavxWrapper(int aBasePort, const std::shared_ptr<NavxSimulator>& aNavx);
    virtual ~BaseNavxWrapper();

    class GyroWrapper : public frc::sim::lowfi::SimulatorComponentBase, public frc::sim::lowfi::GyroSim
    {
    public:
        GyroWrapper(
                const std::shared_ptr<NavxSimulator>& aNavx,
                const std::function<void(double)>& setterFunction,
                const std::function<double(void)>& getterFunction);

        bool IsWrapperInitialized() const override;

        double GetAngle() override
        {
            return m_getAngleFunction();
        }

        void SetAngle(double angle) override
        {
            m_setAngleFunction(angle);
        }

    protected:
        std::shared_ptr<NavxSimulator> mNavx;
        std::function<void(double)> m_setAngleFunction;
        std::function<double(void)> m_getAngleFunction;
    };

    std::shared_ptr<NavxSimulator> mNavx;

    std::shared_ptr<frc::sim::lowfi::AccelerometerSim> mXWrapper;
    std::shared_ptr<frc::sim::lowfi::AccelerometerSim> mYWrapper;
    std::shared_ptr<frc::sim::lowfi::AccelerometerSim> mZWrapper;

    std::shared_ptr<GyroWrapper> mYawWrapper;
    std::shared_ptr<GyroWrapper> mPitchWrapper;
    std::shared_ptr<GyroWrapper> mRollWrapper;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_SIMULATORCOMPONENTS_NAVXWRAPPERS_BASENAVXWRAPPER_H_
