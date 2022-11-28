#include <iostream>
#include<locale>

using namespace std;

class Arr {
private:
	int size;
	int* mas;

public:
	//=======================================================================================================
	Arr(int i) {
		this->size = i;
		this->mas = new int[size];
	};
	//=======================================================================================================
	~Arr() {
		delete[] mas;
	};
	//=======================================================================================================
	Arr(const Arr& other) {
		this->size = other.size;
		this->mas = new int[other.size];
		for (int i = 0; i < other.size; i++) {
			this->mas[i] = other.mas[i];//memcopy
		};
	};
	//=======================================================================================================
	Arr operator -(const Arr& other) {
		int a, b;
		a = this->size;
		b = other.size;
		Arr temp(a > b ? a : b);
		if (this->size > other.size) {
			temp.SetNewSize(this->size);
			for (int i = 0; i < other.size; i++) {
				temp.mas[i] = this->mas[i] - other.mas[i];
			};
			while (b != a) {
				temp.mas[b] = this->mas[b];
				b++;
			};
		}
		else if (this->size < other.size) {
			temp.SetNewSize(other.size);
			for (int i = 0; i < this->size; i++) {
				temp.mas[i] = this->mas[i] - other.mas[i];
			};
			while (a != b) {
				temp.mas[a] = 0 - other.mas[a];
				a++;
			};
		}
		else {
			temp.SetNewSize(this->size);
			for (int i = 0; i < size; i++) {
				temp.mas[i] = this->mas[i] - other.mas[i];
			};
		};
		return temp;
	};
	//=======================================================================================================
	Arr operator +(const Arr& other) {
		int a, b;
		a = this->size;
		b = other.size;
		Arr temp(a > b ? a : b);
		if (this->size > other.size) {
			//temp.SetNewSize(this->size);
			for (int i = 0; i < other.size; i++) {
				temp.mas[i] = this->mas[i] + other.mas[i];
			};
			while (b != a) {
				temp.mas[b] = this->mas[b];
				b++;
			}
		}
		else {//if (this->size < other.size) {
			//temp.SetNewSize(other.size);
			for (int i = 0; i < this->size; i++) {
				temp.mas[i] = this->mas[i] + other.mas[i];
			}
			while (a != b) {
				temp.mas[a] = other.mas[a];
				a++;
			}
		}
		/*
		else {
			//temp.SetNewSize(this->size);
			for (int i = 0; i < size; i++) {
				temp.mas[i] = this->mas[i] + other.mas[i];
			};
		};
		*/
		return temp;
	};
	//=======================================================================================================
	void SetNewSize(const int i) {
		int* newMas = new int[i];
		delete mas;
		mas = newMas;
		size = i;
	};
	//=======================================================================================================
	void SetArr(const int i, const int value) {
		if ((i < 0) or (i > size - 1)) {
			cout << "Ошибка. Выход за границы массива\n";
			return;
		}
		if ((value < -100) or (value > 100)) {
			cout << "Ошибка. Значение должно принадлежать промежутку [-100;100]\n";
			return;
		}

		mas[i] = value;

	};
	//=======================================================================================================
	int GetArr(const int i) {
		if ((i < 0) or (i > size - 1)) {
			cout << "Ошибка. Выход за границы массива\n";
			return;
		}

		cout << i << " элемент массива = " << mas[i] << "\n";

	};
	//=======================================================================================================
	void printArr() {
		for (int i = 0; i != size; i++) {
			cout << mas[i] << " ";
		};
		cout << "\n";
	};
	//=======================================================================================================
	void Push_Back(int value) {
		if ((value < -100) or (value > 100)) {
			cout << "Ошибка. Значение должно принадлежать промежутку [-100;100]\n";
			return;
		}

		int* newMas = new int[size + 1];
		for (int i = 0; i < size; i++) {
			newMas[i] = mas[i];//memcopy
		};
		newMas[size] = value;
		delete[] mas;
		mas = newMas;
		size = size + 1;

		//=======================================================================================================
	};
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Arr a(5);
	a.SetArr(0, 5);
	a.SetArr(1, 3);
	a.SetArr(2, 2);
	a.SetArr(3, 1);
	a.SetArr(4, 99);
	a.printArr();

	Arr b(a);
	b.Push_Back(7);
	b.printArr();

	Arr c = a + b;
	c.printArr();

	Arr d = a - b;
	d.printArr();

	return 0;
}