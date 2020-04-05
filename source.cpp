#include <iostream>
using namespace std;

struct List {
	int data;
	List* next;
};

void add(List*& head, List*& tail, int what) {
	List* new_one = new List;
	new_one->data = what;
	if (!head && !tail) {
		head = new_one;
		tail = new_one;
		new_one->next = new_one;
	}
	else {
		tail->next = new_one;
		tail = new_one;
		new_one->next = head;
	}
}

void del(List*& head, List*& tail, List*& what) {
	if (head == tail) {
		free(what);
	}
	else if (head == what) {
		List* tmp = head;
		List* tmp_2 = head;
		head = head->next;
		while (tmp_2->next != tail) {
			tmp_2 = tmp_2->next;
		}
		tmp_2 = tmp_2->next;
		tmp_2->next = head;
		free(tmp);
	}
	else if (tail == what) {
		List* tmp_2 = head;
		while (tmp_2->next != tail)
			tmp_2 = tmp_2->next;
		List* tmp = tail;
		tmp_2->next = head;
		tail = tmp_2;
		free(tmp);
	}
	else {
		List* before = head;
		while (before->next != what)
			before = before->next;
		before->next = what->next;
		free(what);
	}
}

void ListPrint(List*& head, List*& tail, int size) {
	List* tempHead = head;
	while (size != 0) {
		cout << tempHead->data << " ";
		tempHead = tempHead->next;
		size--;
	}
}

int main() {
	setlocale(0, "");
	List* head = nullptr;
	List* tail = nullptr;
	int n, m, count = 1;
	cout << "Введите количество людей и слов в считалочке: " << endl;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		add(head, tail, i);
	}
	ListPrint(head, tail, n);
	cout << endl;
	List* tmp = head;
	List* tmp2;
	while (head != tail) {
		for (int i = 1; i < m; i++) {
			tmp = tmp->next;
		}
		cout << "Выбывает игрок под номером " << tmp->data << endl;
		tmp2 = tmp->next;
		del(head, tail, tmp);
		tmp = tmp2;
		n--;
		ListPrint(head, tail, n);
		cout << endl;
		count++;
	}
	cout << "Победил игрок под номером " << tmp->data;
}
