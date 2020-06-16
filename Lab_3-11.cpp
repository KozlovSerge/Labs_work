/*
3-11. �������� ����������� ������ �������� ����������, ������ �������
����� ������ �������� ���������� �� ��������(�����, ������� �������)
�� ����������� ���������� ��� ����� ��������, � ����� ���������
�����������, ������� ���������� �����, ������� ��������� �����,
������� ��� �� ������ ������������ ��������(���� / �������)).
1) ���������� ������� ��������� ��������� �����, ��������� ������
�������� �� ������ �������(INSERT), ��������� �������� � ������
�������(DELETE).���������� ���� ������ ��������� � ���������.
2) ������������ ������ �� ������� ��������, � � ����� ������ ��������
� �� ������� ���������� ����� � ������� ��������.
*/
// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"


#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <string.h>

using namespace std;

struct Subject
{
	string subject_name;
	float credits;
	int semester_number;
	int classroom_hours;
	int lecture_hours;
	int MKR;
	string semester_control;
};

struct List
{
	Subject subject;
	List* next;
};

List* head = NULL;

void Input_Subject(Subject* subject)
{
	cout << "������� �������� ����������: ";
	cin.get();
	getline(cin, subject->subject_name);
	cout << "������� ���������� �������� ����������: ";
	cin >> subject->credits;
	cout << "������� ����� ��������, � ������� ����������� ����������: ";
	cin >> subject->semester_number;
	cout << "������� ���������� ���������� ����� ����������: ";
	cin >> subject->classroom_hours;
	cout << "������� ���������� ���������� ����� ����������: ";
	cin >> subject->lecture_hours;
	cout << "������� ���������� ��� ����������: ";
	cin >> subject->MKR;

	bool correct_input = false;
	int type_control;
	while (correct_input == false)
	{
		cout << "�������� ��� �������� (1-�������, 2-�����): ";
		cin >> type_control;
		if (type_control == 1)
		{
			subject->semester_control = "�������";
			correct_input = true;
		}
		else if (type_control == 2)
		{
			subject->semester_control = "�����";
			correct_input = true;
		}
		else
		{
			cout << "������ �����!" << endl;
		}

	}
}

void Input_Subject_2(Subject* subject, string subject_name, float credits, int semester_number, int classroom_hours, int lecture_hours, int MKR, int type_control)
{
	subject->subject_name = subject_name;
	subject->credits = credits;
	subject->semester_number = semester_number;
	subject->classroom_hours = classroom_hours;
	subject->lecture_hours = lecture_hours;
	subject->MKR = MKR;

	bool correct_input = false;
	while (correct_input == false)
	{
		if (type_control == 1)
		{
			subject->semester_control = "�������";
			correct_input = true;
		}
		else if (type_control == 2)
		{
			subject->semester_control = "�����";
			correct_input = true;
		}
		else
		{
			cout << "������ �����!" << endl;
		}

	}
}

void Print_Subject(Subject* subject)
{
	cout << "�������� ��������   ���������� ��������   ����� ��������   ���������� ���������� �����    ���������� ���������� �����   ���   ��� ��������" << endl;
	cout << subject->subject_name << "   ";
	cout << subject->credits << "   ";
	cout << subject->semester_number << "   ";
	cout << subject->classroom_hours << "   ";
	cout << subject->lecture_hours << "   ";
	cout << subject->MKR << "   ";
	cout << subject->semester_control << "   " << endl;
}


void Init_Subject_List(Subject& subject_1, Subject& subject_2)
{
	head = new List; //�������� ������ ��� ������ ������� ������
	head->subject = subject_1; // ��������� ���� � �������
	head->next = NULL; // ��������� �� ��������� ������� ����
	List* end; // ���������, ������� ������ ����� ���������� �������� ������
	end = head; // ������ ��������� ������� ������ ��������� � ��� �������
	end->next = new List; // �������� ����� � ������ ��� ���������� �������� ������
	end = end->next; // �������������� ��������� end �� ���������� ������� ������
	end->subject = subject_2; // ��������� ���� � �������
	end->next = NULL; // ��������� �� ��������� ������� ����
}

void Add_Subject_to_end(List* head, Subject& subject)
{
	List* current = head; // ���������, ������� ���������� ������
	List* new_subject = new List; // �������� ������ ��� ������ �������� ������
	new_subject->subject = subject; // ��������� ���� ������ �������� ������ 
	new_subject->next = NULL; // ������ ���� ������� ���������

	while (true)
	{
		if (current->next == 0)
		{
			current->next = new_subject;
			break;
		}
		current = current->next;
	}
}

void Add_Subject_to_begin(List** head, Subject& subject)
{
	List* new_subject = new List;
	new_subject->subject = subject;
	new_subject->next = *head;
	*head = new_subject;
}

void Insert_after_subject(List** head, Subject& subject)
{
	List* new_subject = new List;
	new_subject->subject = subject;
	string previous_subject_name;
	int previous_subject_semestr;
	cout << "������� �������� ��������, ����� �������� ������ �������� �������: ";
	cin.get();
	getline(cin, previous_subject_name);
	cout << "������� ������� ��������, ����� �������� ������ �������� �������: ";
	cin >> previous_subject_semestr;

	List* current = *head; // ������� ���������, ������� ���������� �� ������
	List* next_subject = current->next;

	int insert_choice;
	bool correct_subject_choice = false;
	cout << "�������� ������� � ������ ������ ��� ����� ���������� ��������? (0 - � ������ ������, 1 - ����� ���������� ��������): ";
	cin >> insert_choice;
	if (insert_choice == 0) // ������� � ������ ������ ���������
	{
		new_subject->next = *head;
		*head = new_subject;
	}
	else if (insert_choice == 1)
	{
		while (next_subject != NULL)
		{
			if (current->subject.subject_name == previous_subject_name && current->subject.semester_number == previous_subject_semestr && *head != current && current->next != NULL) // ��������� ����� ����������� �������� �� ������ � �� � ������ ������
			{
				current->next = new_subject;
				new_subject->next = next_subject;
				correct_subject_choice = true;
				return;
			}
			else if (current->subject.subject_name == previous_subject_name && current->subject.semester_number == previous_subject_semestr && current->next == NULL) // ���� ��������� ����� ���������� �������� ������ 
			{
				current->next = new_subject;
				new_subject->next = NULL;
				correct_subject_choice = true;
				break;
			}
			current = next_subject;
			next_subject = next_subject->next;
		}
		if (correct_subject_choice == false)
		{
			cout << "������� ����� �������� ����� �������� ����� ������� ����������� � ������." << endl;
		}
	}
	else
	{
		cout << "������ �����. �� ���������� ����� ������� �������� � ������ ���������. " << endl;
	}
}

void Delete_subject(List** head, int subject_counter)
{
	cout << "===== �������� �������� �� ������ =====" << endl;

	if (*head == NULL) // ���� ������ ���� - ������� ������
	{
		cout << "������ ����. ��� ��������� ��� ��������.";
		return;
	}

	string delete_subject_name;
	int delete_subject_semestr;
	cout << "������� �������� ��������, ������� ����� �������: ";
	cin.get();
	getline(cin, delete_subject_name);
	cout << "������� ������� ��������, ������� ����� �������: ";
	cin >> delete_subject_semestr;

	List* current = *head;
	if (current->subject.subject_name == delete_subject_name && current->subject.semester_number == delete_subject_semestr) // ���� �������� ������ �� ���� � ��������� ������ �������
	{
		*head = current->next;
		delete current;
		subject_counter--;
		return;
	}

	List* next_subject = current->next;
	bool correct_input = false;
	while (next_subject != NULL)
	{
		if (current->subject.subject_name == delete_subject_name && current->subject.semester_number == delete_subject_semestr) // ���� �������� ������ �� ���� � ��������� �� ������ ������� �������
		{
			current->next = next_subject->next;
			delete next_subject;
			correct_input = true;
			subject_counter--;
			return;
		}
		current = next_subject;
		next_subject = next_subject->next;
	}
	if (correct_input == false)
	{
		cout << "������ �����. ��������� ������� �� ������." << endl;
	}
}

void Clear_List(List** head)
{
	if (*head == NULL)
	{
		return;
	}
	List* next_subject = *head;
	List* current;
	while (next_subject != NULL)
	{
		current = next_subject;
		next_subject = next_subject->next;
		delete current;
	}
	*head = NULL;
}

void Print_Subject_List(List* head)
{
	List* print = head;
	cout << "�������� ��������   ���������� ��������   ����� ��������   ���������� ���������� �����    ���������� ���������� �����   ���   ��� ��������" << endl;
	while (print)
	{
		cout << print->subject.subject_name << "   ";
		cout << print->subject.credits << "   ";
		cout << print->subject.semester_number << "   ";
		cout << print->subject.classroom_hours << "   ";
		cout << print->subject.lecture_hours << "   ";
		cout << print->subject.MKR << "   ";
		cout << print->subject.semester_control << "   ";
		print = print->next;
		cout << endl;
	}
}


// ������� ������������ ������� ���� �������

List* mergeLists_by_semestr(List* a, List* b)
{
	List tmp;
	List* head = &tmp;
	List* c = head;

	// �������
	while ((a != 0) && (b != 0))
	{
		if (a->subject.semester_number < b->subject.semester_number)

		{
			c->next = a;
			c = a;
			a = a->next;
		}
		else
		{
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	// ������������ ���������� "�����"
	c->next = (a == 0) ? b : a;
	return head->next;
}

// ���������� �������� ������ ��������

List* mergeSort_by_semestr(List* c)
{
	if (c == 0 || c->next == 0) // ����������� ������
		return c;
	List* a = c; // a ������ ������ ������ �����
	List* b = c->next; // ��������� ���������
	while ((b != 0) && (b->next != 0))
	{
		c = c->next; // ������ ��������� ������ ���� ���
		b = b->next->next; // ������ - ��� ����
	}
	b = c->next; // � b �������� ������ ������ ����� ������
	c->next = 0; // ��������� ����� - ����� ������ ����� ������
	//cout << "----" << endl;
	// ���������� �������� �� �� ��������� � ������� ����� ������
	return mergeLists_by_semestr(mergeSort_by_semestr(a), mergeSort_by_semestr(b));
}

// ������� ������������ ������� ���� �������

List* mergeLists_by_classroom_hours(List* a, List* b)
{
	List tmp;
	List* head = &tmp;
	List* c = head;

	// �������
	while ((a != 0) && (b != 0))
	{
		if (a->subject.semester_number == b->subject.semester_number && a->subject.classroom_hours > b->subject.classroom_hours)

		{
			c->next = a;
			c = a;
			a = a->next;
		}
		else
		{
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	// ������������ ���������� "�����"
	c->next = (a == 0) ? b : a;
	return head->next;
}

// ���������� �������� ������ ��������

List* mergeSort_by_classroom_hours(List* c)
{
	if (c == 0 || c->next == 0) // ����������� ������
		return c;
	List* a = c; // a ������ ������ ������ �����
	List* b = c->next; // ��������� ���������
	while ((b != 0) && (b->next != 0))
	{
		c = c->next; // ������ ��������� ������ ���� ���
		b = b->next->next; // ������ - ��� ����
	}
	b = c->next; // � b �������� ������ ������ ����� ������
	c->next = 0; // ��������� ����� - ����� ������ ����� ������
	//cout << "----" << endl;
	// ���������� �������� �� �� ��������� � ������� ����� ������
	return mergeLists_by_classroom_hours(mergeSort_by_classroom_hours(a), mergeSort_by_classroom_hours(b));
}

void PRINT(int subject_counter, List* head, Subject* subject)
{
	if (subject_counter > 1)
	{
		Print_Subject_List(head);
	}
	else if (subject_counter == 1)
	{
		Print_Subject(subject);
	}
	else
	{
		cout << "������ ��������� ����." << endl;
	}
}

void INSERT(int subject_counter, List** head, /*Subject* subject,*/ int insert_mode)
{
	cout << "===== ������� ������ �������� =====" << endl;
	Subject subject_1, subject_2;

	while (true)
	{
		if (subject_counter == 0)
		{
			cout << "������ ��������� ����. ��������� ������ �������." << endl;
			Input_Subject(&subject_1);
			subject_counter++;
			break;
		}
		cout << "1 - �������� ������� � ������ ������, 2 - �������� ������� ����� ���������� ��������, 3 - �������� ������� � ������ ������" << endl;
		cout << "�������� ��� ������� ������ ��������: ";
		cin >> insert_mode;
		if (insert_mode == 1) // ������� � ������ ������
		{
			if (subject_counter >= 2) // ���� ������ ��� ������
			{
				Add_Subject_to_begin(head, subject_2);
				subject_counter++;
				break;
			}
			else // ���� ������ ��� �� ������, �� ���� ���� �������
			{
				Input_Subject(&subject_1);
				Init_Subject_List(subject_2, subject_1);
				subject_counter++;
				break;
			}
		}
		else if (insert_mode == 2 && subject_counter >= 2) // ������� ����� ����������� ��������
		{
			Insert_after_subject(head, subject_2);
			subject_counter++;
			break;
		}
		else if (insert_mode == 3 && subject_counter >= 2) // ������� � ����� ������
		{
			Add_Subject_to_end(*head, subject_2);
			subject_counter++;
			break;
		}
		else if (subject_counter == 1 && (insert_mode == 2 || insert_mode == 3)) // ���� ������ ��� �� ������, �� ���� ������ ���� ������� ��������� ������ ������� �������������� ������
		{
			Input_Subject(&subject_2);
			Init_Subject_List(subject_1, subject_2);
			subject_counter++;
			break;
		}
		else
		{
			cout << "������ �����!" << endl;
			continue;
		}
	}
}

void SORT(int subject_counter, List* head, int sort_mode)
{
	cout << "===== ���������� ������ ��������� =====" << endl;
	if (subject_counter < 2)
	{
		cout << "� ������ ������������ ��������� ��� ����������.";
		return;
	}
	while (true)
	{
		cout << "1 - ���������� ������ ��������� �� ���������, 2 - ���������� ������ ��������� �� ��������� � ���������� ���������� �����" << endl;
		cout << "�������� ��� ����������: ";
		cin >> sort_mode;
		if (sort_mode == 1)
		{
			mergeSort_by_semestr(head);
			break;
		}
		else if (sort_mode == 2)
		{
			mergeSort_by_semestr(head);
			mergeSort_by_classroom_hours(head);
			break;
		}
		else
		{
			cout << "������ �����!" << endl;
			continue;
		}
	}
}


int main_lab_3_11()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*
	Subject subject_1, subject_2;
	int mode, subject_counter = 0, sort_mode, insert_mode;

	cout << "##########################################" << endl;
	cout << "###### ����������� ������ ��������� ######" << endl;
	cout << "##########################################" << endl;

	while (true)
	{
		cout << "===== ������� ���� =====" << endl;
		cout << "��������: 1 - ������� ������ � �������, 2 - �������� ����� �������, 3 - ������� �������, 4 - ���������� ������, 5 - ��������� ������" << endl;
		cout << "������� ��������: ";
		cin >> mode;
		if (mode == 1)
		{
			cout << "===== ����� ����� ������ =====" << endl;
			PRINT(subject_counter, head, &subject_1);
			continue;
		}
		else if (mode == 2)
		{
			cout << "===== �������� ����� ������� =====" << endl;
			INSERT(subject_counter, &head, insert_mode);
			continue;
		}
		else if (mode == 3)
		{
			cout << "===== ������� ������� =====" << endl;
			Delete_subject(&head, subject_counter);
			continue;
		}
		else if (mode == 4)
		{
			cout << "===== ���������� ������ =====" << endl;
			SORT(subject_counter, head, subject, sort_mode);
			continue;
		}
		else if (mode == 5)
		{
			cout << "===== ���������� ������. ������� ������..." << endl;
			Clear_List(&head);
			break;
		}
		else
		{
			cout << "������ �����!" << endl;
			continue;
		}
	}
	*/

	//���������� ��������� � �� �����������
	Subject subject_1, subject_2, subject_3, subject_4, subject_5, subject_6, subject_7, subject_8;
	Input_Subject_2(&subject_1, "���������� ����������", 8.0, 5, 144, 72, 100, 1);
	Input_Subject_2(&subject_2, "������������ ��������", 7.0, 6, 126, 72, 100, 1);
	Init_Subject_List(subject_1, subject_2);
	Input_Subject_2(&subject_3, "������ �������� �������", 5.0, 7, 72, 54, 100, 1);
	Add_Subject_to_end(head, subject_3);
	Input_Subject_2(&subject_4, "������ �������� �������", 4.0, 8, 54, 46, 100, 1);
	Add_Subject_to_end(head, subject_4);
	Input_Subject_2(&subject_5, "������������ ��������", 7.0, 7, 126, 72, 100, 1);
	Add_Subject_to_end(head, subject_5);
	Input_Subject_2(&subject_6, "���", 6.0, 6, 90, 54, 100, 1);
	Add_Subject_to_end(head, subject_6);
	Input_Subject_2(&subject_7, "���������� ��-���������", 3.0, 8, 54, 36, 100, 2);
	Add_Subject_to_end(head, subject_7);
	Input_Subject_2(&subject_8, "��������� � ��������� ������", 4.0, 5, 54, 36, 100, 2);
	Add_Subject_to_end(head, subject_8);
	cout << "������� ������ ���������..." << endl;
	Print_Subject_List(head);
	cout << endl << "�������� ������ ��������� �� ��������..." << endl;
	mergeSort_by_semestr(head);
	Print_Subject_List(head);
	cout << endl << "�������� ������ ��������� �� ���������� ���������� �����..." << endl;
	mergeSort_by_classroom_hours(head);
	Print_Subject_List(head);



	/*
	Subject subject_1, subject_2, subject_3, subject_4, subject_5, subject_6, subject_7, subject_8;
	cout << "������ ������ �������...." << endl;
	Input_Subject(&subject_1);
	cout << "������� ������ �������:" << endl;
	Print_Subject(&subject_1);
	cout << "������ ������ ������� � ��������� ������...." << endl;
	Input_Subject(&subject_2);
	Init_Subject_List(subject_1, subject_2);
	cout << "��������� ������ ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_3);
	Add_Subject_to_List(head, subject_3);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_4);
	Add_Subject_to_List(head, subject_4);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_5);
	Add_Subject_to_List(head, subject_5);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_6);
	Add_Subject_to_List(head, subject_6);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_7);
	Add_Subject_to_List(head, subject_7);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_8);
	Add_Subject_to_List(head, subject_8);
	cout << "������� ������ � ����������� ���������:" << endl;
	Print_Subject_List(head);
	cout << "�������� ������ ��������� �� ��������" << endl;
	mergeSort_by_semestr(head);
	Print_Subject_List(head);
	*/

	/*
	cout << "��������� ����� ������� � ������ ������..." << endl;
	Add_Subject_to_begin(&head, subject_4);
	cout << "������� ������ � ����������� ��������� � ������ ������:" << endl;
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_5);
	cout << "��������� ����� ������� � ������������ ����� ������..." << endl;
	Insert_after_subject(&head, subject_5);
	Print_Subject_List(head);
	cout << "��������� ����� �������..." << endl;
	Input_Subject(&subject_6);
	*/



	return 0;
}


