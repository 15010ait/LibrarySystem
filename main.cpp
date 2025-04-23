// main.cpp (main application logic)

#include <iostream>
#include "book.h"
using namespace std;

int main() {
    const int MAX_BOOKS = 100;
    Book* books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    // Initialize 5 default books
    PrintedBook pb1, pb2, pb3;
    pb1.setPrintedBookDetails("C++ Basics", "Jane Smith", "103", true, "2023-03-01", 250, "A1");
    pb2.setPrintedBookDetails("Advanced C++", "Joseph Murray", "101", true, "2023-02-15", 300, "B2");
    pb3.setPrintedBookDetails("C++ in Practice", "Alan Turing", "105", false, "2023-03-10", 280, "C3");

    EBook eb1, eb2;
    eb1.setEBookDetails("Learn C++ Online", "Grace Hopper", "102", true, "2023-04-05", "PDF", 5.6, "2026-12-31");
    eb2.setEBookDetails("Mastering C++", "Bjarne Stroustrup", "104", false, "2023-05-20", "EPUB", 8.2, "2027-01-01");

    books[bookCount++] = new PrintedBook(pb1);
    books[bookCount++] = new PrintedBook(pb2);
    books[bookCount++] = new PrintedBook(pb3);
    books[bookCount++] = new EBook(eb1);
    books[bookCount++] = new EBook(eb2);

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Add a new book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\n--- All Books ---";
                for (int i = 0; i < bookCount; i++) {
                    cout << "\nType: " << books[i]->getType();
                    books[i]->displayBookDetails();
                }
                break;

            case 2: {
                string isbn;
                cout << "Enter ISBN to borrow: ";
                getline(cin, isbn);
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i]->getISBN() == isbn) {
                        found = true;
                        books[i]->borrowBook();
                        break;
                    }
                }
                if (!found)
                    cout << "Book not found.\n";
                break;
            }

            case 3: {
                string isbn;
                cout << "Enter ISBN to return: ";
                getline(cin, isbn);
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i]->getISBN() == isbn) {
                        found = true;
                        books[i]->returnBook();
                        break;
                    }
                }
                if (!found)
                    cout << "Book not found.\n";
                break;
            }

              case 4: {
                int type;
                cout << "Choose book type (1 - Printed, 2 - EBook): ";
                cin >> type;

                if (type == 1) {
                     PrintedBook* pb = new PrintedBook();
                     string t, a, i, d, s;
                     int pages;
                 bool avail;
                 cout << "Enter title: "; cin.ignore(); getline(cin, t);
                 cout << "Author: "; getline(cin, a);
                 cout << "ISBN: "; getline(cin, i);
                 cout << "Enter date added (YYYY-MM-DD): "; getline(cin, d);
                 cout << "Is available (1 = yes, 0 = no): "; cin >> avail;
                 cout << "Pages: "; cin >> pages;
                 cout << "Shelf: "; cin >> s;

        pb->setPrintedBookDetails(t, a, i, avail, d, pages, s);
        books[bookCount++] = pb;
        cout << "Book added successfully!\n";

    } else if (type == 2) {
        EBook* eb = new EBook();
        string t, a, i, d, f, l;
        double size;
        bool avail;
        cout << "Enter title: "; cin.ignore(); getline(cin, t);
        cout << "Author: "; getline(cin, a);
        cout << "ISBN: "; getline(cin, i);
        cout << "Enter date added (YYYY-MM-DD): "; getline(cin, d);
        cout << "Is available (1 = yes, 0 = no): "; cin >> avail;
        cout << "Format: "; cin >> f;
        cout << "Size in MB: "; cin >> size;
        cout << "License End Date: (YYYY-MM-DD)"; cin >> l;

        eb->setEBookDetails(t, a, i, avail, d, f, size, l);
        books[bookCount++] = eb;
        cout << "Book added successfully!\n";

    } else {
        cout << "Invalid type.\n";
    }
    break;
}


            case 5:
                cout << "Thank you for using the Community Library System!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    // Clean up
    for (int i = 0; i < bookCount; i++) {
        delete books[i];
    }

    return 0;
}
