#include <iostream>
#include <Windows.h>
#include <math.h>
void error_estimate_mean_value() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Выполнение функции подсчёте среднего и его ошибки..." << std::endl << std::endl;
	int n = 0;
	std::cout << "Введите количество значений измерянной величины : ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cin >> n;
	SetConsoleTextAttribute(hConsole, 3);
	double value[100];
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " значение измерянной величины : ";
		SetConsoleTextAttribute(hConsole, 14);
		std::cin >> value[i];
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << std::endl;

	}
	double average_value = 0;
	for (int i = 0; i < n; i++) {
		average_value += value[i];
	}
	average_value = average_value / n;

	double sigma_value = 0;
	double sum_of_squared_difference = 0;
	for (int i = 0; i < n; i++) {
		sum_of_squared_difference += (value[i] - average_value) * (value[i] - average_value);
	}
	sigma_value = sqrt(sum_of_squared_difference / (n * (n - 1)));
	SetConsoleTextAttribute(hConsole, 2);
	std::cout << "Среднее значение величины : " << average_value << std::endl;
	std::cout << "Оценка погрешности среднего значения измеряемой величины : " << sigma_value << std::endl;
	SetConsoleTextAttribute(hConsole, 3);
}
void least_square_method() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "Выполнение функции нахождения наилучшей прямой методом наименьших квадратов..." << std::endl << std::endl;
	double k = 0;
	double b = 0;
	double sigma_k = 0;
	double sigma_b = 0;
	double function_arguments[100];
	double function_values[100];
	int n = 0;
	std::cout << "Введите количество точек : ";
	SetConsoleTextAttribute(hConsole, 14);
	std::cin >> n;
	SetConsoleTextAttribute(hConsole, 3);
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " аргумент(x) : ";
		SetConsoleTextAttribute(hConsole, 14);
		std::cin >> function_arguments[i];
		SetConsoleTextAttribute(hConsole, 3);
	}
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i + 1 << " значение функции(y) : ";
		SetConsoleTextAttribute(hConsole, 14);
		std::cin >> function_values[i];
		SetConsoleTextAttribute(hConsole, 3);
	}
	std::cout << "Функция проходит через начало координат? Если да, то введите 1, иначе 0 : ";
	int origin = 0;
	SetConsoleTextAttribute(hConsole, 14);
	std::cin >> origin;
	SetConsoleTextAttribute(hConsole, 3);

	double average_x_by_y = 0;
	double average_x = 0;
	double average_y = 0;
	double average_square_x = 0;
	double average_square_y = 0;


	for (int i = 0; i < n; i++) {
		average_x_by_y += function_arguments[i] * function_values[i];
	}
	average_x_by_y = average_x_by_y / n;

	for (int i = 0; i < n; i++) {
		average_x += function_arguments[i];
	}
	average_x = average_x / n;

	for (int i = 0; i < n; i++) {
		average_y += function_values[i];
	}
	average_y = average_y / n;

	for (int i = 0; i < n; i++) {
		average_square_x += function_arguments[i] * function_arguments[i];
	}
	average_square_x = average_square_x / n;

	for (int i = 0; i < n; i++) {
		average_square_y += function_values[i] * function_values[i];
	}
	average_square_y = average_square_y / n;
	SetConsoleTextAttribute(hConsole, 2);
	if (origin == 1) {
		k = average_x_by_y / average_square_x;
		sigma_k = 1 / sqrt(n) * sqrt((average_square_y / average_square_x - k * k));
		std::cout << std::endl;
		std::cout << "Угловой коэффициент : " << k << std::endl << "Погрешность : " << sigma_k;
		std::cout << std::endl;
	}
	else {
		k = (average_x_by_y - average_x * average_y) / (average_square_x - average_x * average_x);
		b = average_y - k * average_x;
		sigma_k = 1 / sqrt(n) * sqrt((average_square_y - average_y * average_y) / (average_square_x -
			average_x * average_x) - k * k);
		sigma_b = sigma_k * sqrt(average_square_x - average_x * average_x);
		std::cout << std::endl;
		std::cout << "Угловой коэффициент : " << k << std::endl << "Погрешность : " << sigma_k;
		std::cout << std::endl << "Коэффициент b : " << b << std::endl << "Погрешность : " << sigma_b;
		std::cout << std::endl;

	}
	SetConsoleTextAttribute(hConsole, 3);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "Это программа предназначена для расчёта данных в лабораторных работах по физике." << std::endl;
		std::cout << " Существуют следующие функции :" << std::endl;
		std::cout << "1. Расчёт среднего и погрешности среднего" << std::endl;
		std::cout << "2. Поиск наилучшей прямой методом наименьних квадратов" << std::endl;
		std::cout << "Введите номер нужной функции, для выхода из программы введите любой символ : " << std::endl;
		char function_number;
		SetConsoleTextAttribute(hConsole, 14);
		std::cin >> function_number;
		SetConsoleTextAttribute(hConsole, 3);
		if (function_number == 49) {
			error_estimate_mean_value();
			Sleep(2000);
			std::cout << std::endl << "Продолжить выполнение программы или выйти?" << std::endl;
			std::cout << "Введите 1 для продолжения, любой другой символ для выхода: " << std::endl;
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> function_number;
			SetConsoleTextAttribute(hConsole, 3);
			if (function_number != 49) {
				std::cout << "Выход из программы..." << std::endl;
				break;
			}
			Sleep(2000);
			system("cls");
		}
		else if (function_number == 50) {
			least_square_method();
			Sleep(2000);
			std::cout << std::endl << "Продолжить выполнение программы или выйти?" << std::endl;
			std::cout << "Введите 1 для продолжения, любой другой символ для выхода: " << std::endl;
			SetConsoleTextAttribute(hConsole, 14);
			std::cin >> function_number;
			SetConsoleTextAttribute(hConsole, 3);
			if (function_number != 49) {
				std::cout << "Выход из программы..." << std::endl;
				break;
			}
			system("cls");
			Sleep(2000);
		}
		else {
			std::cout << "Выход из программы..." << std::endl;
			break;
		}
	}
	return 0;
}