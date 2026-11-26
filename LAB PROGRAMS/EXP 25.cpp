#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    FILE *fp;
    struct stat st;
    int ch;

    fp = fopen("sample.txt", "w+");

    if(fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    fprintf(fp, "Operating System Lab");

    printf("File created successfully\n");

    fseek(fp, 0, SEEK_SET);

    printf("File contents: ");

    while((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);

    if(stat("sample.txt", &st) == 0)
    {
        printf("\n\nFile size: %ld bytes", (long)st.st_size);
    }
    else
    {
        printf("\nUnable to get file information");
    }

    return 0;
}