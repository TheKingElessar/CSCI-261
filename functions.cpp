#include "functions.h"
#include<string>
#include <iostream>
#include <fstream>
#include <iomanip>

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
    }
}

vector<string> filterUniqueWords(const vector<string> &allWords)
{
    vector<string> uniqueWords;
    bool flag = false;
    for (const string &word : allWords)
    {
        flag = false;
        for (const string &uniqueWord : uniqueWords)
        {
            if (uniqueWord == word)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            uniqueWords.push_back(word);
        }
    }

    return uniqueWords;
}

vector<unsigned int> countUniqueWords(const vector<string> &allWords, const vector<string> &uniqueWords)
{
    vector<unsigned int> uniqueWordCounts;
    for (const string &uniqueWord : uniqueWords)
    {
        unsigned int uniqueWordCount = 0;
        for (const string &allWord : allWords)
        {
            if (allWord == uniqueWord)
            {
                uniqueWordCount++;
            }
        }
        uniqueWordCounts.push_back(uniqueWordCount);
    }

    return uniqueWordCounts;
}

void sortWordsByCounts(vector<string> &uniqueWords, vector<unsigned int> &uniqueWordCounts)
{
    for (int i = 0; i < uniqueWords.size(); i++)
    {
        string iWord = uniqueWords.at(i);
        unsigned int iCount = uniqueWordCounts.at(i);
        for (int j = 0; j < uniqueWords.size(); j++)
        {
            string jWord = uniqueWords.at(j);
            unsigned int jCount = uniqueWordCounts.at(j);
            if (jCount > iCount)
            {
                uniqueWords.at(i) = jWord;
                uniqueWordCounts.at(i) = jCount;
                uniqueWords.at(j) = iWord;
                uniqueWordCounts.at(j) = iCount;
                // todo: something wrong here
                cout << "Swapped " << iWord << " with " << jWord << ". " << iCount << " to " << jCount << endl;
            }
        }
    }

    for (int i = 0; i < uniqueWords.size(); i++)
    {
        cout << uniqueWords.at(i) << ": " << uniqueWordCounts.at(i) << endl;
    }
}

void printWordsAndCounts(const vector<string> &allWords, const vector<unsigned int> &allCounts)
{
    unsigned int largestCount = 0;
    unsigned int largestWord = 0;
    for (int i = 0; i < allWords.size(); i++)
    {
        if (allWords.at(i).size() > largestWord) largestWord = allWords.at(i).size();
        if (to_string(allCounts.at(i)).size() > largestCount) largestCount = to_string(allCounts.at(i)).size();
    }

    for (int i = 0; i < allWords.size(); i++)
    {
        cout << setw(to_string(allCounts.size()).size()) << right << i + 1;
        cout << " : ";
        cout << setw(largestWord) << left << allWords.at(i);
        cout << " : ";
        cout << setw(largestCount) << right << allCounts.at(i);
        cout << endl;
    }
}

void countLetters(vector<string>, unsigned int[26])
{
}

void printLetterCounts(unsigned int[26])
{
}

void printMaxMinLetter(unsigned int[26])
{
}
