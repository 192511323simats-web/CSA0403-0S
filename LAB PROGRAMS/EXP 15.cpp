#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

int main()
{
    char mainDirectory[] =
        "C:/Users/itssk/OneDrive/Desktop";

    char subDirectory[] = "os";
    char fileName[] = "example.txt";
    char dirPath[200];
    char filePath[300];

    /* Create directory path */
    snprintf(dirPath, sizeof(dirPath),
             "%s/%s", mainDirectory, subDirectory);

    /* Create the folder if it does not exist */
    if (_mkdir(dirPath) != 0) {
        /* Folder may already exist */
        FILE *test = fopen(dirPath, "r");
        if (test != NULL) {
            fclose(test);
        }
    }

    /* Create complete file path */
    snprintf(filePath, sizeof(filePath),
             "%s/%s", dirPath, fileName);

    /* Create the file */
    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }

    /* Write content into the file */
    fprintf(file, "This is an example file content.");

    fclose(file);

    printf("Folder created or already exists.\n");
    printf("File created successfully: %s\n", filePath);

    return 0;
}