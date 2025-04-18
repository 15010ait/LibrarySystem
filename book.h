// book.h (Header File - class definitions)

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

// Base class
class Book {
private:   
   // Basic book attributes
    string title;
    string author;
    string ISBN;
    bool availability;   // Availability flag: true = available, false = borrowed
    string dateAdded;

public:
    virtual ~Book() {} // Virtual destructor for proper cleanup of derived objects

    // Set basic book info
    void setBookDetails(string t, string a, string i, bool avail, string date);

    // Getter functions for book properties (Getters for derived classes and others)
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getDateAdded() const;
    bool isAvailable() const;

    // Allows derived classes to change availability status (used in copy constructors)
    void setAvailability(bool avail);    // Needed for copy constructors

    virtual void displayBookDetails();  // Display book details (can be overridden by subclasses)
    void borrowBook();
    void returnBook();


    // Static sorting function for books (by title, ascending or descending)
    static void sortBooksByTitle(Book* books[], int size, bool ascending);
};

// Derived class: PrintedBook
class PrintedBook : public Book {
private:
    int numberOfPages;
    string shelfNumber;

public:
    PrintedBook() {}                        // Default constructor
    PrintedBook(const PrintedBook& pb);     // Copy constructor

    // Sets printed book-specific details
    void setPrintedBookDetails(string t, string a, string i, bool avail, string date, int pages, string shelf);
   // Displays full details of a printed book (overrides base method)
    void displayBookDetails() override;
};

// Derived class: EBook
class EBook : public Book {
private:
    string fileFormat;        
    double fileSizeMB;       
    string licenseEndDate;

public:
    EBook() {}                     // Default constructor
    EBook(const EBook& eb);       // Copy constructor

    // Sets eBook-specific details
    void setEBookDetails(string t, string a, string i, bool avail, string date, string format, double size, string licenseDate);
   // Displays full details of an eBook (overrides base method)
    void displayBookDetails() override;
};

#endif
