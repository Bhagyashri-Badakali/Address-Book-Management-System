# Address Book Management System in C

## Overview

The Address Book Management System is a menu-driven application developed using the C programming language. It provides a simple way to manage contact information through a command-line interface.

The application allows users to create, search, edit, and delete contacts, display the complete contact list, and save contact information to a file. The project focuses on applying core C programming concepts through a practical application.

## Features

- **Create Contact:** Add new contacts to the address book.
- **Search Contact:** Search for existing contacts.
- **Edit Contact:** Modify the details of a saved contact.
- **Delete Contact:** Remove contacts from the address book.
- **List All Contacts:** Display all contacts in a structured table.
- **Save and Exit:** Save contact information before exiting the application.

## Technologies Used

- C Programming
- GCC Compiler
- Structures and Functions
- Header Files
- File Handling
- ANSI Escape Codes for terminal colors

## Project Structure

```text
AddressBook-NewDesign/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.txt
└── .gitignore
```

## Application Workflow

1. Launch the application.
2. Select an operation from the main menu.
3. Enter the required contact information or search criteria.
4. Perform the selected contact management operation.
5. View the results in the terminal.
6. Select **Save and Exit** to save the contact information and close the application.

## Getting Started

### Prerequisites

- GCC compiler
- A C development environment, such as Visual Studio Code with GCC configured

### Compilation

Open a terminal in the project directory and compile the source files:

```bash
gcc main.c contact.c file.c -o address_book
```

Make sure all required source files are included in the compilation command.

### Run the Application

**Windows (PowerShell):**

```powershell
.\address_book.exe
```

**Linux:**

```bash
./address_book
```

## Concepts Practiced

- Modular programming using multiple source files
- Header files and function declarations
- Structures for organizing contact information
- Functions and menu-driven control flow
- File operations for storing contact data
- Formatted console output
- Basic error handling and input processing


## Author

Developed as a C programming project to strengthen my understanding of programming fundamentals, modular design, and file handling.

---
