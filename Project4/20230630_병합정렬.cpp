//#include <iostream>
//using namespace std;
//
//const int SIZE = 13;
//
//void swap(int* a, int* b);
//void merge(int* arr1, int* arr2);
//void mergeSort(int* arr, int first, int last);
//static int* arr3 = new int[SIZE];
//
//int main()
//{
//    int arr[SIZE] = { 2,4,6,8,11,13 , 1,2,3,4,9,16,21 };
//
//    mergeSort(arr, 0, SIZE);
//
//    for (int i = 0; i < SIZE; i++)
//        cout << arr3[i] << " ";
//    cout << endl;
//
//    return 0;
//}
//
//void swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void merge(int* arr1, int* arr2, int first, int last)
//{
//    int pa = 0, pb = 0, pc = 0;
//
//    while (pa != 6 || pb == 7)
//    {
//        arr3[pc++] = (arr1[pa] < arr2[pb]) ? arr1[pa++] : arr2[pb++];
//    }
//
//    if (pa == 6)
//    {
//        while (pb != 7)
//            arr3[pc++] = arr2[pb++];
//    }
//    else
//    {
//        while (pa != 6)
//            arr3[pc++] = arr1[pa++];
//    }
//}
//
//void mergeSort(int* arr, int first, int last)
//{
//    if (first < last)
//    {
//        int center = (first + last) / 2;
//        int* arr1 = new int[center];
//        int* arr2 = new int[center + 1];
//
//        mergeSort(arr, first, center);
//        mergeSort(arr, center + 1, last);
//        for (int i = 0; i < center; i++)
//        {
//            arr1[i] = arr[i];
//            arr2[i] = arr[center + i];
//        }
//        arr2[center] = arr[2 * center];
//
//        merge(arr1, arr2, first, last);
//    }
//
//}