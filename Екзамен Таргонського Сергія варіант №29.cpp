#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

void Fill_array(int mas[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        mas[i] = (rand() % 20) * pow(-1, rand() % 30);
}

int Find_Mult(int mas[], int p, int l, int n)
{
    int multiply = 1;
    for (int i = 0; i < n; i = i + 2)
    {
        if (mas[i] < 0)
        {
            multiply *= mas[i];
            p--;
        }
        if (p == 0) return multiply;
    }
    return multiply;
}

void Sort(int mas[], int n)
{
    int index_max = 0;
    int index_min = 0;
    int max = mas[0];
    int min = mas[0];
    int up, down;

    for (int i = 1; i < n; i++)
    {
        if (mas[i] > max)
        {
            max = mas[i];
            index_max = i;
        }
        if (mas[i] < min)
        {
            min = mas[i];
            index_min = i;
        }
    }

    std::cout << "max number = " << max << "\n";
    std::cout << "min number = " << min << "\n";

    if (index_max > index_min) {
        up = index_max; down = index_min;
    }
    else
    {
        up = index_min; down = index_max;
    }

    for (int i = down; i < up; i++)
        for (int j = 1; j < up - i + 1; j++)
            if (mas[i] > mas[i + j])
            {
                int temp = mas[i];
                mas[i] = mas[i + j];
                mas[i + j] = temp;
            }
}

int main()
{
    int n, p, l;
    n = 10;

    int array[10];

    std::cout << "enter count of number to sum:\t";
    std::cin >> p;
    std::cout << "enter max number:\t";
    std::cin >> l;

    Fill_array(array, n);

    for (int i = 0; i < n; i++)
        std::cout << array[i] << "\t";

    std::cout << "multiplication = " << Find_Mult(array, p, l, n) << "\n";
    Sort(array, n);
    std::cout << "\n\n\n";

    for (int i = 0; i < n; i++)
        std::cout << array[i] << "\t";

    return 0;
}