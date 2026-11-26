#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    HANDLE hMapFile;
    char *shm_ptr;

    // Create shared memory
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        SHM_SIZE,
        "MySharedMemory"
    );

    if (hMapFile == NULL)
    {
        printf("Error creating shared memory.\n");
        return 1;
    }

    // Attach shared memory
    shm_ptr = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHM_SIZE
    );

    if (shm_ptr == NULL)
    {
        printf("Error attaching shared memory.\n");
        CloseHandle(hMapFile);
        return 1;
    }

    // Write data to shared memory
    strcpy(shm_ptr, "Hello, shared memory!");

    // Display data
    printf("Data written to shared memory: %s\n", shm_ptr);

    // Detach shared memory
    UnmapViewOfFile(shm_ptr);

    // Close shared memory handle
    CloseHandle(hMapFile);

    getch();

    return 0;
}