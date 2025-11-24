#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Film
{
    char title[50];    // Назва фільму
    char actor[50];    // Виконавець головної ролі
    int year;          // Рік випуску
    char genre[30];    // Жанр
};

Film a[10];

int main()
{
    system("color f0");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість фільмів (до 10): ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "\nФільм #" << i + 1 << endl;
        cout << "Назва фільму:\t";
        cin.getline(a[i].title, sizeof(a[i].title));
        cout << "Виконавець головної ролі:\t";
        cin.getline(a[i].actor, sizeof(a[i].actor));
        cout << "Рік випуску:\t";
        cin >> a[i].year;
        cin.ignore();
        cout << "Жанр:\t";
        cin.getline(a[i].genre, sizeof(a[i].genre));
    }

    // Сортування за роком випуску (зростання)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].year > a[j].year)
                swap(a[i], a[j]);

    system("cls");
    cout << setw(25) << left << "Назва фільму"
        << setw(25) << "Виконавець"
        << setw(10) << "Рік"
        << setw(15) << "Жанр" << endl;
    cout << "=======================================================================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(25) << left << a[i].title
            << setw(25) << a[i].actor
            << setw(10) << a[i].year
            << setw(15) << a[i].genre << endl;
    }

    // Пошук акторів, які знімалися більше ніж в одному фільмі
    bool found = false;
    cout << "\n--- Фільми з однаковим актором ---\n";

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(a[i].actor, a[j].actor) == 0)
                count++;
        }

        if (count > 1)
        {
            found = true;
            cout << "\nАктор: " << a[i].actor << endl;
            for (int j = 0; j < n; j++)
            {
                if (strcmp(a[i].actor, a[j].actor) == 0)
                {
                    cout << "  - " << a[j].title << " (" << a[j].year << ", " << a[j].genre << ")" << endl;
                }
            }
            break; // виводимо лише першу групу акторів
        }
    }

    if (!found)
        cout << "Немає акторів, які грали в кількох фільмах.\n";

    system("pause");
    return 0;
}

