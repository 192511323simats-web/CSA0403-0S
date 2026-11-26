#include <stdio.h>
#include <windows.h>

int main()
{
    WIN32_FIND_DATA findFile;
    HANDLE hFind;

    hFind = FindFirstFile("*", &findFile);

    if(hFind == INVALID_HANDLE_VALUE)
    {
        printf("No files found");
        return 1;
    }

    printf("Files and Directories:\n\n");

    do
    {
        printf("%s\n", findFile.cFileName);
    }
    while(FindNextFile(hFind, &findFile));

    FindClose(hFind);

    return 0;
}