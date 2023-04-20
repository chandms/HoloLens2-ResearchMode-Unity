# Apply DTW on repetitions for each gesture

import argparse
import datetime
import os
from tslearn.metrics import dtw, dtw_path, cdist_dtw
from sklearn.cluster import AffinityPropagation
import numpy as np
from sklearn import metrics
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import plotly.graph_objs as go
import pandas as pd
import plotly.express as px
import scipy
from scipy.stats import skew, kurtosis, median_abs_deviation
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import confusion_matrix, classification_report, accuracy_score
from prettytable import PrettyTable
import webbrowser


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path", help="read files from this path")
parser.add_argument(
    "--test_path", help="test files are stored in this location")

args = parser.parse_args()

if not args.path or not args.test_path:
    print("check with help")
    exit(1)

filepath = args.path
test_file_path = args.test_path

inp_files = os.listdir(filepath)


# list of gestures
gestures = ['cir', 'tri', 'w', 'square', 'b_']
gest_dict = {
    'cir': 'circle',
    'tri': 'triangle',
    'square': 'square',
    'w': 'w-shape'
}
# all the repetitions for above gestures will be stored
signals = []
# correponding signal file name will be stored
prev_label = []

# storing all the repetitions for all the gestures
for gest in gestures:
    for cur_file in inp_files:
        if gest in cur_file:
            lines = ""
            with open(filepath+"/"+cur_file, 'r') as f:
                lines = f.readlines()

            cur_data = []
            for line in lines:
                cdata = line.split(' ')
                cur_data.append(
                    [float(cdata[0]), float(cdata[1]), float(cdata[2])])
            signals.append(cur_data)
            prev_label.append(cur_file)


# initializing similarity matrix
rows, cols = (len(signals), len(signals))
similarity_matrix = [[0 for i in range(cols)] for j in range(rows)]


for j in range(len(signals)):

    for k in range(len(signals)):
        # applying dtw on any two above selected signals
        dt_path, dt_dist = dtw_path(signals[j], signals[k])
        similarity_matrix[j][k] = dt_dist
        # print(cdist_dtw(repetitions[j], repetitions[k]))


af = AffinityPropagation(random_state=0).fit(similarity_matrix)
cluster_centers_indices = af.cluster_centers_indices_
labels = af.labels_

n_clusters_ = len(cluster_centers_indices)

print("Estimated number of clusters: %d" % n_clusters_)
print(cluster_centers_indices)
# the indices in 'cluster_centers_indices' refer to signals
print(labels)

################################################################

# How good is AP algorithm in classifying different Head Movements #

################################################################


def rgb_to_hex(r, g, b):
    return '#{:02x}{:02x}{:02x}'.format(r, g, b)


comp_df = pd.DataFrame(
    columns=['True Label', 'Assigned Cluster', "Assigned User", "Assigned Shape"])

for j in range(len(signals)):
    cur_shape_assign = prev_label[cluster_centers_indices[labels[j]]].split(".txt")[
        0].split("_")[0]
    cur_user_assign = prev_label[cluster_centers_indices[labels[j]]].split(".txt")[
        0].split("_")[1]
    cur_shape_assign = "".join(
        filter(lambda x: not x.isdigit(), cur_shape_assign))
    comp_df.loc[len(comp_df)] = [prev_label[j].split(".txt")[0], "class " +
                                 str(labels[j]), cur_user_assign, gest_dict[cur_shape_assign]]

comp_df.style.set_properties(
    **{'border': '1px solid green', 'color': 'magenta'})
html_comp = comp_df.to_html()
html_comp_filename = 'output/comp_'+str(datetime.datetime.now())+".html"
with open(html_comp_filename, 'w') as hc:
    hc.write(html_comp)

print(comp_df)

fig = plt.figure(figsize=(10, 10))
ax = plt.axes(projection='3d')

df = pd.DataFrame()
color_dct = {}
color_lst = []

for j in range(len(signals)):
    cur_color = ""
    if (labels[j] in color_dct):
        cur_color = color_dct[labels[j]]
    else:
        while True:
            cur_color = list(np.random.choice(range(255), size=3))
            if cur_color not in color_lst:
                color_dct[labels[j]] = cur_color
                color_lst.append(cur_color)
                break

    cur_label = "class "+str(labels[j])
    cur_color = rgb_to_hex(cur_color[0], cur_color[1], cur_color[2])

    df2 = pd.DataFrame(signals[j], columns=['X', 'Y', 'Z'])
    color_list = [cur_color]*len(signals[j])
    label_list = [cur_label]*len(signals[j])
    prev_lable_list = [prev_label[j]]*len(signals[j])
    df2 = df2.assign(color=color_list)
    df2 = df2.assign(label=label_list)
    df2 = df2.assign(prev_label=prev_lable_list)
    df2 = df2.sample(n=15)
    df = df.append(df2)

    for k in range(len(signals[j])):
        if k % 20 == 0:
            ax.scatter(signals[j][k][0], signals[j][k][1], signals[j]
                       [k][2], s=40, color=cur_color, label=cur_label)

fig = px.scatter_3d(df, x='X', y='Y', z='Z', color='color',
                    symbol='label', hover_data=['prev_label'])
fig.show()
plt.show()

#############################################
# One way of Testing - Get some more test data
# Find out similarity score for each of this test instance with all the Exemplar found above
# Get the similarity score, pick the label where the score is lowest
#############################################

# store all the signals appearing as cluster center

centers = []


test_df = pd.DataFrame(
    columns=['True Label', 'Assigned Cluster', 'Assigned User', 'Assigned Shape'])

for k in range(len(cluster_centers_indices)):
    centers.append(signals[cluster_centers_indices[k]])


test_files = os.listdir(test_file_path)

for testf in test_files:
    lines = ""
    with open(test_file_path+"/"+testf, 'r') as tf:
        lines = tf.readlines()

    cur_signal_data = []
    for line in lines:
        cdata = line.split(' ')
        cur_signal_data.append(
            [float(cdata[0]), float(cdata[1]), float(cdata[2])])

    cur_score = []

    for j in range(len(centers)):
        dt_path, dt_dist = dtw_path(centers[j], cur_signal_data)

        cur_score.append(dt_dist)

    idf = -1

    for j in range(len(cur_score)):
        if idf == -1:
            idf = j
        else:
            if cur_score[j] < cur_score[idf]:
                idf = j

    cur_user = prev_label[cluster_centers_indices[idf]].split(".txt")[
        0].split("_")[1]

    cur_shape = prev_label[cluster_centers_indices[idf]].split(".txt")[
        0].split("_")[0]
    cur_shape = "".join(filter(lambda x: not x.isdigit(), cur_shape))
    cur_shape = gest_dict[cur_shape]

    test_df.loc[len(test_df)] = [
        testf.split(".txt")[0], "class "+str(labels[cluster_centers_indices[idf]]), cur_user, cur_shape]


test_df.style.set_properties(
    **{'border': '1px solid green', 'color': 'magenta'})


print('\n\n')
print(test_df)

html_test = test_df.to_html()
html_test_filename = "output/test_"+str(datetime.datetime.now())+".html"
with open(html_test_filename, "w") as th:
    th.write(html_test)
