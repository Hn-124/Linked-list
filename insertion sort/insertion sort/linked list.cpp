#include <iostream>
using namespace std;
struct note {
	int data;
	note* next;
	note(int val) : data(val), next(nullptr){}
};
void themphantu(note*& head, int val) {
	note* phantumoi = new note(val);
	if (head == nullptr) {
		head = phantumoi ;
	}
	else {
		note* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = phantumoi;
	}
}
void insertionsort(note*& head) {
	if (head == nullptr || head->next == nullptr) return;
	note* sapxep=nullptr;
	note* danhsach=head;
	while (danhsach != nullptr) {
		note* next = danhsach->next;
		if (sapxep == nullptr || sapxep->data >= danhsach->data) {
			danhsach->next = sapxep;
			sapxep = danhsach;
		}
		else {
			note* temp = sapxep;
			while (temp->next != nullptr && temp->next->data < danhsach->data) {
				temp = temp->next;
			}
			danhsach -> next = temp->next;
			temp->next = danhsach;
		}
		danhsach = next;
	}
	head = sapxep;
}
void indanhsach(note* head) {
	note* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}cout << endl;
}
int main() {
	note* head = nullptr;
	int n;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0 ; i < n; ++i) {
		int value;
		cout << "so phan tu thu " << i + 1 << ":";
		cin >> value;
		themphantu(head, value);
	}
	cout << "danh sach chua sap xep la: ";
	indanhsach(head);
	cout << "danh sach sau khi sap xep la: ";
	insertionsort(head);
	indanhsach(head);
	return 0;
}