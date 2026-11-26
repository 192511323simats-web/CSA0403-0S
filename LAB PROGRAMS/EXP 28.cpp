#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50];
    char pattern[50];
    char line[200];
    int found = 0;

    printf("Enter filename: ");
    scanf("%49s", filename);

    printf("Enter search word: ");
    scanf("%49s", pattern);

    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("File not found");
        return 1;
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strstr(line, pattern) != NULL)
        {
            printf("%s", line);
            found = 1;
        }
    }

    if(!found)
        printf("Pattern not found");

    fclose(fp);

    return 0;
}