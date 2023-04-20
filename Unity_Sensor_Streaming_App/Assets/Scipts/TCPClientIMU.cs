using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO;
using System.Text;
//using System.Runtime.Serialization.Formatters.Binary;
#if WINDOWS_UWP
using Windows.Networking.Sockets;
using Windows.Storage.Streams;
#endif


public class TCPClientIMU : MonoBehaviour
{
    #region Unity Functions

    private void Awake()
    {
        ConnectionStatusLED.material.color = Color.red;
    }
    #endregion // Unity Functions

    [SerializeField]
    string hostIPAddress, port;


    public Renderer ConnectionStatusLED;
    private bool connected = false;
    public string configfileName = "config_sensor.txt";
    public bool Connected
    {
        get { return connected; }
    }

#if WINDOWS_UWP
    StreamSocket socket = null;
    public DataWriter dw;
    public DataReader dr;
    private async void StartCoonection()
    {
        if (socket != null) socket.Dispose();

        string configfilePath = Path.Combine(Application.persistentDataPath, configfileName);
        // string configfilePath = configfileName;

        if (File.Exists(configfilePath))
        {

            byte[] configData = UnityEngine.Windows.File.ReadAllBytes(configfilePath);
            string configText = Encoding.ASCII.GetString(configData);

            string[] words = configText.Split('\n');

            foreach (var word in words)
            {
                string[] cur_pair = word.Split(':');
                string key = cur_pair[0].Trim();
                string val = cur_pair[1].Trim();

                if (string.Compare(key, "ip") == 0)
                {
                    hostIPAddress = val;
                }

                else if(string.Compare(key, "port") == 0){
                    port = val;
                }
            }
        }

        try
        {
            socket = new StreamSocket();
            var hostName = new Windows.Networking.HostName(hostIPAddress);
            await socket.ConnectAsync(hostName, port);
            dw = new DataWriter(socket.OutputStream);
            dr = new DataReader(socket.InputStream);
            dr.InputStreamOptions = InputStreamOptions.Partial;
            connected = true;
            ConnectionStatusLED.material.color = Color.green;
        }
        catch (Exception ex)
        {
            SocketErrorStatus webErrorStatus = SocketError.GetStatus(ex.GetBaseException().HResult);
            Debug.Log(webErrorStatus.ToString() != "Unknown" ? webErrorStatus.ToString() : ex.Message);
        }
    }


    private void StopCoonection()
    {
        dw?.DetachStream();
        dw?.Dispose();
        dw = null;

        dr?.DetachStream();
        dr?.Dispose();
        dr = null;

        socket?.Dispose();
        connected = false;
        ConnectionStatusLED.material.color = Color.red;
    }

    bool lastMessageSent = true;
    public async void SendSensorData(string param)
    {
        if (!lastMessageSent) return;
        lastMessageSent = false;
        try
        {
            // Write the data
            dw.WriteString(param); // header "s" 

            // Send out
            await dw.StoreAsync();
            await dw.FlushAsync();
        }
        catch (Exception ex)
        {
            SocketErrorStatus webErrorStatus = SocketError.GetStatus(ex.GetBaseException().HResult);
            Debug.Log(webErrorStatus.ToString() != "Unknown" ? webErrorStatus.ToString() : ex.Message);
        }
        lastMessageSent = true;
    }

#endif

    #region Button Callback
    public void CallServerEvent()
    {
        Debug.Log("server called");
#if WINDOWS_UWP
        if (!connected) StartCoonection();
        else StopCoonection();
#endif
    }
    #endregion

}
