#include "functions.h"
#include<string>
#include <iostream>
#include <fstream>

using namespace std;

string promptUserForFilename()
{
    cout << "Enter filename: ";
    string filename;
    cin >> filename;
    return filename;
}

bool openFile(ifstream &inputFileStream, const string &filename)
{
    inputFileStream.open(filename);
    if (inputFileStream.fail())
    {
        return false;
    }
    return true;
}

vector<string> readWordsFromFile(ifstream &inputFileStream)
{
    vector<string> allWords;
    string word;
    while (!inputFileStream.eof())
    {
        inputFileStream >> word;
        allWords.push_back(word);
        cout << word << endl;
    }

    return allWords;
}

void removePunctuation(vector<string> &allWords, const string &punctuation)
{
    string cleanedWord;
    for (int i = 0; i < allWords.size(); i++)
    {
        string originalWord = allWords.at(i);
        cleanedWord = originalWord;
        for (char punctuationMark : punctuation)
        {
            unsigned long long foundPos;
            while (cleanedWord.find(punctuationMark) != string::npos)
            {
                foundPos = cleanedWord.find(punctuationMark);
                cleanedWord.replace(foundPos, 1, "");
            }
        }
        allWords.at(i) = cleanedWord;
        cout << "Replaced " << originalWord << " with " << cleanedWord << endl;
    }
}

void capitalizeWords(vector<string> &allWords)
{
    string capitalWord;
    string oldWord;
    for (int i = 0; i < allWords.size(); i++)
    {
        oldWord = allWords.at(i);
        capitalWord = oldWord;
        for (int j = 0; j < capitalWord.size(); j++)
        {
            capitalWord.at(j) = static_cast<char>(toupper(capitalWord[j]));
        }
        allWords.at(i) = capitalWord;
        cout << "Replaced " << oldWord << " with " << capitalWord << endl;
    }
}

vector<string> filterUniqueWords(vector<string>) {}

vector<unsigned int> countUniqueWords(vector<string>, vector<string>) {}

void sortWordsByCounts(vector<string>, vector<unsigned int>) {}

void printWordsAndCounts(vector<string>, vector<unsigned int>) {}

void countLetters(vector<string>, unsigned int[26]) {}

void printLetterCounts(unsigned int[26]) {}

void printMaxMinLetter(unsigned int[26]) {}
