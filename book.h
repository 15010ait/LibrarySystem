#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

// Base class
class Book {
private:  // Core book details
    string title;
    string author;
    string ISBN;
    bool availability;  // Availability flag: true = available, false = borrowed
    string dateAdded;

public: // Set common book details
    void setBookDetails(string t, string a, string i, bool avail, string date);
    void displayBookDetails(); // Display book details
    void borrowBook();   // Borrow the book (sets availability to false)
    void returnBook();  // Return the book (sets availability to true)
    string getISBN();   // Get the ISBN (used for searching/sorting)
    bool isAvailable();  // Check if book is available
    static void sortBookData(Book books[], int size); // Static method to sort array of books by ISBN using insertion sort
};

// Derived Class: EBook
// EBook class
class EBook : public Book {
private:
    string fileFormat;  // e.g., PDF, EPUB
    double fileSizeMB;  // File size in megabytes
    string licenseEndDate;

public:  // Set details specific to an EBook
    void setEBookDetails(string t, string a, string i, bool avail, string date,
                         string format, double size, string licenseDate);
    void displayEBookDetails(); // Display details specific to an EBook
    void downloadBook(); 
};

// Derived Class: PrintedBook
// PrintedBook class
class PrintedBook : public Book {
private:
    int numberOfPages; // Total pages
    string shelfNumber; // Physical shelf location

public: // Set details specific to a PrintedBook
    void setPrintedBookDetails(string t, string a, string i, bool avail, string date,
                               int pages, string shelf);
    void displayPrintedBookDetails();
    void reserveShelfSpace();
};

#endif
