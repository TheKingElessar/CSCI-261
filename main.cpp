/* CSCI 261 Lab 5C: Array of Structures
 *
 * Author: Nathan Panzer
 *
 * Using structs instead of lots arrays :eyes:
 */

#include <string>
#include <iostream>

using namespace std;

int getValidInt(const string& message);

struct Book
{
    string title;
    string author;
    // Price in cents, stored as an int to avoid floating-point rounding errors.
    int price;
    int publicationYear;
};

int main()
{
    Book bookArray[5];

    cout << "Enter the data for each book." << endl;
    for (int i = 0; i < 5; i++)
    {
        Book tempBook = Book();
        cout << "--- Book " << i + 1 << " ---" << endl;
        cout << "Title: ";
        getline(cin, tempBook.title);
        cout << "Author: ";
        getline(cin, tempBook.author);
        tempBook.price = getValidInt("Price (in cents): ");
        tempBook.publicationYear = getValidInt("Publication Year: ");
        bookArray[i] = tempBook;
        cout << endl;
    }


    return 0;
}

int getValidInt(const string& message)
{
    cout << message;
    int input;
    cin >> input;

    while (cin.fail())
    {
        cin.clear();
        char errInput = cin.get();
        while (errInput != '\n')
        {
            errInput = cin.get();
        }
        cout << "Invalid input! Please enter an integer value." << endl;
        cout << message;
        cin >> input;
    }

    return input;
}
