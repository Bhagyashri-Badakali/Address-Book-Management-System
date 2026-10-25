#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"

int length(char str[])
{
    int i =0;
    while(str[i++]);
    return i-1;
}

int validate_name(char str[])    //function for validate contact name
{
    int i=0;
    while(str[i])
    {
        if(!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'|| str[i] == '.'|| str[i] == ' '))
        {    
             printf(RED"\nThe name must contain exclusively aplhabetic /(.) /space characters...!"RESET);
            return 0; //Invalid
        }      
       i++;
    }
    return 1;   //valid
}

int validate_phone(char num[],AddressBook *addressBook) //Function to validate phone number
{
    int i=0;
    while(num[i])
    {
        if(!(num[i] >= '0' && num[i] <= '9'))
        {
              printf(RED"\nOnly digits (0-9) are allowed in phone number...!"RESET);
              return 0;  //Invalid
        }
        i++;   
    }
    if(i != 10)
    {
            printf(RED"\nPhone number should exclusively contain 10 digits...!"RESET);
            return 0; //Invalid
    }
    for(i=0 ; i <= addressBook->contactCount;i++)
    {
         if(strcmp(addressBook->contacts[i].phone,num) == 0) 
         {
            printf(RED"\nThis phone number already exist in the contact list...!"RESET);
            return 0;  //Invalid
         }
    }
    return 1; //valid
}

int validate_email(char mail_id[],AddressBook *addressBook)  //function to validate email
{
    int i = 0;
    char com[5] = ".com";   //email should end with .com
    if( !(mail_id[i] >= 'a' && mail_id[i] <= 'z'))
    {
        printf(RED"\nEmail id should exclusively start with lower alphabetical character...!\n"RESET);
        return 0;  //Invalid
    }
    i++;
    int len = length(mail_id);
    int l = 0,j;
    for(j = len-4 ; j <= len ; j++)
    {
        if(mail_id[j] != com[l])
        {
            printf(RED"\nEmail should end with .com ..."RESET);
            return 0;  //Invalid
        }
        l++;
    }
    int flag = 0;  //to check @ should only one
    int check = 0;  //to store index of @
    while(mail_id[i])
    {
       if(!(mail_id[i] >= 'a' && mail_id[i] <= 'z' || mail_id[i] == '.' ||
                mail_id[i] >= '0' && mail_id[i] <= '9' || mail_id[i] == '@'))
        {
           printf(RED"\nEmail should contain only lower case alphabets and digits and special chaaratter (@) & (.) only...!"RESET);
           return 0;  //Invalid
        }   
        if(mail_id[i] == '@')
        {
            flag++;
            check = i;
        }   
        i++;
    }
    if(flag!=1)
    {
         printf(RED"\nEmail should contain only one @ character...!"RESET);
         return 0; //Invalid
    }
    else
    {
       if(((len-4)-check ) <= 1 )
        {
           printf(RED"\nThere should be minimum one character between @ and .com ..."RESET);
             return 0;  //Invalid
        }
        else
        {
          int m;
          for(m = check + 1 ; m < len-4 ; m++)
          {
             if(!(mail_id[m] >= 'a' && mail_id[m] <= 'z' || mail_id[m] >= '0' && mail_id[m] <= '9'))
              {
                 printf(RED"\nIn Email b/w @ and .com only charcaters and digits valid...!"RESET);
                 return 0;//Invalid
               }
            }
         }
    }

    for(i=0 ; i <= addressBook->contactCount;i++)
    {
         if(strcmp(addressBook->contacts[i].email,mail_id) == 0) 
         {
            printf(RED"\nThis Email id already exist in the contact list...!"RESET);
            return 0;//Invalid
         }
    }     
   return 1; //valid
}

void createContact(AddressBook *addressBook)
{
    char str[50];
    char num[20];
    char mail_id[50]; 
    int res=0,i=3;
    while(res == 0 && i != 0)
    {
          printf(BLUE"\nEnter the Name : "RESET);  //ask user to enter the name
          scanf(" %[^\n]",str);
          res = validate_name(str);
          i--;
          if(res)
             break;
          else
            printf(RED"\nattemptes left %d out of 3"RESET,i);    
    } 
    if(i == 0)
    {
        printf(RED"\nattempt left 0 Too many attempts returning to main menu..."RESET);
        return;
    }
     res=0;
     i=3;
    while(res == 0 && i != 0)
    {
        printf(BLUE"\nEnter the Phone No : "RESET);
        scanf(" %[^\n]",num);
        res = validate_phone(num,addressBook);
        i--;
          if(res)
             break;
          else
            printf(RED"\nattemptes left %d out of 3"RESET,i);    
    } 
    if(i == 0)
    {
        printf(RED"\nattempt left 0 Too many attempts returning to main menu..."RESET);
        return;
    }
    res=0;
     i=3;
     while(res == 0 && i != 0)
    {
        printf(BLUE"\nEnter the mail id : "RESET);
        scanf(" %[^\n]",mail_id);
        res = validate_email(mail_id,addressBook);
        i--;
          if(res)
             break;
          else
            printf(RED"\nattemptes left %d out of 3"RESET,i);    
    }
    if(i == 0)
    {
        printf(RED"\nattempt left 0 Too many attempts returning to main..."RESET);
        return;
    };
    strcpy((addressBook->contacts[addressBook->contactCount]).name,str);
    strcpy((addressBook->contacts[addressBook->contactCount]).phone,num);
    strcpy((addressBook->contacts[addressBook->contactCount]).email,mail_id);

    addressBook->contactCount++;
    printf("\n"SUCCESS GREEN"Successfully Created contact ...\n\n"RESET);
}


void sort_by_name(AddressBook *addressBook)
{
    int i,j;
    Contact temp;
    //Bubble sort based on Name
    for(i = 0; i < addressBook->contactCount - 1 ; i++)
    {
        for(j = 0 ; j < addressBook->contactCount - i - 1 ; j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }

    printf( RED CONTACT RESET "  Contact List: \n");
    printf("+-----------------------------------------------------------------------+");
    printf("\n|"MAGENTA"SI.No\tName\t\tPhone No\t\tEmail ID  \t\t"RESET"|");
    printf("\n+-----------------------------------------------------------------------+");
    for(i = 0; i < addressBook->contactCount ; i++)
    {
      printf("\n|%d\t%s\t\t%s\t\t%-20s\t|",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone
                ,addressBook->contacts[i].email);
    }
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n\n\n");
}

void sort_by_phone(AddressBook *addressBook)
{
    int i,j;
    Contact temp;
    //Bubble sort based on phone number
    for(i = 0; i < addressBook->contactCount-1; i++)
    {
        for(j = 0 ; j < addressBook->contactCount - i -1; j++)
        {
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    printf( RED CONTACT RESET "  Contact List: \n");
      printf("+-----------------------------------------------------------------------+");
    printf("\n|"MAGENTA"SI.No\tName\t\tPhone No\t\tEmail ID  \t\t"RESET"|");

    printf("\n+-----------------------------------------------------------------------+");
    for(i = 0; i < addressBook->contactCount ; i++)
    {
      printf("\n|%d\t%s\t\t%s\t\t%-20s\t|",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone
                ,addressBook->contacts[i].email);
    }
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n\n\n");
}

void sort_by_email(AddressBook *addressBook)
{

    int i,j;
    Contact temp;
    //Bubble sort based on Email ID
    for(i = 0; i < addressBook->contactCount - 1 ; i++)
    {
        for(j = 0 ; j < addressBook->contactCount - i -1 ; j++)
        {
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
     printf( RED CONTACT RESET "  Contact List: \n");
      printf("+-----------------------------------------------------------------------+");
    printf("\n|"MAGENTA"SI.No\tName\t\tPhone No\t\tEmail ID  \t\t"RESET"|");
    printf("\n+-----------------------------------------------------------------------+");
    for(i = 0; i < addressBook->contactCount ; i++)
    {
      printf("\n|%d\t%s\t\t%s\t\t%-20s\t|",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone
                ,addressBook->contacts[i].email);
    }
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n\n\n");
}

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the field
    if(addressBook->contactCount <= 0)
    {
        printf(RED"Zero Contacts in the list...."RESET);
        return;
    } 
    int choice;
        printf(YELLOW"1.Sort by Name\n2.Sort by Phone\n3.Sort by Email\n4.Exit"RESET);
        printf(CYAN"\nEnter the choice : "RESET);
         //__fpurge(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:sort_by_name(addressBook);
                   break;
            case 2:sort_by_phone(addressBook);
                   break;
            case 3:sort_by_email(addressBook);
                   break;
            case 4:printf(GREEN"\nExit from list of contacts is success..."RESET);
                   break; 
            default:printf(RED"\nInvalid Choice"RESET);                           
        }    
}

void initialize(AddressBook *addressBook) {
   addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
   saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


int search_by_name(AddressBook *addressBook)
{
   char s_name[50]; 
   printf(BLUE"Enter Name to search: "RESET);
    //__fpurge(stdin);
   scanf(" %[^\n]",s_name);
   int i,count=0,num;
   int index[100]={0};
   for(i = 0 ; i < addressBook->contactCount ;i++ )
   {
       if(strcmp(addressBook->contacts[i].name,s_name) == 0)
            index[count++] = i;
   }
    if(count == 1)
    {
        return index[0];   //single name found
    } 
    if(count > 1)     //Multiple name found
    {
       
        for(i = 0; i < count ;i++)
        {
           printf(MAGENTA"\n%d\t%s\t%s\t%s"RESET,i+1,addressBook->contacts[index[i]].name,
                    addressBook->contacts[index[i]].phone,addressBook->contacts[index[i]].email);
        }
        do
        {
            printf("Select by serial number(1-%d):  ",count);
             //__fpurge(stdin);
            scanf("%d",&num);
            if(num>0 && num <= count)
              return index[num-1];
        }while(num<0 && num > count);     
       
    }
   return -1;  //Name not found
}

int search_by_phone(AddressBook *addressBook)
{
   char s_phone[20]; 
   printf(BLUE"Enter the Phone number to search: "RESET);
    //__fpurge(stdin);
   scanf(" %[^\n]",s_phone);

   int i;
   for(i = 0 ; i < addressBook->contactCount ;i++ )
   {
       if(strcmp(addressBook->contacts[i].phone,s_phone) == 0)
           return i;   //found phone number return index
   }
   return -1;   //not found
} 

int search_by_email(AddressBook *addressBook)
{
   char s_email[50];
   printf(BLUE"Enter the Email id to search: "RESET);
    //__fpurge(stdin);
   scanf(" %[^\n]",s_email);
   int i;
   for(i = 0 ; i < addressBook->contactCount ; i++)
   {
       if(strcmp(addressBook->contacts[i].email,s_email) == 0)
           return i;   //fond email return index
   }
   return -1;   //not found
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    if(addressBook->contactCount <= 0)
    {
        printf(MAGENTA"Zero Contacts in the list...."RESET);
        return;
    }
    int choice,res;
    do
    {
       printf(YELLOW"1.Search by Name\n2.Search by Phone Number\n3.Search by Email\n4.Exit"RESET);
       printf(BLUE"\nEnetr Your choice:  "RESET);
        //__fpurge(stdin);
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:res = search_by_name(addressBook);
                  break;
           case 2:res = search_by_phone(addressBook);
                  break;
           case 3:res = search_by_email(addressBook); 
                  break;
           case 4:printf(GREEN"\nExit success..."RESET);
                  break;
           default:printf(RED"\nInvalid choice...."RESET);                            
       }
    if(res != -1)
    {
      printf(GREEN"\nContact Found"RESET);
      printf("\n%s\t%s\t%s",addressBook->contacts[res].name,addressBook->contacts[res].phone
                    ,addressBook->contacts[res].email);
                    break;
    }
    else
    {
       printf(RED"Contact NOT FOUND"RESET);
       break;
    }  
    }while(choice != 4);
}

void edit_by_name(AddressBook *addressBook,int indx)
{
    char new_name[50];
    int res;
    do
    {
        printf(BLUE"\nEnter the New name: "RESET);
         //__fpurge(stdin);
        scanf(" %[^\n]",new_name);
        res = validate_name(new_name);
    } while (res == 0);
   strcpy(addressBook->contacts[indx].name , new_name); 
   printf(GREEN"\nSuccessfully edited the name in Contact list..."RESET);  
}

void edit_by_phone(AddressBook *addressBook,int indx)
{
    char new_phone[50];
    int res;
    do
    {
        printf(BLUE"\nEnter the New Phone Number: "RESET);
         //__fpurge(stdin);
        scanf(" %[^\n]",new_phone);
        res = validate_phone(new_phone,addressBook);
    } while (res == 0);
   strcpy(addressBook->contacts[indx].phone , new_phone); 
   printf(GREEN"\nSuccessfully edited the Phone number in Contact list..."RESET);  
}

void edit_by_email(AddressBook *addressBook,int indx)
{
    char new_email[50];
    int res;
    do
    {
        printf(BLUE"\nEnter New Email ID: "RESET);
         //__fpurge(stdin);
        scanf(" %[^\n]",new_email);
        res = validate_email(new_email,addressBook);
    } while (res == 0);
   strcpy(addressBook->contacts[indx].email , new_email); 
   printf(GREEN"\nSuccessfully edited the email id in Contact list..."RESET);  
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    if(addressBook->contactCount <= 0)
    {
        printf(MAGENTA"Zero Contacts in the list...."RESET);
        return;
    }
    int choice,res;
    do
    { 
      printf(BLUE"\nTo Edit contact Search contact by -->"RESET);
      printf(YELLOW"\n1.Search by Name\n2.Seacrh by Phone\n3.Search by Email\n4.exit"RESET);
      printf(BLUE"\nEnter a Choice : "RESET);
       //__fpurge(stdin);
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:res = search_by_name(addressBook);
                break;
        case 2:res = search_by_phone(addressBook);
                break;
        case 3:res = search_by_email(addressBook);
                break;
        case 4:printf(GREEN"\nExit success..."RESET);
                break; 
        default:printf(RED"\nInvalid Choice. Please Select correct choice..."RESET); 
      }  

      if(res == -1)
      {
          printf(RED"\nContact NOT FOUND"RESET);
          break;
     }
     else
     {
        int field;
        printf(YELLOW"\n1.Edit Name\n2.Edit Phone Number\n3.Edit Email ID\n4.exit"RESET);
        printf(BLUE"\nEnter the field you want to edit : "RESET);
         //__fpurge(stdin);
        scanf("%d",&field);
        switch(choice)
        {
          case 1:edit_by_name(addressBook,res);
                 break;
          case 2:edit_by_phone(addressBook,res);
                 break;
          case 3:edit_by_email(addressBook,res);
                 break;
          case 4:printf(GREEN"\nExit success..."RESET);
                 break; 
          default:printf(RED"\nInvalid Choice"RESET); 
        }  
        break; 
     } 
    } while (choice != 4);   
}

void deleteContact(AddressBook *addressBook)
{
    if(addressBook->contactCount <= 0)
    {
        printf("Zero Contacts in the list....");
        return;
    }
	int choice,res;
    do
    { 
      printf(BLUE"\nTo delete contact Search contact by "RESET);
      printf(YELLOW"\n1.Search by Name\n2.Seacrh by Phone\n3.Search by Email\n4.exit"RESET);
      printf(BLUE"\nEnter a Choice : "RESET);
       //__fpurge(stdin);
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:res = search_by_name(addressBook);
                break;
        case 2:res = search_by_phone(addressBook);
                break;
        case 3:res = search_by_email(addressBook);
                break;
        case 4:printf(GREEN"\nExit success..."RESET);
                break; 
        default:printf(RED"\nInvalid Choice"RESET); 
      }  

      if(res == -1)
      {
          printf(RED"\nContact NOT FOUND"RESET);
          break;
     }
     else
     {
        int i;
         for( i = res ; i < addressBook->contactCount ; i++)
         {
            addressBook->contacts[i] = addressBook->contacts[i+1];
         }
         addressBook->contactCount--;
         printf(GREEN "\nContact deleted Successfully..."RESET);
         break;
     } 
    } while(choice != 4);
   
}
