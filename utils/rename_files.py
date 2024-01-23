import os
import glob

directory = '/path/to/your/directory'  # Replace with your directory
pattern = '*.root'  # Replace with your pattern


def rename_files(directory, pattern):
    files = glob.glob(os.path.join(directory, pattern))

    for i, file in enumerate(files):
        new_name = os.path.join(directory, f'ntuple_{i}.root')
        os.rename(file, new_name)
        print(f'Renamed {file} to {new_name}')


rename_files(directory, pattern)
