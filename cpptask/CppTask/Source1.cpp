//C++ codes for temperature sensor

#include <iostream>
#include <ctime> 
#include <Windows.h>
int Climate = 1;
using namespace std;
int Temp_values[30];

//Class declaration
class MyClass
{
public:
	void Idle();
	void Sensing();
	void Processing();
};

//Enumaration declaration
enum Condition
{
	MyIdel = 1,
	MySensing = 2,
	MyProcessing = 3,
};

// Main Function with switch statement
int main()
{
	MyClass myObj;
	while (1)
	{
		switch (Climate)
		{
		case 1:
			myObj.Idle();
			break;
		case 2:
			myObj.Sensing();
			break;
		case 3:
			myObj.Processing();
			break;
		}
	}

}

// Calling Sensing function
void MyClass:: Sensing()
{
	cout <<endl<< "Getting Data"<<endl<<endl;
	Sleep(1000);
	int i = 1;
	srand((unsigned)time(NULL));
	for (int i = 1; i < 30; i++)
	{
		Temp_values[i] = 1 + rand() % 10;
	}
	cout << "<<Changing state from Sensing to Processing>>" << endl << endl;
	Sleep(1000);
	Climate = 3;
}

// Calling Processing function
void MyClass:: Processing()
{
	cout << "Processing Please Wait" << endl << endl;
	Sleep(2000);
	int n, i;
	float sum = 0.0;
	float avg = 0.0;
	for (i = 0; i < 30; i++)
	{
		sum = sum + Temp_values[i];
	}
	avg = sum / 30;
	cout << "Average Temperature in Dublin =" << avg << " C"<<endl<<endl;
	cout << "<<Changing state from Processing to Idle>>" << endl << endl;
	Sleep(1000);
	Climate = 1;
}

//Calling Idle function
void MyClass:: Idle()
{
	string idle[10] = { "I", "D", "L", "E", " ", "S", "T", "A" ,"T", "E" };
	for (int i = 0; i < 10; i++)
	{
		cout << idle[i];
		Sleep(500);
		
	}
	cout << endl << endl;
	cout << "<<Changing state from Idle to Sensing>>" << endl << endl;
	Sleep(1000);
	Climate=2;
}






