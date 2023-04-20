import argparse
import os
import matplotlib.pyplot as plt
import numpy as np

# plot different sensors for any gesture

# python plot_all_sensors.py --path <FULL PATH> --plot <SENSOR>
# Mag, Accel, Gyro, Head, Eye


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path", help="provide the filepath")
parser.add_argument("--plot", help="provide the sensor")

args = parser.parse_args()

if not args.path or not args.plot:
    print("check with help")
    exit(1)

filepath = args.path
plot = [args.plot]

# plot = ["Head", "Eye", "Gyro", "Mag", "Accel"]

lines = ""

with open(filepath, 'r') as fp:
    lines = fp.readlines()

# head origin data
Hox = []
Hoy = []
Hoz = []

# Accelerometer
Ax = []
Ay = []
Az = []

# Gyroscope
Gx = []
Gy = []
Gz = []

# Eye Cursor
Ex = []
Ey = []
Ez = []

# Magnetometer
Mx = []
My = []
Mz = []

# Time
T = []
st = -1

for line in lines:
    if ":" not in line and "-" not in line and line.strip() != "":
        line = line.strip()
        data = line.split("\n")[0].split(" ")
        for k in range(len(data)):
            data[k] = int(data[k])

        if st == -1:
            st = data
            T.append(0)
        else:
            diff = (data[0]*3600000 + data[1]*60000 + data[2]*1000 +
                    data[3]) - (st[0]*3600000 + st[1]*60000 + st[2]*1000 + st[3])
            T.append(float(diff/1000))

    elif 'head_origin :' in line:
        data = line.split("\n")[0].split(":")[1].split(
            "(")[1].split(")")[0].split(", ")
        Hox.append(float(data[0]))
        Hoy.append(float(data[1]))
        Hoz.append(float(data[2]))

    elif 'Accelerometer[0]' in line:
        data = line.split("\n")[0].split(":")[1]
        Ax.append(float(data))

    elif 'Accelerometer[1]' in line:
        data = line.split("\n")[0].split(":")[1]
        Ay.append(float(data))

    elif 'Accelerometer[2]' in line:
        data = line.split("\n")[0].split(":")[1]
        Az.append(float(data))

    elif 'Gyroscope[0]' in line:
        data = line.split("\n")[0].split(":")[1]
        Gx.append(float(data))

    elif 'Gyroscope[1]' in line:
        data = line.split("\n")[0].split(":")[1]
        Gy.append(float(data))

    elif 'Gyroscope[2]' in line:
        data = line.split("\n")[0].split(":")[1]
        Gz.append(float(data))

    elif 'Magnetometer[0]' in line:
        data = line.split("\n")[0].split(":")[1]
        Mx.append(float(data))

    elif 'Magnetometer[1]' in line:
        data = line.split("\n")[0].split(":")[1]
        My.append(float(data))

    elif 'Magnetometer[2]' in line:
        data = line.split("\n")[0].split(":")[1]
        Mz.append(float(data))

    elif 'eye_cursor' in line:
        data = line.split("\n")[0].split(":")[1].split(
            "(")[1].split(")")[0].split(", ")
        Ex.append(float(data[0]))
        Ey.append(float(data[1]))
        Ez.append(float(data[2]))


def plot_cur(H, A, G, E, M, title):
    plt.figure(figsize=(10, 6))

    ylabel = ""
    if 'Head' in plot:
        ylabel = "Head Position (m)"
        plt.plot(T, H, label="Head Origin", color='red')

    if 'Accel' in plot:
        ylabel = "Accelerometer (m^2/s)"
        plt.plot(T, A,  label="Accelerometer", color='blue')

    if "Gyro" in plot:
        ylabel = "Gyroscope (rad/s)"
        plt.plot(T, G, label="Gyroscope", color='orange')

    if "Eye" in plot:
        ylabel = "Eye Cursor Position (m)"
        plt.plot(T, E,  label="Eye Cursor", color='cyan')

    if "Mag" in plot:
        ylabel = "Magnetometer (micro-tesla)"
        plt.plot(T, M,  label="Magnetometer", color='magenta')

    plt.legend(loc="upper right")
    plt.xlabel('time (s)', fontsize=20)
    plt.ylabel(ylabel, fontsize=20)
    plt.title(title, fontsize=20)
    plt.show()


plot_cur(Hox, Ax, Gx, Ex, Mx, "Plot For X Axis")
plot_cur(Hoy, Ay, Gy, Ey, My, "Plot For Y Axis")
plot_cur(Hoz, Az, Gz, Ez, Mz, "Plot For Z Axis")
