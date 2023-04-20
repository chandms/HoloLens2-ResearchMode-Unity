# Dataset

    1. user1 - 2 different datasets of user1 (folder - user1_day1, user1_day2)
    2. user2 - 2 different datasets of user2 (folder - user2_day1, user2_day2)
    3. user3 - 1 dataset (folder - user3_day1)

### <span style="color:red"> Note - keep the scipts in same directory with the dataset folders.</span>

<span style="color:blue"> In the command line, move to Head_Movement_Analysis folder and keep everything as it is, then execute the scripts using correct commands. </span>

# Plot all sensor data for a particular file

    python plot_all_sensors.py --path <PATH TO INPUT FILE> --plot <Accel/Mag/Gyro/Head/Eye>
    Example - python plot_all_sensors.py --path user1_day1/cir1_user1.txt --plot Gyro

# Extract gyroscope data

### Note - OUTPUT folder may not exist - that is fine (Name a separate folder as output path)

    python extract_gyro.py --path <PATH TO INPUT FOLDER> --out_path <PATH TO OUTPUT FOLDER>
    Example - python extract_gyro.py --path user1_day1 --out_path user1_day1_gyro
    Example - python extract_gyro.py --path user1_day2 --out_path user1_day2_gyro
    Example - python extract_gyro.py --path user2_day1 --out_path user2_day1_gyro

# Extract head origin data

### Note - OUTPUT folder may not exist - that is fine (Name a separate folder as output path)

    python extract_head.py --path <PATH TO INPUT FOLDER> --out_path <PATH TO OUTPUT FOLDER>
    Example - python extract_head.py --path user1_day1 --out_path user1_day1_head

# Plot Figures for Different User, Same Gesture

    python plot_diff_user_same_gest.py --path1 <USER1 GYRO/HEAD FOLDER PATH> --path2 <USER2 GYRO/HEAD FOLDER PATH> --plot <cir/w/tri/square/diff>
    Example - python plot_diff_user_same_gest.py --path1 user1_day1_gyro --path2 user2_day1_gyro --plot cir
    Example - python plot_diff_user_same_gest.py --path1 user1_day1_gyro --path2 user2_day1_gyro --plot tri

# Plot Figures for Same User, Different/Same Gesture

    python plot_same_user_diff_gest.py --path <USER GYRO/HEAD FOLDER PATH> --plot <cir/w/tri/square/diff>

    To compare same gestures of same user, use <ins>cir or w or tr or square</ins> as input in plot argument.
    Example - python plot_same_user_diff_gest.py --path user1_day1_gyro --plot square

    To compare Different gestures of same user, use <ins>diff</ins> as input in plot argument.
    Example - python plot_same_user_diff_gest.py --path user1_day1_gyro --plot diff

# DTW Affinity -

### output folder is already created [html tables will be stored there]

### 3D plot will also popup.

    python dtw_sim_affinity.py --path <USER GYRO/HEAD FOLDER1 PATH> --test_path <USER GYRO/HEAD FOLDER2 PATH>
    Example - python dtw_sim_affinity.py --path user1_day1_gyro --test_path user1_day2_gyro

# DTW SVM on AP cluster id -

### MIX either all GYRO or HEAD data FROM ALL USER IN A NEW FOLDER

    python dtw_sim_svm_tsfresh.py --path <PATH TO NEW FOLDER>

    Create a new folder MIX_GYRO, put all the extracted gyro files from all the users or create a new folder MIX_HEAD, put all the extracted head files from all the users.
    For example - copy all the files from user1_day1_gyro, user1_day2_gyro, user2_day1_gyro

    Example - python dtw_sim_svm_tsfresh.py --path MIX_GYRO
    Example - python dtw_sim_svm_tsfresh.py --path MIX_HEAD

# DTW SVM on user id-

### MIX either all GYRO or HEAD data FROM ALL USER IN A NEW FOLDER

    python dtw_sim_svm_user_tsfresh.py --path <PATH TO NEW FOLDER>

    Create a new folder MIX_GYRO, put all the extracted gyro files from all the users or create a new folder MIX_HEAD, put all the extracted head files from all the users.
    For example - copy all the files from user1_day1_gyro, user1_day2_gyro, user2_day1_gyro

    Example - python dtw_sim_svm_user_tsfresh.py --path MIX_GYRO
    Example - python dtw_sim_svm_user_tsfresh.py --path MIX_HEAD
