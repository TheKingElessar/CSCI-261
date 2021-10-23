/* CSCI 261 Lab 5C: Array of Structures
 *
 * Author: Nathan Panzer
 *
 * Using structs instead of lots arrays :eyes:
 */

#include <string>
#include <iostream>

using namespace std;

int getValidInt(const string &message);

float getValidFloat(const string &message);

struct Book
{
    string title;
    string author;
    // Price in cents, stored as an int to avoid floating-point rounding errors.
    float price;
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
        tempBook.price = getValidFloat("Price: ");
        tempBook.publicationYear = getValidInt("Publication Year: ");
        bookArray[i] = tempBook;
        cout << endl;
    }

    cout << "Books entered!" << endl;

    while (true)
    {
        cout << "Which number book do you want information for (1-5)? (\"exit\" to exit) ";
        int input;
        string exit;
        cin >> input;

        bool flag = false;
        while (cin.fail())
        {
            cin.clear();

            cin >> exit;
            if (exit == "exit")
            {
                flag = true;
                break;
            }

            char errInput = cin.get();
            while (errInput != '\n')
            {
                errInput = cin.get();
            }
            cout << "Invalid input! Please enter an integer value." << endl;
            cin >> input;
        }
        if (flag)
        {
            break;
        }

        Book book = bookArray[input - 1];
        cout << "Book " << input << " title: " << book.title << endl;
        cout << "Book " << input << " author: " << book.author << endl;
        cout << "Book " << input << " price: $" << book.price << endl;
        cout << "Book " << input << " publication year: " << book.publicationYear << endl;
        cout << endl;
    }

    return 0;
}

int getValidInt(const string &message)
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

    string empty;
    getline(cin, empty);

    return input;
}

float getValidFloat(const string &message)
{
    cout << message;
    float input;
    cin >> input;

    while (cin.fail())
    {
        cin.clear();
        char errInput = cin.get();
        while (errInput != '\n')
        {
            errInput = cin.get();
        }
        cout << "Invalid input! Please enter a float value." << endl;
        cout << message;
        cin >> input;
    }

    return input;
}