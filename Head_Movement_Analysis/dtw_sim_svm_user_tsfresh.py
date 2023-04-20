# Apply DTW on repetitions for each gesture

from sklearn.metrics import confusion_matrix, classification_report, accuracy_score
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
from scipy.stats import median_abs_deviation
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import cross_val_score, GridSearchCV
from tsfresh.feature_extraction.feature_calculators import variation_coefficient, variance_larger_than_standard_deviation, variance, symmetry_looking, sum_values, sum_of_reoccurring_data_points, standard_deviation, skewness, sample_entropy, root_mean_square, ratio_value_number_to_time_series_length, number_peaks, number_cwt_peaks, median, mean_second_derivative_central, mean_change, mean_abs_change, mean, longest_strike_below_mean, longest_strike_above_mean, kurtosis, absolute_sum_of_changes, abs_energy
import warnings
warnings.filterwarnings('ignore')


parser = argparse.ArgumentParser(description='gyroscope data extract ')
parser.add_argument("--path", help="read files from this path")
args = parser.parse_args()

if not args.path:
    print("check with help")
    exit(1)

filepath = args.path

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

################################################################

# How good is AP algorithm in classifying different Head Movements #

################################################################


comp_df = pd.DataFrame(
    columns=['True Label', 'Assigned Cluster', "User", "Shape"])

user_true_label = []
for j in range(len(signals)):
    cur_shape_assign = prev_label[cluster_centers_indices[labels[j]]].split(".txt")[
        0].split("_")[0]
    cur_user_assign = prev_label[cluster_centers_indices[labels[j]]].split(".txt")[
        0].split("_")[1]
    cur_shape_assign = "".join(
        filter(lambda x: not x.isdigit(), cur_shape_assign))
    comp_df.loc[len(comp_df)] = [prev_label[j], "class " +
                                 str(labels[j]), cur_user_assign, gest_dict[cur_shape_assign]]
    user_true_label.append(cur_user_assign)


print(comp_df)

# Feature Extraction
# mean, std, rms, kurtosis, skewness, median absolute deviation
# zero crossing rate, inter quartile range,
# inter axis correlation,
# avg peak to peak duration, avg peak to peak amplitude, peak number

# extract features from each signals above
# assign the label obtained after AP
# test using new samples

# One way
# we can use the whole file's data and extract features
# Other Way
# we can divide the data into some chunks and
# for each chunk -> get the features, assign same labels.
############################################

# feature extraction of traing samples

extended_signals = []
extended_labels = []
extended_user_labels = []
for j in range(len(signals)):
    # change this variable to 1 if no need to divide the data
    # or change to some other value
    div = 1

    full_len = float(len(signals[j])/div)

    it = 0
    cur_sig = []
    for k in range(len(signals[j])):
        if it < full_len:
            cur_sig.append(signals[j][k])
            it += 1
        if (it >= full_len) or (k+1 == len(signals[j])):
            extended_signals.append(cur_sig)
            extended_labels.append(labels[j])
            extended_user_labels.append(user_true_label[j])
            cur_sig = []
            it = 0


full_dataset = []
full_dataset_label = []
full_user_dataset_label = []
for j in range(len(extended_signals)):
    ex_sig = extended_signals[j]

    feats = []
    # X, Y, Z separately

    # Storing X
    temp_x = []
    for k in range(len(ex_sig)):
        xsig = ex_sig[k][0]
        temp_x.append(xsig)

    # Storing Y
    temp_y = []
    for k in range(len(ex_sig)):
        ysig = ex_sig[k][1]
        temp_y.append(ysig)

    # Storing Z
    temp_z = []
    for k in range(len(ex_sig)):
        zsig = ex_sig[k][2]
        temp_z.append(zsig)

    # Storing X features first

    # variation_coefficient, variance_larger_than_standard_deviation, variance,
    # sum_values, sum_of_reoccurring_data_points, standard_deviation,
    # skewness, sample_entropy, root_mean_square,
    # ratio_value_number_to_time_series_length, number_cwt_peaks, number_peaks,
    # number_cwt_peaks, median, mean_second_derivative_central, mean_n_absolute_max,
    # mean_change, mean_abs_change, mean, longest_strike_below_mean, longest_strike_above_mean,

    feats.append(abs_energy(np.array(temp_x)))  # abs_energy
    # absolute_sum_of_changes
    feats.append(absolute_sum_of_changes(np.array(temp_x)))
    feats.append(kurtosis(np.array(temp_x)))  # kurtosis
    # longest_strike_above_mean
    feats.append(longest_strike_above_mean(np.array(temp_x)))
    # longest_strike_below_mean
    feats.append(longest_strike_below_mean(np.array(temp_x)))
    feats.append(mean(np.array(temp_x)))  # mean
    feats.append(mean_abs_change(np.array(temp_x)))  # mean_abs_change
    feats.append(mean_change(np.array(temp_x)))  # mean_change
    # mean_second_derivative_central
    feats.append(mean_second_derivative_central(np.array(temp_x)))
    feats.append(median(np.array(temp_x)))  # median
    # number_cwt_peaks, can change the n later
    feats.append(number_cwt_peaks(np.array(temp_x), 10))
    # number_peaks
    feats.append(number_peaks(np.array(temp_x), 10))
    feats.append(ratio_value_number_to_time_series_length(np.array(temp_x)))
    feats.append(root_mean_square(np.array(temp_x)))
    feats.append(sample_entropy(np.array(temp_x)))
    feats.append(skewness(np.array(temp_x)))
    feats.append(standard_deviation(np.array(temp_x)))
    feats.append(sum_of_reoccurring_data_points(np.array(temp_x)))
    feats.append(sum_values(np.array(temp_x)))
    feats.append(variance(np.array(temp_x)))
    feats.append(variance_larger_than_standard_deviation(np.array(temp_x)))
    feats.append(variation_coefficient(np.array(temp_x)))
    feats.append(median_abs_deviation(temp_x))  # median_abs_deviation

    # Storing Y features second

    feats.append(abs_energy(np.array(temp_y)))  # abs_energy
    # absolute_sum_of_changes
    feats.append(absolute_sum_of_changes(np.array(temp_y)))
    feats.append(kurtosis(np.array(temp_y)))  # kurtosis
    # longest_strike_above_mean
    feats.append(longest_strike_above_mean(np.array(temp_y)))
    # longest_strike_below_mean
    feats.append(longest_strike_below_mean(np.array(temp_y)))
    feats.append(mean(np.array(temp_y)))  # mean
    feats.append(mean_abs_change(np.array(temp_y)))  # mean_abs_change
    feats.append(mean_change(np.array(temp_y)))  # mean_change
    # mean_second_derivative_central
    feats.append(mean_second_derivative_central(np.array(temp_y)))
    feats.append(median(np.array(temp_y)))  # median
    # number_cwt_peaks, can change the n later
    feats.append(number_cwt_peaks(np.array(temp_y), 10))
    # number_peaks
    feats.append(number_peaks(np.array(temp_y), 10))
    feats.append(ratio_value_number_to_time_series_length(np.array(temp_y)))
    feats.append(root_mean_square(np.array(temp_y)))
    feats.append(sample_entropy(np.array(temp_y)))
    feats.append(skewness(np.array(temp_y)))
    feats.append(standard_deviation(np.array(temp_y)))
    feats.append(sum_of_reoccurring_data_points(np.array(temp_y)))
    feats.append(sum_values(np.array(temp_y)))
    feats.append(variance(np.array(temp_y)))
    feats.append(variance_larger_than_standard_deviation(np.array(temp_y)))
    feats.append(variation_coefficient(np.array(temp_y)))
    feats.append(median_abs_deviation(temp_y))

    # Storing Z features third

    feats.append(abs_energy(np.array(temp_z)))  # abs_energy
    # absolute_sum_of_changes
    feats.append(absolute_sum_of_changes(np.array(temp_z)))
    feats.append(kurtosis(np.array(temp_z)))  # kurtosis
    # longest_strike_above_mean
    feats.append(longest_strike_above_mean(np.array(temp_z)))
    # longest_strike_below_mean
    feats.append(longest_strike_below_mean(np.array(temp_z)))
    feats.append(mean(np.array(temp_z)))  # mean
    feats.append(mean_abs_change(np.array(temp_z)))  # mean_abs_change
    feats.append(mean_change(np.array(temp_z)))  # mean_change
    # mean_second_derivative_central
    feats.append(mean_second_derivative_central(np.array(temp_z)))
    feats.append(median(np.array(temp_z)))  # median
    # number_cwt_peaks, can change the n later
    feats.append(number_cwt_peaks(np.array(temp_z), 10))
    # number_peaks
    feats.append(number_peaks(np.array(temp_z), 10))
    feats.append(ratio_value_number_to_time_series_length(np.array(temp_z)))
    feats.append(root_mean_square(np.array(temp_z)))
    feats.append(sample_entropy(np.array(temp_z)))
    feats.append(skewness(np.array(temp_z)))
    feats.append(standard_deviation(np.array(temp_z)))
    feats.append(sum_of_reoccurring_data_points(np.array(temp_z)))
    feats.append(sum_values(np.array(temp_z)))
    feats.append(variance(np.array(temp_z)))
    feats.append(variance_larger_than_standard_deviation(np.array(temp_z)))
    feats.append(variation_coefficient(np.array(temp_z)))
    feats.append(median_abs_deviation(temp_z))

    full_dataset.append(feats)

    # finally append the label
    full_dataset_label.append(extended_labels[j])

    # appending the user label
    full_user_dataset_label.append(extended_user_labels[j])


# Train with SVM
X_train, X_test, y_train, y_test = train_test_split(
    full_dataset, full_user_dataset_label, test_size=0.3, random_state=42)

sc = StandardScaler()

X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

params_grid = [{'kernel': ['rbf'], 'gamma': [1e-3, 1e-4],
                'C': [1, 10, 100, 1000]},
               {'kernel': ['linear'], 'C': [1, 10, 100, 1000]}]

clf = GridSearchCV(SVC(), params_grid, cv=5)


clf.fit(X_train, y_train)

print('Best score for training data:', clf.best_score_, "\n")

# View the best parameters for the model found using grid search
print('Best C:', clf.best_estimator_.C, "\n")
print('Best Kernel:', clf.best_estimator_.kernel, "\n")
print('Best Gamma:', clf.best_estimator_.gamma, "\n")

final_model = clf.best_estimator_

# train with the best model
final_model.fit(X_train, y_train)
y_pred = final_model.predict(X_test)

print(y_pred)
print(y_test)

accuracy = accuracy_score(y_test, y_pred)*100
confusion_mat = confusion_matrix(y_test, y_pred)

# Printing the results
print("Accuracy for SVM is:", accuracy)
print("Confusion Matrix")
print(confusion_mat)

print("############# classification_report #####################")
print(classification_report(y_test, y_pred))

print("Training set score for SVM: %f" % final_model.score(X_train, y_train))
print("Testing  set score for SVM: %f" % final_model.score(X_test, y_test))
