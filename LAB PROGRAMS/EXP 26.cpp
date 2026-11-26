#include <stdio.h>

int main()
{
    FILE *fp;
    char data[100];
    int choice;

    printf("1. Create and Write\n");
    printf("2. Read File\n");
    printf("3. Delete File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            fp = fopen("example.txt", "w");

            if(fp == NULL)
            {
                printf("File creation failed");
                return 1;
            }

            printf("Enter text: ");
            scanf(" %[^\n]", data);

            fprintf(fp, "%s", data);
            fclose(fp);

            printf("File created successfully");
            break;

        case 2:
            fp = fopen("example.txt", "r");

            if(fp == NULL)
            {
                printf("File not found");
                return 1;
            }

            while(fgets(data, sizeof(data), fp) != NULL)
                printf("%s\n", data);

            fclose(fp);
            break;

        case 3:
            if(remove("example.txt") == 0)
                printf("File deleted successfully");
            else
                printf("File not found");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}