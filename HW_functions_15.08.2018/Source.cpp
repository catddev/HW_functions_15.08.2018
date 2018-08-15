//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

//1.	Написать функцию, которая принимает два параметра :
//основание степени и показатель степени,
//и вычисляет степень числа на основе полученных данных.
double power1(double x, double y) {
	int n = 1;
	while (y != 0)
	{
		n *= x;
		y--;
	}
	return n;
}

//2.	Написать функцию, которая получает в качестве параметров 2 целых числа
//и возвращает сумму чисел из диапазона между ними.
int sumRange(int x, int y) {
	if (x > y) swap(x, y);
	int sum = 0;
	for (int i = x + 1; i < y; i++)
		sum += i;
	return sum;
}

//3.	Написать функцию для округления заданного числа с заданной точностью.
int roundNum(int x, int y) { // где Y - кол-во разрядов, на сколько нужно округлить,
	// если считать разряды справа налево
	int n = y;
	while (n != 0)
	{
		if (n == 1)
		{
			if (x % 10 >= 5) x = (x / 10 + 1)*pow(10, y);
			else x = x / 10 * pow(10, y);
		}
		else x /= 10;
		n--;
	}
	return x;
}
//int roundNum(int x, int y) { // где Y - кол-во разрядов, на сколько нужно округлить,
// если считать разряды слева направо
//	int k = 0;
//	int n = x;
//	while (abs(n) > 0)
//	{
//		n /= 10;
//		k++;
//	}
//	int r = k - y;
//
//	while (r != 0)
//	{
//		if (r == 1)
//		{
//			if (x % 10 >= 5) x = (x/10 + 1)*pow(10, (k - y));
//			else x = x/10*pow(10, (k - y));
//		}
//		else x /= 10;
//		r--;
//	}
//	return x;
//}

//4.	**Напишите функцию, которая принимает массив, количество элементов,
//тип сортировки(пузырьком, выбором и т.д. - строка)
//и порядок сортировки(по убыванию, по возрастанию – логическая переменная).
//Функция сортирует массив.
//Реализовать перегрузки для целых и вещественных чисел.
void sort(int arr[], int size, char str[], bool direction) {
	int i = 0;
	if (direction)
	{
		if (str == "bubble")
		{
			for (int pass = 0; pass<size - 1; pass++)
				for (i = 0; i < size - 1; i++)
					if (arr[i] > arr[i + 1])
						swap(arr[i], arr[i + 1]);
		}
		else if (str == "selection")
		{
			double min_e;
			int k = 0;
			for (int pass = 0; pass < size - 1; pass++)
			{
				min_e = arr[size - 1];

				for (i = pass + 1; i < size; i++)
				{
					if (arr[i] <= min_e)
					{
						min_e = arr[i];
						k = i;
					}
				}
				if (min_e<arr[pass]) swap(arr[k], arr[pass]);
			}
		}
		else if (str == "insert")
		{
			for (int pass = 1; pass < size; pass++)
			{
				i = pass;
				while ((arr[i] < arr[i - 1]) && i > 0)
				{
					swap(arr[i], arr[i - 1]);
					i--;
				}
			}
		}
		else cout << "error: wrong sort type" << endl << endl;
	}
	else
	{
		if (str == "bubble")
		{
			for (int pass = 0; pass<size - 1; pass++)
				for (i = 0; i < size - 1; i++)
					if (arr[i] < arr[i + 1])
						swap(arr[i], arr[i + 1]);
		}
		else if (str == "selection")
		{
			double max_e;
			int k = 0;
			for (int pass = 0; pass < size - 1; pass++)
			{
				max_e = arr[size - 1];

				for (i = pass + 1; i < size; i++)
				{
					if (arr[i] >= max_e)
					{
						max_e = arr[i];
						k = i;
					}
				}
				if (max_e>arr[pass]) swap(arr[k], arr[pass]);
			}
		}
		else if (str == "insert")
		{
			for (int pass = 1; pass < size; pass++)
			{
				i = pass;
				while ((arr[i] > arr[i - 1]) && i > 0)
				{
					swap(arr[i], arr[i - 1]);
					i--;
				}
			}
		}
		else cout << "error: wrong sort type" << endl << endl;
	}
}
// перегрузка
void sort(double arr[], int size, char str[], bool direction) {
	int i = 0;
	if (direction)
	{
		if (str == "bubble")
		{
			for (int pass = 0; pass<size - 1; pass++)
				for (i = 0; i < size - 1; i++)
					if (arr[i] > arr[i + 1])
						swap(arr[i], arr[i + 1]);
		}

		else if (str == "selection")
		{
			double min_e;
			int k = 0;
			for (int pass = 0; pass < size - 1; pass++)
			{
				min_e = arr[size - 1];

				for (i = pass + 1; i < size; i++)
				{
					if (arr[i] <= min_e)
					{
						min_e = arr[i];
						k = i;
					}
				}
				if (min_e<arr[pass]) swap(arr[k], arr[pass]);
			}
		}

		else if (str == "insert")
		{
			for (int pass = 1; pass < size; pass++)
			{
				i = pass;
				while ((arr[i] < arr[i - 1]) && i > 0)
				{
					swap(arr[i], arr[i - 1]);
					i--;
				}
			}
		}
		else cout << "error: wrong sort type" << endl << endl;
	}
	else
	{
		if (str == "bubble")
		{
			for (int pass = 0; pass<size - 1; pass++)
				for (i = 0; i < size - 1; i++)
					if (arr[i] < arr[i + 1])
						swap(arr[i], arr[i + 1]);
		}
		else if (str == "selection")
		{
			double max_e;
			int k = 0;
			for (int pass = 0; pass < size - 1; pass++)
			{
				max_e = arr[size - 1];

				for (i = pass + 1; i < size; i++)
				{
					if (arr[i] >= max_e)
					{
						max_e = arr[i];
						k = i;
					}
				}
				if (max_e>arr[pass]) swap(arr[k], arr[pass]);
			}
		}
		else if (str == "insert")
		{
			for (int pass = 1; pass < size; pass++)
			{
				i = pass;
				while ((arr[i] > arr[i - 1]) && i > 0)
				{
					swap(arr[i], arr[i - 1]);
					i--;
				}
			}
		}
		else cout << "error: wrong sort type" << endl << endl;
	}
}

//5.	**Напишите функцию, которая принимает целое число
//и возвращает количество цифр в числе и процент четных цифр.
//Рекомендации: Воспользуйтесь передачей параметров по ссылке.
void digitPercent(int x, int &n, double &p) {
	int k=0;
	n = 0;
	while (x != 0)
	{
		if (x % 10 % 2 == 0) k++;
		x /= 10;
		n++;
	}
	p = double(k) / double(n)* 100;
}

//6.	*Напишите функцию, которая принимает массив и количество элементов
//и возвращает среднее арифметическое всех элементов массива.
//Реализуйте перегрузку для целых и вещественных чисел.
double average_arr(double arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
}
double average_arr(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return (double)sum / size;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			double a, b;
			cin >> a >> b;

			cout << power1(a, b) << endl << endl;
		}
		break;
		case 2:
		{
			int a, b;
			cin >> a >> b;

			cout << sumRange(a, b) << endl << endl;
		}
		break;
		case 3:
		{
			int a, b;
			cin >> a >> b;

			cout << roundNum(a, b) << endl << endl;
		}
		break;
		case 4:
		{
			int a[] = { 1, 6, 4, 2, 3, 5 };
			double b[] = { 1.5, 2, 3.5, 4, 5, 6 };

			char type[10];
			bool direction;
			cout << "Выберите тип сортировки: bubble, selection, insert" << endl;
			cin >> type;
			cout << "1 - по возрастанию, 0 - по убыванию" << endl;
			cin >> direction;

			sort(a, 6, type, direction);
			
			for (int i = 0; i < 6; i++)
				cout << a[i] << " ";
			cout << endl << endl;

			sort(b, 6, type, direction);
			for (int i = 0; i < 6; i++)
				cout << a[i] << " ";
			cout << endl << endl;
		}
		break;
		case 7:
		{
			
			/*char type[7];
			bool direction;
			cout << "Выберите тип сортировки: bubble, selection, insert" << endl;
			cin >> type;

			if (type == "bubble") cout << direction << endl;
			else cout << type << endl;*/
			
		}
		break;
		case 5:
		{
			int a;
			cin >> a;
			int b = 0;
			double c = 50;

			digitPercent(a, b, c);
			cout << b << endl << c << "%" << endl << endl;
		}
		break;
		case 6:
		{
			double a[7] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5 };
			int b[] = { 1, 2, 3, 4, 5, 6 };

			cout << average_arr(a, 7) << endl << endl;
			cout << average_arr(b, 6) << endl << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}