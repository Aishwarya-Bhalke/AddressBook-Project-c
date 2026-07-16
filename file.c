#include <stdio.h>
#include "file.h"

void saveContactsToFile(struct AddressBook *addressBook)
{
    FILE *fptr = fopen("data.csv","w");
    // Check the file is opened or not 
        fprintf(fptr,"#%d#\n",addressBook->contactCount);
        for(int i=0; i < addressBook->contactCount;i++)
        {
           
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

        } 
        fclose(fptr);

}

void loadContactsFromFile(struct AddressBook *addressBook)
{
   FILE *fptr=fopen("data.csv","r");
    //check the file is opened or not 
    if (fptr==NULL)

    printf("File not exist\n");
    int count;
    fscanf(fptr,"#%d#\n",&count);
    addressBook->contactCount=count;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
fclose(fptr);



}
