/* CSCI 261 Assignment 6: Green Eggs and Ham
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * In this homework, we will focus on arrays, vectors, strings, File I/O, and Functions!

Copyright 2021 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "functions.h"

int main() {
    // get filename to open
    string filename = promptUserForFilename();

    // open file for parsing
    ifstream fileIn;
    if( !openFile(fileIn, filename) ) {
        cerr << "Could not open file \"" << filename << "\"" << endl;
        cerr << "Shutting down" << endl;
        return -1;
    }

    // read all the words in the file
    vector<string> allWords = readWordsFromFile(fileIn);
    fileIn.close();
    cout << "Read in " << allWords.size() << " words" << endl;

    //*************************************************************************************
    // word processing

    // clean the words to remove punctuation and convert to uppercase
    removePunctuation(allWords, "?!.,;:\"()_");
    capitalizeWords(allWords);

    // todo: start here

    // find only the unique words in the file
    vector<string> uniqueWords = filterUniqueWords(allWords);
    cout << "Encountered " << uniqueWords.size() << " unique words" << endl;

    // count the number of occurrences of each word
    vector<unsigned int> uniqueWordCounts = countUniqueWords(allWords, uniqueWords);

    // sort the words by count
    sortWordsByCounts(uniqueWords, uniqueWordCounts);

    // pretty print the unique words and their corresponding counts
    printWordsAndCounts(uniqueWords, uniqueWordCounts);

    //*************************************************************************************
    // letter processing

    // count the occurrences of every letter in the entire text
    unsigned int letterCounts[26] = {0};
    countLetters(allWords, letterCounts);
    printLetterCounts(letterCounts);

    // print statistics on letter frequencies
    printMaxMinLetter(letterCounts);

    return 0;
}