/*----------------------------------------------------------------
AUTHOR: spexcher
Name: Gourab Modak
email: gm2623@cse.jgec.ac.in
Institution: Jalpaiguri Government Engineering College (B. Tech UG CSE 4 year)
Github: https://github.com/gauravthedeveloper/
linkedin : https://www.linkedin.com/in/gourabmodak/
codeforces : https://codeforces.com/profile/sectumsempra07/
codechef : https://www.codechef.com/users/sectumsempra07/
leetcode : https://leetcode.com/sectumsempra07/
--------------------------------------------------------------------
*/
#include <stdio.h>

void createArray(int arr[], int n)
{
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void modifiedBubbleSort(int arr[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped++;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    createArray(arr, n);

    printf("\nOriginal array:\n");
    displayArray(arr, n);

    selectionSort(arr, n);
    printf("\nArray after Selection Sort:\n");
    displayArray(arr, n);

    bubbleSort(arr, n);
    printf("\nArray after Bubble Sort:\n");
    displayArray(arr, n);

    modifiedBubbleSort(arr, n);
    printf("\nArray after Modified Bubble Sort:\n");
    displayArray(arr, n);

    insertionSort(arr, n);
    printf("\nArray after Insertion Sort:\n");
    displayArray(arr, n);

    mergeSort(arr, 0, n - 1);
    printf("\nArray after Merge Sort:\n");
    displayArray(arr, n);

    return 0;
}
