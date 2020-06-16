// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Element
{
	int number;
	int value;
};


void Show_Array(Element* pAr, int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << pAr[i].value << "    " << pAr[i].number << endl;
}

void quickSort(Element* numbers, int left, int right)
{
	register int l_hold, r_hold;
	int pivot; // ����������� �������
	struct Element temp;

	l_hold = left; //����� �������
	r_hold = right; // ������ �������
	pivot = numbers[(left + right) / 2].value;

	do
	{
		while ((numbers[l_hold].value < pivot) && (l_hold < right))
			l_hold++;
		while ((numbers[r_hold].value > pivot) && (r_hold > left))
			r_hold--;
		if (l_hold <= r_hold)
		{
			temp = numbers[l_hold];
			numbers[l_hold] = numbers[r_hold];
			numbers[r_hold] = temp;
			l_hold++;
			r_hold--;
		}
	} while (l_hold <= r_hold);
	if (left < r_hold)
	{
		quickSort(numbers, left, r_hold);
	}
	if (l_hold < right)
	{
		quickSort(numbers, l_hold, right);
	}
}

// ������� "�����������" ����� ���� - ������������ ����
void siftDown(Element* numbers, int root, int bottom)
{
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)    // ���� �� � ��������� ����,
			maxChild = root * 2;    // ���������� ����� �������
		  // ����� ���������� ������� ������� �� ����
		else if (numbers[root * 2].value > numbers[root * 2 + 1].value)
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// ���� ������� ������� ������ ������������� �������
		if (numbers[root].value < numbers[maxChild].value)
		{
			Element temp = numbers[root]; // ������ �� �������
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else // �����
			done = 1; // �������� ������������
	}
}
// ������� ���������� �� ����
void heapSort(Element* numbers, int array_size)
{
	// ��������� ������ ��� ��������
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size - 1);
	// ���������� ����� �������� ��������� ��������
	for (int i = array_size - 1; i >= 1; i--)
	{
		Element temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}

void generator(int Size)
{
	int value;
	ofstream fout;
	fout.open("data.in.txt");
	for (int i = 0; i < Size; ++i)
	{
		value = rand() % 20;
		fout.seekp(0, ios::end);
		fout << value << endl;
	}
	fout.close();
}

void Import_data_to_array(Element* pAr, int Size)
{
	int counter = 1;
	ifstream fin;
	fin.open("data.in.txt");
	for (int i = 0; i < Size; ++i)
	{
		fin.seekg(0, ios::cur);
		fin >> pAr[i].value;
		pAr[i].number = counter;
		counter++;
	}
	fin.close();
}

void Export_data_from_array_to_file(Element* pAr, int Size)
{
	ofstream fout;
	fout.open("data.out.txt");
	for (int i = 0; i < Size; ++i)
	{
		fout.seekp(0, ios::end);
		fout << pAr[i].value << "   " << pAr[i].number << endl;
	}
	fout.close();
}

int arrayUnique(Element* ar, int size) // �������, ������������ �������� ������� � ������������ ����������
{
	for (int counter1 = 1; counter1 <= size; counter1++)
	{
		for (int counter2 = counter1 + 1; counter2 <= size; counter2++)
		{
			if (ar[counter1].value == ar[counter2].value) // ���� ������ ���������� �������
			{
				for (int counter_shift = counter2; counter_shift <= size - 1; counter_shift++)
				{
					// ��������� ����� ���� ��������� ��������� ������� �� -1, ������� �� ���������� ��������, ����� ���������� �����
					ar[counter_shift] = ar[counter_shift + 1];
				}
				size -= 1; // ��������� ������ ������� �� 1

				if (ar[counter1].value == ar[counter2].value) // ���� ��������� ������� - �����
				{
					counter2--; // ��������� ������� �� ���������� �������     
				}
			}
		}
	}
	return size;
}

int main_lab_2_7()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int Size_input = 10;
	int Size_output;
	Element iAr[Size_input];

	generator(Size_input);

	Import_data_to_array(iAr, Size_input);

	cout << "�������� ������ ������:" << endl;
	Show_Array(iAr, Size_input);

	cout << "������� ����������:" << endl;
	Size_output = arrayUnique(iAr, Size_input);
	Show_Array(iAr, Size_output);


	quickSort(iAr, 0, Size_output - 1);
	//heapSort(iAr, Size_output);
	cout << endl << "��������������� ������ ������:" << endl;
	Show_Array(iAr, Size_output);



	Export_data_from_array_to_file(iAr, Size_output);


	//vector<int>iAr(Size);
	//quickSort_2(iAr, 0, Size - 1);


	return 0;
}


