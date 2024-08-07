import sys
import os
import re
import glob
import pandas as pd
import numpy as np

def parse_tiling(df, df_energy, df_mpi):
    reference_group = df[~df['File'].str.contains('tiled')]
    tiled_group = df[df['File'].str.contains('tiled')]

    # Extract the substring before "mpi" in the "File" column and add it as a new column for grouping
    # reference_group['Group'] = reference_group['File'].str.extract(r'^(.*?)mpi')
    # reference_group['Group'] = reference_group['File'].str.extract(r'^(.*?)mpi')
    reference_group['Group'] = reference_group['File'].str.extract(r'^(.*?)mpi')
    reference_group['Group'] = reference_group['Group'] + np.where(reference_group['File'].str.contains('omp'), 'omp', '')
    reference_group['BestEnergy'] = df_energy.loc[df_energy['File'].isin(reference_group['File']), 'Best'].values
    reference_group['BestEnergyDRAM'] = df_energy.loc[df_energy['File'].isin(reference_group['File']), 'Best_DRAM'].values
    reference_group['BestMPI'] = df_mpi.loc[df_mpi['File'].isin(reference_group['File']), 'Best'].values
    # Group by the new column and display the groups
    grouped_reference = reference_group.groupby('Group')

    # Find the minimum runtime for each group and the corresponding File
    best_runtime_df = grouped_reference.apply(lambda x: x.loc[x['Best'].idxmin()])

    # Select only the relevant columns: Group, File, and runtime
    best_runtime_df = best_runtime_df[['Group', 'File', 'Best']].reset_index(drop=True)
    best_runtime_df['BestEnergy'] = df_energy.loc[df_energy['File'].isin(best_runtime_df['File']), 'Best'].values
    best_runtime_df['BestEnergyDRAM'] = df_energy.loc[df_energy['File'].isin(best_runtime_df['File']), 'Best_DRAM'].values
    best_runtime_df['BestMPI'] = df_mpi.loc[df_mpi['File'].isin(best_runtime_df['File']), 'Best'].values


    # Extract the substring before "mpi" in the "File" column and add it as a new column for grouping
    tiled_group['Group'] = tiled_group['File'].str.extract(r'^(.*?)mpi')
    tiled_group['Group'] = tiled_group['Group'] + np.where(tiled_group['File'].str.contains('omp'), 'omp', '')

    # Group by the new column and find the minimum runtime for each group and the corresponding File
    grouped_tiled = tiled_group.groupby('Group')
    best_tiled_runtime_df = grouped_tiled.apply(lambda x: x.loc[x['Best'].idxmin()])

    # Select only the relevant columns: Group, File, and runtime
    best_tiled_runtime_df = best_tiled_runtime_df[['Group', 'File', 'Best']].reset_index(drop=True)

    # Merge the best runtime dataframes on the Group column to facilitate speedup calculation
    merged_df = pd.merge(best_runtime_df, best_tiled_runtime_df, on='Group', suffixes=('_ref', '_tiled'))

    # Calculate the speedup for each group
    merged_df['Speedup'] = merged_df['Best_ref'] / merged_df['Best_tiled']

    merged_df['BestEnergy_ref'] = df_energy.loc[df_energy['File'].isin(merged_df['File_ref']), 'Best'].values
    merged_df['BestEnergyDRAM_ref'] = df_energy.loc[df_energy['File'].isin(merged_df['File_ref']), 'Best_DRAM'].values
    merged_df['BestMPI_ref'] = df_mpi.loc[df_mpi['File'].isin(merged_df['File_ref']), 'Best'].values
    merged_df['BestEnergy_tiled'] = df_energy.loc[df_energy['File'].isin(merged_df['File_tiled']), 'Best'].values
    merged_df['BestEnergyDRAM_tiled'] = df_energy.loc[df_energy['File'].isin(merged_df['File_tiled']), 'Best_DRAM'].values
    merged_df['BestMPI_tiled'] = df_mpi.loc[df_mpi['File'].isin(merged_df['File_tiled']), 'Best'].values
    merged_df['Energy_speedup'] = merged_df['BestEnergy_ref'] / merged_df['BestEnergy_tiled']

    # Select relevant columns for display
    speedup_df = merged_df[['Group', 'File_ref', 'Best_ref', 'BestEnergy_ref', 'BestEnergyDRAM_ref', 'BestMPI_ref', 'File_tiled', 'Best_tiled', 'BestEnergy_tiled', 'BestEnergyDRAM_tiled','BestMPI_tiled','Speedup', 'Energy_speedup']]

    print(reference_group.to_string())
    print(best_runtime_df.to_string())
    print(speedup_df.to_string())

    # Filter speedup_df to exclude rows where Group contains "_sp_" or "opensbli"
    filtered_speedup_df = speedup_df[~speedup_df['Group'].str.contains('_sp_|opensbli')]
    print(filtered_speedup_df.to_string())

# pattern to search as a regular expression
pattern = re.compile(r'Total Wall|GFLOP/s|Max total runtime|Main simulation runtime|semi_discrete_step|Wave propagation time')
pattern_energy = re.compile(r'Total CPU energy consumed')
pattern_mpi = re.compile(r'halo exchange time')

# prepare a list to hold the results
dfs = []
dfs_energy = []
dfs_mpi = []

# iterate over all directories given as command-line arguments
for directory in sys.argv[1:]:
    results = []
    results_energy = []
    results_energy_dram = []
    results_mpi = []
    # iterate over all files in the directory
    for filename in glob.glob(os.path.join(directory, '*')):
        total = 0.0
        count = 0
        total_energy = 0.0
        total_energy_dram = 0.0
        count_energy = 0
        total_mpi = 0.0
        count_mpi = 0
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
                if pattern_energy.search(line):
                    # extract all floating-point numbers in the line
                    numbers = re.findall(r'[-+]?\d*\.\d+|\d+', line)
                    # iterate over the numbers and add them to the total
                    if len(numbers) > 0:
                        if numbers[0] == '0':
                            continue
                        total_energy += float(numbers[0])
                        count_energy += 1
                    #if there is a second number on the line, it is the energy consumed by the DRAM
                    if len(numbers) > 1:
                        if numbers[1] == '0':
                            continue
                        total_energy_dram += float(numbers[1])
                if pattern_mpi.search(line):
                    numbers = re.findall(r'[-+]?\d*\.\d+|\d+', line)
                    for number in numbers:
                        if number == '0':
                            continue
                        total_mpi += float(number)
                        count_mpi += 1

        # if pattern was found and we extracted some numbers
        if count > 0:
            average = total / count
            results.append([os.path.basename(filename), average])
            if count_mpi > 0:
                average_mpi = total_mpi / count_mpi
                results_mpi.append([os.path.basename(filename), average_mpi])
            else:
                results_mpi.append([os.path.basename(filename), 0])
            if count_energy > 0:
                average_energy = total_energy / count_energy
                average_energy_dram = total_energy_dram / count_energy
                results_energy.append([os.path.basename(filename), average_energy, average_energy_dram])
            else:
                results_energy.append([os.path.basename(filename), 0, 0])

    # create a DataFrame from the results and use directory name as the column for averages
    df = pd.DataFrame(results, columns=['File', os.path.basename(directory)])
    df_energy = pd.DataFrame(results_energy, columns=['File', os.path.basename(directory), os.path.basename(directory)+'_DRAM'])
    df_mpi = pd.DataFrame(results_mpi, columns=['File', os.path.basename(directory)])
    dfs.append(df)
    dfs_energy.append(df_energy)
    dfs_mpi.append(df_mpi)

# merge all DataFrames
df_final = dfs[0]
for df in dfs[1:]:
    df_final = df_final.merge(df, on='File', how='outer')

df_final_energy = dfs_energy[0]
for df in dfs_energy[1:]:
    df_final_energy = df_final_energy.merge(df, on='File', how='outer')

df_final_mpi = dfs_mpi[0]
for df in dfs_mpi[1:]:
    df_final_mpi = df_final_mpi.merge(df, on='File', how='outer')

# Sort the final DataFrame by 'File'
df_final.sort_values('File', inplace=True)
df_final_energy.sort_values('File', inplace=True)
df_final_mpi.sort_values('File', inplace=True)

# Convert the values in the DataFrame to numeric
# df_final.iloc[:, 1:] = df_final.iloc[:, 1:].apply(pd.to_numeric, errors='coerce')


# Add a column, showing the minimum value for each row
df_final['Best'] = df_final.iloc[:, 1:].min(axis=1)
df_final_energy_nodram = df_final_energy.loc[:, ~df_final_energy.columns.str.contains('_DRAM')]
df_final_energy['Best'] = df_final_energy_nodram.iloc[:, 1:].min(axis=1)
# Add a column with the name of the column that has the smallest average for each row
df_final['MinAverage'] = df_final.iloc[:, 1:-1].idxmin(axis=1)
df_final_energy['MinAverage'] = df_final_energy_nodram.iloc[:, 1:].idxmin(axis=1)
df_final_energy['Best_DRAM'] = df_final_energy['MinAverage'].apply(lambda x: x + '_DRAM')
df_final_energy['Best_DRAM'] = df_final_energy.apply(lambda row: row[row['Best_DRAM']], axis=1)
df_final_energy['BestRuntime'] = df_final['MinAverage']
df_final_energy['BestMatches'] = df_final_energy['MinAverage'] == df_final_energy['BestRuntime']
df_final['Best_MPI'] = df_final_mpi.apply(lambda row: row[df_final.loc[row.name, 'MinAverage']], axis=1)
df_final_mpi['Best'] = df_final['Best_MPI']

#for any rows with 'bude' in the filename, set the 'Best' value to the maximum value
df_final.loc[df_final['File'].str.contains('bude'), 'Best'] = df_final.iloc[:, 1:-2].max(axis=1)

# print the final DataFrame
print(df_final.to_string())
print(df_final_energy.to_string())

parse_tiling(df_final, df_final_energy, df_final_mpi)
