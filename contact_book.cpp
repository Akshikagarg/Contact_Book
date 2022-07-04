#include<iostream>
#include <fstream>             //File handling
#include <sstream>             //Allows a string object to be treated as a stream
#include "Functions.cpp"
using namespace std;
#define ll long long

int main()
{   
    Contact_Book MyContactBook;
    MyContactBook.reopen();
	string name;
	cout<<" ENTER YOUR NAME: "; cin>>name;
	
    cout<<"***********"<<endl;
	cout<<" WELCOME TO CONTACTBOOK "<<name<<"!"<<endl;
	cout<<"***********"<<endl;
	MyContactBook.Structure();
	return 0;
}

// code by AKSHIKA GARG
