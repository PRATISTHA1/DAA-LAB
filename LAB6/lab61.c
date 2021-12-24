#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int inputs[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
int arr[40000];
double random_num[10], asc[10], desc[10];
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void max_heapify(int arr[], int i, int size_)
{
    int largest, l = (2 * i) + 1, r = l + 1;

    if (l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r < size_ && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, size_);
    }
}

void build_max_heap(int arr[], int n)
{
    for (int i = (n / 2); i >= 0; i--)
        max_heapify(arr, i, n);
}

void heap_sort(int arr[], int n)
{
    build_max_heap(arr, n);
    int sz = n;
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        sz--;
        max_heapify(arr, 0, sz);
    }
}
void create_array(int n, int arr[])
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 501;
}
void display_array(int n, int arr[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void showChoices()
{
    printf("0. Quit\n1. n Random numbers=>Array\n2. Display the Array\n3. Sort the Array in Ascending Order by using Max-Heap Sort technique\n4. Sort the Array in Descending Order by using any algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order \n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending all Cases (Data Ascending,Data in Descending & Random Data) in Tabular form forvalues n=5000 to 50000, step=5000\n9. Extract largest element\n10. Replace value at a node with new value\n11. Insert a new element\n12. Delete an element\n");
    printf("Enter your choice :");
}

// A function to implement bubble sort
void descending(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void display_table()
{
    clock_t s1, s2, s3, e1, e2, e3;
    double t1, t2, t3;
    for (int i = 0; i < 8; i++)
    {
        create_array(inputs[i], arr);
        s1 = clock();
        sleep(1);
        heap_sort(arr, inputs[i]);
        e1 = clock();
        t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
        s2 = clock();
        sleep(1);
        heap_sort(arr, inputs[i]);
        e2 = clock();
        t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
        descending(arr, inputs[i]);
        s3 = clock();
        sleep(1);
        heap_sort(arr, inputs[i]);
        e3 = clock();
        t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
        random_num[i] = t1;
        asc[i] = t2;
        desc[i] = t3;
    }
    printf("INPUTS\tRANDOM\tASCENDING\tDESCENDING\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d\t%f\t%f\t%f\n", inputs[i], random_num[i], asc[i], desc[i]);
    }
}
int main()
{
    int n, choice, idx, value;
    clockid_t s1, s2, s3, e1, e2, e3;
    double t1, t2, t3;
    do
    {
        showChoices();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the size of the array :\n");
            scanf("%d", &n);
            create_array(n, arr);
            break;
        case 2:
            display_array(n, arr);
            break;
        case 3:
            s1 = clock();
            sleep(1);
            heap_sort(arr, n);
            e1 = clock();
            t1 = (double)(e1 - s1) / CLOCKS_PER_SEC;
            break;
        case 4:
            descending(arr, n);
            break;
        case 5:
            printf("Time taken to sort random data = %f\n", t1);
            break;
        case 6:
            heap_sort(arr, n);
            s2 = clock();
            sleep(1);
            heap_sort(arr, n);
            e2 = clock();
            t2 = (double)(e2 - s2) / CLOCKS_PER_SEC;
            printf("Time taken to sort ascending data data = %f\n", t2);
            break;
        case 7:
            descending(arr, n);
            s3 = clock();
            sleep(1);
            heap_sort(arr, n);
            e3 = clock();
            t3 = (double)(e3 - s3) / CLOCKS_PER_SEC;
            printf("Time taken to sort data which is sorted in descendin order = %f\n", t3);
            break;
        case 8:
            display_table();
            break;
        case 9:
            build_max_heap(arr, n);
            printf("%d", arr[0]);
            break;
        case 10:
            printf("enter idx and value\n");
            scanf("%d%d", &idx, &value);
            arr[idx] = value;
            break;
        case 11:
            printf("enter value\n");
            scanf("%d", &value);
            arr[n] = value;
            n++;
            break;

        default:
            printf("Invalid input");
        }

    } while (choice != 0);
}