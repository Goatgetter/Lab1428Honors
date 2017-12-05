#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

//function prototypes
bool betFunc(int &myMoney, int &bet);
void getRolls(int &compDie1, int &userDie1);
void results(int &compDie1, int &userDie1,int &myMoney,int &betAmount);

int main(){

    srand(time(NULL));
    rand() % 6+1 ;
    int myMoney= 1000;
    cout << "Gambling is an addiction..."<<endl;
    char ender = 'y';
    do{
        int bet;
        int compDie1= rand() % 6+1;
        int userDie1= rand() % 6+1;
        if(betFunc(myMoney,bet))
            return -1;
        getRolls(compDie1,userDie1);
        results(compDie1,userDie1,myMoney,bet);
        if(myMoney<=0)
        {
            cout << "You ran out of money :(";
            ender=='n';
        }
        else{
        cout <<endl<<"Would you like to continue? ('y' or 'n')";
        cin >>ender;}
    }while(ender=='y');
    cout <<endl<< "You ended with $"<<myMoney;
}

bool betFunc(int &myMoney,int &bet)
{
    cout<< "You currently have $"<<myMoney<<endl;
    cout<< "How much do you bet?"<<endl<<"$";
    cin >> bet;
    if(bet>myMoney)
        {cout << "Error: You don't have that much money!";
        return true;}
    return false;
}

void getRolls(int &compDie1,int &userDie1)
{
    cout <<endl<<"You rolled a "<<userDie1<<endl;
    cout <<"Your opponent rolled a "<<compDie1<<endl;
}

void results(int &compDie1,int &userDie1,int &myMoney,int &betAmount)
{
    if(compDie1>userDie1)
    {
        cout << "You lose $"<<betAmount;
        myMoney-=betAmount;
    }
    else if(compDie1<userDie1)
    {
        cout << "You gain $"<<betAmount;
        myMoney+=betAmount;
    }
    else
    {
        cout << "You tied! Everyone's money stays the same!";
    }
}
