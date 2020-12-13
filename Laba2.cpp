#include <string>
#include <iostream>

using namespace std;


class House {
	char adr[30];
	int level, numRoom, square;

public:
	House() {
		cout << "Введите адрес: "; cin >> adr;
		cout << "Введите этаж: "; cin >> level;
		cout << "Введите количество комнат: "; cin >> numRoom;
		cout << "Введите площадь: "; cin >> square;
	}
	void show() {
		cout << "Адрес: " <<  adr;
		cout << "\nЭтаж: " << level;
		cout << "\nКоличество комнат: " << numRoom;
		cout << "\nПлощадь: " << square;
	}

	char* getAddres() { return adr; }
	int getLevel() { return level; };
	int getNumRoom() { return numRoom; };
	int getSquare() { return square; };
};

void filter_1(House arr[], int n) {
	cout << endl;
	int num;
	cout << "Введите количество комнат для выборки: "; cin >> num;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (num == arr[i].getNumRoom()) {
			cout << "==============================" << endl;
			arr->show();
		}
	}
}


void filter_2(House arr[], int n) {
	cout << endl;
	int num, level;
	cout << "Введите количество комнат для выборки: "; cin >> num;
	cout << "Введите этаж для выборки: "; cin >> level;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if ((num == arr[i].getNumRoom()) && (level == arr[i].getLevel())) {
			arr->show();
			cout << "==============================" << endl;
		}
	}
}

void filter_3(House arr[], int n) {
	cout << endl;
	int square;
	cout << "Введите площадь для выборки: "; cin >> square;
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (square <= arr[i].getSquare()) {
			arr->show();
			cout << "\n==============================" << endl;
		}
	}
}


void main()
{
	setlocale(LC_ALL, "Russian");

	House* arr;
	int n;
	cout << "Введите количество квартир: "; cin >> n;

	arr = new House[n];

	for (int i = 0; i < n; i++) {
		cout << "\n==============================\n";
		arr[i].show();
		cout << "\n" << endl;
	}

	filter_1(arr, n);
	
	filter_2(arr, n);

	filter_3(arr, n);

	delete[] arr;

	system("pause");
}