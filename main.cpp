// I cannot feel my teeth

#include <iostream>
#include <fstream>

using namespace std;

const string BRICK_PATH = "brick.ppm";
const string WALLPAPER_PATH = "wallpaper.ppm";
const string PRIVATE_PATH = "private.ppm";

int greyscaleAverage(const int pixel[3]);

int main()
{

    /*
     * User inputs which file and process
     */
    cout << "Which image to load?"
            "  1. Brick\n"
            "  2. Wallpaper\n"
            "  3. Private\n"
            "Enter 1, 2, or 3: ";

    int input;
    cin >> input;
    while (input < 1 || input > 3)
    {
        cout << "Invalid input. Try again." << endl << endl;
        cin >> input;
    }

    cout << "Which process to apply?\n"
            "  1. Grayscale\n"
            "  2. Inversion\n"
            "Enter 1 or 2: ";
    int process;
    cin >> process;
    while (process < 1 || process > 2)
    {
        cout << "Invalid input. Try again." << endl << endl;
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

    ifstream inputFile(filePath);
    if (inputFile.fail())
    {
        cout << "File " << filePath << " could not be opened. Exiting." << endl;
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
     * Read metadata.
     */
    int width, height, maxValue;
    inputFile >> height >> width >> maxValue;

    /*
     * Read each pixel for each column for each row.
     * The pixel's color values are saved in pixel[]:
     * [red, green, blue]
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
        }
    }

    inputFile.close();
    return 0;
}

int greyscaleAverage(const int pixel[3])
{
    double average = 0.2989 * pixel[0] + 0.5870 * pixel[1] + 0.1140 * pixel[2];
    return (int) average;
}