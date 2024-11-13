float add(int x, float y)
{
    return x + y;
}
float substract(int x, float y)
{
    return (x - y);
}
float multiply(float x, int y)
{
    return x * y;
}
float divide(float x, int y)
{
    if (y == 0)
    {
        printf("Error: Division by zero\n");
        return 0.0f;
    }
    return x / y;
}

int modulus(int x, int y)
{
    if (y == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return x % y;
}
float absolute(float x)
{
    return (x > 0) ? x : -x;
}

int MaxAddr(int *arr, int sz)
{
    int max = 0;
    int count = 0;
    max = *(arr + 0);
    int i = 0;
    for (i = 1; i < sz-1; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
            count = i;
        }
    }
    return count;
}

int month(int input)
{
    //if (x % 4 == 0 && x % 100 != 0 && x % 400 == 0)
    int monthdays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i = 0;
    while (input >= 0)
    {
        input = input - monthdays[i];
        i++;
    }
    return i;
}
int day(int input, int m)
{
    int monthdays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d = input;
    while (m > 1)
    {
        d = d - monthdays[m - 1];
        m--;
    }
    return d;
}
int week(int input)
{
    int w = input % 7 + 2;
    return w;
}