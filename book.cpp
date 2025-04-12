#include <iostream>
#include "book.h"
using namespace std;

// Base class - Book Class Methods 
// Sets the details of the Book
void Book::setBookDetails(string t, string a, string i, bool avail, string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

// Displays book details (shared by EBook and PrintedBook)
void Book::displayBookDetails() {
    cout << "\nTitle: " << title << "\nAuthor: " << author
         << "\nISBN: " << ISBN
         << "\nAvailable: " << (availability ? "Yes" : "No")
         << "\nDate Added: " << dateAdded << endl;
}

// Borrows the book if available
void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Book is not available." << endl;
    }
}

// Returns the book (sets availability to true)
void Book::returnBook() {
    availability = true;
    cout << "Book returned successfully." << endl;
}

// Getter for ISBN 
string Book::getISBN() {
    return ISBN;
}

// Checks if book is available
bool Book::isAvailable() {
    return availability;
}

// Sorts an array of Book objects using Insertion Sort based on ISBN
void Book::sortBookData(Book books[], int size) {
    for (int i = 1; i < size; ++i) {
        Book key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].getISBN() > key.getISBN()) { // Shift books that have greater ISBN than key to one position ahead
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

// EBook class Methods
// Sets the details of an EBook
void EBook::setEBookDetails(string t, string a, string i, bool avail, string date,
                            string format, double size, string licenseDate) {
    setBookDetails(t, a, i, avail, date); // Call base class method
    fileFormat = format;
    fileSizeMB = size;
    licenseEndDate = licenseDate;
}

// Displays EBook-specific details
void EBook::displayEBookDetails() {
    displayBookDetails();  // Call base class method
    cout << "File Format: " << fileFormat
         << "\nFile Size: " << fileSizeMB << "MB"
         << "\nLicense End Date: " << licenseEndDate << endl;
}

void EBook::downloadBook() {
    cout << "Downloading the book in " << fileFormat << " format (" << fileSizeMB << "MB)..." << endl;
}

// PrintedBook class
// Sets the details of a PrintedBook
void PrintedBook::setPrintedBookDetails(string t, string a, string i, bool avail, string date,
                                        int pages, string shelf) {
    setBookDetails(t, a, i, avail, date); // Call base class method
    numberOfPages = pages;
    shelfNumber = shelf;
}

// Displays PrintedBook-specific details
void PrintedBook::displayPrintedBookDetails() {
    displayBookDetails(); // Call base class method
    cout << "Number of Pages: " << numberOfPages
         << "\nShelf Number: " << shelfNumber << endl;
}

void PrintedBook::reserveShelfSpace() {
    cout << "Shelf " << shelfNumber << " reserved for this printed book." << endl;
}
