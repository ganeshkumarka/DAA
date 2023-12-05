#include <iostream>
using namespace std;
int Fibonacci(int N)
{
    int fib[N + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[N];
}

int main()
{
    int n;
    cout << "Enter n to calculate nth fibonacci term: ";
    cin >> n;
    int fib = Fibonacci(n);
    cout << "nth Fibonacci term: " << fib << endl;
    return 0;
}