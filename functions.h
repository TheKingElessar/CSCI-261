#ifndef CSCI261_FUNCTIONS_H
#define CSCI261_FUNCTIONS_H

using namespace std;

#include<string>
#include<vector>

string promptUserForFilename();

bool openFile(ifstream &, const string &);

vector<string> readWordsFromFile(ifstream &);

void removePunctuation(vector<string>&, const string&);

void capitalizeWords(vector<string>&);

vector<string> filterUniqueWords(vector<string>);

vector<unsigned int> countUniqueWords(vector<string>, vector<string>);

void sortWordsByCounts(vector<string>, vector<unsigned int>);

void printWordsAndCounts(vector<string>, vector<unsigned int>);

void countLetters(vector<string>, unsigned int[26]);

void printLetterCounts(unsigned int[26]);

void printMaxMinLetter(unsigned int[26]);

#endif //CSCI261_FUNCTIONS_H
