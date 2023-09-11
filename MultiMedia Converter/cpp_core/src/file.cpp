#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream> // For file existence check

using namespace std;

// Function to check if a file exists
bool fileExists(const string& filePath) {
    ifstream file(filePath.c_str());
    return file.good();
}

// Function to convert multimedia files
bool convertMultimedia(const string& sourceFile, const string& targetFormat, const string& outputLocation) {
    // Check if the source file exists
    if (!fileExists(sourceFile)) {
        cerr << "Source file does not exist." << endl;
        return false;
    }

    // Construct the FFmpeg command for conversion
    string ffmpegCommand = "ffmpeg -i \"" + sourceFile + "\" -f " + targetFormat + " \"" + outputLocation + "\"";

    // Execute using system()
    int returnCode = system(ffmpegCommand.c_str());

    // Check the return code to determine success or failure
    if (returnCode == 0) {
        // Conversion was successful
        return true;
    } else {
        // Conversion failed
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <sourceFile> <targetFormat> <outputLocation>" << endl;
        return 1;
    }

    // Extract command-line arguments
    string sourceFile = argv[1];
    string targetFormat = argv[2];
    string outputLocation = argv[3];

    // Perform multimedia conversion
    if (convertMultimedia(sourceFile, targetFormat, outputLocation)) {
        cout << "Conversion completed successfully." << endl;
        return 0;
    } else {
        cerr << "Conversion failed." << endl;
        return 1;
    }
}

