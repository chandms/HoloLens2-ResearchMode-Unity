using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;
using System.Runtime.InteropServices;
using System.IO;

#if ENABLE_WINMD_SUPPORT
using HL2UnityPlugin;
#endif

namespace Microsoft.MixedReality.Toolkit
{

    public class ResearchModeImuStream : MonoBehaviour
    {
#if ENABLE_WINMD_SUPPORT
    HL2ResearchMode researchMode;
#endif
        private float[] accelSampleData = null;
        private Vector3 accelVector;

        private float[] gyroSampleData = null;
        private Vector3 gyroEulerAngle;

        private float[] magSampleData = null;

        public Text AccelText = null;
        public Text GyroText = null;
        public Text MagText = null;

        public Text HeadOriginText = null;
        public Text HeadDirectionText = null;
        public Text HeadVelocityText = null;
        public Text HeadMovementDirectionText = null;

        public Text EyeOriginText = null;
        public Text EyeDirectionText = null;
        public Text EyeCursorText = null;

        private int count = 0;

        public string logFlag = "All";

        public ImuVisualize RefImuVisualize = null;

        public string filename = "sensor_data.txt";

        public Vector3 eye_origin = Vector3.zero;

        public Vector3 eye_direction = Vector3.zero;

        public Vector3 eye_cursor = Vector3.zero;

        public Vector3 head_movement_direction = Vector3.zero;

        TCPClientIMU tcpClientIMU;

        public Vector3 head_velocity = Vector3.zero;

        public Vector3 head_origin = Vector3.zero;
        public Vector3 head_direction = Vector3.zero;

        [SerializeField]
        private float defaultDistanceInMeters = 2f;

        public bool log_sensor_data = false;

        void Start()
        {
         tcpClientIMU = GetComponent<TCPClientIMU>();

#if ENABLE_WINMD_SUPPORT
        researchMode = new HL2ResearchMode();
        researchMode.InitializeAccelSensor();
        researchMode.InitializeGyroSensor();
        researchMode.InitializeMagSensor();

        researchMode.StartAccelSensorLoop();
        researchMode.StartGyroSensorLoop();
        researchMode.StartMagSensorLoop();
#endif
        }

        public string PrepareData()
        {
            string temp_data = "";

            temp_data += "\r\nLog Entry : \n";
            DateTime curDateTime = DateTime.Now;
            temp_data += $"{curDateTime.ToLongTimeString()} {DateTime.Now.ToLongDateString()}\n";
            temp_data += $"{curDateTime.Hour} {curDateTime.Minute} {curDateTime.Second} {curDateTime.Millisecond} \n";

            if (string.Compare("Head",logFlag)==0 || string.Compare("All", logFlag) == 0) {

                temp_data += $" head_origin :{head_origin.ToString("F5")}\n";
                temp_data += $" head_direction :{head_direction.ToString("F5")}\n";
                temp_data += $" head movement direction :{head_movement_direction.ToString("F5")}\n";
                temp_data += $" head velocity :{head_velocity.ToString("F5")}\n";
            }


            if (string.Compare("Accel", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                if (accelSampleData != null && accelSampleData.Length == 3)
                {
                    temp_data += $" Accelerometer[0] :{accelSampleData[0].ToString("F5")}\n";
                    temp_data += $" Accelerometer[1] :{accelSampleData[1].ToString("F5")}\n";
                    temp_data += $" Accelerometer[2] :{accelSampleData[2].ToString("F5")}\n";
                }
            }

            if (string.Compare("Gyro", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                if (gyroSampleData != null && gyroSampleData.Length == 3)
                {
                    temp_data += $" Gyroscope[0] :{gyroSampleData[0].ToString("F5")}\n";
                    temp_data += $" Gyroscope[1] :{gyroSampleData[1].ToString("F5")}\n";
                    temp_data += $" Gyroscope[2] :{gyroSampleData[2].ToString("F5")}\n";
                }
            }

            if (string.Compare("Mag", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                if (magSampleData != null && magSampleData.Length == 3)
                {
                    temp_data += $" Magnetometer[0] :{ magSampleData[0].ToString("F5")}\n";
                    temp_data += $" Magnetometer[1] :{magSampleData[1].ToString("F5")}\n";
                    temp_data += $" Magnetometer[2] :{magSampleData[2].ToString("F5")}\n";
                }
            }


            if (string.Compare("Eye", logFlag) == 0 || string.Compare("All", logFlag) == 0) {
                temp_data += $" eye_origin :{eye_origin.ToString("F5")}\n";
                temp_data += $" eye_direction :{eye_direction.ToString("F5")}\n";
                temp_data += $" eye_cursor :{eye_cursor.ToString("F5")}\n";

            }


            temp_data += "-------------------------------\n";

            return temp_data;

        }
        void LateUpdate()
        {
#if ENABLE_WINMD_SUPPORT
        // update Accel Sample
        if (researchMode.AccelSampleUpdated())
        {
            accelSampleData = researchMode.GetAccelSample();
            if (accelSampleData.Length == 3)
            {
                if (string.Compare("Accel", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                    AccelText.text = $"Accel : {accelSampleData[0]:F3}, {accelSampleData[1]:F3}, {accelSampleData[2]:F3}";
                }
                else{
                    AccelText.text = $"Accel : ";
                }
            }
        }

        // update Gyro Sample
        if (researchMode.GyroSampleUpdated())
        {
            gyroSampleData = researchMode.GetGyroSample();
            if (gyroSampleData.Length == 3)
            {
                if (string.Compare("Gyro", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                GyroText.text = $"Gyro  : {gyroSampleData[0]:F3}, {gyroSampleData[1]:F3}, {gyroSampleData[2]:F3}";
                }
                else{
                    GyroText.text = $"Gyro  : ";
                }
            }
        }

        // update Mag Sample
        if (researchMode.MagSampleUpdated())
        {
            magSampleData = researchMode.GetMagSample();
            if (magSampleData.Length == 3)
            {
                if (string.Compare("Mag", logFlag) == 0 || string.Compare("All", logFlag) == 0 || string.Compare("IMU", logFlag) == 0) {
                MagText.text = $"Mag   : {magSampleData[0]:F3}, {magSampleData[1]:F3}, {magSampleData[2]:F3}";
                }
                else{
                    MagText.text = $"Mag   : ";
                }
            }
        }
#endif





            Debug.Log(logFlag);

            // Convert to Vector3
            accelVector = CreateAccelVector(accelSampleData);
            gyroEulerAngle = CreateGyroEulerAngle(gyroSampleData);

            // Visualize corrected values
            RefImuVisualize.AccelVector = accelVector * 0.1f;
            RefImuVisualize.GyroEulorAngle = gyroEulerAngle * 30.0f;

            var eyeGazeProvider = CoreServices.InputSystem?.EyeGazeProvider;
            if (eyeGazeProvider != null)
            {
                eye_origin = eyeGazeProvider.GazeOrigin;
                eye_direction = eyeGazeProvider.GazeDirection;

                gameObject.transform.position = eye_origin + eye_direction.normalized * defaultDistanceInMeters;

                eye_cursor = gameObject.transform.position;

                head_movement_direction = eyeGazeProvider.HeadMovementDirection;

                head_velocity = eyeGazeProvider.HeadVelocity;



            }

            head_origin = Camera.main.transform.position;
            head_direction = Camera.main.transform.forward;

            if (string.Compare("Head", logFlag) == 0 || string.Compare("All", logFlag) == 0)
            {
                HeadMovementDirectionText.text = $"H Move Dir : {head_movement_direction.ToString("F5")}";
                HeadOriginText.text = $"H Origin : {head_origin.ToString("F5")}";
                HeadDirectionText.text = $"H Direction : {head_direction.ToString("F5")}";
                HeadVelocityText.text = $"H Velocity : {head_velocity.ToString("F5")}";
            }
            else
            {
                HeadMovementDirectionText.text = $"H Move Dir : ";
                HeadOriginText.text = $"H Origin : ";
                HeadDirectionText.text = $"H Direction : ";
                HeadVelocityText.text = $"H Velocity : ";
            }

            if (string.Compare("Eye", logFlag) == 0 || string.Compare("All", logFlag) == 0)
            {
                EyeCursorText.text = $"E Cursor : {eye_cursor.ToString("F5")}";
                EyeDirectionText.text = $"E Direction : {eye_direction.ToString("F5")}";
                EyeOriginText.text = $"E Origin : {eye_origin.ToString("F5")}";
            }
            else
            {
                EyeCursorText.text = $"E Cursor : ";
                EyeDirectionText.text = $"E Direction : ";
                EyeOriginText.text = $"E Origin : ";
            }

            string temp_data = PrepareData();

            


            if (log_sensor_data == true)
            {
                LogAllSensorData(temp_data);
            }

           

            #if WINDOWS_UWP
                if (tcpClientIMU != null)
                {
                    tcpClientIMU.SendSensorData(temp_data);
                }
            #endif



            count += 1;
        }

        private Vector3 CreateAccelVector(float[] accelSample)
        {
            Vector3 vector = Vector3.zero;
            if ((accelSample?.Length ?? 0) == 3)
            {
                // Positive directions
                //  accelSample[0] : Down direction
                //  accelSample[1] : Back direction
                //  accelSample[0] : Right direction
                vector = new Vector3(
                    accelSample[2],
                    -1.0f * accelSample[0],
                    -1.0f * accelSample[1]
                    );
            }
            return vector;
        }

        private Vector3 CreateGyroEulerAngle(float[] gyroSample)
        {
            Vector3 vector = Vector3.zero;
            if ((gyroSample?.Length ?? 0) == 3)
            {
                // Axis of rotation
                //  gyroSample[0] : Unity Y axis(Plus)
                //  gyroSample[1] : Unity Z axis(Plus)
                //  gyroSample[2] : Unity X axis(Plus)
                vector = new Vector3(
                    gyroSample[2],
                    gyroSample[0],
                    gyroSample[1]
                    );
            }
            return vector;
        }

        public void StopSensorsEvent()
        {
#if ENABLE_WINMD_SUPPORT
        researchMode.StopAllSensorDevice();
#endif
        }

        private void OnApplicationFocus(bool focus)
        {
            if (!focus) StopSensorsEvent();
        }

        public void UpdateLogVar()
        {
            log_sensor_data = !log_sensor_data;
        }

        public void LogAllSensorData(string param_str)
        {
            string path = Path.Combine(Application.persistentDataPath, filename);
            //string path = filename;
    
            Debug.Log("file path "+path);
            using (var file = new FileStream(path, FileMode.Append, FileAccess.Write, FileShare.Write))
            {
                using (var writer = new StreamWriter(file))
                {

                    writer.Write("\r\nLog Entry : ");
                    writer.WriteLine(param_str);


                }

            }
        }

        public void ChangeLogFlagToAccel()
        {
            logFlag = "Accel";
        }

        public void ChangeLogFlagToGyro()
        {
            logFlag = "Gyro";
        }

        public void ChangeLogFlagToMag()
        {
            logFlag = "Mag";
        }

        public void ChangeLogFlagToHead()
        {
            logFlag = "Head";
        }

        public void ChangeLogFlagToEye()
        {
            logFlag = "Eye";
        }

        public void ChangeLogFlagToAll()
        {
            logFlag = "All";
        }

        public void ChangeLogFlagToIMU()
        {
            logFlag = "IMU";
        }
    }

}
