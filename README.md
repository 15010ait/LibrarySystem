Library System:
This project is a C++ console application for a Community Library System. It allows the management of books, including EBooks and Printed Books. It allows basic operations such as borrowing, returning, viewing, and sorting books using object-oriented programming concepts such as inheritance, polymorphism, and encapsulation.

Features
Book Management with support for:
Title, author, ISBN, availability flag, and date added
PrintedBook and EBook subclasses:
PrintedBook adds numberOfPages and shelfNumber
EBook adds fileFormat, fileSizeMB, and licenseEndDate
Borrow and Return logic using an availability flag
Dynamic Polymorphism via base class pointers
Sorting by Book Title (ascending or descending)
Console Menu Interface for user interaction
Object-Oriented Structure: clean separation of declarations, definitions, and main logic

File Structure
LibrarySystem/
book.h - Class declarations
book.cpp - Class method definitions
main.cpp - Main program logic
README.md - Project description

How It Works
At startup, 3 printed books and 2 ebooks are added.
A main menu lets users:
Display all books
Borrow a book (based on ISBN)
Return a book (based on ISBN)
Add a new book
Exit the application
Borrowing: Only possible if availability == true
Returning: Resets availability to true

Class Overview
Book (Base Class)
Attributes: title, author, ISBN, availability, dateAdded
Methods:
setBookDetails(), displayBookDetails()
borrowBook(), returnBook(), isAvailable()
getISBN(), getTitle(), etc.
static sortBooksByTitle(Book*[], int, bool)

PrintedBook (Derived from Book)
Additional Attributes: numberOfPages, shelfNumber
Methods:
setPrintedBookDetails(), displayBookDetails()

EBook (Derived from Book)
Additional Attributes: fileFormat, fileSizeMB, licenseEndDate
Methods:
setEBookDetails(), displayBookDetails()

Example Use Cases
Borrowing a printed book:
Input ISBN when prompted and check availability.
Returning an ebook:
Enter the ISBN to mark it as available again.
Adding a new book: The user inputs the book information.

Concepts Demonstrated
Inheritance: PrintedBook and EBook inherit from Book.
Polymorphism: Base class pointer array holds derived class objects.
Encapsulation: Attributes are private, accessed via methods.

Notes
The borrowBook() method checks the availability flag and displays a message if the book is already borrowed.
Demonstrates OOP best practices like:
Inheritance: PrintedBook and EBook extend from Book.
Encapsulation: Book data is protected through accessors/mutators.
Polymorphism: Shared interface with distinct child behavior.

