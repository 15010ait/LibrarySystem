Library System:
This project is a C++ console application for a Community Library System. It allows the management of books, including EBooks and Printed Books, and supports borrowing and returning functionality.  It showcases core Object-Oriented Programming (OOP) principles like inheritance, encapsulation, and code reuse.

Features
Object-Oriented Programming (OOP) using inheritance. 
Book as the parent class with shared attributes and methods.
EBook and PrintedBook as child classes with additional attributes/methods.
Borrowing and returning books with availability flag checking.
Simple console output for interaction.
Structured code using header (.h), implementation (.cpp), and main file.

File Structure
LibrarySystem/
book.h - Class declarations
book.cpp - Class method definitions
main.cpp - Main program logic
README.md - Project description

Classes
Book (Parent or Base class)
Attributes: title, author, ISBN, availability, dateAdded
Methods:
setBookDetails()
displayBookDetails()
borrowBook() -  Flags the book as borrowed
returnBook() -  Flags the book as available
getISBN()
isAvailable()
sortBookData() – Static method to sort an array of Book objects by ISBN

EBook (Child of Book or Derived Class)
Extra Attributes: fileFormat, fileSizeMB, licenseEnddate
Methods:
setEBookDetails()
displayEBookDetails()
downloadBook()

PrintedBook (Child of Book or Derived Class)
Additional Attributes: numberOfPages, shelfNumber
Methods:
setPrintedBookDetails()
displayPrintedBookDetails()
reserveShelfSpace()

Notes
The borrowBook() method displays a message if the book is already borrowed (flag not available).
Uses OOP best practices like inheritance and encapsulation for clean, reusable code.
Static sorting function in Book allows sorting mixed arrays of EBooks and PrintedBooks by their ISBN.
