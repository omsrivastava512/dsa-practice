#include <vector>
#include <string>
#include <utility>

using namespace std;
 
/*************
 * Array Basics
 *************/

// Implement a class for dynamic array operations
class ArrayOperations {
private:
    int* arr;
    int size;
    int capacity;
public:
    // Constructor, destructor
    // insertAt(index, value)
    // deleteAt(index)
    // search(value) - return index
    // display()
    // resize() - when capacity is full
};

// 1. Reverse array in-place without extra space
void reverseArray(int arr[], int n);

// 2. Rotate array left by k positions
void rotateLeft(int arr[], int n, int k);

// 3. Find second largest element without sorting
int secondLargest(int arr[], int n);

// 4. Move all zeros to end maintaining order of non-zeros
void moveZerosToEnd(int arr[], int n);

// 5. Remove duplicates from sorted array in-place
int removeDuplicates(int arr[], int n);

// 1. Count frequency of each element (without using extra array)
void countFrequency(int arr[], int n);

// 2. Find missing number in array of size n-1 with numbers 1 to n
int findMissing(int arr[], int n);

// 3. Find the element that appears odd number of times
int findOdd(int arr[], int n);

// 4. Check if array is a subset of another array
bool isSubset(int arr1[], int m, int arr2[], int n);

// 1. Basic linear search
int linearSearch(int arr[], int n, int key);

// 2. Linear search in unsorted array - find all occurrences
vector<int> linearSearchAll(int arr[], int n, int key);

// 3. Search in array where difference between adjacent is at most k
int searchInSpecialArray(int arr[], int n, int x, int k);

// 4. Find element in array sorted in ascending then descending order
int searchInBitonicArray(int arr[], int n, int key);

// 1. Iterative binary search
int binarySearchIterative(int arr[], int n, int key);

// 2. Recursive binary search
int binarySearchRecursive(int arr[], int low, int high, int key);

// 3. Find first occurrence of element in sorted array with duplicates
int findFirst(int arr[], int n, int key);

// 4. Find last occurrence of element in sorted array with duplicates
int findLast(int arr[], int n, int key);

// 5. Count occurrences in sorted array
int countOccurrences(int arr[], int n, int key);

// 1. Bubble Sort with optimization
void bubbleSort(int arr[], int n);

// 2. Selection Sort
void selectionSort(int arr[], int n);

// 3. Insertion Sort
void insertionSort(int arr[], int n);

// 4. Insertion Sort for nearly sorted array
void insertionSortOptimized(int arr[], int n);

// Compare performance and write analysis for each

/**********************
 *  Advanced in array
 **********************/

// 1. Search in rotated sorted array
int searchRotated(int arr[], int n, int key);

// 2. Find peak element (element greater than its neighbors)
int findPeak(int arr[], int n);

// 3. Find square root of number using binary search
int sqrt(int x);

// 4. Search in 2D matrix (sorted row-wise and column-wise)
bool search2D(int matrix[][4], int n, int m, int key);

// 5. Find minimum in rotated sorted array
int findMin(int arr[], int n);

// 1. Merge Sort (Divide and Conquer)
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

// 2. Quick Sort with different pivot strategies
void quickSort(int arr[], int low, int high);
int partitionLomuto(int arr[], int low, int high);
int partitionHoare(int arr[], int low, int high);

// 3. Heap Sort (implement heap operations)
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);

// 4. Counting Sort (for limited range)
void countingSort(int arr[], int n);

// 1. Radix Sort
void radixSort(int arr[], int n);
void countingSortForRadix(int arr[], int n, int exp);

// 2. Bucket Sort
void bucketSort(float arr[], int n);

// 3. Sort array of 0s, 1s, and 2s (Dutch Flag Problem)
void sort012(int arr[], int n);

// 4. Sort by frequency
void sortByFrequency(int arr[], int n);

// 5. External Merge Sort simulation (for large files)
void externalMergeSort(string filename, int memorySize);

// 1. Merge two sorted arrays without extra space
void mergeTwoSorted(int arr1[], int n, int arr2[], int m);

// 2. Find kth smallest element using QuickSelect
int quickSelect(int arr[], int n, int k);

// 3. Sort array according to another array
void sortAccordingToOther(int arr1[], int arr2[], int n);

// 4. Minimum number of swaps to sort array
int minSwapsToSort(int arr[], int n);

// 1. Two sum in sorted array
pair<int,int> twoSum(int arr[], int n, int target);

// 2. Three sum equal to zero
vector<vector<int>> threeSum(int arr[], int n);

// 3. Container with most water
int maxWater(int height[], int n);

// 4. Remove element in-place
int removeElement(int arr[], int n, int val);

// 5. Valid palindrome check
bool isPalindrome(string s);

// 1. Maximum sum subarray of size k
int maxSumSubarray(int arr[], int n, int k);

// 2. First negative number in every window of size k
void firstNegative(int arr[], int n, int k);

// 3. Longest subarray with sum k
int longestSubarraySum(int arr[], int n, int k);

// 4. Minimum window substring
string minWindow(string s, string t);

// 1. Range sum queries
class PrefixSum {
private:
    vector<int> prefix;
public:
    PrefixSum(int arr[], int n);
    int rangeSum(int i, int j);
};

// 2. Subarray with given sum
bool subarraySum(int arr[], int n, int sum);

// 3. Maximum subarray sum (Kadane's algorithm)
int maxSubarraySum(int arr[], int n);

// 4. Equilibrium point in array
int equilibrium(int arr[], int n);



