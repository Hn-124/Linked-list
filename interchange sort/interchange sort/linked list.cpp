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

// Hàm sắp xếp Interchange Sort cho danh sách liên kết
void interchangeSort(Node* head) {
    if (!head) return;

    for (Node* i = head; i->next != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data > j->data) {
                // Hoán đổi dữ liệu giữa hai Node
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
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

    interchangeSort(head);

    cout << "Danh sach sau khi sap xep: ";
    inDanhSach(head);

    return 0;
}
