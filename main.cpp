/* CSCI 261 Assignment 5: Wavefront OBJ File Validator
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * Your task for this assignment is to read in a simplified Wavefront OBJ file and validate if it would correctly form a model.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Vertex
{
    float x;
    float y;
    float z;
};

struct Face
{
    int v1;
    int v2;
    int v3;
};

int main()
{

    cout << "What file would you like to open? ";
    string inputFileName;
    getline(cin, inputFileName);

    ifstream inputFile(inputFileName);

    if (inputFile.fail())
    {
        cout << "Error opening file " << inputFileName << ". Exiting." << endl;
        return -1;
    }

    vector<string> comments;
    vector<Vertex> vertices;
    vector<Face> faces;

    char firstChar;
    while (!inputFile.eof())
    {
        firstChar = inputFile.get();
        switch (firstChar)
        {
            case '#':
            {
                string readString;
                getline(inputFile, readString);
                comments.push_back(readString);
                break;
            }
            case 'v':
            {
                Vertex vertex{};
                inputFile >> vertex.x;
                inputFile >> vertex.y;
                inputFile >> vertex.z;
                vertices.push_back(vertex);
                break;
            }
            case 'f':
            {
                Face face{};
                inputFile >> face.v1;
                inputFile >> face.v2;
                inputFile >> face.v3;
                faces.push_back(face);
                break;
            }
        }
    }

    cout << "Read in" << endl;
    cout << "    " << comments.size() << " comments" << endl;
    cout << "    " << vertices.size() << " vertices" << endl;
    cout << "    " << faces.size() << " faces" << endl;

    cout << "Validating faces..." << endl;

    bool invalid = false;
    for (int i = 1; i <= faces.size(); i++)
    {
        bool duplicateIndices = false;
        Face face = faces[i - 1];
        if (face.v1 == face.v2 || face.v1 == face.v3)
        {
            duplicateIndices = true;
        }
        if (face.v2 == face.v1 || face.v2 == face.v3)
        {
            duplicateIndices = true;
        }
        if (face.v3 == face.v1 || face.v3 == face.v2)
        {
            duplicateIndices = true;
        }

        bool outOfRange = false;
        if (face.v1 > vertices.size() || face.v1 < 1)
        {
            outOfRange = true;
        }
        if (face.v2 > vertices.size() || face.v2 < 1)
        {
            outOfRange = true;
        }
        if (face.v3 > vertices.size() || face.v3 < 1)
        {
            outOfRange = true;
        }

        if (duplicateIndices)
        {
            cout << "    Face " << i << " has duplicate indices" << endl;
        }

        if (outOfRange)
        {
            cout << "    Face " << i << " contains vertices out of range" << endl;
        }

        invalid = duplicateIndices || outOfRange;
    }

    if (invalid)
    {
        cout << "File is invalid. Exiting." << endl;
        return 0;
    }
    else
    {
        cout << "File is valid!" << endl;
    }

    while (true)
    {
        cout << endl;
        cout << "What do you wish to do?\n"
                "    1) Print comments\n"
                "    2) Print vertices\n"
                "    3) Print faces\n"
                "    4) Quit\n"
                "Choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                for (int i = 1; i <= comments.size(); i++)
                {
                    cout << "Comment #" << i << ": " << comments.at(i - 1) << endl;
                }
                break;
            case 2:
                for (int i = 1; i <= vertices.size(); i++)
                {
                    cout << "Vertex #" << i << ": (" << vertices.at(i - 1).x << ", " << vertices.at(i - 1).y << ", "
                         << vertices.at(i - 1).z << ")" << endl;
                }
                break;
            case 3:
                for (int i = 1; i <= faces.size(); i++)
                {
                    cout << "Face #" << i << ":    ";
                    cout << "(" << vertices.at(faces.at(i - 1).v1 - 1).x << ", "
                         << vertices.at(faces.at(i - 1).v1 - 1).y
                         << ", "
                         << vertices.at(faces.at(i - 1).v1 - 1).z << ")    ";
                    cout << "(" << vertices.at(faces.at(i - 1).v2 - 1).x << ", "
                         << vertices.at(faces.at(i - 1).v2 - 1).y
                         << ", "
                         << vertices.at(faces.at(i - 1).v2 - 1).z << ")    ";
                    cout << "(" << vertices.at(faces.at(i - 1).v3 - 1).x << ", "
                         << vertices.at(faces.at(i - 1).v3 - 1).y
                         << ", "
                         << vertices.at(faces.at(i - 1).v3 - 1).z << ")";
                    cout << endl;
                }
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
        }
    }
}