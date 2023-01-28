#include <iostream>

double input()
{
    double num; 
    bool isCorrect = false;

    while (!isCorrect)
    {
        std::cout << "Введите число: ";
        std::cin.clear();
        std::cin >> num;
        if (std::cin.fail()) {
            std::cout << "Ошибка\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else {
            isCorrect = true;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    }

    return num;
}

int Fib(int i)
{
    unsigned long f1 = 0;
    unsigned long f2 = 1;
    unsigned long fn;
    unsigned long summ = 1;
    if (i < 1) { return 1; }
    if (i == 1) { std::cout << "0 1\nСумма: 1\n"; }
    if (i > 1){
        std::cout << "0 1 ";
        for (int j = 1; j < i; j++)
        {
            fn = f1 + f2;
            summ += fn;
            std::cout << fn << " ";
            f1 = f2;
            f2 = fn;
        }
    }
    std::cout << "\nСумма: " << summ << "\n\n";
    return 0;
}


int main()
{
    std::setlocale(0, "");
    std::cout << "Калькулятор\n";
    bool isStillRuning = true;
    do 
    {
        std::cout << "Выбор операции:\n1.Сложение\n2.Вычитание\n3.Умножение\n4.Деление\n5.Остаток\n6.Числа Фиббоначи\n7.Завершение работы.\n\n";

        double num1;
        double num2;

        int index = input();
        std::cout << "\n\n";

        switch (index)
        {
        case 1:
            num1 = input();
            num1 = num1 + input();
            std::cout << "Результат: " << num1 << "\n\n\n";
            break;

        case 2:
            num1 = input();
            num1 = num1 - input();
            std::cout << "Результат: " << num1 << "\n\n\n";
            break;

        case 3: 
            num1 = input();
            num1 = num1 == 0 ? 0 : num1 * input();
            std::cout << "Результат: " << num1 << "\n\n\n";
            break;

        case 4:
            num1 = input();
            num2 = input();
            if (num2 == 0) {
                std::cout << "Деление на 0 невозможно\n\n";
            }
            else {
                num1 = num1 / num2;
                std::cout << "Результат: " << num1 << "\n\n";
            }
            break;

        case 5:
            num1 = input();
            num2 = input();
            if (num2 == 0) {
                std::cout << "Деление на 0 невозможно\n\n";
            }
            else {
                num1 = std::fmod(num1, num2);
                std::cout << "Результат: " << num1 << "\n\n";
            }
            break;

        case 6:
            num1 = input();
            if (Fib(num1) == 1) { std::cout << "Количество членов не может быть меньше 0\n"; }
            break;

        case 7:
            isStillRuning = false;
            std::cout << "Программа завершена\n";
            break;

        default:
            break;
        }

    } while (isStillRuning);

    return 0;
}
