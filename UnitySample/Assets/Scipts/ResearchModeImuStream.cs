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

        public ImuVisualize RefImuVisualize = null;

        public string filename = "sensor_data.txt";

        public Vector3 eye_origin = Vector3.zero;

        public Vector3 eye_direction = Vector3.zero;

        public Vector3 eye_cursor = Vector3.zero;

        public Vector3 head_movement_direction = Vector3.zero;

        public Vector3 head_velocity = Vector3.zero;

        [SerializeField]
        private float defaultDistanceInMeters = 2f;

        void Start()
        {
#if ENABLE_WINMD_SUPPORT
        researchMode = new HL2ResearchMode();
        researchMode.InitializeAccelSensor();
        researchMode.InitializeGyroSensor();
        researchMode.InitializeMagSensor();

        researchMode.StartAccelSensorLoop();
        researchMode.StartGyroSensorLoop();
        researchMode.StartMagSensorLoop();
#endif
            AccelText.text = $"Accel Nothing : CM";
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
                AccelText.text = $"Accel : {accelSampleData[0]:F3}, {accelSampleData[1]:F3}, {accelSampleData[2]:F3}";
            }
            else{
                AccelText.text = $"Accel Nothing : {accelSampleData.Length}";
            }
        }

        // update Gyro Sample
        if (researchMode.GyroSampleUpdated())
        {
            gyroSampleData = researchMode.GetGyroSample();
            if (gyroSampleData.Length == 3)
            {
                GyroText.text = $"Gyro  : {gyroSampleData[0]:F3}, {gyroSampleData[1]:F3}, {gyroSampleData[2]:F3}";
            }
            else{
                GyroText.text = $"Gyro Nothing : {gyroSampleData.Length}";
            }
        }

        // update Mag Sample
        if (researchMode.MagSampleUpdated())
        {
            magSampleData = researchMode.GetMagSample();
            if (magSampleData.Length == 3)
            {
                MagText.text = $"Mag   : {magSampleData[0]:F3}, {magSampleData[1]:F3}, {magSampleData[2]:F3}";
            }
        }
#endif
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

            LogAllSensorData();
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
                Console.WriteLine("accl " + accelSample[2] + " " + accelSample[0] + " " + accelSample[1]);
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
                Console.WriteLine("gyro " + gyroSample[2] + " " + gyroSample[0] + " " + gyroSample[1]);
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

        public void LogAllSensorData()
        {
            string path = Path.Combine(Application.persistentDataPath, filename);
            //string path = filename;
    
            // Debug.Log("file path "+path);
            using (var file = new FileStream(path, FileMode.Append, FileAccess.Write, FileShare.Write))
            {
                using (var writer = new StreamWriter(file))
                {

                    writer.Write("\r\nLog Entry : ");
                    DateTime curDateTime = DateTime.Now;
                    writer.WriteLine($"{curDateTime.ToLongTimeString()} {DateTime.Now.ToLongDateString()}");
                    writer.WriteLine($"{curDateTime.Hour} {curDateTime.Minute} {curDateTime.Second} {curDateTime.Millisecond} ");

                    writer.WriteLine("Head Tracking ");
                    writer.WriteLine($" head_origin :{Camera.main.transform.position.ToString("F5")}");
                    writer.WriteLine($" head_direction :{Camera.main.transform.forward.ToString("F5")}");
                    writer.WriteLine($" head movement direction :{head_movement_direction.ToString("F5")}");
                    writer.WriteLine($" head velocity :{head_velocity.ToString("F5")}");


                    writer.WriteLine("Accelerometer Data ");
                    if ((accelSampleData?.Length ?? 0) == 3)
                    {
                        writer.WriteLine($" Accelerometer[0] :{accelSampleData[0].ToString("F5")}");
                        writer.WriteLine($" Accelerometer[1] :{accelSampleData[1].ToString("F5")}");
                        writer.WriteLine($" Accelerometer[2] :{accelSampleData[2].ToString("F5")}");
                    }

                    writer.WriteLine("Gyroscope Data ");
                    if ((gyroSampleData?.Length ?? 0) == 3)
                    {
                        writer.WriteLine($" Gyroscope[0] :{gyroSampleData[0].ToString("F5")}");
                        writer.WriteLine($" Gyroscope[1] :{gyroSampleData[1].ToString("F5")}");
                        writer.WriteLine($" Gyroscope[2] :{gyroSampleData[2].ToString("F5")}");
                    }


                    writer.WriteLine("Magnetometer Data ");
                    if ((magSampleData?.Length ?? 0) == 3)
                    {
                        writer.WriteLine($" Magnetometer[0] :{magSampleData[0].ToString("F5")}");
                        writer.WriteLine($" Magnetometer[1] :{magSampleData[1].ToString("F5")}");
                        writer.WriteLine($" Magnetometer[2] :{magSampleData[2].ToString("F5")}");
                    }

                    writer.WriteLine("Eye Tracking ");
                    writer.WriteLine($" eye_origin :{eye_origin.ToString("F5")}");
                    writer.WriteLine($" eye_direction :{eye_direction.ToString("F5")}");
                    writer.WriteLine($" eye_cursor :{eye_cursor.ToString("F5")}");

                    writer.WriteLine("-------------------------------");



                }

            }
        }
    }

}
