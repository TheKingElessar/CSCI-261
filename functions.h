/* CSCI 261 Assignment 6: Green Eggs and Ham
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * In this homework, we will focus on arrays, vectors, strings, File I/O, and Functions!
 */

#ifndef CSCI261_FUNCTIONS_H
#define CSCI261_FUNCTIONS_H

using namespace std;

#include<string>
#include<vector>

string promptUserForFilename();

bool openFile(ifstream &, const string &);

vector<string> readWordsFromFile(ifstream &);

void removePunctuation(vector<string> &, const string &);

void capitalizeWords(vector<string> &);

vector<string> filterUniqueWords(const vector<string> &);

vector<unsigned int> countUniqueWords(const vector<string> &, const vector<string> &);

void sortWordsByCounts(vector<string> &, vector<unsigned int> &);

void printWordsAndCounts(const vector<string> &, const vector<unsigned int> &);

void countLetters(const vector<string> &, const vector<unsigned int> &);

void countLetters(const vector<string> &, unsigned int[26]);

void printLetterCounts(const unsigned int[26]);

void printMaxMinLetter(const unsigned int[26]);

#endif
