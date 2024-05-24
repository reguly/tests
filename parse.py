import sys
import os
import re
import glob
import pandas as pd
import numpy as np

# pattern to search as a regular expression
pattern = re.compile(r'Total Wall|GFLOP/s|Max total runtime|Main simulation runtime|semi_discrete_step|Wave propagation time')
#pattern = re.compile(r'Total CPU energy consumed')

# prepare a list to hold the results
dfs = []

# iterate over all directories given as command-line arguments
for directory in sys.argv[1:]:
    results = []
    # iterate over all files in the directory
    for filename in glob.glob(os.path.join(directory, '*')):
        total = 0.0
        count = 0
        with open(filename, 'r') as file:
            for line in file:
                if pattern.search(line):
                    # extract all floating-point numbers in the line
                    numbers = re.findall(r'[-+]?\d*\.\d+|\d+', line)
                    # iterate over the numbers and add them to the total
                    for number in numbers:
                        if number == '0':
                            continue
                        total += float(number)
                        count += 1
        # if pattern was found and we extracted some numbers
        if count > 0:
            average = total / count
            results.append([os.path.basename(filename), average])
    # create a DataFrame from the results and use directory name as the column for averages
    df = pd.DataFrame(results, columns=['File', os.path.basename(directory)])
    dfs.append(df)

# merge all DataFrames
df_final = dfs[0]
for df in dfs[1:]:
    df_final = df_final.merge(df, on='File', how='outer')

# Sort the final DataFrame by 'File'
df_final.sort_values('File', inplace=True)

# Add a column with the name of the column that has the smallest average for each row
df_final['MinAverage'] = df_final.iloc[:, 1:].idxmin(axis=1)

# print the final DataFrame
print(df_final.to_string())
