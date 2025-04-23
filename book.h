// book.h (Header File - class definitions)

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdded;

public:
    virtual ~Book() {}

    void setBookDetails(string t, string a, string i, bool avail, string date);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getDateAdded() const;
    bool isAvailable() const;

    void setAvailability(bool avail);

    virtual void displayBookDetails();
    virtual string getType() const = 0;

    void borrowBook();
    void returnBook();

    static void sortBooksByTitle(Book* books[], int size, bool ascending);
};

class PrintedBook : public Book {
private:
    int numberOfPages;
    string shelfNumber;

public:
    PrintedBook() {}
    PrintedBook(const PrintedBook& pb);

    void setPrintedBookDetails(string t, string a, string i, bool avail, string date, int pages, string shelf);
    void displayBookDetails() override;
    string getType() const override;
};

class EBook : public Book {
private:
    string fileFormat;
    double fileSizeMB;
    string licenseEndDate;

public:
    EBook() {}
    EBook(const EBook& eb);

    void setEBookDetails(string t, string a, string i, bool avail, string date, string format, double size, string licenseDate);
    void displayBookDetails() override;
    string getType() const override;
};

#endif


