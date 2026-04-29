#include <iostream>
using namespace std;

class MaxHeap {
    int *arr;
    int capacity;
    int size;

public:
    // Constructor
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Utility index functions
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    // Insert a new key
    void insert(int key) {
        if (size == capacity) {
            cout << "Heap is full\n";
            return;
        }

        size++;
        int i = size - 1;
        arr[i] = key;

        // Maintain heap property (bubble-up)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify function (used by deleteRoot & sort)
    void heapify(int i, int heapSize) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heapSize && arr[left] > arr[largest])
            largest = left;

        if (right < heapSize && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest, heapSize);
        }
    }

    // Delete root element (max)
    void deleteRoot() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return;
        }

        if (size == 1) {
            size--;
            return;
        }

        arr[0] = arr[size - 1];
        size--;
        heapify(0, size);
    }

    // Get max element
    int getMax() {
        if (size <= 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Display current heap
    void display() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Perform Heap Sort
    void heapSort() {
        int n = size;

        // Step 1: Build max heap (already built via insertions, but we ensure consistency)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i, n);

        // Step 2: Extract elements one by one
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);  // Move current root to end
            heapify(0, i);         // Restore heap property
        }

        cout << "Heap after sorting (Ascending Order): ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Driver Code
int main() {
    MaxHeap h(10);

    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(50);

    cout << "Initial Heap:\n";
    h.display();

    cout << "Max element: " << h.getMax() << endl;

    h.deleteRoot();
    cout << "After deleting root:\n";
    h.display();

    cout << "\nPerforming Heap Sort...\n";
    h.heapSort();

    return 0;
}
