#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

// Base Class: Book
class Book {
protected:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdded;

public:
    void setBookDetails(string t, string a, string i, bool avail, string date);
    void displayBookDetails();
    void borrowBook();
    void returnBook();
    void sortBookData();
};

// Child Class: EBook
class EBook : public Book {
private:
    string fileFormat;
    double fileSizeMB;

public:
    void setEBookDetails(string t, string a, string i, bool avail, string date,
                         string format, double size);
    void downloadBook();
};

// Child Class: PrintedBook
class PrintedBook : public Book {
private:
    int numberOfPages;
    string shelfLocation;

public:
    void setPrintedBookDetails(string t, string a, string i, bool avail, string date,
                                int pages, string location);
    void reserveShelfSpace();
};

#endif
