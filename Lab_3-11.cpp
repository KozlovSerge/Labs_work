/*
3-11. Створити однозв’язний список дисциплін факультету, кожний елемент
якого містить загальну інформацію по дисципліні(назва, кількість кредитів)
та деталізовану інформацію про номер семестру, у якому дисципліна
викладається, кількість аудиторних годин, кількість лекційних годин,
кількість МКР та ознаку семестрового контролю(залік / екзамен)).
1) Реалізувати функції перегляду записаних даних, додавання нового
елемента на задану позицію(INSERT), видалення елемента з заданої
позиції(DELETE).Початковий вміст списку заповнити з клавіатури.
2) Впорядкувати записи за номером семестру, а в межах одного семестру
— за кількістю аудиторних годин у порядку спадання.
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"


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
	cout << "Введите название дисциплины: ";
	cin.get();
	getline(cin, subject->subject_name);
	cout << "Введите количество кредитов дисциплины: ";
	cin >> subject->credits;
	cout << "Введите номер семестра, в котором преподается дисциплина: ";
	cin >> subject->semester_number;
	cout << "Введите количество аудиторных часов дисциплины: ";
	cin >> subject->classroom_hours;
	cout << "Введите количество лекционных часов дисциплины: ";
	cin >> subject->lecture_hours;
	cout << "Введите количество МКР дисциплины: ";
	cin >> subject->MKR;

	bool correct_input = false;
	int type_control;
	while (correct_input == false)
	{
		cout << "Выберите тип контроля (1-экзамен, 2-зачёт): ";
		cin >> type_control;
		if (type_control == 1)
		{
			subject->semester_control = "Экзамен";
			correct_input = true;
		}
		else if (type_control == 2)
		{
			subject->semester_control = "Зачёт";
			correct_input = true;
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
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
			subject->semester_control = "Экзамен";
			correct_input = true;
		}
		else if (type_control == 2)
		{
			subject->semester_control = "Зачёт";
			correct_input = true;
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
		}

	}
}

void Print_Subject(Subject* subject)
{
	cout << "Название предмета   Количество кредитов   Номер семестра   Количество аудиторных часов    Количество лекционных часов   МКР   Тип контроля" << endl;
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
	head = new List; //выделяем память под первый элемент списка
	head->subject = subject_1; // заполняем поля с данными
	head->next = NULL; // указатель на следующий элемент пуст
	List* end; // указатель, который хранит адрес последнего элемента списка
	end = head; // сейчас последний элемент списка совпадает с его началом
	end->next = new List; // выделяем место в памяти для следующего элемента списка
	end = end->next; // перенаправляем укахатель end на выделенную область памяти
	end->subject = subject_2; // заполняем поля с данными
	end->next = NULL; // указатель на следующий элемент пуст
}

void Add_Subject_to_end(List* head, Subject& subject)
{
	List* current = head; // указатель, который перебирает список
	List* new_subject = new List; // выделяем память для нового элемента списка
	new_subject->subject = subject; // заполняем поля нового элемента списка 
	new_subject->next = NULL; // делаем этот элемент последним

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
	cout << "Введите название предмета, после которого хотите вставить предмет: ";
	cin.get();
	getline(cin, previous_subject_name);
	cout << "Введите семестр предмета, после которого хотите вставить предмет: ";
	cin >> previous_subject_semestr;

	List* current = *head; // создаем указатель, который проходится по списку
	List* next_subject = current->next;

	int insert_choice;
	bool correct_subject_choice = false;
	cout << "Вставить предмет в начало списка или после выбранного предмета? (0 - в начало списка, 1 - после выбранного предмета): ";
	cin >> insert_choice;
	if (insert_choice == 0) // вставка в начало списка предметов
	{
		new_subject->next = *head;
		*head = new_subject;
	}
	else if (insert_choice == 1)
	{
		while (next_subject != NULL)
		{
			if (current->subject.subject_name == previous_subject_name && current->subject.semester_number == previous_subject_semestr && *head != current && current->next != NULL) // вставляем после конкретного предмета не вконце и не в начале списка
			{
				current->next = new_subject;
				new_subject->next = next_subject;
				correct_subject_choice = true;
				return;
			}
			else if (current->subject.subject_name == previous_subject_name && current->subject.semester_number == previous_subject_semestr && current->next == NULL) // если вставляем после последнего предмета списка 
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
			cout << "Предмет после которого нужно вставить новый предмет отсутствует в списке." << endl;
		}
	}
	else
	{
		cout << "Ошибка ввода. Не корректный выбор вставки предмета в список предметов. " << endl;
	}
}

void Delete_subject(List** head, int subject_counter)
{
	cout << "===== Удаление предмета из списка =====" << endl;

	if (*head == NULL) // если список пуст - удалять нечего
	{
		cout << "Список пуст. Нет предметов для удаления.";
		return;
	}

	string delete_subject_name;
	int delete_subject_semestr;
	cout << "Введите название предмета, который нужно удалить: ";
	cin.get();
	getline(cin, delete_subject_name);
	cout << "Введите семестр предмета, который нужно удалить: ";
	cin >> delete_subject_semestr;

	List* current = *head;
	if (current->subject.subject_name == delete_subject_name && current->subject.semester_number == delete_subject_semestr) // если исходный список не пуст и удаляется первый предмет
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
		if (current->subject.subject_name == delete_subject_name && current->subject.semester_number == delete_subject_semestr) // если исходный список не пуст и удаляется не первый предмет элемент
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
		cout << "Ошибка ввода. Удаляемый предмет не найден." << endl;
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
	cout << "Название предмета   Количество кредитов   Номер семестра   Количество аудиторных часов    Количество лекционных часов   МКР   Тип контроля" << endl;
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


// Функция осуществляет слияние двух списков

List* mergeLists_by_semestr(List* a, List* b)
{
	List tmp;
	List* head = &tmp;
	List* c = head;

	// Сливаем
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
	// Присоединяем оставшийся "хвост"
	c->next = (a == 0) ? b : a;
	return head->next;
}

// Сортировка связного списка слиянием

List* mergeSort_by_semestr(List* c)
{
	if (c == 0 || c->next == 0) // сортировать нечего
		return c;
	List* a = c; // a хранит начало первой части
	List* b = c->next; // служебный указатель
	while ((b != 0) && (b->next != 0))
	{
		c = c->next; // первый указатель делает один шаг
		b = b->next->next; // второй - два шага
	}
	b = c->next; // в b записали начало второй части списка
	c->next = 0; // разрываем связь - конец первой части списка
	//cout << "----" << endl;
	// Рекурсивно вызываем ту же процедуру и сливаем части списка
	return mergeLists_by_semestr(mergeSort_by_semestr(a), mergeSort_by_semestr(b));
}

// Функция осуществляет слияние двух списков

List* mergeLists_by_classroom_hours(List* a, List* b)
{
	List tmp;
	List* head = &tmp;
	List* c = head;

	// Сливаем
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
	// Присоединяем оставшийся "хвост"
	c->next = (a == 0) ? b : a;
	return head->next;
}

// Сортировка связного списка слиянием

List* mergeSort_by_classroom_hours(List* c)
{
	if (c == 0 || c->next == 0) // сортировать нечего
		return c;
	List* a = c; // a хранит начало первой части
	List* b = c->next; // служебный указатель
	while ((b != 0) && (b->next != 0))
	{
		c = c->next; // первый указатель делает один шаг
		b = b->next->next; // второй - два шага
	}
	b = c->next; // в b записали начало второй части списка
	c->next = 0; // разрываем связь - конец первой части списка
	//cout << "----" << endl;
	// Рекурсивно вызываем ту же процедуру и сливаем части списка
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
		cout << "Список предметов пуст." << endl;
	}
}

void INSERT(int subject_counter, List** head, /*Subject* subject,*/ int insert_mode)
{
	cout << "===== Вставка нового предмета =====" << endl;
	Subject subject_1, subject_2;

	while (true)
	{
		if (subject_counter == 0)
		{
			cout << "Список предметов пуст. Добавляем первый предмет." << endl;
			Input_Subject(&subject_1);
			subject_counter++;
			break;
		}
		cout << "1 - Вставить предмет в начало списка, 2 - Вставить предмет после введенного предмета, 3 - Вставить предмет в конець списка" << endl;
		cout << "Выберите вид вставки нового предмета: ";
		cin >> insert_mode;
		if (insert_mode == 1) // вставка в начало списка
		{
			if (subject_counter >= 2) // если список уже создан
			{
				Add_Subject_to_begin(head, subject_2);
				subject_counter++;
				break;
			}
			else // если список ещё не создан, но есть один предмет
			{
				Input_Subject(&subject_1);
				Init_Subject_List(subject_2, subject_1);
				subject_counter++;
				break;
			}
		}
		else if (insert_mode == 2 && subject_counter >= 2) // вставка после конкретного предмета
		{
			Insert_after_subject(head, subject_2);
			subject_counter++;
			break;
		}
		else if (insert_mode == 3 && subject_counter >= 2) // вставка в конец списка
		{
			Add_Subject_to_end(*head, subject_2);
			subject_counter++;
			break;
		}
		else if (subject_counter == 1 && (insert_mode == 2 || insert_mode == 3)) // если список ещё не создан, но есть только один предмет вставляем второй предмет инициализацией списка
		{
			Input_Subject(&subject_2);
			Init_Subject_List(subject_1, subject_2);
			subject_counter++;
			break;
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
			continue;
		}
	}
}

void SORT(int subject_counter, List* head, int sort_mode)
{
	cout << "===== Сортировка списка предметов =====" << endl;
	if (subject_counter < 2)
	{
		cout << "В списке недостаточно предметов для сортировки.";
		return;
	}
	while (true)
	{
		cout << "1 - Сортировка списка предметов по семестрам, 2 - Сортировка списка предметов по семестрам и количеству аудиторных часов" << endl;
		cout << "Выберите вид сортировки: ";
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
			cout << "Ошибка ввода!" << endl;
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
	cout << "###### ОДНОСВЯЗНЫЙ СПИСОК ПРЕДМЕТОВ ######" << endl;
	cout << "##########################################" << endl;

	while (true)
	{
		cout << "===== Главное меню =====" << endl;
		cout << "Действия: 1 - Вывести список в консоль, 2 - Вставить новый предмет, 3 - Удалить предмет, 4 - Сортировка списка, 5 - Завершить работу" << endl;
		cout << "Введите действие: ";
		cin >> mode;
		if (mode == 1)
		{
			cout << "===== Вывод всего списка =====" << endl;
			PRINT(subject_counter, head, &subject_1);
			continue;
		}
		else if (mode == 2)
		{
			cout << "===== Вставить новый предмет =====" << endl;
			INSERT(subject_counter, &head, insert_mode);
			continue;
		}
		else if (mode == 3)
		{
			cout << "===== Удалить предмет =====" << endl;
			Delete_subject(&head, subject_counter);
			continue;
		}
		else if (mode == 4)
		{
			cout << "===== Сортировка списка =====" << endl;
			SORT(subject_counter, head, subject, sort_mode);
			continue;
		}
		else if (mode == 5)
		{
			cout << "===== Завершение работы. Очистка памяти..." << endl;
			Clear_List(&head);
			break;
		}
		else
		{
			cout << "Ошибка ввода!" << endl;
			continue;
		}
	}
	*/

	//Добавление предметов и их соритировка
	Subject subject_1, subject_2, subject_3, subject_4, subject_5, subject_6, subject_7, subject_8;
	Input_Subject_2(&subject_1, "Дискретная математика", 8.0, 5, 144, 72, 100, 1);
	Input_Subject_2(&subject_2, "Исследование операций", 7.0, 6, 126, 72, 100, 1);
	Init_Subject_List(subject_1, subject_2);
	Input_Subject_2(&subject_3, "Теория принятия решений", 5.0, 7, 72, 54, 100, 1);
	Add_Subject_to_end(head, subject_3);
	Input_Subject_2(&subject_4, "Теория принятия решений", 4.0, 8, 54, 46, 100, 1);
	Add_Subject_to_end(head, subject_4);
	Input_Subject_2(&subject_5, "Исследование операций", 7.0, 7, 126, 72, 100, 1);
	Add_Subject_to_end(head, subject_5);
	Input_Subject_2(&subject_6, "ООП", 6.0, 6, 90, 54, 100, 1);
	Add_Subject_to_end(head, subject_6);
	Input_Subject_2(&subject_7, "Управление ИТ-проектами", 3.0, 8, 54, 36, 100, 2);
	Add_Subject_to_end(head, subject_7);
	Input_Subject_2(&subject_8, "Алгоритмы и структуры данных", 4.0, 5, 54, 36, 100, 2);
	Add_Subject_to_end(head, subject_8);
	cout << "Выводим список предметов..." << endl;
	Print_Subject_List(head);
	cout << endl << "Сортирум список предметов по семестру..." << endl;
	mergeSort_by_semestr(head);
	Print_Subject_List(head);
	cout << endl << "Сортирум список предметов по количеству аудиторных часов..." << endl;
	mergeSort_by_classroom_hours(head);
	Print_Subject_List(head);



	/*
	Subject subject_1, subject_2, subject_3, subject_4, subject_5, subject_6, subject_7, subject_8;
	cout << "Вводим первый предмет...." << endl;
	Input_Subject(&subject_1);
	cout << "Выводим первый предмет:" << endl;
	Print_Subject(&subject_1);
	cout << "Вводим второй предмет и формируем список...." << endl;
	Input_Subject(&subject_2);
	Init_Subject_List(subject_1, subject_2);
	cout << "Созданный список предметов:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_3);
	Add_Subject_to_List(head, subject_3);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_4);
	Add_Subject_to_List(head, subject_4);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_5);
	Add_Subject_to_List(head, subject_5);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_6);
	Add_Subject_to_List(head, subject_6);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_7);
	Add_Subject_to_List(head, subject_7);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_8);
	Add_Subject_to_List(head, subject_8);
	cout << "Выводим список с добавленным предметом:" << endl;
	Print_Subject_List(head);
	cout << "Сортирум список предметов по семестру" << endl;
	mergeSort_by_semestr(head);
	Print_Subject_List(head);
	*/

	/*
	cout << "Вставляем новый предмет в начало списка..." << endl;
	Add_Subject_to_begin(&head, subject_4);
	cout << "Выводим список с добавленным предметом в начало списка:" << endl;
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_5);
	cout << "Вставляем новый предмет в определенное место списка..." << endl;
	Insert_after_subject(&head, subject_5);
	Print_Subject_List(head);
	cout << "Добавляем новый предмет..." << endl;
	Input_Subject(&subject_6);
	*/



	return 0;
}


