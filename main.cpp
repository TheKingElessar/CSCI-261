/* CSCI 261 Assignment 3: Sprockets R Us
 *
 * Author: Nathan Panzer
 * Skip Days Used: 0
 * Skip Days Remaining: 5
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity): None
 *
 * geez taht was painful
 * i guess this makes you a receipt it's kinda cool
 * lots of rounding and formatting
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;

const string FILE_NAME = "product_public.txt";
const string RECEIPT_FILE = "receipt.txt";

int main()
{
    double pricePerIndividualUnit;
    double salesTaxPercentageRate;
    double shippingMin1, flatShippingRate1;
    double shippingMin2, flatShippingRate2;
    double shippingMin3, flatShippingRate3;
    double freeShippingMin;

    ifstream inputFile(FILE_NAME);
    if (inputFile.fail())
    {
        cout << "Error opening file " << FILE_NAME << ". Exiting." << endl;
        return -1;
    }

    inputFile >> pricePerIndividualUnit;
    inputFile >> salesTaxPercentageRate;
    salesTaxPercentageRate /= 100;
    inputFile >> shippingMin1;
    inputFile >> flatShippingRate1;
    inputFile >> shippingMin2;
    inputFile >> flatShippingRate2;
    inputFile >> shippingMin3;
    inputFile >> flatShippingRate3;
    inputFile >> freeShippingMin;
    inputFile.close();

    cout << "Welcome to Sprockets-R-Us!" << endl;
    cout << "We sell round sprockets, square sprockets, and triangle sprockets." << endl;
    cout << "The cost of a single sprocket is $" << pricePerIndividualUnit << "." << endl;
    cout << "How many sprockets do you wish to order?" << endl;

    int unitsOrdered;
    cin >> unitsOrdered;

    if (unitsOrdered <= 0)
    {
        cout << "Invalid order. Exiting." << endl;
        return 0;
    }

    cout << "Thank you for your order of " << unitsOrdered
    << " sprockets!  One moment while we prepare your receipt...\n"
    << endl;

    double unitSubtotal = pricePerIndividualUnit * unitsOrdered;
    double shippingFee;
    if (unitSubtotal > freeShippingMin)
    {
        shippingFee = 0;
        cout << "Shipping is FREE! Thank you for your large purchase!" << endl;
    }
    else if (unitSubtotal > shippingMin3)
    {
        shippingFee = flatShippingRate3;
    }
    else if (unitSubtotal > shippingMin2)
    {
        shippingFee = flatShippingRate2;
    }
    else if (unitSubtotal > shippingMin1)
    {
        shippingFee = flatShippingRate1;
    }

    double shippingSubtotal = shippingFee + unitSubtotal;
    double tax = salesTaxPercentageRate * shippingSubtotal;
    tax = round(tax * 100.) / 100.;

    /* bruh for some reason i was having trouble using round()
     * for this purpose so i wrote this and it turns out yeah
     * i can use round() all along i hate my life

    double scaledTax = (tax - (int) tax) * 100.;
    double lastDigit = scaledTax - (int) scaledTax;
    if (0.5 - lastDigit <= 0.0000000001)
    {
        lastDigit = ceil(lastDigit);
    }
    else
    {
        lastDigit = floor(lastDigit);
    }

    double fullRoundedTax = (int) ((tax + (lastDigit / 100.)) * 100.) / 100.;
    cout << "Full rounded tax: " << fullRoundedTax << endl;
    */

    double taxTotal = shippingSubtotal + tax;
    double grandTotal = taxTotal;
    bool donation = false;
    double donationAmount = 0.;
    if ((taxTotal * 100.) - (int) taxTotal > 0)
    {
        cout << "Order subtotal: $" << taxTotal << endl;

        cout << "Would you like to round up your order to make a donation to Gamers Against Wisconsin? [Y/N]" << endl;
        char donateChar;
        cin >> donateChar;
        if (donateChar == 'Y' || donateChar == 'y')
        {
            donation = true;
        }
        else if (donateChar == 'N' || donateChar == 'n')
        {
            donation = false;
        }
        else
        {
            cout << "Input '" << donateChar << "' not recognised; defaulting to no." << endl;
        }

        if (donation)
        {
            donationAmount = (ceil(taxTotal) - (taxTotal));
            grandTotal += donationAmount;
            cout << "Thank you for your donation!" << endl;
        }
    }

    cout << "\nThank you for your order. Your order total is $" << grandTotal << "." << endl;

    ofstream receiptFile(RECEIPT_FILE);
    if (receiptFile.fail())
    {
        cout << "Error writing to " << RECEIPT_FILE << ". Exiting.";
        return -1;
    }
    receiptFile.fill('-');
    receiptFile << setw(29) << "" << endl;

    receiptFile << "Sprockets-R-Us Order Receipt" << endl;

    receiptFile.fill('-');
    receiptFile << setw(29) << "" << endl;
    receiptFile.fill(' ');

    receiptFile << left << "Price Per Unit:    $" << right << setw(9) << fixed << setprecision(2)
    << pricePerIndividualUnit << endl;
    receiptFile << left << "Quantity Ordered:" << right << setw(12) << unitsOrdered << endl;
    receiptFile << left << "Unit Subtotal:     $" << right << setw(9) << fixed << setprecision(2)
    << unitSubtotal << endl;

    receiptFile.fill('-');
    receiptFile << setw(29) << "" << endl;
    receiptFile.fill(' ');

    receiptFile << left << "Shipping Fee:      $" << right << setw(9) << fixed << setprecision(2)
    << shippingFee << endl;

    receiptFile.fill('-');
    receiptFile << setw(29) << "" << endl;
    receiptFile.fill(' ');

    char donationCharOut;
    if (donation)
    {
        donationCharOut = 'Y';
    }
    else
    {
        donationCharOut = 'N';
    }

    receiptFile << "Donation?" << setw(20) << right << donationCharOut << endl;
    if (donation)
    {
        receiptFile << left << "Donation Amount:   $" << right << setw(9) << fixed << setprecision(2)
        << donationAmount << endl;
    }

    receiptFile.fill('=');
    receiptFile << setw(29) << "" << endl;
    receiptFile.fill(' ');

    receiptFile << left << "Grand Total:       $" << right << setw(9) << fixed << setprecision(2)
    << grandTotal << endl;

    receiptFile.fill('=');
    receiptFile << setw(29) << "";

    receiptFile.close();
    cout << "Receipt saved to " << RECEIPT_FILE << "! Have a good day." << endl;

    return 0;
}