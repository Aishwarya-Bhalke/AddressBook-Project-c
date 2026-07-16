/*
Aishwarya B.Bhalke 
25012_096
24/07/2025
AddressBook holds all contacts and the total number of contacts it stored feilds
name: the contact's name
phone :tha contact's phone
email:the contact's email
AddressBook project
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "ctype.h"

void listContacts(struct AddressBook *addressBook)
{
    
       for(int i=0;i<addressBook->contactCount;i++)
      {   
        printf("\ncontact %d\n",i+1);
        printf("Name : %s\n",addressBook -> contacts[i].name);
        printf("phone : %s\n",addressBook -> contacts[i].phone);
        printf("Email: %s\n",addressBook -> contacts[i].email);
      }
    /* Define the logic for print the contacts */
}


void initialize(struct AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);

}
void saveAndExit(struct AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);             // Exit the program 
}

//to validate to name
int validate_name(char name[])
{

 //Name contain should be  only alphabets
    for(int i=0;name[i]!='\0';i++)
    {
        if(name[i]>='a' && name[i]<'z' ||name[i]>='A' && name[i]<='Z')
        {
              continue;
        }
        else
        {
            return 0;  

        }
    }
    return 1;
}




//to validate to phone
int validate_phone(char phone[])
{

    int count = 0;

    // Loop through each character in the string
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            count++;  // Count only if it's a digit
        }
        else
        {
            return 0;  // Invalid character found
        }
    }

    // Check if total digits are exactly 10
    if (count == 10)
    {
        return 1;  // Valid phone number
    } 
    else
    {
        return 0;  // Not exactly 10 digits
    }
}

    
  // to valid to email

  int validate_email(char email[])
  {
        
    if(!islower(email[0]))
    {
        printf("Invalid Email ID! Enter again\n");
        return 0;
    }

    char *isatpresent = strchr(email, '@');
    if(isatpresent == NULL)
    {
        printf("Invalid Email ID! Enter again\n");
        return 0;
    }
    // Validate username part (before '@')
    for(int i = 1; email + i < isatpresent; i++)
    {
        if(!islower(email[i])  && !isdigit(email[i]))
        {
           printf("Invalid Email ID! Enter again\n");
            return 0;
        }
    }

    char *isdotpresent = strchr(isatpresent, '.');
    if(isdotpresent == NULL)
    { 
        printf("Invalid Email ID! Enter again\n");
        return 0;
    }
    if(isdotpresent <= isatpresent+1)
    {
        printf("Invalid Email ID! Enter again\n");
        return 0;
    }
    // Validate domain part (between @ and .)
    for(int i = 1;  isatpresent + i < isdotpresent; i++)
    {
        if(!islower(isatpresent[i]) && !isdigit(isatpresent[i]))
        {
            printf("Invalid Email ID! Enter again\n");
            return 0;
        }
    }
    // Allow only .com domain
    if(strcmp(isdotpresent, ".com") != 0)
    {
        printf("Invalid Email ID! Enter again\n");
        return 0;
    }
    return 1;
}



  

void createContact(struct AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */

    printf("------------------------###create contact###---------------------------------------------\n");
    // Name 
    char name[100];
    char phone[100];
    char email[100];
    do
    {
        printf("Enter the name: "); //name
        scanf(" %[^\n]", name);
        int res=validate_name(name);
        if(res==1)
        {
          strcpy(addressBook->contacts[addressBook->contactCount].name,name);//storing the name
           
            break;
        }
        else
        {
            printf("Invalid name. please Try again.\n");
        }
    }
    while(1);


    do
    {
        printf("Enter the phone: ");
        scanf(" %[^\n]", phone);  //phone
        int res=(validate_phone(phone));
        if(res==1)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].phone,phone); //storing the phone
            
            break;
        }
        else
        {
            printf("Invalid phone number. Try again.\n");
        }
    }
    while(1);
    

    do
    {
         printf("Enter email: ");
        scanf(" %[^\n]", email);
        int res=(validate_email(email));
        if(res==1)
        {
           strcpy(addressBook->contacts[addressBook->contactCount].email,email);  //storing the email
   
            break;
        }
        else
        {

            //printf("Invalid email. Try again.\n");
        }
    }
    while(1); 


    addressBook->contactCount++;
    printf("Contact created successfully!\n");
    printf("-------------------------------------------------------------------------------------------");
    
}
    // Read the name from the user
    // Increment the contact count.  is valid
void searchContact(struct AddressBook *addressBook)
{
    printf("--------------------------##### Search Contact #####------------------------\n");
    char name[100];
    char phone[100];
    char email[100];
    int opt;
    printf("1. Name\n2. Phone\n3. Email\n4 Exit.\n");
    printf("Enter your option: ");
    scanf("%d", &opt);
       
    
    if (opt == 1)
    {   
        int flag=1;
        do
        {
        printf("Enter the name to search: "); //searching by name
        scanf(" %[^\n]", name);
        if(validate_name(name))  //validate the name
        {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, name) == 0)  //compare the number
            {
                printf("------------ Contact Found ------------\n");
                printf("Name   : %s\n", addressBook->contacts[i].name);
                printf("Phone  : %s\n", addressBook->contacts[i].phone);
                printf("Email  : %s\n", addressBook->contacts[i].email);
                printf("----------------------------------------\n");
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            printf("contact not found");
            
        }
        break;
    }
    else
    {
        printf("Invalid input please try again");
        flag=0;
    }
}while(1);
}
    else if (opt == 2)
    {
        int flag=1;
        do
        {
        printf("Enter the phone to search: ");
        scanf(" %[^\n]", phone);  //searching for phone
        if(validate_phone(phone))  //valiation the phone
        {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, phone) == 0) //compare phone
            {
                printf("------------ Contact Found ------------\n");
                printf("Name   : %s\n", addressBook->contacts[i].name);
                printf("Phone  : %s\n", addressBook->contacts[i].phone);
                printf("Email  : %s\n", addressBook->contacts[i].email);
                printf("----------------------------------------\n");
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            printf("contact not found");
            
        }
        break;
    }
     else
     {
        printf("Invalid input please try again");
        flag=0;
      }
    }  while(1);
    }
    
    else if (opt == 3)
    {
        int flag=1;
      
     do
      {
        printf("Enter the email to search: ");
        scanf(" %[^\n]", email);     //searching by email
        if(validate_email(email))  //validate the email
       {
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, email) == 0) //compare email
            {
                printf("------------ Contact Found ------------\n");
                printf("Name   : %s\n", addressBook->contacts[i].name);
                printf("Phone  : %s\n", addressBook->contacts[i].phone);
                printf("Email  : %s\n", addressBook->contacts[i].email);
                printf("----------------------------------------\n");
                flag = 0;
                break;
            }
        }
       if(flag==1)
        {
            printf("contact not found");
            
        }
        break;
    }
     else
     {
        printf("Invalid input please try again");
        flag=0;
      }
    }  while(1);
    }
    
    
    else if(opt==4)
    {
        printf("Exiting edit contact...\n");
    }
}



    /* Define the logic for search */
void editContact(struct AddressBook *addressBook)
{
     //Define the logic for Editcontact
    printf("--------------------------##### Edit Contact #####------------------------\n");

    int opt;
    int flag = 1;
    do
    {
        printf("\n1. Edit by Name\n2. Edit by Phone\n3. Edit by Email\n4. Exit.n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        if (opt == 1)
        {
            char name[100];
            printf("Enter the name: ");
            scanf(" %[^\n]", name);  

            if (validate_name(name))  //valiadate by name
            {
                flag = 1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].name, name) == 0) //compare by name
                    {
                        printf("\nContact Found:\n");
                        printf("Name : %s\n", addressBook->contacts[i].name);
                        printf("Phone: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);

                        char new_name[100];
                        printf("Enter new name: ");  
                        scanf(" %[^\n]", new_name);

                        if (validate_name(new_name))  // validation for name
                        {
                            strcpy(addressBook->contacts[i].name, new_name);//storing the new_name
                            printf("Contact Edited Successfully!\n");
                        }
                        else
                        {
                            printf("Invalid new name. Edit failed.\n");
                        }

                        flag = 0;
                        break;
                    }
                }

                if (flag == 1)
                {
                    printf("Contact not found.\n");
                }
            }
            else
            {
                printf("Invalid name input. Please try again.\n");
            }
        }

        else if (opt == 2)
        {
            char phone[100];
            printf("Enter the phone of the contact to edit: "); //Edited by phone 
            scanf(" %[^\n]", phone);

            if (validate_phone(phone)) // valiadtion for phone 
            {
                flag = 1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].phone, phone) == 0) //compare phone
                    {
                        printf("\nContact Found:\n");
                        printf("Name : %s\n", addressBook->contacts[i].name);
                        printf("Phone: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);

                        char new_phone[100];
                        printf("Enter new phone: ");
                        scanf(" %[^\n]", new_phone);

                        if (validate_phone(new_phone))   //validation for newphone
                        {
                            strcpy(addressBook->contacts[i].phone, new_phone); //storing the newphone
                            printf("Contact Edited Successfully!\n");
                        }
                        else
                        {
                            printf("Invalid new phone. Edit failed.\n");
                        }

                        flag = 0;
                        break;
                    }
                }

                if (flag == 1)
                {
                    printf("Contact not found.\n");
                }
            }
            else
            {
                printf("Invalid phone input. Please try again.\n");
            }
        }

        else if (opt == 3)
        {
            char email[100];
            printf("Enter the email of the contact to edit: "); //edited by email
            scanf(" %[^\n]", email);

            if (validate_email(email)) //validation by email
            {
                flag = 1;
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].email, email) == 0) //compare email
                    {
                        printf("\nContact Found:\n");
                        printf("Name : %s\n", addressBook->contacts[i].name);
                        printf("Phone: %s\n", addressBook->contacts[i].phone);
                        printf("Email: %s\n", addressBook->contacts[i].email);

                        char new_email[100];
                        printf("Enter new email: ");
                        scanf(" %[^\n]", new_email);

                        if (validate_email(new_email))  //valiadtion for new_email
                        {
                            strcpy(addressBook->contacts[i].email, new_email);// storing the new_email
                            printf("Contact Edited Successfully!\n");
                        }
                        else
                        {
                            printf("Invalid new email. Edit failed.\n");
                        }

                        flag = 0;
                        break;
                    }
                }

                if (flag == 1)
                {
                    printf("Contact not found.\n");
                }
            }
            else
            {
                printf("Invalid email input. Please try again.\n");
            }
        }

        else if (opt == 4)
        {
            printf("Exiting edit contact...\n");
        }

        else
        {
            printf("Invalid option. Please try again.\n");
        }

    } while (opt != 4);
}

    

    /* Define the logic for Editcontact */

void deleteContact(struct AddressBook *addressBook)
{
    // define the logic for Edited contact 
    char name[50];
    char phone[50];
    char email[50];
     int opt;
    printf("1. Name\n2. Phone\n3. Email\n"); //delete by name ,phone ,email
    printf("Enter your option: ");
    scanf("%d", &opt); 
    if(opt==1)
    {
        int flag=0;
         printf("Enter the name of the contact to delete: ");
         scanf(" %[^\n]", name); //deleted by name

      for (int i = 0; i < addressBook->contactCount; i++) 
      {
          if (strcmp(addressBook->contacts[i].name, name) == 0) 
          {
            // Shift remaining contacts up
            for (int j = i; j < addressBook->contactCount - 1; j++) 
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1]; //replace the current data with next data
            }
            addressBook->contactCount--;  //decrements the count
            flag = 1;
            printf("Contact deleted successfully!\n");
            break;
        }
    }

     if (flag==0)
    {
        printf("Contact not found.\n");
    }
}

   else if(opt==2)
   {
    int flag=0;
         printf("Enter the phone of the contact to delete: ");
         scanf(" %[^\n]", phone); //deleted by phone

      
  for (int i = 0; i < addressBook->contactCount; i++) 
      {
          if (strcmp(addressBook->contacts[i].phone, phone) == 0)// compare phone
          {
            // Shift remaining contacts up
            for (int j = i; j < addressBook->contactCount - 1; j++) 
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1]; //replace the current data with next data
            }
            addressBook->contactCount--; //decrements the count
            flag = 1;
            printf("Contact deleted successfully!\n");
            break;
        }
   }
   
     if (flag==0)
    {
        printf("Contact not found.\n");
    }
}
 else if(opt==3)
 {
    int flag=0;
         printf("Enter the email of the contact to delete: ");
         scanf(" %[^\n]", email);  //deletd by email

      for (int i = 0; i < addressBook->contactCount; i++) 
      {
          if (strcmp(addressBook->contacts[i].email, email) == 0)  //compare email
          {
            // Shift remaining contacts up
            for (int j = i; j < addressBook->contactCount - 1; j++) 
            {
                addressBook->contacts[j] = addressBook->contacts[j + 1]; //replace the current data with next data
            }
            addressBook->contactCount--; //decrement count
            flag = 1;
            printf("Contact deleted successfully!\n");
            break;
        }
   }
   
     if (flag==0)
    {
        printf("Contact not found.\n");
    }
}

}


