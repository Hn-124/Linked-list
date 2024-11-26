#include <iostream>
using namespace std;
struct note {
	int data;
	note* next;
	note(int val) : data(val), next(nullptr) {}
};
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
void bubblesort(note*& head) {
	if (head == nullptr) return;
	bool hoandoi;
	note* ptr1;
	note* ptr2 = nullptr;
	do {
		hoandoi = false;
		ptr1 = head;
		while (ptr1->next != ptr2) {
			if (ptr1->data > ptr1->next->data) {
				int temp = ptr1->data;
				ptr1->data = ptr1->next->data;
				ptr1->next->data = temp;
				hoandoi = true;
			}
			ptr1 = ptr1->next;
		}
		ptr2 = ptr1;
	} while (hoandoi);

}
void indanhsach(note* head) {
	note* temp = head;
	while (temp != nullptr) {
		cout << temp->data<<" ";
		temp = temp->next;
	}cout << endl;
}
int main() {
	note* head = nullptr;
	int n;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int value;
		cout << "so phan tu thu " << i + 1 << ":";
		cin >> value;
		themphantu(head, value);
	}
	cout << "danh sach chua sap xep la: ";
	indanhsach(head);
	cout << "danh sach sau khi sap xep la: ";
	bubblesort(head);
	indanhsach(head);
	return 0;
}