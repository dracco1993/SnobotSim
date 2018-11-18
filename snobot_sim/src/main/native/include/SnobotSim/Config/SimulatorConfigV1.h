
#include <string>
#include <vector>
#include <map>

struct BasicModuleConfig
{
    int mHandle = 0;
    std::string mName = "";
    std::string mType = "";

    virtual void Print(std::ostream& aStream, const std::string& aIndent="");
};

struct EncoderConfig : public BasicModuleConfig
{
    int mConnectedSpeedControllerHandle = 0;

    void Print(std::ostream& aStream, const std::string& aIndent="") override;
};

struct PwmConfig : public BasicModuleConfig
{

    void Print(std::ostream& aStream, const std::string& aIndent="") override;
};


struct SimulatorConfigV1
{
    std::vector<BasicModuleConfig> mAccelerometers;
    std::vector<BasicModuleConfig> mAnalogIn;
    std::vector<BasicModuleConfig> mAnalogOut;
    std::vector<BasicModuleConfig> mDigitalIO;
    std::vector<BasicModuleConfig> mGyros;
    std::vector<BasicModuleConfig> mRelays;
    std::vector<BasicModuleConfig> mSolenoids;
    std::vector<EncoderConfig> mEncoders;
    std::vector<PwmConfig> mPwm;
    std::map<int, std::string> mDefaultI2CWrappers;
    std::map<int, std::string> mDefaultSpiWrappers;
    
    virtual void Print(std::ostream& aStream);
};
