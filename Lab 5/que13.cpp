#include <iostream>
using namespace std;

// ================== MaxHeap ==================
class MaxHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MaxHeap(int cap)
    {
        this->size = 0;
        this->capacity = cap;
        arr = new int[cap];
    };
    int getSize()
    {
        return size;
    };
    int getTop()
    {
        return size > 0 ? arr[0] : 0;
    };
    void insert(int val)
    {
        if (size == capacity)
            return;
        arr[size] = val;
        int i = size;
        size++;

        while (i > 0 && arr[(i - 1) / 2] < arr[i])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    };
    int extractTop()
    {
        if (size <= 0)
            return 0;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    };
    void heapify(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    };
};

// ================== MinHeap ==================
class MinHeap
{
    int *arr;
    int capacity;
    int size;

public:
    MinHeap(int cap)
    {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    int getSize() { return size; }
    int getTop() { return size > 0 ? arr[0] : 0; }

    void insert(int val)
    {
        if (size == capacity)
            return;
        arr[size] = val;
        int i = size;
        size++;

        while (i > 0 && arr[(i - 1) / 2] > arr[i])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractTop()
    {
        if (size <= 0)
            return 0;
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void heapify(int i)
    {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
};

// ================== MedianFinder ==================
class MedianFinder
{
    MaxHeap left;  // max-heap for smaller half
    MinHeap right; // min-heap for larger half

public:
    MedianFinder(int cap) : left(cap), right(cap) {}

    void addNum(int num)
    {
        if (left.getSize() == 0 || num <= left.getTop())
        {
            left.insert(num);
        }
        else
        {
            right.insert(num);
        }

        // balance heaps
        if (left.getSize() > right.getSize() + 1)
        {
            right.insert(left.extractTop());
        }
        else if (right.getSize() > left.getSize())
        {
            left.insert(right.extractTop());
        }
    }

    double findMedian()
    {
        if (left.getSize() == right.getSize())
        {
            return (left.getTop() + right.getTop()) / 2.0;
        }
        else
        {
            return left.getTop();
        }
    }
};

// ================== main() ==================
int main()
{
    int n;
    cin >> n;              // number of operations
    MedianFinder mf(1000); // capacity large enough for input size

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "addNum")
        {
            int x;
            cin >> x;
            mf.addNum(x);
        }
        else if (cmd == "findMedian")
        {
            cout << mf.findMedian() << endl;
        }
    }
    return 0;
}