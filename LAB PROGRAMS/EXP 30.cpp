#include <stdio.h>
#include <windows.h>

DWORD WINAPI threadFunction(LPVOID arg)
{
    printf("Thread is running\n");

    ExitThread(0);

    return 0;
}

int main()
{
    HANDLE thread1, thread2;
    DWORD id1, id2;

    thread1 = CreateThread(
        NULL, 0, threadFunction, NULL, 0, &id1);

    thread2 = CreateThread(
        NULL, 0, threadFunction, NULL, 0, &id2);

    if(thread1 == NULL || thread2 == NULL)
    {
        printf("Thread creation failed\n");
        return 1;
    }

    printf("Threads created successfully\n");

    if(id1 == id2)
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    printf("Threads joined successfully\n");

    CloseHandle(thread1);
    CloseHandle(thread2);

    return 0;
}