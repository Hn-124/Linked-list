#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Thêm phần tử vào cuối danh sách liên kết
void themPhanTu(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Chuyển Linked List thành mảng
vector<int> linkedListToArray(Node* head) {
    vector<int> arr;
    while (head != nullptr) {
        arr.push_back(head->data);
        head = head->next;
    }
    return arr;
}

// Chuyển mảng thành Linked List
Node* arrayToLinkedList(const vector<int>& arr) {
    Node* head = nullptr;
    for (int val : arr) {
        themPhanTu(head, val);
    }
    return head;
}
// Hàm Heapify để duy trì tính chất Max Heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // Node cha
    int left = 2 * i + 1;  // Con trái
    int right = 2 * i + 2; // Con phải

    // Nếu con trái lớn hơn cha
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Nếu con phải lớn hơn cha
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Nếu node cha không phải lớn nhất
    if (largest != i) {
        swap(arr[i], arr[largest]); // Đổi chỗ
        heapify(arr, n, largest);  // Đệ quy Heapify cho nhánh bị ảnh hưởng
    }
}

// Hàm Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Xây dựng Max Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Trích xuất phần tử lớn nhất và sắp xếp
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]); // Đưa phần tử lớn nhất về cuối
        heapify(arr, i, 0);   // Heapify phần còn lại
    }
}
// In danh sách liên kết
void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> value;
        themPhanTu(head, value);
    }

    cout << "Danh sach truoc khi sap xep: ";
    inDanhSach(head);

    heapSort(arr);

    cout << "Danh sach sau khi sap xep: ";
    inDanhSach(head);

    return 0;
}
