#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;


// Функции для умножения матриц и сортировок
void MatrixMultiplication();
void AlgTime();

// Функции, отвечающие за сортировку данных
void RandomValues();    // Рандомная последовательность
void IncreasingSequence();  // Возрастающаяя последовательность
void DescendingSequence();  // Убывающая последовательность
void IncDesSequence();  // Возрастающе-убывающая последовательность
void Qsort();   // Быстрая сортировка всех последовательностей

// Функции, отвечающие за последовательность данных
int PartialSorting(int* , int);
int PartialSort(int *, int);
int ShellShort(int*, int);  // Сортировка Шелла
void QS(int *, int, int);   // Быстрая сортировка
int CombPartSort(int* , int);

int compare(const void*, const void*);



int main()
{
    int action = 0;

    cout << "Press \"Alt+F4\" to quit" << endl;

    while(1)
    {
        cout << "#  Choose the task: ";
        cin >> action;
        if ((action < 1) || (action > 2)) {cout << "Invalid operation" << endl;}
        else if(action == 1) MatrixMultiplication();    // Умножение матриц
        else if(action == 2) AlgTime(); // Сортировки
    }

    return 0;
}


void MatrixMultiplication()
{
    int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0, i, j, k, sum;
    int **matrix1, **matrix2, **matrixresult;
    clock_t start_time, end_time;
    double cpu_time_used;

    cout << "<- Matrix multiplication ->" << endl;
    cout << "1'st matrix" << endl << "Enter Y-positions: ";
    cin >> Y1;
    cout << "Enter X-positions: ";
    cin >> X1;
    cout << "2'nd matrix" << endl << "Enter Y-positions: ";
    cin >> Y2;
    cout << "Enter X-positions: ";
    cin >> X2;

    // 1'st matrix initialisation
    matrix1 = new int*[Y1];
    for(i = 0; i < Y1; i++)
    matrix1[i] = new int[X1];

    // filling the 1'st matrix
    for(i = 0; i < Y1; i++)
    {
        for(j = 0; j < X1; j++)
        {
        matrix1[i][j] = rand() % (100 + 100 + 1) - 100;
        }
        //cout << endl;
    }

    // 2'nd matrix initialisation
    matrix2 = new int*[Y2];
    for(i = 0; i < Y2; i++)
    matrix2[i] = new int[X2];

    // filling the 2'nd matrix
    for(i = 0; i < Y2; i++)
    {
        for(j = 0; j < X2; j++)
        {
        matrix2[i][j] = rand() % (100 + 100 + 1) - 100;
        }
        //cout << endl;
    }

    // sum matrix initialisation
    matrixresult = new int*[Y1];
    for(i = 0; i < Y1; i++)
    matrixresult[i] = new int[X2];

    // matrix multiplication
    if (X1 == Y2)
    {
    start_time = clock();
       for (i = 0; i < Y1; i++)
       {
            for (j = 0; j < X2; j++)
            {
                sum = 0;
                for(k = 0; k < X1; k++)
                {
                    sum = sum + matrix1[i][k] * matrix2[k][j];
                }
                matrixresult[i][j] = sum;
            }
       }
    end_time = clock();
    }

    else cout << "Error: it's not possible to perform multiplication" << endl;

    // clearing memory
    for(i = 0; i < Y1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for(i = 0; i < Y2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for(i = 0; i < Y1; i++)
    {
        delete[] matrixresult[i];
    }
    delete[] matrixresult;

    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << endl;
}

void AlgTime()
{
int action = 0;
while(1)
    {
        cout << "Choose the task: ";
        cin >> action;
        if ((action < 0) || (action > 5)) {cout << "Invalid operation" << endl;}
        else if(action == 0) main();
        else if(action == 1) RandomValues();
        else if(action == 2) IncreasingSequence();
        else if(action == 3) DescendingSequence();
        else if(action == 4) IncDesSequence();
        else if(action == 5) Qsort();
    }
}

void RandomValues()
{
    clock_t start_time, end_time, start_time1, end_time1;
    double cpu_time_used, cpu_time_used1;
    int length = 0, i;

    cout << "<- Sort random values ->" << endl;
    cout << "Enter array length: ";
    cin >> length;

    int *array = new int[length];

    for(i = 0; i < length; i++)
    {
    array[i] = rand() % 100;
    }

    // Shell short
    start_time = clock();
    ShellShort(array, length);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time of Shell short: " << cpu_time_used << endl;

    // quick sort
    start_time1 = clock();
    QS(array, 0, length);
    end_time1 = clock();
    cpu_time_used1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    cout << "Time of Quick short: " << cpu_time_used1 << endl;


    delete[] array;
}

void IncreasingSequence()
{
    clock_t start_time, end_time, start_time1, end_time1;
    double cpu_time_used, cpu_time_used1;
    int length = 0, i;

    cout << "<- Sort increasing values ->" << endl;
    cout << "Enter array length: ";
    cin >> length;

    int *array = new int[length];

    for(i = 0; i < length; i++)
    array[i] = rand() % 100;

    // partial sort
    PartialSorting(array, length);

    // Shell short
    start_time = clock();
    ShellShort(array, length);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time of Shell short: " << cpu_time_used << endl;

    // quick sort
    start_time1 = clock();
    QS(array, 0, length);
    end_time1 = clock();
    cpu_time_used1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    cout << "Time of Quick short: " << cpu_time_used1 << endl;


    delete[] array;
}

void DescendingSequence()
{
    clock_t start_time, end_time, start_time1, end_time1;
    double cpu_time_used, cpu_time_used1;
    int length = 0, i;

    cout << "<- Sort descending values ->" << endl;
    cout << "Enter array length: ";
    cin >> length;

    int *array = new int[length];

    for(i = 0; i < length; i++)
    array[i] = rand() % 100;

    // partial sort
    PartialSort(array, length);

    // Shell short
    start_time = clock();
    ShellShort(array, length);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time of Shell short: " << cpu_time_used << endl;

    // quick sort
    start_time1 = clock();
    QS(array, 0, length);
    end_time1 = clock();
    cpu_time_used1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    cout << "Time of Quick short: " << cpu_time_used1 << endl;


    delete[] array;
}

void IncDesSequence()
{
    clock_t start_time, end_time, start_time1, end_time1;
    double cpu_time_used, cpu_time_used1;
    int length = 0, i;

    cout << "<- Sort Increasing and descending values ->" << endl;
    cout << "Enter array length: ";
    cin >> length;

    int *array = new int[length];

    for(i = 0; i < length; i++)
    array[i] = rand() % 100;

    // partial sort
    CombPartSort(array, length);

    // Shell short
    start_time = clock();
    ShellShort(array, length);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time of Shell short: " << cpu_time_used << endl;

    // quick sort
    start_time1 = clock();
    QS(array, 0, length);
    end_time1 = clock();
    cpu_time_used1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    cout << "Time of Quick short: " << cpu_time_used1 << endl;


    delete[] array;
}

int compare(const void *x1, const void *x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void Qsort()
{
    clock_t start_time, end_time, start_time1, end_time1, start_time2, end_time2, start_time3, end_time3;
    double cpu_time_used, cpu_time_used1, cpu_time_used2, cpu_time_used3;
    int length = 0, i;

    cout << "<- Include Quick sort ->" << endl;
    cout << "Enter array length: ";
    cin >> length;

    int *array = new int[length];
    int *mas = new int[length];
    int *mas1 = new int[length];
    int *mas2 = new int[length];

    for(i = 0; i < length; i++)
    {
    array[i] = rand() % 100;
    mas[i] = array[i];
    mas1[i] = array[i];
    mas2[i] = array[i];
    }

    // Quick short
    start_time = clock();
    qsort(array, length, sizeof(int), compare);
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "Time of quich sorting Random sequence: " << cpu_time_used << endl;

    // partial sort
    PartialSorting(mas, length);

    // Quick short
    start_time1 = clock();
    qsort(mas, length, sizeof(int), compare);
    end_time1 = clock();
    cpu_time_used1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;
    cout << "Time of quich sorting Increacing sequence: " << cpu_time_used1 << endl;

    // partial sort
    PartialSort(mas1, length);

    // quick sort
    start_time2 = clock();
    qsort(mas1, length, sizeof(int), compare);
    end_time2 = clock();
    cpu_time_used2 = ((double)(end_time2 - start_time2)) / CLOCKS_PER_SEC;
    cout << "Time of quick shorting Descending sequence: " << cpu_time_used2 << endl;

    // partial sort
    CombPartSort(mas2, length);
    // quick sort
    start_time3 = clock();
    qsort(mas2, length, sizeof(int), compare);
    end_time3 = clock();
    cpu_time_used3 = ((double)(end_time3 - start_time3)) / CLOCKS_PER_SEC;
    cout << "Time of quick shorting Increacing and Descending sequence: " << cpu_time_used3 << endl;

    delete[] array;
    delete[] mas;
    delete[] mas1;
    delete[] mas2;
}

int PartialSorting(int *array, int array_size)
{
    int tmp = 0, j = 0;

    while(j <= array_size / 3)
    {
        for(int i = 0; i < array_size; i++)
            {
                if(array[i] > array[i + 1])
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }
        j++;
    }

    return *array;
}

int PartialSort(int *array, int array_size)
{
    int tmp = 0, j = 0;

    while(j <= array_size / 3)
    {
        for(int i = 0; i < array_size; i++)
            {
                if(array[i] < array[i + 1])
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }
        j++;
    }

    return *array;
}

int CombPartSort(int *array, int array_size)
{
    int tmp = 0, j = 0;
    int left = array_size / 2;

    while(j <= array_size)
    {
        for(int i = 0; i < left; i++)
            {
                if(array[i] > array[i + 1])
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }
        j++;
    }

    j = 0;
    while(j <= array_size)
    {
        for(int i = left; i < array_size; i++)
            {
                if(array[i + 1] > array[i])
                {
                    tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                }
            }
        j++;
    }

    return *array;
}

int ShellShort(int *array, int array_size)
{
    int i, d = array_size / 2;
    int *mas = new int[array_size];

    for(i = 0; i < array_size; i++)
    mas[i] = array[i];

    while(d >= 1)
    {
        for(i = d; i < array_size; i++)
        {
            int j = i;
            while((j >= d) && (mas[j - d] > mas[j]))
            {
                int t = mas[j];
                mas[j] = mas[j - d];
                mas[j - d] = t;
                j = j - d;
            }
        }
        d = d / 2;
    }

    delete[] mas;

    return 0;
}

void QS(int *array, int left, int right)
{
    int i = left, j = right;
    int x = array[(left + right) / 2], y;

    do
    {
        while((array[i] < x) && (i < right)) i++;
        while((x < array[j]) && (j > left)) j--;

        if(i <= j)
        {
            y = array[i];
            array[i] = array[j];
            array[j] = y;
            i++;
            j--;

        }
    } while(i <= j);

    if(left < j) QS(array, left, j);
    if(i < right) QS(array, i, right);
}
