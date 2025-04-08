#include <iostream>
#include "book.h"
using namespace std;

int main() {
    // Example for EBook
    EBook myEbook;
    myEbook.setEBookDetails("Digital Learning", "Jane Brown", "123E", true, "2023-01-01", "PDF", 5.2);
    myEbook.displayBookDetails();
    myEbook.downloadBook();
    myEbook.borrowBook();
    myEbook.borrowBook(); // Try borrowing again

    cout << "\n";

    // Example for PrintedBook
    PrintedBook myPrintedBook;
    myPrintedBook.setPrintedBookDetails("C++ Mastery", "Paul Smith", "456P", true, "2022-10-10", 300, "Shelf A3");
    myPrintedBook.displayBookDetails();
    myPrintedBook.reserveShelfSpace();
    myPrintedBook.borrowBook();

    return 0;
}
