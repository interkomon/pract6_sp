// pract6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

void ReverseWord(char* str);

int main()
{
    setlocale(LC_ALL, "RUS");
    std::cout << "Hello World!\n";
    char str[100];
    std::cout << "Введите строку: ";
    gets_s(str);
    ReverseWord(str);
    std::cout << "Изменная строка: ";
    puts(str);

}

bool Check(const char* str)
{
    while (*str)
    {
        if (isdigit(*str) || strchr("*'&@`~", *str))
            return true;
        str++;
    }
    return false;
}

void ReverseWord(char* str)
{
    int count = 0;
    char* wordstart = str;
    char* temp = str;
    while (*temp)
    {
        temp++;
        if (*temp == '\0' || *temp == ' ') //проверка на то есть ли  пробел или конец строки (терминальный ноль \0) - символ конца
        {
            if (Check(wordstart)) {
                std::cout << "Ошибка: слово содержит символы которые нельзя!\n";

            }
            if (count % 2 == 1)
            {
                char* end = temp - 1;
                while (wordstart < end)
                {
                    char tempchar = *wordstart;
                    *wordstart = *end;
                    *end = tempchar;
                    wordstart++;
                    end--;
                }
            }
            count++;
            wordstart = temp + 1;
        }
    }
}





















// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
