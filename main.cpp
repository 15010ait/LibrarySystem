// main.cpp (main application logic)

#include <iostream>
#include "book.h"
using namespace std;

int main() {
    const int SIZE = 5;
    Book* books[SIZE];  // Array of base class pointers to support polymorphism

    // Create Printed and EBooks
    PrintedBook pb1, pb2, pb3;
    pb1.setPrintedBookDetails("C++ Basics", "Jane Smith", "103", true, "2023-03-01", 250, "A1");
    pb2.setPrintedBookDetails("Advanced C++", "Joseph Murray", "101", true, "2023-02-15", 300, "B2");
    pb3.setPrintedBookDetails("C++ in Practice", "Alan Turing", "105", false, "2023-03-10", 280, "C3");

    EBook eb1, eb2;
    eb1.setEBookDetails("Learn C++ Online", "Grace Hopper", "102", true, "2023-04-05", "PDF", 5.6, "2026-12-31");
    eb2.setEBookDetails("Mastering C++", "Bjarne Stroustrup", "104", false, "2023-05-20", "EPUB", 8.2, "2027-01-01");

    // Dynamically allocate objects and assign to Book pointers
    // This enables polymorphism when calling virtual functions
    books[0] = new PrintedBook(pb1);
    books[1] = new PrintedBook(pb2);
    books[2] = new PrintedBook(pb3);
    books[3] = new EBook(eb1);
    books[4] = new EBook(eb2);

    int choice;
    do {
        
        // Display main menu
        cout << "\nCommunity Library - Choose an option (1 - 5):\n";
        cout << "1. Display all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Sort books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
// Option 1: Display details of all books
            case 1:
                cout << "\n--- All Books ---";
                for (int i = 0; i < SIZE; i++) {
                    books[i]->displayBookDetails();
                }
                break;

// Option 2: Borrow a book by ISBN
            case 2: { 
                string inputISBN;
                cout << "\nEnter ISBN to borrow: ";
                cin >> inputISBN;

                bool found = false;
                for (int i = 0; i < SIZE; i++) {
                    if (books[i]->getISBN() == inputISBN) {
                        found = true;
                        books[i]->displayBookDetails();

                        if (books[i]->isAvailable()) {
                            books[i]->borrowBook();
                        } else {
                            cout << "Sorry, the book is currently not available.\n";
                        }
                        break;
                    }
                }

                if (!found)
                    cout << "Book not found.\n";
                break;
            }

// Option 3: Return a book by ISBN
            case 3: {
                string inputISBN;
                cout << "\nEnter ISBN to return: ";
                cin >> inputISBN;

                bool found = false;
                for (int i = 0; i < SIZE; i++) {
                    if (books[i]->getISBN() == inputISBN) {
                        found = true;
                        books[i]->returnBook();	// Mark book as available
                        break;
                    }
                }

                if (!found)
                    cout << "Book not found.\n";
                break;
            }

// Option 4: Sort books by title
            case 4: {
                
                // Sort Books by Title
                char sortOrder;
                cout << "Sort by Title:\n";
                cout << "a. Ascending (A - Z)\nb. Descending (Z - A)\nEnter your choice: ";
                cin >> sortOrder;

	   // Call static sort method on Book class
                if (sortOrder == 'a' || sortOrder == 'A') {
                    Book::sortBooksByTitle(books, SIZE, true);	// Ascending order
                    cout << "\nBooks sorted in ascending order:\n";
                } else if (sortOrder == 'b' || sortOrder == 'B') {
                    Book::sortBooksByTitle(books, SIZE, false);  // Descending order
                    cout << "\nBooks sorted in descending order:\n";
                } else {
                    cout << "Invalid sort option.\n";
                    break;
                }

                // Display sorted list
                for (int i = 0; i < SIZE; i++) {
                    books[i]->displayBookDetails();
                }
                break;
            }

// Option 5: Exit the program
            case 5:
                cout << "Thank you for using the Community Library System!\n";
                break;

            default: 	// Handle invalid input
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5); // Continue until user chooses to exit


    // Free dynamically allocated memory
    for (int i = 0; i < SIZE; ++i) {
        delete books[i];
    }

    return 0;
}
