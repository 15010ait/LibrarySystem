// book.cpp (Implementation file)

#include <iostream>
#include "book.h"
using namespace std;

void Book::setBookDetails(string t, string a, string i, bool avail, string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return ISBN; }
string Book::getDateAdded() const { return dateAdded; }
bool Book::isAvailable() const { return availability; }
void Book::setAvailability(bool avail) { availability = avail; }

void Book::displayBookDetails() {
    cout << "\nTitle: " << title
         << "\nAuthor: " << author
         << "\nISBN: " << ISBN
         << "\nAvailable: " << (availability ? "Yes" : "No")
         << "\nDate Added: " << dateAdded << endl;
}

void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Book is not available." << endl;
    }
}

void Book::returnBook() {
    availability = true;
    cout << "Book returned successfully." << endl;
}


// PrintedBook

PrintedBook::PrintedBook(const PrintedBook& pb) {
    setPrintedBookDetails(
        pb.getTitle(), pb.getAuthor(), pb.getISBN(), pb.isAvailable(), pb.getDateAdded(),
        pb.numberOfPages, pb.shelfNumber
    );
}

void PrintedBook::setPrintedBookDetails(string t, string a, string i, bool avail, string date, int pages, string shelf) {
    setBookDetails(t, a, i, avail, date);
    numberOfPages = pages;
    shelfNumber = shelf;
}

void PrintedBook::displayBookDetails() {
    cout << "\n[Printed Book]";
    Book::displayBookDetails();
    cout << "Pages: " << numberOfPages << "\nShelf: " << shelfNumber << endl;
}

string PrintedBook::getType() const {
    return "Printed";
}

// EBook

EBook::EBook(const EBook& eb) {
    setEBookDetails(
        eb.getTitle(), eb.getAuthor(), eb.getISBN(), eb.isAvailable(), eb.getDateAdded(),
        eb.fileFormat, eb.fileSizeMB, eb.licenseEndDate
    );
}

void EBook::setEBookDetails(string t, string a, string i, bool avail, string date, string format, double size, string licenseDate) {
    setBookDetails(t, a, i, avail, date);
    fileFormat = format;
    fileSizeMB = size;
    licenseEndDate = licenseDate;
}

void EBook::displayBookDetails() {
    cout << "\n[E-Book]";
    Book::displayBookDetails();
    cout << "Format: " << fileFormat << "\nSize: " << fileSizeMB << "MB"
         << "\nLicense End Date: " << licenseEndDate << endl;
}

string EBook::getType() const {
    return "EBook";
}




   

