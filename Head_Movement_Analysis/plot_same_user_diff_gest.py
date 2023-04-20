import argparse
import os
import matplotlib.pyplot as plt
import numpy as np

# python plot_same_user_diff_gest.py --path <User Data Path> --plot <cir/w/tri/square/diff>
# pass diff if want to compare different gestures of same user
# pass particular gesture <cir/w/tri> to compare similar gesture for same user
# if nothing passed, will show all the files


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path", help="read files from this path")
parser.add_argument("--plot", help="read files from this path")

args = parser.parse_args()

if not args.path:
    print("check with help")
    exit(1)


filepath = args.path
plot = args.plot if args.plot else "all"

inp_files = os.listdir(filepath)


for it in range(3):
    gestures = []
    plt.figure(figsize=(10, 6))
    mn_val = -1
    mx_val = -1
    for cur_file in inp_files:
        cur_shape = cur_file.split(".txt")[0].split("_")[0]
        cur_shape = "".join(filter(lambda x: not x.isdigit(), cur_shape))
        if (plot == "diff"):
            if cur_shape not in gestures:
                gestures.append(cur_shape)
            else:
                continue

        if plot == "all" or plot in cur_file or plot == "diff":
            lines = ""
            with open(filepath+"/"+cur_file, 'r') as fp:
                lines = fp.readlines()

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

            plt.plot(count, points, label=cur_file.split(".txt")[0])

    yaxis_label = np.arange(mn_val, mx_val, 0.5)
    plt.yticks(yaxis_label)
    plt.xlabel("Data Point Count", fontsize=20)
    plt.ylabel("Gyroscope Reading (rad/s)", fontsize=20)
    title = "Plot for "
    if (it == 0):
        title += "X Axis"
    elif (it == 1):
        title += "Y Axis"
    else:
        title += "Z Axis"
    plt.title(title, fontsize=20)
    plt.legend(loc="upper right")
    plt.show()
