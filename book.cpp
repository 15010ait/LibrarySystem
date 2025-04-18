// book.cpp (Implementation file)

#include <iostream>
#include "book.h"
using namespace std;

// Book (base class)
// Set base book details (used by all book types)
void Book::setBookDetails(string t, string a, string i, bool avail, string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

// Getter methods
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}

string Book::getDateAdded() const {
    return dateAdded;
}

bool Book::isAvailable() const {
    return availability;
}

// Setter for availability (useful for constructors/copying)
void Book::setAvailability(bool avail) {
    availability = avail;
}

// Displays basic book details
void Book::displayBookDetails() {
    cout << "\nTitle: " << title
         << "\nAuthor: " << author
         << "\nISBN: " << ISBN
         << "\nAvailable: " << (availability ? "Yes" : "No")
         << "\nDate Added: " << dateAdded << endl;
}

// Borrow logic with availability check
void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Book is not available." << endl;
    }
}

// Return logic (just marks it available again)
void Book::returnBook() {
    availability = true;
    cout << "Book returned successfully." << endl;
}

// Insertion sort for array of Book pointers (by title)
void Book::sortBooksByTitle(Book* books[], int size, bool ascending) {
    for (int i = 1; i < size; ++i) {
        Book* key = books[i];
        int j = i - 1;

        // Compare based on ascending or descending flag
        while (j >= 0 &&
            (ascending ? (books[j]->getTitle() > key->getTitle()) : (books[j]->getTitle() < key->getTitle()))) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

// PrintedBook
// Copy constructor to ensure deep copy of printed book info
PrintedBook::PrintedBook(const PrintedBook& pb) {
    setPrintedBookDetails(
        pb.getTitle(), pb.getAuthor(), pb.getISBN(), pb.isAvailable(), pb.getDateAdded(),
        pb.numberOfPages, pb.shelfNumber
    );
}

// Sets printed book-specific fields + common book fields
void PrintedBook::setPrintedBookDetails(string t, string a, string i, bool avail, string date, int pages, string shelf) {
    setBookDetails(t, a, i, avail, date);
    numberOfPages = pages;
    shelfNumber = shelf;
}

// Displays printed book info (with [Printed Book] label)
void PrintedBook::displayBookDetails() {
    cout << "\n[Printed Book]";
    Book::displayBookDetails();
    cout << "Pages: " << numberOfPages << "\nShelf: " << shelfNumber << endl;
}

// EBook
// Copy constructor to ensure deep copy of ebook info
EBook::EBook(const EBook& eb) {
    setEBookDetails(
        eb.getTitle(), eb.getAuthor(), eb.getISBN(), eb.isAvailable(), eb.getDateAdded(),
        eb.fileFormat, eb.fileSizeMB, eb.licenseEndDate
    );
}

// Sets ebook-specific fields + common book fields
void EBook::setEBookDetails(string t, string a, string i, bool avail, string date, string format, double size, string licenseDate) {
    setBookDetails(t, a, i, avail, date);
    fileFormat = format;
    fileSizeMB = size;
    licenseEndDate = licenseDate;
}

// Displays eBook info (with [E-Book] label)
void EBook::displayBookDetails() {
    cout << "\n[E-Book]";
    Book::displayBookDetails();   // Call base version for common info
    cout << "Format: " << fileFormat << "\nSize: " << fileSizeMB << "MB"
         << "\nLicense End Date: " << licenseEndDate << endl;
}

