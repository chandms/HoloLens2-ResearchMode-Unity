import argparse
import os
import matplotlib.pyplot as plt
import numpy as np

# python plot_diff_user_same_gest.py --path1 <User1 Data Path> --path2 <User2 Data Path> --plot <cir/w/tri/square>

# select the gesture type that  you want to compare


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path1", help="read files from this path")
parser.add_argument("--path2", help="read files from this path")
parser.add_argument("--plot", help="read files from this path")

args = parser.parse_args()

if not args.path1 or not args.path2 or not args.plot:
    print("check with help")
    exit(1)


path1 = args.path1
path2 = args.path2
plot = args.plot

inp_files1 = os.listdir(path1)
filename1 = ""
for cur_file in inp_files1:
    cur_shape = cur_file.split(".txt")[0].split("_")[0]
    cur_shape = "".join(filter(lambda x: not x.isdigit(), cur_shape))
    if (cur_shape in plot):
        filename1 = cur_file
        break

inp_files2 = os.listdir(path2)
filename2 = ""
for cur_file in inp_files2:
    cur_shape = cur_file.split(".txt")[0].split("_")[0]
    cur_shape = "".join(filter(lambda x: not x.isdigit(), cur_shape))
    if (cur_shape in plot):
        filename2 = cur_file
        break


def get_list(lines, mn_val, mx_val):
    points = []
    count = []
    k = 0
    cnt = 0

    for line in lines:
        if (k % 1 == 0):
            data = float(line.split("\n")[0].split(" ")[it])
            if mn_val == -1:
                mn_val = data
            else:
                mn_val = min(mn_val, data)

            if mx_val == -1:
                mx_val = data
            else:
                mx_val = max(mx_val, data)

            points.append(data)
            count.append(cnt)
            cnt += 1
        k += 1
    return points, count, mn_val, mx_val


for it in range(3):
    plt.figure(figsize=(10, 6))
    lines = ""
    with open(path1+"/"+filename1, "r") as fp1:
        lines = fp1.readlines()

    mn_val = -1
    mx_val = -1
    points, count, mn_val, mx_val = get_list(lines, mn_val, mx_val)
    plt.plot(count, points, label=filename1.split(".txt")[0])

    lines = ""
    with open(path2+"/"+filename2, "r") as fp2:
        lines = fp2.readlines()

    points, count, mn_val, mx_val = get_list(lines, mn_val, mx_val)
    plt.plot(count, points, label=filename2.split(".txt")[0])

    yaxis_label = np.arange(mn_val, mx_val, 0.5)
    plt.yticks(yaxis_label)
    plt.ylabel("Gyroscope Reading (rad/s)", fontsize=18)
    plt.xlabel("Data Point Count", fontsize=18)
    plt.legend(loc="upper right")
    title = "Plot for "
    if (it == 0):
        title += "X Axis"
    elif (it == 1):
        title += "Y Axis"
    else:
        title += "Z Axis"
    plt.title(title, fontsize=18)
    plt.show()
