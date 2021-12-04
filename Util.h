#ifndef CSCI261_UTIL_H
#define CSCI261_UTIL_H

#include <ctime>

using namespace std;

/**
 *  @brief  Converts a string to a time_t object using a formatting string.
 *  @param timeString  The time string.
 *  @param formatting  The formatting string.
 *  @return  A new time_t object.
 *
 *  Converts a time string to a time_t object. See
 *  https://en.cppreference.com/w/cpp/io/manip/get_time
 *  for information on formatting the string.
 *  For example, 12/08/21 08:00 is %m/%d/%y %H:%M.
*/
time_t stringToTime(const string &timeString, const string &formatting);

/**
 *  @brief  Converts a string to a time_t object.
 *  @param timeString  The time string.
 *  @return  A new time_t object.
 *
 *  Converts a string of the format %m/%d/%y %H:%M
 *  to a time_t object.
*/
time_t stringToTime(const string &timeString);

/**
 *  @brief  Replaces every instance of a character in a string.
 *  @param inputString  The string to be modified.
 *  @param origChar  The character to be replaced.
 *  @param replaceChar  The character to insert, as a string.
 *  @return  The inputted string.
 *
 *  Replaces every instance of a character in a string.
 *  Note that the inputted string is modified in-place, but is
 *  also returned for easier inline use.
*/
string replaceChar(string inputString, const char &origChar, const string &replaceChar);

#endif //CSCI261_UTIL_H
