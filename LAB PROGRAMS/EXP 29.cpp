#include <stdio.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int count = 0;

void produce()
{
    int item;

    if(count == SIZE)
    {
        printf("Buffer is Full\n");
        return;
    }

    printf("Enter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    in = (in + 1) % SIZE;
    count++;

    printf("Produced item: %d\n", item);
}

void consume()
{
    int item;

    if(count == 0)
    {
        printf("Buffer is Empty\n");
        return;
    }

    item = buffer[out];
    out = (out + 1) % SIZE;
    count--;

    printf("Consumed item: %d\n", item);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                produce();
                break;

            case 2:
                consume();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}