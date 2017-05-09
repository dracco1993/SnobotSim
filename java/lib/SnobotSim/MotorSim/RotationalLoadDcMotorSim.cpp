/*
 * RotationalLoadDcMotorSim.cpp
 *
 *  Created on: May 9, 2017
 *      Author: preiniger
 */

#include "SnobotSim/MotorSim/RotationalLoadDcMotorSim.h"
#include <math.h>

const double RotationalLoadDcMotorSim::sGRAVITY = 9.8;

RotationalLoadDcMotorSim::RotationalLoadDcMotorSim(const DcMotorModel& aMotorModel, const std::shared_ptr<SpeedControllerWrapper>& aSpeedController,
        double aArmCenterOfMass, double aArmMass, double aConstantAssistTorque, double aOverCenterAssistTorque) :    
    BaseDcMotorSimulator(aMotorModel),
    mSpeedController(aSpeedController), 
    mArmInertia(aArmMass * aArmCenterOfMass * aArmCenterOfMass), 
    mGravityBasedTorqueFactor(aArmMass * aArmCenterOfMass * sGRAVITY),
    mConstantAssistTorque(aConstantAssistTorque), 
    mOverCenterAssistTorque(aOverCenterAssistTorque)
{

}

RotationalLoadDcMotorSim::~RotationalLoadDcMotorSim()
{

}

void RotationalLoadDcMotorSim::Update(double cycleTime)
{
    double position = mSpeedController->GetPosition();
    double gravityTorque = mGravityBasedTorqueFactor * sin(position);
    gravityTorque += mConstantAssistTorque;
    gravityTorque += mOverCenterAssistTorque * sin(position);

    double inVolts = mVoltagePercentage * 12;

    mMotorModel.Step(inVolts, mArmInertia, gravityTorque, cycleTime);
}
