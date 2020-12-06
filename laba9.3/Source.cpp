#include<iostream>
#include <iomanip>
#include<fstream>
#include<string>
#include<Windows.h>


using namespace std;

struct Bill
{
	string RP;
	string RO;
	int suma;
};

void creat(Bill* s, const int n)
{
	//cout << "=======================================" << endl;
	//cout<<"| Рах. плат. | Рах.одер. |"

	for (int i = 0; i < n; i++)
	{
		cout << "Рахунок платника: "; cin>>s[i].RP;
		cout << "Рахунок одержувача: "; cin >> s[i].RO;
		cout << "Перерахова сума у гривнях: "; cin >> s[i].suma;
		cout << endl;
	}
	cout << endl << endl;
}
void sort(Bill *s, const int n)
{
	Bill tmp;
	for (int i =0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if (s[j].RP > s[j + 1].RP)
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
		    }

}
void print(Bill* s, const int n)
{
	cout << "===================================" << endl;
	cout << "| Рах. плат. | Рах.одер. |  Сума  | " << endl;
	for (int i = 0; i < n; i++) {
		cout << "|" << setw(12) << s[i].RP << "|" << setw(11)
			<< s[i].RO << "|" << setw(8) << s[i].suma << "|" << endl;
		
	}
	cout << "===================================" << endl;
}
Bill sum(Bill* s, const int n)
{
	Bill i;
	string t;
	cout << "Введіть номер платника по якому" << endl;
	cout << "потрібно перевірити суму переказу :"; cin >> t;
	cout << endl;
	for (int i = 0; i < n; i++)
		if (t == s[i].RP)
		{
			cout << "Сума переказу: " << s[i].suma << endl<<endl;
			break;
			
		}
		else
		{
			cout << "Не знайдено" << endl << endl;
			break;
		}
	return i;
}
int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	int n;
	cout << "Кількість транзакцій: "; cin >> n;
	cout << endl;

	Bill* s = new Bill[n];
	/*creat(s, n);
	print(s, n);
	sort(s, n);
	print(s, n);
	suma(s, n);*/

	int menu;

	do
	{

		cout << "   Виберіть значення" << endl;
		cout << "[1] - Ввести дані." << endl;
		cout << "[2] - Вивіід даних на екран." << endl;
		cout << "[3] - Сортування даних за алфавітом."<<endl;
		cout << "[4] - Вивід суми транкзакції" << endl << endl;

		cout << "[0] - Вихід" << endl<<endl;

		cout << "Введіть значення: "; cin >> menu; cout << endl;

		switch (menu)
		{
		case 1:
			creat(s, n);
			break;
		case 2:
			print(s, n);
			break;
		case 3:
			sort(s, n);
			break;
		case 4:
			 sum(s, n);
			break;

		case 0:
			return 0;
		default:
			cout << "Ви ввели не правильне значення!" << endl;
			break;
		}


	} while (menu != 0);

	return 0;
}