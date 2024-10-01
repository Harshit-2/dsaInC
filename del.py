import os

# Use the same directory as before
directory = './'

# Iterate over all the files in the directory
for filename in os.listdir(directory):
    # Check if the filename starts with 'CWH_'
    if filename.startswith('CWH_'):
        # Create the new filename by removing 'CWH_'
        new_filename = filename.replace('CWH_', '', 1)
        
        # Get the full paths
        old_file = os.path.join(directory, filename)
        new_file = os.path.join(directory, new_filename)
        
        # Rename the file
        os.rename(old_file, new_file)
        print(f'Renamed: {filename} -> {new_filename}')

print('Renaming completed.')
