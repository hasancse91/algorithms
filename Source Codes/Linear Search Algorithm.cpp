#include<stdio.h>
#define arr_size 100

int main()
{
    int i, n, arr[arr_size], item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter your searching item: ");
    scanf("%d", &item); //that value we want to search

    //Searching start
    for(i=0; i<arr_size; i++)
    {
        if(arr[i]==item)
        {
            printf("\nItem found. Location is: %d\n", i+1);
            break;
        }
    }

    if(i==arr_size)
        printf("\nItem not found\n");

    return 0;
}

