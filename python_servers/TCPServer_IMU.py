import socket
import struct
import sys
import os
import numpy as np
import time
import pickle as pkl
from datetime import datetime


def tcp_server():
    serverHost = ''  # localhost
    serverPort = 9090
    save_folder = 'data/'

    if not os.path.isdir(save_folder):
        os.mkdir(save_folder)

    # Create a socket
    sSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind server to port
    try:
        sSock.bind((serverHost, serverPort))
        print('Server bind to port ' + str(serverPort))
    except socket.error as msg:
        print('Bind failed. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
        return

    sSock.listen(10)
    print('Start listening...')
    sSock.settimeout(3.0)
    while True:
        try:
            conn, addr = sSock.accept()  # Blocking, wait for incoming connection
            print('Connected with ' + addr[0] + ':' + str(addr[1]))

            output_file_name = "sensor_data_" + str(datetime.now().timestamp()) + ".txt"
            while True:
                # Receiving from client
                try:
                    data = conn.recv(512 * 512 * 4 + 100)
                    if len(data) == 0:
                        break
                    sensor_data = data.decode('utf-8')

                    print(sensor_data)
                    print(output_file_name)
                    try:
                        with open(output_file_name, 'a') as fp:
                            fp.writelines(data.decode('utf-8'))
                    except Exception as e:
                        print('problem with opening file ' + repr(e))

                    print(len(data))

                except Exception as e:
                    print('problem '+str(e))
                    break
        except KeyboardInterrupt:
            sys.exit(0)
        except Exception:
            continue

    print('Closing socket...')
    sSock.close()


if __name__ == "__main__":
    tcp_server()
