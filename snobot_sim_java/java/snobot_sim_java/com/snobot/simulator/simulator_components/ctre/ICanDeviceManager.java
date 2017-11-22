package com.snobot.simulator.simulator_components.ctre;

import java.nio.ByteBuffer;

public interface ICanDeviceManager
{

    void handleSend(int aMessageId, ByteBuffer aData, int aDataSize);

    void handleReceive(int aMessageId, ByteBuffer aData, int aDataSize);

    int openStreamSession(int aMessageId);

    void readStreamSession(ByteBuffer[] messages, int messagesToRead);

}
