#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

const char *sourcefile =
    "C:/Users/itssk/OneDrive/Desktop/sasi.txt";

const char *destination_file =
    "C:/Users/itssk/OneDrive/Desktop/sk.txt";

/* Function to copy a file */
void copy()
{
    FILE *source = fopen(sourcefile, "rb");

    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destination = fopen(destination_file, "wb");

    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int error = 0;

    while ((bytesRead = fread(buffer, 1,
                              BUFFER_SIZE, source)) > 0) {
        if (fwrite(buffer, 1, bytesRead,
                   destination) != bytesRead) {
            perror("Error writing file");
            error = 1;
            break;
        }
    }

    if (ferror(source)) {
        perror("Error reading file");
        error = 1;
    }

    fclose(source);

    if (fclose(destination) != 0) {
        perror("Error closing destination file");
        error = 1;
    }

    if (!error) {
        printf("File copied successfully.\n");
    }
}

/* Function to create a file */
void create()
{
    FILE *fp = fopen(sourcefile, "w");

    if (fp == NULL) {
        perror("File creation failed");
        return;
    }

    fclose(fp);
    printf("File created successfully.\n");
}

/* Function to delete a file */
void deleteFile()
{
    if (remove(sourcefile) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("File deletion failed");
    }
}

/* Main function */
int main()
{
    int n;

    printf("\n--- FILE MANAGEMENT ---\n");
    printf("1. Create File\n");
    printf("2. Copy File\n");
    printf("3. Delete File\n");
    printf("Enter your choice: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (n) {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            deleteFile();
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}