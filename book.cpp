#include "book.h"
#include <iostream>
using namespace std;

// ------------ Book ------------
void Book::setBookDetails(string t, string a, string i, bool avail, string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

void Book::displayBookDetails() {
    cout << "-----------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Available: " << (availability ? "Yes" : "No") << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "-----------------------------" << endl;
}

void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully." << endl;
    } else {
        cout << "Book is not available." << endl;
    }
}

void Book::returnBook() {
    availability = true;
    cout << "Book returned successfully." << endl;
}

void Book::sortBookData() {
    cout << "Sorting logic would go here (e.g., sorting array by ISBN)." << endl;
}

// ----------- EBook -----------
void EBook::setEBookDetails(string t, string a, string i, bool avail, string date,
                            string format, double size) {
    setBookDetails(t, a, i, avail, date);
    fileFormat = format;
    fileSizeMB = size;
}

void EBook::downloadBook() {
    cout << "Downloading eBook in " << fileFormat
         << " format (" << fileSizeMB << "MB)." << endl;
}

// ------- PrintedBook ---------
void PrintedBook::setPrintedBookDetails(string t, string a, string i, bool avail, string date,
                                        int pages, string location) {
    setBookDetails(t, a, i, avail, date);
    numberOfPages = pages;
    shelfLocation = location;
}

void PrintedBook::reserveShelfSpace() {
    cout << "Reserving shelf space at " << shelfLocation
         << " for a book with " << numberOfPages << " pages." << endl;
}
