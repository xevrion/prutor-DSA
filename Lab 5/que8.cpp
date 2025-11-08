#include <iostream>
#include <vector>

class SortManager
{
private:
    std::vector<int> arr;
    int bth; // Bubble Sort threshold
    int ith; // Insertion Sort threshold

    // Function to perform Bubble Sort
    void bubbleSort()
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Function to perform Insertion Sort
    void insertionSort()
    {
        int n = arr.size();
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

    void merge(int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        std::vector<int> left(n1);
        std::vector<int> right(n2);

        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++)
        {
            right[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k++] = left[i++];
            }
            else
            {
                arr[k++] = right[j++];
            }
        }

        while (i < n1)
        {
            arr[k++] = left[i++];
        }
        while (j < n2)
        {
            arr[k++] = right[j++];
        }
    }

    // Function to perform Merge Sort
    void mergeSort(int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            merge(l, m, r);
        }
    }

public:
    SortManager(int bubbleThreshold, int insertionThreshold)
        : bth(bubbleThreshold), ith(insertionThreshold) {}

    void getUserInput()
    {
        int size;
        // std::cout << "Enter the size of the array: ";
        std::cin >> size;
        arr.resize(size);

        // std::cout << "Enter the elements of the array:\n";
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }

    void printArray() const
    {
        for (int num : arr)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void smartSort()
    {
        int size = arr.size();
        if (size == 0)
        {
            // std::cout << "Empty array. Nothing to sort." << std::endl;
            return;
        }

        if (size < bth)
        {
            std::cout << "1" << std::endl;
            bubbleSort();
        }
        else if (size < ith)
        {
            std::cout << "2" << std::endl;
            insertionSort();
        }
        else
        {
            std::cout << "3" << std::endl;
            mergeSort(0, size - 1);
        }
    }
};

int main()
{
    int bubbleThreshold = 10;
    int insertionThreshold = 15;

    SortManager sorter(bubbleThreshold, insertionThreshold);

    sorter.getUserInput();
    sorter.smartSort();
    sorter.printArray();

    return 0;
}