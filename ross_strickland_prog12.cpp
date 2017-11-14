#include <iostream>

//author Ross Strickland
//Lab12
//11/14/17

using namespace std;

//functions
int factorial(int n);
int fib(int sent);

int main()
{
    int in; //factorial stuff
    cout << "Input a number to find a factorial of: ";
    cin >> in;
    cout <<endl<< "Factorial of "<<in<<" is "<<factorial(in)<<"!"<<endl;

    int n;
    cout << "Input how many fibonacci numbers you want generated: ";
    cin >> n;
    cout <<endl<< "Fib Seq: ";
    for(int i=0;i<n;i++)
        cout << fib(i)<<" ";
    return 0;
}

int factorial(int n) //returns factorial of n
{
    if(n<=1)
        return 1;
    else
        return (n*factorial(n-1));
}

int fib(int sent)
{
    if(sent==0)
        return 0;
    else if(sent==1)
        return 1;
    else
        return fib(sent-1) + fib(sent-2);
}
//fib(3)
//fib(2) + fib(1)
//fib(1) + fib(0) + 1
//1 + 0 + 1
