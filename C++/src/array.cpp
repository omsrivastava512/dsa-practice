#include <iostream>
#include <climits>

using namespace std;

// Implement a class for dynamic array operations
class ArrayOperations
{
private:
    int *arr;
    int size;
    int capacity;
    void resize(int newCapacity)
    {
        int *newArr = (int *)realloc(arr, newCapacity);
        if (!newArr)
            return;
        capacity = newCapacity;
        arr = newArr;
    }

public:
    // Constructor
    ArrayOperations(int initialCapacity)
    {
        size = 0;
        capacity = initialCapacity;
        arr = (int *)calloc(capacity, sizeof(int));
    }
    ~ArrayOperations()
    {
        free(arr);
    }

    void insertAt(int index, int value)
    {
        /**
         *  index can not be greater than the size to ensure
         *  that you don't leave space behind on insertion
         **/
        if (index < 0 || index > size)
        {
            cout << "Invalid index for insertion" << endl;
            return;
        }
        while (size == capacity)
        {
            resize(capacity + 5);
        }

        /**
         * Shifting elements to make space
         * -> If size>index space is filled.
         * -> If size == index, space is vacant
         */
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        // Inserting element
        arr[index] = value;
        size++;
    }

    void deleteAt(int index)
    {
        /**
         * Check for invalid indices
         * Check if the index is not blank
         */
        if (index < 0 || index >= size)
        {
            cout << "Invalid index for deletion.";
            return;
        }
        for (int i = index; i < size; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    int search(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
                return i;
        }
        return -1;
    }

    void display()
    {
        cout << "Array[" << size << "]: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bound";
            return -1;
        }
        return arr[index];
    }
    void set(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bound";
            return;
        }
        arr[index] = value;
    }
    void push(int value)
    {
        insertAt(size, value);
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "Array Empty";
            return -1;
        }
        int val = arr[size - 1];
        deleteAt(size - 1);
        return val;
    }

    // 1. Reverse array in-place without extra space
    void reverseArray()
    {
        for (int i = 0; i < size / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
        display();
    }

    // 3. Find second largest element without sorting
    int secondLargest()
    {
        if (size < 2)
            return -1;
        int max = INT_MIN;
        int max_2 = max;
        /**
         * If we encounter an element greater than the max we update both max and max_2.
         * However we can also encounter cases where the current element is
         * only greater than the max_2. In such cases we only update max_2.
         */
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max_2 = max;
                max = arr[i];
            }
            else if (arr[i] > max_2 && arr[i] != max)
            {
                // Ensuring that the largest number is not duplicated
                max_2 = arr[i];
            }
        }
        return max_2;
    }

    // 4. Move all zeros to end maintaining order of non-zeros
    void moveZerosToEnd()
    {
        int current = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
            {   // current index wait for the next non-zero integer
                // and fills the 0 element with it
                arr[current++] = arr[i];
            }
        }
        for (int i = current; i < size; i++)
        {
            arr[i] = 0;
        }
        
    }
    // 5. Remove duplicates from sorted array in-place
    int removeDuplicates(){

    }
};

int main()
{
    ArrayOperations arr(3);
    arr.insertAt(0, 4);
    arr.insertAt(0, 0);
    arr.insertAt(0, 4);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);
    arr.insertAt(0, 0);

    arr.display();
    arr.moveZerosToEnd();
    arr.display();
    arr.reverseArray();
    return 0;
}


