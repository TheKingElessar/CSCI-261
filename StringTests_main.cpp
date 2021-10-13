/* CSCI261 Lab: stringTest
 *
 * Author: Nathan Panzer
 *
 * This program executes some tests that illustrate the properties
 * and behaviors of strings.
 *
 * Copyright 2021 Dr. Jeffrey Paone

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
 *
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void runAllTests();

int main()
{

    cout << "Testing your functions...\n\n";
    runAllTests();

    // Exit program.
    return 0;
}

/// \desc A generic test function, that simply prints "PASSED" if LHS equals RHS
/// and otherwise prints FAILED. Do not modify this function.
/// \param [out] testNum Number of the test.  Value will be incremented upon completion
/// \param [in] MESSAGE description of test
/// \param [in] LHS computed result
/// \param [in] RHS expected result
/// \returns 1 if test passed, 0 otherwise
template<class T>
int test(int &testNum, const string MESSAGE, const T LHS, const T RHS)
{
    cout << "Test #" << setw(3) << right << ++testNum;
    cout << setw(30) << right;
    cout << MESSAGE << ": ";
    cout << left;
    if (LHS == RHS)
    {
        cout << "    PASSED   \n";
    }
    else
    {
        cout << " !!>FAILED<!! Computed: \"" << LHS << "\" != Expected: \"" << RHS << "\"\n";
    }
    return LHS == RHS ? 1 : 0;
}

/// \desc Returns the length of a string
/// \param STR string to return the length of
/// \returns length of the input string
int stringLength(const string STR)
{
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

/// \desc Returns the character of a string at a given index
/// \param STR full string
/// \param IDX index to access string at
/// \returns character from STR at index IDX
char charAt(const string STR, const int IDX)
{
    char result = '\0';
    result = STR[IDX];
    return result;
}

/// \desc Returns a concatenation of strings left and right
/// \param LEFT string to be appended to
/// \param RIGHT string to be appended
/// \returns concatenated string LEFTRIGHT
string stringAppend(const string LEFT, const string RIGHT)
{
    string result = LEFT;
    result = LEFT + RIGHT;
    return result;
}

/// \desc Returns the result of inserting a string into another at a given position
/// \param STR original string
/// \param TO_INSERT string to be inserted into STR
/// \param IDX location within STR to insert TO_INSERT
/// \returns a new string with TO_INSERT inserted at index IDX of STR
string stringInsert(const string STR, const string TO_INSERT, const int IDX)
{
    string result = STR;
    result.insert(IDX, TO_INSERT);
    return result;
}

/// \desc Returns the first index of a character in a string
/// \param STR string to search within (the haystack)
/// \param C character to search for (the needle)
/// \returns if found, first position within STR that C is located.  otherwise returns string::npos
int stringFind(const string STR, const char C)
{
    int result = -1;
    result = STR.find_first_of(C);
    return result;
}

/// \desc Returns part of a string
/// \param STR original full string
/// \param IDX starting position to return a substring from
/// \param LEN length of substring to return
/// \returns a substring of length LEN from STR
string stringSubstring(const string STR, const int IDX, const int LEN)
{
    string result = STR;
    result = STR.substr(IDX, LEN);
    return result;
}

/// \desc Replaces part of a string
/// \param STR original full string (the haystack)
/// \param TEXT_TO_REPLACE the existing text to replace (the needle)
/// \param REPLACE_WITH the new text to insert
/// \returns modified string (if text found), otherwise the original string
string stringReplace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH)
{
    string result = STR;
    int location = result.find(TEXT_TO_REPLACE);

    if (location == string::npos)
    {
        return result;
    }

    result = result.replace(location, TEXT_TO_REPLACE.length(), REPLACE_WITH);
    return result;
}

/// \desc Returns the first word, given a sentence
/// \param STR original full string
/// \returns substring up to the first whitespace
string firstWord(const string STR)
{
    string result = STR;
    int spaceLocation = result.find(" ");
    if (spaceLocation == string::npos)
    {
        return result;
    }
    result = result.substr(0, spaceLocation);
    return result;
}

/// \desc Returns the string with the first word removed
/// \param STR original full string
/// \returns substring after the first whitespace
string removeFirstWord(const string STR)
{
    string result = STR;
    string firstWordFound = firstWord(STR);
    result = stringReplace(STR, firstWordFound, "");
    result = result.replace(0, 1, "");
    return result;
}

/// \desc Returns the second word, given a sentence
/// \param STR original full string
/// \returns substring after the first whitespace up to the second whitespace
string secondWord(const string STR)
{
    string result = STR;
    result = removeFirstWord(STR);
    result = firstWord(result);
    return result;
}

/// \desc Returns the third word, given a sentence
/// \param STR original full string
/// \returns substring after the second whitespace up to the third whitespace
string thirdWord(const string STR)
{
    string result = STR;
    result = removeFirstWord(STR);
    result = removeFirstWord(result);
    result = firstWord(result);

    return result;
}

/// \desc Returns the nth word, given a sentence
/// \param STR original full string
/// \param N word within STR to return (beginning at 1)
/// \returns corresponding word from STR
string nthWord(const string STR, const int N)
{
    string result = STR;
    for (int i = 1; i < N; i++)
    {
        result = removeFirstWord(result);
    }
    result = firstWord(result);
    return result;
}

/// \desc Returns a string substituting target character with replacement character
/// \param STR original full string (the haystack)
/// \param TARGET character to replace (the needle)
/// \param REPLACEMENT character to substitute with
/// \returns string with all instance of TARGET replaced with REPLACEMENT
string substitute(const string STR, const char TARGET, const char REPLACEMENT)
{
    string result = STR;
    for (int i = 0; i < STR.length(); i++)
    {
        char charAt = result[i];
        if (charAt == TARGET)
        {
            result[i] = REPLACEMENT;
        }
    }
    return result;
}

/// \brief Test suite. You should read, but not modify, this function.
void runAllTests()
{
    int totalPassed = 0, totalNumTests = 0;
    totalPassed += test<int>(totalNumTests, "Testing length()", stringLength("Now"), 3);
    totalPassed += test<int>(totalNumTests, "Testing length()", stringLength("Tablet"), 6);
    totalPassed += test<char>(totalNumTests, "Testing at()", charAt("Elephant", 3), 'p');
    totalPassed += test<char>(totalNumTests, "Testing at()", charAt("Giraffe", 2), 'r');
    totalPassed += test<char>(totalNumTests, "Testing at()", charAt("Armadillo", 4), 'd');
    totalPassed += test<string>(totalNumTests, "Testing append()", stringAppend("There's a ", "natural mystic."),
                                "There's a natural mystic.");
    totalPassed += test<string>(totalNumTests, "Testing append()", stringAppend("It's the ", "eye of the tiger."),
                                "It's the eye of the tiger.");
    totalPassed += test<string>(totalNumTests, "Testing insert()", stringInsert("If you carefully.", "listen ", 7),
                                "If you listen carefully.");
    totalPassed += test<string>(totalNumTests, "Testing insert()", stringInsert("carefully.", "Watch ", 0),
                                "Watch carefully.");
    totalPassed += test<int>(totalNumTests, "Testing find()", stringFind("Have to face reality now.", 'o'), 6);
    totalPassed += test<int>(totalNumTests, "Testing find()", stringFind("Have to face reality now.", 'e'), 3);
    totalPassed += test<string>(totalNumTests, "Testing substr()", stringSubstring("Such a natural mystic", 7, 7),
                                "natural");
    totalPassed += test<string>(totalNumTests, "Testing substr()", stringSubstring("Such a natural mystic", 0, 4),
                                "Such");
    totalPassed += test<string>(totalNumTests, "Testing replace()",
                                stringReplace("Strings are not the way", "Strings", "Things"),
                                "Things are not the way");
    totalPassed += test<string>(totalNumTests, "Testing replace()",
                                stringReplace("Show me the things", "things", "way"), "Show me the way");
    totalPassed += test<string>(totalNumTests, "Testing replace()", stringReplace("Show me the things", "car", "way"),
                                "Show me the things");
    totalPassed += test<string>(totalNumTests, "Testing firstWord()",
                                firstWord("The quick brown fox jumped over the lazy dog"), "The");
    totalPassed += test<string>(totalNumTests, "Testing firstWord()", firstWord("A man a plan a canal Panama"), "A");
    totalPassed += test<string>(totalNumTests, "Testing firstWord()", firstWord("I have the hang of this"), "I");
    totalPassed += test<string>(totalNumTests, "Testing firstWord()", firstWord("Single"), "Single");
    totalPassed += test<string>(totalNumTests, "Testing removeFirstWord()",
                                removeFirstWord("The quick brown fox jumped over the lazy dog"),
                                "quick brown fox jumped over the lazy dog");
    totalPassed += test<string>(totalNumTests, "Testing removeFirstWord()", removeFirstWord("Goodbye"), "");
    totalPassed += test<string>(totalNumTests, "Testing removeFirstWord()",
                                removeFirstWord(removeFirstWord("The quick brown fox jumped over the lazy dog")),
                                "brown fox jumped over the lazy dog");
    totalPassed += test<string>(totalNumTests, "Testing secondWord()",
                                secondWord("The quick brown fox jumped over the lazy dog"), "quick");
    totalPassed += test<string>(totalNumTests, "Testing secondWord()", secondWord("A man a plan a canal Panama"),
                                "man");
    totalPassed += test<string>(totalNumTests, "Testing secondWord()", secondWord("I have the hang of this"), "have");
    totalPassed += test<string>(totalNumTests, "Testing thirdWord()",
                                thirdWord("The quick brown fox jumped over the lazy dog"), "brown");
    totalPassed += test<string>(totalNumTests, "Testing thirdWord()", thirdWord("A man a plan a canal Panama"), "a");
    totalPassed += test<string>(totalNumTests, "Testing thirdWord()", thirdWord("I have the hang of this"), "the");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(1)",
                                nthWord("The quick brown fox jumped over the lazy dog", 1), "The");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(2)",
                                nthWord("The quick brown fox jumped over the lazy dog", 2), "quick");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(3)",
                                nthWord("The quick brown fox jumped over the lazy dog", 3), "brown");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(4)",
                                nthWord("The quick brown fox jumped over the lazy dog", 4), "fox");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(5)",
                                nthWord("The quick brown fox jumped over the lazy dog", 5), "jumped");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(6)",
                                nthWord("The quick brown fox jumped over the lazy dog", 6), "over");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(7)",
                                nthWord("The quick brown fox jumped over the lazy dog", 7), "the");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(8)",
                                nthWord("The quick brown fox jumped over the lazy dog", 8), "lazy");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(9)",
                                nthWord("The quick brown fox jumped over the lazy dog", 9), "dog");
    totalPassed += test<string>(totalNumTests, "Testing nthWord(10)",
                                nthWord("The quick brown fox jumped over the lazy dog", 10), "");
    totalPassed += test<string>(totalNumTests, "Testing substitute()", substitute("The Gxxgle", 'x', 'o'),
                                "The Google");
    totalPassed += test<string>(totalNumTests, "Testing substitute()", substitute("$chool of Mine$", '$', 's'),
                                "school of Mines");
    totalPassed += test<string>(totalNumTests, "Testing substitute()",
                                substitute(substitute("D--", '-', '+'), 'D', 'C'), "C++");
    cout << endl;
    cout << "Tests Passed: " << setw(3) << right << totalPassed << " / " << setw(3) << totalNumTests << " ("
         << setprecision(0) << fixed << totalPassed * 100.0f / totalNumTests << "%)" << endl;
}
