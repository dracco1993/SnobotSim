
#include "SnobotSim/Config/SimulatorConfigReaderV1.h"
#include "SnobotSim/Config/SimulatorConfigV1.h"
#include "SnobotSim/Logging/SnobotLogger.h"
#include "SnobotSim/ModuleWrapper/Factories/FactoryContainer.h"
#include "SnobotSim/SensorActuatorRegistry.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <experimental/filesystem>


template <typename T>
void ParseVector(const YAML::Node& aNode, std::vector<T>& aVector)
{
    for (YAML::const_iterator it=aNode.begin(); it!=aNode.end(); ++it) {
        T value;
        (*it) >> value;
        aVector.push_back(value);
    }
}


const YAML::Node& operator>> (const YAML::Node& aNode, BasicModuleConfig& aOutput)
{
    aOutput.mHandle = aNode["mHandle"].as<int>();
    aOutput.mName = aNode["mName"].as<std::string>();
    aOutput.mType = aNode["mType"].as<std::string>();
    return aNode;
}


const YAML::Node& operator>> (const YAML::Node& configNode, SimulatorConfigV1& config)
{
    ParseVector(configNode["mAccelerometers"], config.mAccelerometers);
    ParseVector(configNode["mAnalogIn"], config.mAnalogIn);
    ParseVector(configNode["mAnalogOut"], config.mAnalogOut);
    ParseVector(configNode["mDigitalIO"], config.mDigitalIO);
    ParseVector(configNode["mGyros"], config.mGyros);
    ParseVector(configNode["mRelays"], config.mRelays);
    ParseVector(configNode["mSolenoids"], config.mSolenoids);
    ParseVector(configNode["mEncoders"], config.mEncoders);
    ParseVector(configNode["mPwm"], config.mPwm);

    return configNode;
}


SimulatorConfigReaderV1::SimulatorConfigReaderV1()
{

}

SimulatorConfigReaderV1::~SimulatorConfigReaderV1()
{
    
}

template <typename FactoryType, typename WrapperType>
void CreateBasicComponent(std::shared_ptr<FactoryType> aFactory, const std::map<int, WrapperType>& wrapperMap, const BasicModuleConfig& aConfig)
{
    aFactory->Create(aConfig.mHandle, aConfig.mType);
    auto findIter = wrapperMap.find(aConfig.mHandle);
    if(findIter != wrapperMap.end())
    {
        findIter->second->SetName("HEllo");
    }
    else
    {
        SNOBOT_LOG(SnobotLogging::LOG_LEVEL_CRITICAL, "Could not set name for handle " << aConfig.mHandle);
    }
}

template <typename FactoryType, typename WrapperType>
void CreateBasicComponents(std::shared_ptr<FactoryType> aFactory, const std::map<int, WrapperType>& wrapperMap, const std::vector<BasicModuleConfig>& aConfigs)
{
    for(auto it : aConfigs)
    {
        CreateBasicComponent(aFactory, wrapperMap, it);
    }
}


void CreatePwmComponents(std::shared_ptr<SpeedControllerFactory> aFactory, const std::map<int, std::shared_ptr<ISpeedControllerWrapper>>& wrapperMap, const std::vector<PwmConfig>& aConfigs)
{
    for(auto it : aConfigs)
    {
        CreateBasicComponent(aFactory, wrapperMap, it);
    }
}

void CreateEncoderComponents(std::shared_ptr<EncoderFactory> aFactory, const std::map<int, std::shared_ptr<IEncoderWrapper>>& wrapperMap, const std::vector<EncoderConfig>& aConfigs)
{
    for(auto it : aConfigs)
    {
        CreateBasicComponent(aFactory, wrapperMap, it);
    }
}

void SetupSimulator(const SimulatorConfigV1& aConfig)
{
    for (auto it : aConfig.mDefaultI2CWrappers)
    {
        FactoryContainer::Get().GetI2CWrapperFactory()->RegisterDefaultWrapperType(it.first, it.second);
    }
    for (auto it : aConfig.mDefaultSpiWrappers)
    {
        FactoryContainer::Get().GetSpiWrapperFactory()->RegisterDefaultWrapperType(it.first, it.second);
    }

    CreateBasicComponents(FactoryContainer::Get().GetAccelerometerFactory(), SensorActuatorRegistry::Get().GetIAccelerometerWrapperMap(), aConfig.mAccelerometers);
    CreateBasicComponents(FactoryContainer::Get().GetAnalogInFactory(), SensorActuatorRegistry::Get().GetIAnalogInWrapperMap(), aConfig.mAnalogIn);
    CreateBasicComponents(FactoryContainer::Get().GetAnalogOutFactory(), SensorActuatorRegistry::Get().GetIAnalogOutWrapperMap(), aConfig.mAnalogOut);
    CreateBasicComponents(FactoryContainer::Get().GetDigitalIoFactory(), SensorActuatorRegistry::Get().GetIDigitalIoWrapperMap(), aConfig.mDigitalIO);
    CreateBasicComponents(FactoryContainer::Get().GetGyroFactory(), SensorActuatorRegistry::Get().GetIGyroWrapperMap(), aConfig.mGyros);
    CreateBasicComponents(FactoryContainer::Get().GetRelayFactory(), SensorActuatorRegistry::Get().GetIRelayWrapperMap(), aConfig.mRelays);
    CreateBasicComponents(FactoryContainer::Get().GetSolenoidFactory(), SensorActuatorRegistry::Get().GetISolenoidWrapperMap(), aConfig.mSolenoids);
    
    CreateEncoderComponents(FactoryContainer::Get().GetEncoderFactory(), SensorActuatorRegistry::Get().GetIEncoderWrapperMap(), aConfig.mEncoders);
    CreatePwmComponents(FactoryContainer::Get().GetSpeedControllerFactory(), SensorActuatorRegistry::Get().GetISpeedControllerWrapperMap(), aConfig.mPwm);
    
}

bool SimulatorConfigReaderV1::LoadConfig(const std::string& aConfigFile)
{
    namespace fs = std::experimental::filesystem;
    fs::path configFile = aConfigFile;

    bool success = true;
    SNOBOT_LOG(SnobotLogging::LOG_LEVEL_INFO, "Loading config file '" << fs::canonical(configFile) << "'");

    try
    {
        YAML::Node configNode = YAML::LoadFile(aConfigFile);

        SimulatorConfigV1 config;
        configNode >> config;

        SetupSimulator(config);
    }
    catch(std::exception& ex)
    {
        SNOBOT_LOG(SnobotLogging::LOG_LEVEL_CRITICAL, "Could not parse config file... " << ex.what());
        success = false;
    }

    return success;
}
