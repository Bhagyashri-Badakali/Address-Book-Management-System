#include <stdio.h>
#include "contact.h"

int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do 
    {
        printf("\n"); 
        printf(BG_BLUE YELLOW "ADDRESS BOOK MENU "RESET "\n\n");   //Menu display

        printf(MAGENTA "1. Create Contact\n" RESET);
        printf(MAGENTA "2. Search Contact\n" RESET);
        printf(MAGENTA "3. Edit Contact\n" RESET);
        printf(MAGENTA "4. Delete Contact\n" RESET);
        printf(MAGENTA "5. List All Contacts\n" RESET);
    	printf(MAGENTA "6. Save and Exit\n"RESET);		
        printf(CYAN "Enter your choice: "RESET);
       
        scanf("%d", &choice);                 //get choice from user
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf(GREEN "Saving and Exiting...\n\n"RESET);
                saveContactsToFile(&addressBook);
                break;
            default:
                printf(RED"Invalid choice. Please try again.\n"RESET);
        }
    } while (choice != 6);   //if choice 6 save and exit
    
    return 0;
}
