#include <iostream>
#include "book.h"
using namespace std;

int main() {
    const int SIZE = 5;

    // Use derived class objects directly
    PrintedBook pb1, pb2, pb3;
    pb1.setPrintedBookDetails("C++ Basics", "Jane Smith", "103", true, "2023-03-01", 250, "A1");
    pb2.setPrintedBookDetails("Advanced C++", "Joseph Murray", "101", true, "2023-02-15", 300, "B2");
    pb3.setPrintedBookDetails("C++ in Practice", "Alan Turing", "105", false, "2023-03-10", 280, "C3");

    EBook eb1, eb2;
    eb1.setEBookDetails("Learn C++ Online", "Grace Hopper", "102", true, "2023-04-05", "PDF", 5.6, "2024-12-31");
    eb2.setEBookDetails("Mastering C++", "Bjarne Stroustrup", "104", false, "2023-05-20", "EPUB", 8.2, "2025-01-01");

    // Use Book array to sort
    Book books[SIZE] = { pb1, pb2, pb3, eb1, eb2 };

    Book::sortBookData(books, SIZE);
    cout << "\nBooks sorted by ISBN:\n";
    for (int i = 0; i < SIZE; ++i) {
        books[i].displayBookDetails();
    }

    // Allow user to borrow books based on ISBN
    string inputISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow (or '0' to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") break;

        bool found = false;

        for (int i = 0; i < SIZE; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                books[i].displayBookDetails();

                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                } else {
                    cout << "Sorry, the book is currently not available." << endl;
                }

                // Option to return book
                char choice;
                cout << "Would you like to return the book? (y/n): ";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    books[i].returnBook();
                }

                break;
            }
        }

        if (!found) {
            cout << "Book not found in the system." << endl;
        }
    }

    cout << "\nThank you for using the Community Library System!" << endl;
    return 0;
}
