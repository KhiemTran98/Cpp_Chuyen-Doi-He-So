#include <iostream>
#include <conio.h>
using namespace std;

struct node
{
	int info;
	node *next;
};

struct stack
{
	node *top;
};

void init(stack &s)
{
	s.top = NULL;
}

int isempty(stack s)
{
	return (s.top == NULL);
}

node *GetNode(int x)
{
	node *p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void push(stack &s, int x)
{
	node *p = GetNode(x);
	p->next = s.top;
	s.top = p;
}

int pop(stack &s)
{
	if (isempty(s) == 0)
	{
		int x = s.top->info;
		s.top = s.top->next;
		return x;
	}
}

void hexpop(stack &s)
{
	if (isempty(s) == 0)
	{
		int x = s.top->info;
		switch (x)
		{
		case 10:
			cout << "A";
			break;
		case 11:
			cout << "B";
			break;
		case 12:
			cout << "C";
			break;
		case 13:
			cout << "D";
			break;
		case 14:
			cout << "E";
			break;
		case 15:
			cout << "F";
			break;
		default:
			cout << x;
			break;
		}
	s.top = s.top->next;
	return;
	}
}

void menu()
{
	cout << "===================== MENU =====================";
	cout << "\n1. Chuyen tu he thap phan sang he nhi phan";
	cout << "\n2. Chuyen tu he thap phan sang he bat phan";
	cout << "\n3. Chuyen tu he thap phan sang he thap luc phan\n\n";
}

void process(stack &s)
{
	int m, k, select;
	do {
		cout << "Chon cong viec (1-3): ";
		cin >> select;
	} while (select < 1 || select > 3);
	switch (select)
	{
	case 1:
		do {
			cout << "\nNhap so thap phan (n*): ";
			cin >> m;
		} while (m <= 0);
		while (m != 0)
		{
			k = m % 2;
			push(s, k);
			m = m / 2;
		}
		cout << "He nhi phan: ";
		while (isempty(s) == 0)
			cout << pop(s);
		break;
	case 2:
		do {
			cout << "\nNhap so thap phan (n*): ";
			cin >> m;
		} while (m <= 0);
		while (m != 0)
		{
			k = m % 8;
			push(s, k);
			m = m / 8;
		}
		cout << "He bat phan: ";
		while (isempty(s) == 0)
			cout << pop(s);
		break;
	case 3:
		do {
			cout << "\nNhap so thap phan (n*): ";
			cin >> m;
		} while (m <= 0);
		while (m != 0)
		{
			k = m % 16;
			push(s, k);
			m = m / 16;
		}
		cout << "He thap luc phan: ";
		while (isempty(s) == 0)
			hexpop(s);
		break;
	}
}

void main()
{
	stack s;
	init(s);
	do {
		system("cls");
		menu();
		process(s);
		cout << "\n\nNhan phim bat ky de tiep tuc hoac ESC de thoat";
	} while (_getch() != 27);
}