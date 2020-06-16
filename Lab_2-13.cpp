#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int** create_matrix(int Size);
void delete_matrix(int** Ar, int Size);
int** insert_matrix_values(int** Ar, int Size, int max_element_value);
void show_matrix(int** Ar, int Size);
int** replace_matrix_elements_by_index(int** Ar, int Size);
int** replace_matrix_elements_by_pointers(int** Ar, int Size);

int main_lab_2_13()
{
    unsigned int Size;
    int max_element_value;
    srand((unsigned int)time(0));
    int** empty_matrix, ** first_matrix, ** second_matrix_by_index, ** second_matrix_by_pointers;
    cout << "Enter matrix size: ";
    cin >> Size;
    cout << "Enter max element value: ";
    cin >> max_element_value;
    empty_matrix = create_matrix(Size);
    first_matrix = insert_matrix_values(empty_matrix, Size, max_element_value);
    unsigned int start_time = clock();
    second_matrix_by_index = replace_matrix_elements_by_index(first_matrix, Size);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    first_matrix = replace_matrix_elements_by_index(first_matrix, Size);
    unsigned int start_time_2 = clock();
    second_matrix_by_pointers = replace_matrix_elements_by_pointers(first_matrix, Size);
    unsigned int end_time_2 = clock();
    unsigned int search_time_2 = end_time_2 - start_time_2;
    if (Size >= 100) {
        cout << "Time of matrix replaced by index: " << search_time << "mls" << endl;
        cout << "Time of matrix replaced by pointers: " << search_time_2 << "mls" << endl;
    }
    else {
        cout << endl << "Base matrix: " << endl;
        show_matrix(first_matrix, Size);
        cout << endl << "Result matrix replaced by index: " << endl;
        show_matrix(second_matrix_by_index, Size);
        cout << "Time of matrix replaced by index: " << search_time << "mls" << endl;
        cout << endl << "Result matrix replaced by pointers: " << endl;
        show_matrix(second_matrix_by_pointers, Size);
        cout << "Time of matrix replaced by pointers: " << search_time_2 << "mls" << endl << endl;
    }
    delete_matrix(first_matrix, Size);
    delete_matrix(second_matrix_by_index, Size);
    delete_matrix(second_matrix_by_pointers, Size);
    delete_matrix(empty_matrix, Size);
    return 0;
}

int** create_matrix(int Size)
{
    int** Ar = new int* [Size];
    for (int row = 0; row < Size; ++row) {
        Ar[row] = new int[Size];
    }
    return Ar;
}

void delete_matrix(int** Ar, int Size)
{
    for (int row = 0; row < Size; ++row) {
        delete[] Ar[row];
    }
    delete[] Ar;
}

int** insert_matrix_values(int** Ar, int Size, int max_element_value)
{
    for (int row = 0; row < Size; ++row) {
        for (int col = 0; col < Size; ++col) {
            Ar[row][col] = rand() % max_element_value;
        }
    }
    return Ar;
}

void show_matrix(int** Ar, int Size)
{
    for (int row = 0; row < Size; ++row) {
        for (int col = 0; col < Size; ++col)
            cout << Ar[row][col] << ' ';
        cout << endl;
    }
}

int** replace_matrix_elements_by_index(int** Ar, int Size)
{
    int buffer;
    int center = Size / 2;
    for (int row = 0; row < center; ++row) {
        for (int col = 0; col < Size; ++col) {
            buffer = Ar[row][col];
            Ar[row][col] = Ar[row + center][col];
            Ar[row + center][col] = buffer;
        }
    }
    return Ar;
}

int** replace_matrix_elements_by_pointers(int** Ar, int Size)
{

    int buffer;
    int center = Size / 2;
    for (int row = 0; row < center; ++row) {
        for (int col = 0; col < Size; ++col) {
            buffer = *(*(Ar + row) + col);
            *(*(Ar + row) + col) = *(*(Ar + row + center) + col);
            *(*(Ar + row + center) + col) = buffer;
        }
    }
    return Ar;
}
