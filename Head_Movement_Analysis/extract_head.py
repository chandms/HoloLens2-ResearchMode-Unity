# Extract the head movement direction data for all the gestures and store in files

# Example Command -
# python extract_head.py --path <PATH> --out_path <PATH>

import argparse
import os


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path", help="read files from this path")
parser.add_argument("--out_path", help="write files in this path")

args = parser.parse_args()

if not args.path or not args.out_path:
    print("check with help")
    exit(1)


filepath = args.path

out_filepath = args.out_path

isExist = os.path.exists(out_filepath)
if not isExist:
    os.makedirs(out_filepath)

inp_files = os.listdir(filepath)


for cur_file in inp_files:
    print("reading ", cur_file)

    lines = ""
    with open(filepath+"/"+cur_file, 'r') as f:
        lines = f.readlines()

    out_str = ""
    for line in lines:
        if ('head_origin' in line):
            data = line.split(":")[1].split("\n")[0].split(
                "(")[1].split(")")[0].split(", ")
            out_str += (data[0]+" "+data[1]+" "+data[2])
            out_str += "\n"

    with open(out_filepath+"/"+cur_file, 'w') as f2:
        f2.writelines(out_str)
