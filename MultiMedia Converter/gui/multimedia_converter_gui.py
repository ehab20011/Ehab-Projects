import os
import tkinter as tk
import sys
from tkinter import filedialog
from tkinter import messagebox
from PIL import Image, ImageTk

# Add the path to the 'python_wrapper' folder to the Python path
python_wrapper_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'python_wrapper'))
sys.path.append(python_wrapper_path)

from multimedia_converter import convert_multimedia, validate_file_formats

def browse_source():
    file_path = filedialog.askopenfilename(filetypes=[("Multimedia files", "*.mp4 *.avi *.mkv *.wav *.mp3")])
    source_entry.delete(0, tk.END)
    source_entry.insert(0, file_path)

def browse_output_location():
    folder_path = filedialog.askdirectory()
    output_location_entry.delete(0, tk.END)
    output_location_entry.insert(0, folder_path)

def convert():
    source_file = source_entry.get()
    target_format = target_format_entry.get()
    output_location = output_location_entry.get()

    # Validate source and target formats
    source_format = source_file.split(".")[-1]
    target_format = target_format.lower()  # Ensure lowercase for comparison

    if not validate_file_formats(source_format, target_format):
        messagebox.showerror("Error", "Invalid source or target format.")
        return

    # Construct the full output path
    file_name = os.path.basename(source_file)  # Get the original file name
    full_output_path = os.path.join(output_location, file_name + '.' + target_format)

    # Perform the conversion
    if convert_multimedia(source_file, target_format, full_output_path):
        messagebox.showinfo("Success", "Conversion completed successfully.")
    else:
        messagebox.showerror("Error", "Conversion failed.")


# Create and configure the GUI window
root = tk.Tk()
root.title("Multimedia Converter")
icon_image = Image.open('pic.png').convert('RGB')
icon_photo = ImageTk.PhotoImage(icon_image)
root.wm_iconphoto(False, icon_photo)


# Define and arrange GUI elements
source_label = tk.Label(root, text="Source File:")
source_entry = tk.Entry(root)
browse_source_button = tk.Button(root, text="Browse", command=browse_source)

target_format_label = tk.Label(root, text="Target Format:")
target_format_entry = tk.Entry(root)

output_location_label = tk.Label(root, text="Output Location:")
output_location_entry = tk.Entry(root)
browse_output_button = tk.Button(root, text="Browse", command=browse_output_location)

convert_button = tk.Button(root, text="Convert", command=convert)

# Arrange GUI elements using grid layout
source_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")
source_entry.grid(row=0, column=1, padx=5, pady=5, columnspan=2)
browse_source_button.grid(row=0, column=3, padx=5, pady=5)

target_format_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")
target_format_entry.grid(row=1, column=1, padx=5, pady=5, columnspan=2)

output_location_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")
output_location_entry.grid(row=2, column=1, padx=5, pady=5, columnspan=2)
browse_output_button.grid(row=2, column=3, padx=5, pady=5)

convert_button.grid(row=3, column=0, columnspan=4, padx=5, pady=10)

# Run the Tkinter main loop
root.mainloop()

