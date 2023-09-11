import subprocess
import os

# Function to check if a file exists
def file_exists(file_path):
    return os.path.isfile(file_path)

# Function to validate file formats
def validate_file_formats(source_format, target_format):
    # List of supported formats (you can extend this list as needed)
    supported_formats = ["mp4", "avi", "mkv", "wav", "mp3"]

    if source_format not in supported_formats:
        print(f"Source format '{source_format}' is not supported.")
        return False

    if target_format not in supported_formats:
        print(f"Target format '{target_format}' is not supported.")
        return False

    return True

def convert_multimedia(source_file, target_format, output_location):
    # Validate source and target formats
    source_format = source_file.split(".")[-1]
    target_format = target_format.lower()  # Ensure lowercase for comparison

    if not validate_file_formats(source_format, target_format):
        return False

    # Check if the source file exists
    if not file_exists(source_file):
        print("Source file does not exist.")
        return False

    # Path to the C++ executable
    executable_path = r'C:\Users\ahmed\Desktop\MultiMedia Converter\cpp_core\src\file.exe'

    # Construct the command to call the C++ executable
    command = f'"{executable_path}" "{source_file}" {target_format} "{output_location}"'

    # Execute the command
    result = subprocess.run(command, shell=True)

    if result.returncode == 0:
        print("Conversion completed successfully.")
        return True
    else:
        print("Conversion failed.")
        return False

if __name__ == "__main__":
    source_file = "input.mp4"  # Replace with the actual path to your input file
    target_format = "mp3"      # Replace with the desired target format
    output_location = "output.mp3"  # Replace with the desired output location

    convert_multimedia(source_file, target_format, output_location)
