# Dataset

    1. user1 - 2 different datasets of user1 (folder - user1_day1, user1_day2)
    2. user2 - 2 different datasets of user2 (folder - user2_day1, user2_day2)
    3. user3 - 1 dataset (folder - user3_day1)

# Note - keep the scipts in same directory as of dataset folders

# Extract gyroscope data

## Note - OUTPUT folder may not exist - that is fine (Name a separate folder as output path)

    python extract_gyro.py --path <PATH TO INPUT FOLDER> --out_path <PATH TO OUTPUT FOLDER>

# Extract head origin data

## Note - OUTPUT folder may not exist - that is fine (Name a separate folder as output path)

    python extract_head.py --path <PATH TO INPUT FOLDER> --out_path <PATH TO OUTPUT FOLDER>

# Plot all sensor data for a particular file

    python plot_all_sensors.py --path <PATH TO INPUT FILE> --plot <Accel/Mag/Gyro/Head/Eye>

# Plot Different user, same gesture

    python plot_diff_user_same_gest.py --path1 <USER1 GYRO/HEAD FOLDER PATH> --path2 <USER2 GYRO/HEAD FOLDER PATH> --plot <cir/w/tr/square/diff>

# Plot Same user, different gesture

    python plot_same_user_diff_gest.py --path <USER GYRO/HEAD FOLDER PATH> --plot <cir/w/tr/square/diff>

# DTW Affinity -

    # Please create a Output folder where the script is

    python dtw_sim_affinity.py --path <USER GYRO/HEAD FOLDER1 PATH> --test_path <USER GYRO/HEAD FOLDER2 PATH>

# DTW SVM on AP cluster id -

    # MIX ALL GYRO DATA FROM ALL USER IN A NEW FOLDER

    python dtw_sim_svm_tsfresh.py --path <PATH TO NEW FOLDER>

# DTW SVM on user id-

    # MIX ALL GYRO DATA FROM ALL USER IN A NEW FOLDER

    python dtw_sim_svm_user_tsfresh.py --path <PATH TO NEW FOLDER>
