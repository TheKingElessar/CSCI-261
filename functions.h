#ifndef CSCI261_FUNCTIONS_H
#define CSCI261_FUNCTIONS_H

using namespace std;

#include<string>
#include<vector>

// test
string promptUserForFilename();

bool openFile(ifstream &, const string &);

vector<string> readWordsFromFile(ifstream &);

void removePunctuation(vector<string> &, const string &);

void capitalizeWords(vector<string> &);

vector<string> filterUniqueWords(const vector<string> &);

vector<unsigned int> countUniqueWords(const vector<string> &, const vector<string> &);

void sortWordsByCounts(vector<string> &, vector<unsigned int> &);

void printWordsAndCounts(const vector<string> &, const vector<unsigned int> &);

void countLetters(vector<string>, unsigned int[26]);

void printLetterCounts(unsigned int[26]);

void printMaxMinLetter(unsigned int[26]);

#endif //CSCI261_FUNCTIONS_H
