#!/bin/bash

# Check if an argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

# Get the input filename from the command line argument
input_file="$1"

# Check if the input file exists
if [ ! -e "$input_file" ]; then
    echo "Error: File '$input_file' not found."
    exit 1
fi

# Check if the file ends with ".c++"
if [[ ! "$input_file" =~ \.cpp$ ]]; then
    echo "Error: '$input_file' is not a C++ source file."
    exit 1
fi

# Extract the file name without the extension
output_name="${input_file%.cpp}"

if [ -e "$output_name" ]; then 
    mv "$output_name" "$output_name.prev"
fi

# Compile the C++ file using g++ with debugging information
g++ -g -o "$output_name" *.cpp -lgmpxx -lgmp -std=c++23

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable: $output_name"
    echo "Running file"
    echo ""
    time ./"$output_name"
else
    echo "Compilation failed."
    echo "This may have been because you have multiple files with main methods in the directory."
fi
