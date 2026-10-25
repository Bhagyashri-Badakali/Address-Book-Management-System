# Address-Book-Management-System
A menu-driven Address Book Management System written in C, supporting contact creation, searching, editing, deletion, listing, and file-based saving.

## Overview

This project provides a simple and organized way to manage contact details. Users can create, search, edit, and delete contacts, view the complete contact list, and save contact information to a file before exiting the application.

The project was developed to strengthen my understanding of C programming, modular program design, and file handling.

## Features

- **Create Contact:** Add new contacts to the address book.
- **Search Contact:** Find existing contacts.
- **Edit Contact:** Modify stored contact information.
- **Delete Contact:** Remove contacts from the address book.
- **List All Contacts:** Display all available contacts in a formatted table.
- **Save and Exit:** Save contact information to a file before closing the application.
- **Formatted Console Interface:** Display a structured menu with colored text for improved readability.

## Technologies Used

- C Programming
- GCC Compiler
- Structures and Functions
- Header Files
- File Handling
- ANSI Escape Codes

## Project Structure

```text
AddressBook-NewDesign/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.txt
└── README.md
```

*The structure above is illustrative; additional source files may be required depending on the implementation.*

## Getting Started

### Prerequisites

- GCC compiler
- A C development environment, such as VS Code with GCC configured

### Compilation

Compile the source files using GCC:

```bash
gcc main.c contact.c -o address_book
```

Include all required source files in the compilation command.

### Execution

**Windows (PowerShell):**

```powershell
.\address_book.exe
```

**Linux:**

```bash
./address_book
```

## Key Learning Outcomes

- Applying modular programming principles in C
- Organizing code using header and source files
- Implementing menu-driven program logic
- Managing structured contact information
- Working with file operations for data storage
- Improving console output formatting

## Future Enhancements

- Input validation and error handling
- Duplicate contact detection
- Improved search options
- Persistent storage and reliable data loading at startup

## Author

Developed as a C programming project to gain practical experience in software development and problem-solving.
