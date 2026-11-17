
#include <stdio.h>

#define MAX 1000

// Завдання 83
// Знайти першу пару сусідніх непарних чисел серед 20 елементів.
void task83(void)
{
    int a[20];
    int found = 0;

    printf("\n--- Завдання 83 ---\n");
    printf("Введіть 20 натуральних чисел:\n");

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 19; i++)
    {
        if (a[i] % 2 != 0 && a[i + 1] % 2 != 0)
        {
            printf("Перша пара сусідніх непарних чисел: %d і %d\n",
                   a[i], a[i + 1]);
            printf("Порядкові номери: %d і %d\n", i + 1, i + 2);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Пари сусідніх непарних чисел немає.\n");
    }
}

// Завдання 90
// Перевірити, чи всі елементи послідовності однакові.
void task90(void)
{
    int a[MAX];
    int n = 0;
    int x;
    int equal = 1;

    printf("\n--- Завдання 90 ---\n");
    printf("Введіть послідовність цілих чисел.\n");
    printf("Для завершення введіть від'ємне число:\n");

    while (n < MAX)
    {
        if (scanf("%d", &x) != 1)
            return;

        if (x < 0)
            break;

        a[n] = x;
        n++;
    }

    if (n == 0)
    {
        printf("Послідовність порожня.\n");
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[0])
        {
            equal = 0;
            break;
        }
    }

    if (equal)
    {
        printf("Усі елементи послідовності однакові.\n");
    }
    else
    {
        printf("Елементи послідовності не однакові.\n");
    }
}

// Завдання 109
// Вставити максимальний елемент на k-е місце масиву.
void task109(void)
{
    double a[MAX];
    int n, k;
    double max;

    printf("\n--- Завдання 109 ---\n");
    printf("Введіть кількість елементів масиву (до %d): ", MAX - 1);
    scanf("%d", &n);

    if (n < 1 || n >= MAX)
    {
        printf("Неправильний розмір масиву.\n");
        return;
    }

    printf("Введіть елементи масиву:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
    }

    max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    printf("Введіть позицію k (від 1 до %d): ", n + 1);
    scanf("%d", &k);

    if (k < 1 || k > n + 1)
    {
        printf("Неправильна позиція.\n");
        return;
    }

    for (int i = n; i >= k; i--)
    {
        a[i] = a[i - 1];
    }

    a[k - 1] = max;
    n++;

    printf("Масив після вставки максимального елемента:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", a[i]);
    }

    printf("\n");
}

// Завдання 146
// Створити масив чисел, які закінчуються заданою цифрою k.
void task146(void)
{
    long long a[MAX];
    long long b[MAX];
    int n, k;
    int count = 0;

    printf("\n--- Завдання 146 ---\n");
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Неправильний розмір масиву.\n");
        return;
    }

    printf("Введіть натуральні числа:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);

        if (a[i] < 0)
        {
            printf("Числа повинні бути натуральними.\n");
            return;
        }
    }

    printf("Введіть цифру k (від 0 до 9): ");
    scanf("%d", &k);

    if (k < 0 || k > 9)
    {
        printf("Неправильна цифра.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 10 == k)
        {
            b[count] = a[i];
            count++;
        }
    }

    printf("Новий масив:\n");

    if (count == 0)
    {
        printf("Елементів із заданою останньою цифрою немає.\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("%lld ", b[i]);
        }
        printf("\n");
    }
}

// Завдання 207
// Визначити кількість різних цифр у натуральному числі.
void task207(void)
{
    long long n;
    int digits[10] = {0};
    int count = 0;

    printf("\n--- Завдання 207 ---\n");
    printf("Введіть натуральне число: ");
    scanf("%lld", &n);

    if (n < 0)
    {
        printf("Число повинно бути натуральним.\n");
        return;
    }

    if (n == 0)
    {
        count = 1;
    }
    else
    {
        while (n > 0)
        {
            int digit = n % 10;

            if (digits[digit] == 0)
            {
                digits[digit] = 1;
                count++;
            }

            n /= 10;
        }
    }

    printf("Кількість різних цифр: %d\n", count);
}

// Завдання 88
// Перевірити, чи впорядковані команди за набраними очками.
void task88(void)
{
    int a[MAX];
    int n;
    int ordered = 1;

    printf("\n--- Завдання 88 ---\n");
    printf("Введіть кількість футбольних команд: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Неправильна кількість команд.\n");
        return;
    }

    printf("Введіть кількість очок кожної команди:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            ordered = 0;
            break;
        }
    }

    if (ordered)
    {
        printf("Команди розташовані відповідно до зайнятих місць.\n");
    }
    else
    {
        printf("Команди не розташовані відповідно до зайнятих місць.\n");
    }
}

// Головна функція програми.
int main(void)
{
    int choice;

    do
    {
        printf("\n================================\n");
        printf("ЛАБОРАТОРНА РОБОТА №5\n");
        printf("Одновимірні масиви\n");
        printf("Варіант 9\n");
        printf("================================\n");

        printf("1. Завдання 83\n");
        printf("2. Завдання 90\n");
        printf("3. Завдання 109\n");
        printf("4. Завдання 146\n");
        printf("5. Завдання 207\n");
        printf("6. Завдання 88\n");
        printf("0. Вихід\n");

        printf("Оберіть завдання: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                task83();
                break;

            case 2:
                task90();
                break;

            case 3:
                task109();
                break;

            case 4:
                task146();
                break;

            case 5:
                task207();
                break;

            case 6:
                task88();
                break;

            case 0:
                printf("Завершення програми.\n");
                break;

            default:
                printf("Неправильний вибір. Спробуйте ще раз.\n");
        }

    } while (choice != 0);

    return 0;
}
