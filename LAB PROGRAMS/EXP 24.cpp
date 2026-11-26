#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char data[100];

    fp = fopen("sample.txt", "w");

    if(fp == NULL)
    {
        printf("File creation failed");
        return 1;
    }

    printf("File created successfully\n");

    fprintf(fp, "Hello World!\n");
    fprintf(fp, "Operating Systems Lab");

    fclose(fp);

    fp = fopen("sample.txt", "r");

    if(fp == NULL)
    {
        printf("File opening failed");
        return 1;
    }

    printf("\nFile Contents:\n");

    while(fgets(data, sizeof(data), fp) != NULL)
        printf("%s", data);

    fclose(fp);

    if(remove("sample.txt") == 0)
        printf("\nFile deleted successfully");
    else
        printf("\nFile deletion failed");

    return 0;
}