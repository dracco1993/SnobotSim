package com.snobot.simulator.simulator_components.ctre;

import java.util.ArrayList;
import java.util.Collection;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Tag;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.FeedbackDevice;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import com.snobot.simulator.motor_sim.DcMotorModelConfig;
import com.snobot.simulator.motor_sim.StaticLoadMotorSimulationConfig;
import com.snobot.simulator.wrapper_accessors.DataAccessorFactory;
import com.snobot.test.utilities.BaseSimulatorJavaTest;

@Tag("CTRE")
public class TestCtreCanTalonControlPosition extends BaseSimulatorJavaTest
{
    public static Collection<Object[]> getData()
    {
        Collection<Object[]> output = new ArrayList<>();

        for (int i = 0; i < 64; ++i)
        {

            output.add(new Object[]{ i, FeedbackDevice.Analog });
            output.add(new Object[]{ i, FeedbackDevice.QuadEncoder });
            output.add(new Object[]{ i, FeedbackDevice.CTRE_MagEncoder_Absolute });
            output.add(new Object[]{ i, FeedbackDevice.CTRE_MagEncoder_Relative });
        }

        return output;
    }

    @ParameterizedTest
    @MethodSource("getData")
    public void testSetWithPosition(int aCanHandle, FeedbackDevice aFeedbackDevice)
    {
        final int rawHandle = aCanHandle + 100;

        Assertions.assertEquals(0, DataAccessorFactory.getInstance().getSpeedControllerAccessor().getPortList().size());
        TalonSRX talon = new TalonSRX(aCanHandle);
        Assertions.assertEquals(1, DataAccessorFactory.getInstance().getSpeedControllerAccessor().getPortList().size());

        talon.configSelectedFeedbackSensor(aFeedbackDevice, 0, 5);
        checkForFeedbackDevice(aCanHandle, rawHandle, aFeedbackDevice);

        // Simulate CIM drivetrain
        DcMotorModelConfig motorConfig = DataAccessorFactory.getInstance().getSimulatorDataAccessor().createMotor("CIM", 1, 10, 1);
        Assertions.assertTrue(DataAccessorFactory.getInstance().getSimulatorDataAccessor().setSpeedControllerModel_Static(rawHandle, motorConfig,
                new StaticLoadMotorSimulationConfig(0.01)));

        talon.config_kP(0, .11, 5);
        talon.config_kI(0, .005, 5);
        talon.config_IntegralZone(0, 2, 5);

        talon.set(ControlMode.Position, 36 * 4096);

        simulateForTime(1, () ->
        {
        });

        Assertions.assertEquals(36, DataAccessorFactory.getInstance().getSpeedControllerAccessor().getPosition(rawHandle), .5);
        Assertions.assertEquals(36, talon.getSelectedSensorPosition(0) / 4096.0, .5);

        talon.setSelectedSensorPosition(0, 0, 0);
        Assertions.assertEquals(0, talon.getSelectedSensorPosition(0), .000001);
    }

    private void checkForFeedbackDevice(int aCanHandle, int aRawHandle, FeedbackDevice aFeedbackDevice)
    {
        switch (aFeedbackDevice)
        {
        case QuadEncoder:
        case CTRE_MagEncoder_Absolute:
        case CTRE_MagEncoder_Relative:
            Assertions.assertTrue(DataAccessorFactory.getInstance().getEncoderAccessor().getPortList().contains(aRawHandle));
            Assertions.assertEquals("CAN Encoder (" + aCanHandle + ")", DataAccessorFactory.getInstance().getEncoderAccessor().getName(aRawHandle));
            break;
        case Analog:
            Assertions.assertTrue(DataAccessorFactory.getInstance().getAnalogInAccessor().getPortList().contains(aRawHandle));
            Assertions.assertEquals("CAN Analog (" + aCanHandle + ")", DataAccessorFactory.getInstance().getAnalogInAccessor().getName(aRawHandle));
            break;
        default:
            Assertions.assertTrue(false);
            break;
        }
    }
}
