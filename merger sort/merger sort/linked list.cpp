#include <iostream>
using namespace std;

struct note {
    int data;
    note* next;
    note(int val) : data(val), next(nullptr) {}
};

// Hàm thêm phần tử vào cuối danh sách liên kết
void themphantu(note*& head, int val) {
    note* phantumoi = new note(val);
    if (head == nullptr) {
        head = phantumoi;
    }
    else {
        note* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = phantumoi;
    }
}

// Hàm tách danh sách liên kết thành hai nửa
note* split(note* head) {
    if (!head || !head->next) return nullptr;
    note* slow = head;
    note* fast = head;
    note* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr; // Tách danh sách thành hai nửa
    return slow;
}

// Hàm hợp nhất hai danh sách đã sắp xếp
note* merge(note* left, note* right) {
    if (!left) return right;
    if (!right) return left;

    note* result = nullptr;
    if (left->data < right->data) {
        result = left;
        result->next = merge(left->next, right);
    }
    else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Hàm Merge Sort sắp xếp danh sách liên kết
void mergeSort(note*& head) {
    if (!head || !head->next) return; // Nếu danh sách chỉ có 0 hoặc 1 phần tử thì không cần sắp xếp

    // Tách danh sách thành hai nửa
    note* second = split(head);

    // Sắp xếp đệ quy từng nửa
    mergeSort(head);
    mergeSort(second);

    // Hợp nhất hai nửa đã sắp xếp lại với nhau
    head = merge(head, second);
}

// Hàm in danh sách liên kết
void indanhsach(note* head) {
    note* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    note* head = nullptr;
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        cout << "So phan tu thu " << i + 1 << ": ";
        cin >> value;
        themphantu(head, value);
    }

    cout << "Danh sach chua sap xep la: ";
    indanhsach(head);

    mergeSort(head);

    cout << "Danh sach sau khi sap xep la: ";
    indanhsach(head);

    return 0;
}
