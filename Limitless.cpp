#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

void print_menu()
{
    cout<<"Limitless"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"1.Instructions"<<endl;
    cout<<"2.Choose mode"<<endl;
    cout<<"3.Play"<<endl;
    cout<<"--------------------"<<endl<<endl;
    cout<<"Enter a number: "<<endl<<endl<<endl;
}
void print_instructions()
{
    cout<<"INSTRUCTIONS"<<endl<<endl;
    cout<<"First of all,You have to choose 2 numbers as min and max.Then the computer will give you a number in range between those number.This is your start number."<<endl;
    cout<<"Rules:"<<endl;
    cout<<"Each turn,The computer will give you 2 numbers randomly.You have to choose one which will be added to your start number."<<endl;
    cout<<"REMEMBER: You have to pick before the time runs out to keep your start number in range between min and max or you will lose,so choose wisely"<<endl<<endl;
    cout<<"- Have fun - "<<endl<<endl;
}

int main()
{
    print_menu();
    return 0;
}