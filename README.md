# HoloLens2-ResearchMode-Unity
Unity Plugin for using research mode functionality in HoloLens 2. Modified based on [HoloLens2ForCV](https://github.com/microsoft/HoloLens2ForCV).

![Picture from HL2 Sensor Streaming App](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/hololens_app.jpg)

# Unity_Sensor_Streaming_App (Overview)
- Capture IMU data from research mode sensor (Assets/Scenes/ImuViewSample.unity)
- Capture Head and Eye tracking information of user
- Stream above data to python server over TCP
  -- upload [config_sensor](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/config_sensor.txt) file (after changing the ip address and port number with server ip and port) in LocalState folder of the deployed app in HoloLens2. Use Windows Device Portal to do this step.
- Use "Connect to Server" button to start streaming
- Use specific buttons on the screen to visuliaze and stream particular data
- Voice commands can also be used
  -- Log Gyroscope [For Gyroscope Data]
  -- Log Magnetometer [For Magnetometer Data]
  -- Log Accel [For Accelerometer Data]
  -- Log Head Tracking [For Head Data]
  -- Log Eye Tracking [For Eye Data]
  -- Log IMU [For IMU sensors data]
  -- Log Sensors [For all the senors data]

# Compatibility
- Unity 2019.4*
- Visual Studio 2019


# Build
1. Open Unity_Sensor_Streaming_App folder in Unity.
2. Go to Build Settings, switch target platform to UWP.
3. In the Project tab, open `Scenes/ImuViewSample.unity`.
4. Hopefully, there is no error in the console. Go to Build Settings, change Target Device to HoloLens, Architecture to ARM64. Build the Unity project in a new folder (e.g. App folder).
5. Open `App/HL2SensorStreaming/Package.appxmanifest` with a text editor. Add `xmlns:rescap="http://schemas.microsoft.com/appx/manifest/foundation/windows10/restrictedcapabilities"` before the `IgnorableNamespaces` in Package tag (line 2). Add `<rescap:Capability Name="perceptionSensorsExperimental" />` in the Capabilities tag between `<uap2:Capability ... >` and `<DeviceCapability ... >`. This is same as enabling Research Mode on HoloLens 1.
6. If IMU is used, add `<DeviceCapability Name="backgroundSpatialPerception"/>` to DeviceCapability.
7. Save the changes. Open `App/HL2ResearchModeUnitySample.sln`. Change the build type to Release/Master-ARM64-Device(or Remote Machine). Build - Deploy.
8. Done!


# Note
- An already built version with necessary changes is present in folder Sensor_Streaming_Application.
- The app may not function properly the first time you open the deployed app when there are pop-up windows asking for permissions. You can simply grant the permissions, close the app and reopen it. Then everything should be fine.
- You need to restart the device (hold the power button for several seconds) each time the device hiberates after you opened an app that uses research mode functions. So if your app suddenly cannot get any sensor data, try restarting your device. Please let me know if you know how to solve this issue.

