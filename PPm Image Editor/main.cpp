// FATEMEH SAREMI
// CS 201
//
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    string newFileName;
    string headerVal;
    //string pathway = "C:\\Users\\fs4re\\CLionProjects\\untitled1\\";

    int width, length,
        brightness, choice;

    cout << "Portable Pixmap (PPM) Image Modder" << endl;

    do
    {
        cout << "Enter image file name (ppm): " << endl;
        cin >> fileName;
        inputFile.open(fileName);
    }while(!inputFile);

    cout << "\nAFTER THE LOOP" << endl;

    // saving the Header File
    inputFile >> headerVal;
    inputFile >> width >> length >> brightness;

    //test statement
    cout << headerVal << " " << width << " " << length << " " << brightness << endl;

    cout << "Enter output image file name: " << endl;
    cin >> newFileName;
    outputFile.open(newFileName);

    //checking size of the image file
    if (length > 1000 || width > 1000)
        return 0;

    //importing the header information to the new file
    outputFile << headerVal << endl;
    outputFile << width << " " << length << endl;
    outputFile << brightness << endl;

    //Display Menu
    do
    {
        cout << " Image Processing Choices: " << endl
             << "1. Convert to greyscale" << endl
             << "2. Invert Red" << endl
             << "3. Invert Green" << endl
             << "4. Invert Blue" << endl
             << "5. Invert All" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
    } while(choice > 5 || choice <0);

    //temporary variables
    int val1, val2, val3;

    while (inputFile >> val1 >> val2 >> val3)
    {
        switch(choice)
        {
            case 1:
            {
                int total = val1 + val2 + val3;
                int mean = total / 3;
                outputFile << mean << " " << mean << " " << mean << " ";
                break;
            }
            case 2:
            {
                int redPixle;
                redPixle = 255 - val1;
                outputFile << redPixle << " " << val2 << " " << val3 << " ";
                break;
            }
            case 3:
            {
                int greenPixle;
                greenPixle = 255 - val2;
                outputFile << val1 << " " << greenPixle << " " << val3 << " ";
                break;
            }
            case 4:
            {
                int bluePixle;
                bluePixle = 255 - val3;
                outputFile << val1 << " " << val2 << " " << bluePixle << " ";
                break;
            }
            case 5:
            {
                int redPixle, greenPixle, bluePixle;
                redPixle = 255 - val1;
                greenPixle = 255 - val2;
                bluePixle = 255 - val3;
                outputFile << redPixle << " " << greenPixle << " " << bluePixle << " ";
                break;
            }
            default:
                cout << "DEFAULT";
                break;
        }
    }
/*
        switch(choice)
        {
            case 1: //GREYSCALE
                while (inputFile >> val1 >> val2 >> val3)
                {
                    int total = val1 + val2 + val3;
                    int mean = total / 3;
                    outputFile << mean << " " << mean << " " << mean << " ";
                }
                break;
            case 2: //INVERT RED
                int redPixle;
                cout << "OUTSIDE";
                while (inputFile >> val1 >> val2 >> val3)
                {
                    redPixle = 255 - val1;
                    outputFile << redPixle << " " << val2 << " " << val3 << " ";
                }
                break;
            default:
                cout << "DEFAULT" << endl;
        }
    }
    else
    {
        cout << "File too large. Program exit";
        return 0;
    }
     */
    outputFile.close();
    inputFile.close();

    return 0;
}
