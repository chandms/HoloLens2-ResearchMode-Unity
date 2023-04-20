# HoloLens2-ResearchMode-Sensor-Streaming-Unity-Application

Unity Plugin for using research mode functionality in HoloLens 2. Modified based on [HoloLens2ForCV](https://github.com/microsoft/HoloLens2ForCV).

![Picture from HL2 Sensor Streaming App](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/hololens_app.jpg)

## Please ensure that you have these required tools for [HoloLesn2 MRTK App development](https://learn.microsoft.com/en-us/windows/mixed-reality/develop/install-the-tools).

# HoloLesn2 Sensor Streaming App (Overview)

- Capture data from IMU sensors (HoloLens2 must be in Research Mode)
- Capture Head and Eye tracking information of user
- Stream above data to python server over TCP
  1. upload [config_sensor](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/config_sensor.txt) file (after changing the ip address and port number with server ip and port) in LocalState folder of the deployed app in HoloLens2. Use Windows Device Portal to do this step.
- Use "Connect to Server" button to start and stop streaming.
- Use specific buttons on the screen to visuliaze and stream particular data
- Voice commands can also be used
  1. Log Gyroscope [For Gyroscope Data]
  2. Log Magnetometer [For Magnetometer Data]
  3. Log Accel [For Accelerometer Data]
  4. Log Head Tracking [For Head Data]
  5. Log Eye Tracking [For Eye Data]
  6. Log IMU [For IMU sensors data]
  7. Log Sensors [For all the senors data]


# Compatibility
- Unity 2019.4*
- Visual Studio 2019


# Build HL2 App
- Open [Unity_Sensor_Streaming_App](https://github.com/chandms/HoloLens2-ResearchMode-Unity/tree/master/Unity_Sensor_Streaming_App) folder in Unity.
- Go to Build Settings, switch target platform to UWP.
- In the Project tab, open [Scenes/ImuViewSample.unity](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/Unity_Sensor_Streaming_App/Assets/Scenes/ImuViewSample.unity).
- Hopefully, there is no error in the console. Go to Build Settings, change Target Device to HoloLens, Architecture to ARM64. Build the Unity project in a new folder (e.g. App folder).
- Open `App/HL2SensorStreaming/Package.appxmanifest` with a text editor. Add `xmlns:rescap="http://schemas.microsoft.com/appx/manifest/foundation/windows10/restrictedcapabilities"` before the `IgnorableNamespaces` in Package tag (line 2). Add `<rescap:Capability Name="perceptionSensorsExperimental" />` in the Capabilities tag between `<uap2:Capability ... >` and `<DeviceCapability ... >`. 
- As IMU is used, add `<DeviceCapability Name="backgroundSpatialPerception"/>` to DeviceCapability.
- Save the changes. Open `App/HL2SensorStreaming.sln`. Change the build type to Release/Master-ARM64-Device(or Remote Machine). Build - Deploy.
- Done!


# Note
- An already built version with necessary changes is present in folder Sensor_Streaming_Application. You can directly open [HL2SensorStreaming.sln](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/Sensor_Streaming_Application/HL2SensorStreaming.sln) in visual studio. However, you need to still upload the
[config_sensor](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/config_sensor.txt) file after deployment (follow the instructions above).

- The app may not function properly the first time you open the deployed app when there are pop-up windows asking for permissions. You can simply grant the permissions, close the app and reopen it. Then everything should be fine.

- You need to restart the device (hold the power button for several seconds) each time the device hiberates after you opened an app that uses research mode functions. So if your app suddenly cannot get any sensor data, try restarting your device. Please let me know if you know how to solve this issue.


# Python Server
- Execute [TCPServer_IMU](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/python_servers/TCPServer_IMU.py) server in your laptop/desktop with suitable ip and port.
- Use the same ip and port in [config_sensor](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/config_sensor.txt) file.
- The server will capture specific data, the user chose to stream
- For each session, data will be stored in a separate timestamped file.

# Head Movement Analysis (Overview)
  - Please check the folder [Head_Movement_Analysis](https://github.com/chandms/HoloLens2-ResearchMode-Unity/tree/master/Head_Movement_Analysis)
  - Collected User Data
  - Python scripts for Analysis.
  - Please follow the [Readme](https://github.com/chandms/HoloLens2-ResearchMode-Unity/blob/master/Head_Movement_Analysis/README.md) of that folder.

# Some Other Important Links - 
  - [Windows Device Portal](https://learn.microsoft.com/en-us/windows/mixed-reality/develop/advanced-concepts/using-the-windows-device-portal)
  - [HoloLens2 App Deployment](https://learn.microsoft.com/en-us/windows/mixed-reality/develop/advanced-concepts/using-visual-studio?tabs=hl2)
  - [Enable Research Mode in HL2](https://learn.microsoft.com/en-us/windows/mixed-reality/develop/advanced-concepts/research-mode)
