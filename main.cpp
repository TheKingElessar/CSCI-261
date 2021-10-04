/* CSCI 261 Assignment 4: PPM Editor
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * Read an image file and perform a few modifications on it.
 * this was actually lots of fun wtf i love cpp now??
 */

#include <iostream>
#include <fstream>

using namespace std;

const string BRICK_PATH = "brick";
const string WALLPAPER_PATH = "wallpaper";
const string PRIVATE_PATH = "private";

void greyscalePixel(int pixel[3]);

void invertPixel(int pixel[3], int maxValue);

void writePixel(const int pixel[3], ofstream &outputFile);

int main()
{

    /*
     * Read user's input: file and process.
     */
    cout << "Which image to load?\n"
            "  1. Brick\n"
            "  2. Wallpaper\n"
            "  3. Private\n"
            "Enter 1, 2, or 3: ";

    int input;
    cin >> input;
    while (input < 1 || input > 3 || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear();
            char errInput = cin.get();
            while (errInput != '\n')
            {
                errInput = cin.get();
            }
        }
        cout << "Invalid input. Try again." << endl;
        cout << "Which image to load?\n"
                "  1. Brick\n"
                "  2. Wallpaper\n"
                "  3. Private\n"
                "Enter 1, 2, or 3: ";
        cin >> input;
    }
    cout << endl;

    cout << "Which process to apply?\n"
            "  1. Grayscale\n"
            "  2. Inversion\n"
            "Enter 1 or 2: ";
    int process;
    cin >> process;
    while (process < 1 || process > 2)
    {
        if (cin.fail())
        {
            cin.clear();
            char errInput = cin.get();
            while (errInput != '\n')
            {
                errInput = cin.get();
            }
        }
        cout << "Invalid input. Try again." << endl;
        cout << "Which process to apply?\n"
                "  1. Grayscale\n"
                "  2. Inversion\n"
                "Enter 1 or 2: ";
        cin >> process;
    }

    cout << endl;

    /*
     * Get file path based on user input. Open and verify file.
     */
    string filePath;

    switch (input)
    {
        case 1:
            filePath = BRICK_PATH;
            break;
        case 2:
            filePath = WALLPAPER_PATH;
            break;
        case 3:
            filePath = PRIVATE_PATH;
            break;
    }

    ifstream inputFile(filePath + ".ppm");
    if (inputFile.fail())
    {
        cout << "File " << filePath << ".ppm" << " could not be opened. Exiting." << endl;
        return -1;
    }

    cout << "Opening " << filePath << " file." << endl;

    string fileType;
    inputFile >> fileType;

    if (!(fileType[0] == 'P' && fileType[1] == '3'))
    {
        cout << "File is type " << fileType << ", not P3. Exiting." << endl;
        return 0;
    }

    /*
     * Open output file.
     */
    string modifier;
    switch (process)
    {
        case 1:
            modifier = "_grayscale";
            break;
        case 2:
            modifier = "_inverted";
            break;
    }

    string outputFilePath = filePath + modifier + ".ppm";
    ofstream outputFile(outputFilePath);
    ofstream *streamPointer = &outputFile;

    if (outputFile.fail())
    {
        cout << "File " << outputFilePath << " could not be opened. Exiting." << endl;
        return -1;
    }

    cout << "Writing " << outputFilePath << " file." << endl;

    /*
     * Read metadata and write to output file.
     */
    int width, height, maxValue;
    inputFile >> width >> height >> maxValue;

    outputFile << "P3\n" << width << " " << height << "\n" << maxValue << endl;

    /*
     * Read each pixel for each column for each row.
     * The pixel's color values are saved in pixel[]:
     * [red, green, blue]
     *
     * Perform process on pixel and write it to output file.
     */
    int readValue;
    int pixel[3];

    for (int row = 1; row <= height; row++)
    {
        for (int column = 1; column <= width; column++)
        {
            for (int i = 0; i < 3; i++)
            {
                inputFile >> readValue;
                pixel[i] = readValue;
            }

            /*
             * Different actions based on user-chosen process.
             */
            switch (process)
            {
                case 1:
                {
                    greyscalePixel(pixel);
                    writePixel(pixel, *streamPointer);
                    break;
                }

                case 2:
                    invertPixel(pixel, maxValue);
                    writePixel(pixel, *streamPointer);
                    break;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Process complete." << endl;
    return 0;
}

void greyscalePixel(int pixel[3])
{
    double average = 0.2989 * pixel[0] + 0.5870 * pixel[1] + 0.1140 * pixel[2];
    for (int i = 0; i < 3; i++)
    {
        pixel[i] = (int) average;
    }
}

void invertPixel(int pixel[3], int maxValue)
{
    for (int i = 0; i < 3; i++)
    {
        pixel[i] = maxValue - pixel[i];
    }
}

/*
 * Writes a pixel array (3 int values) ot the file.
 */
void writePixel(const int pixel[3], ofstream &outputFile)
{
    for (int i = 0; i < 3; i++)
    {
        outputFile << pixel[i] << endl;
    }
}