Library System:
This project is a C++ console application for a Community Library System. It allows the management of books, including EBooks and Printed Books, and supports borrowing and returning functionality. 

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
book.cpp - Class definitions
main.cpp - Main program logic
README.md - Project description

Classes
Book (Parent)
Attributes: title, author, ISBN, availability, dateAdded
Methods:
setBookDetails()
displayBookDetails()
borrowBook()
returnBook()
sortBookData()

EBook (Child of Book)
Extra Attributes: fileFormat, fileSizeMB
Methods:
setEBookDetails()
downloadBook()

PrintedBook (Child of Book)
Extra Attributes: numberOfPages, shelfLocation
Methods:
setPrintedBookDetails()
reserveShelfSpace()

Notes
The borrowBook() method displays a message if the book is already borrowed (flag not available).
Demonstrates object-oriented design with inheritance, encapsulation, and code reuse.
