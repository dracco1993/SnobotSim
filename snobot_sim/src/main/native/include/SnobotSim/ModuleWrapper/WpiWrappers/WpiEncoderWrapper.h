/*
 * EncoderWrapper.h
 *
 *  Created on: May 4, 2017
 *      Author: PJ
 */

#ifndef SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIENCODERWRAPPER_H_
#define SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIENCODERWRAPPER_H_

#include <memory>
#include <string>

#include "SnobotSim/ModuleWrapper/Interfaces/IEncoderWrapper.h"
#include "SnobotSim/ModuleWrapper/Interfaces/ISpeedControllerWrapper.h"
#include "SnobotSim/SimulatorComponents/IFeedbackSensor.h"
#include "lowfisim/SimulatorComponentBase.h"

class WpiEncoderWrapper : public std::enable_shared_from_this<WpiEncoderWrapper>,
                          public frc::sim::lowfi::SimulatorComponentBase,
                          public IFeedbackSensor,
                          public IEncoderWrapper
{
public:
    explicit WpiEncoderWrapper(int aHandle);
    WpiEncoderWrapper(int aPortA, int aPortB);
    virtual ~WpiEncoderWrapper();

    bool IsWrapperInitialized() const override;

    void Reset() override;

    double GetDistance() override;

    double GetVelocity() override;

    bool IsHookedUp() override;

    void SetSpeedController(const std::shared_ptr<ISpeedControllerWrapper>& aMotorWrapper) override;

    const std::shared_ptr<ISpeedControllerWrapper>& GetSpeedController() override;

    void SetDistancePerTick(double aDPT);

    double GetDistancePerTick();

    double GetPosition() override;

    void SetPosition(double aPosition) override;

    void SetVelocity(double aVelocity) override;

protected:
    std::shared_ptr<ISpeedControllerWrapper> mMotorWrapper;
    double mEncodingFactor;
    double mDistancePerTick;
    const int mHandle;
};

#endif // SNOBOTSIM_SNOBOT_SIM_SRC_MAIN_NATIVE_INCLUDE_SNOBOTSIM_MODULEWRAPPER_WPIWRAPPERS_WPIENCODERWRAPPER_H_
