#include <iostream>
using namespace std;

//function prototypes
bool IsPrime(int a);
bool CycleContains(int a);
bool IsHappy(int a);
void SelectionSort();
bool AddToCycle(int a);
//global variables
int ary[20] = {0};

int main()
{
    int test;
    cout << "What number do you wanna test? ";
    cin >> test;
    cout <<endl<< test<<" is ";
    if(IsHappy(test)){cout <<"a Happy";} else{cout <<"an Unhappy";}
    if(IsPrime(test)){cout <<" Prime";} else{cout <<" Non-Prime";}
    cout<<endl;
    cout<<endl;
}

bool IsPrime(int a)
{
    for(int i=2;i<a;i++)
        if((a%i)==0) return false;
    return true;
}

bool CycleContains(int a)
{
    for(int i=0;i<20;i++)
        if(ary[i]==a) return true;
    return false;
}

void SelectionSort()
{
    for(int i=0;i<20;i++) //this loop pushes through the array
    {
        int minval=ary[i]; //lowest value
        int minloc=i; //lowest value location
        for(int j=i;j<20;j++) //this loop finds lowest value within remainder of array
        {
            if(ary[j]<minval)
            {
                minval=ary[j];
                minloc=j;
            }
        }
        int swappy=ary[i]; //the swap
        ary[i]=ary[minloc];
        ary[minloc]=swappy;
    }
}

bool AddToCycle(int a) //if true, it's not in there, if false it's in there already or we're full
{
    bool en=true; //to end
    if(CycleContains(a)){return false;} //if it's in the array already returns false
    for(int i=0;i<20;i++)
    if(ary[i]==0){ary[i]=a;SelectionSort();return true;} //if it's not then it adds it in the zero spot
    return false;
}

bool IsHappy(int a) //tests happiness
{
    int sum=0;
    while(a>=10)
    {
        sum+= (a%10)*(a%10);
        a/=10;
    }
    if(sum==1){return true;} //executes if it's a happy number
    else if(AddToCycle(sum)){return IsHappy(sum);} //executes if number is new and theres still space in the array.
    else {return false;} //only executes if ATC returns false because array is overloaded or num appears twice.
}
