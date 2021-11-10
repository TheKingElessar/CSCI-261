/* CSCI 261 Assignment 6: Green Eggs and Ham
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * In this homework, we will focus on arrays, vectors, strings, File I/O, and Functions!
 */

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
    while (inputFileStream >> word)
    {
        allWords.push_back(word);
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
        string oldWord = uniqueWords.at(i);
        unsigned int oldCount = uniqueWordCounts.at(i);

        int largestIndex = i;
        unsigned int largestCount = uniqueWordCounts.at(largestIndex);
        for (int j = i + 1; j < uniqueWords.size(); j++)
        {
            if (uniqueWordCounts.at(j) > largestCount)
            {
                largestIndex = j;
                largestCount = uniqueWordCounts.at(j);
            }
            else if (uniqueWordCounts.at(j) == largestCount)
            {
                if (uniqueWords.at(j) < uniqueWords.at(largestIndex))
                {
                    largestIndex = j;
                    largestCount = uniqueWordCounts.at(j);
                }
            }
        }

        string largestWord = uniqueWords.at(largestIndex);

        if (largestIndex != i)
        {
            uniqueWords.at(i) = largestWord;
            uniqueWordCounts.at(i) = largestCount;
            uniqueWords.at(largestIndex) = oldWord;
            uniqueWordCounts.at(largestIndex) = oldCount;
        }
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

    cout << endl << "Word Counts" << endl;
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

void countLetters(const vector<string> &allWords, unsigned int letterCounts[26])
{
    for (const string &word : allWords)
    {
        for (const char letter : word)
        {
            letterCounts[letter - 'A']++;
        }
    }
}

void printLetterCounts(const unsigned int letterCounts[26])
{
    unsigned int largestCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (to_string(letterCounts[i]).size() > largestCount) largestCount = to_string(letterCounts[i]).size();
    }

    cout << endl << "Letter Counts" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << (char) (i + 'A');
        cout << " : ";
        cout << setw(largestCount) << right << letterCounts[i];
        cout << endl;
    }
}

void printMaxMinLetter(const unsigned int letterCounts[26])
{
    unsigned int sum = 0;

    int leastFrequentIndex = 0;
    int mostFrequentIndex = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += letterCounts[i];
        if (letterCounts[i] < letterCounts[leastFrequentIndex]) leastFrequentIndex = i;
        if (letterCounts[i] > letterCounts[mostFrequentIndex]) mostFrequentIndex = i;
    }
    double leastFrequentPercent = (letterCounts[leastFrequentIndex] / (double) sum) * 100;
    double mostFrequentPercent = (letterCounts[mostFrequentIndex] / (double) sum) * 100;

    cout << endl;
    cout << setw(23) << left << "Least Frequent Letter: " << static_cast<char>(leastFrequentIndex + 'A') << " ("
         << right << setw(7) << fixed << setprecision(3) << leastFrequentPercent << "%)"
         << left << endl;

    cout << setw(23) << left << "Most Frequent Letter: " << static_cast<char>(mostFrequentIndex + 'A') << " (" << right
         << setw(7) << fixed << setprecision(3) << mostFrequentPercent << "%)" << left
         << endl;
}
