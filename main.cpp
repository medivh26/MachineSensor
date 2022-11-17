#include <iostream>
#include <string>
#include "Sensor.h"
#include "Machine.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Sensor ID1("ID1",-1,0,1);
	ID1.calculateSensorStats();
	ID1.print();
	
	Sensor ID2("ID2",-0.8,0.1,0.6);
	ID2.calculateSensorStats();
	ID2.print();
	
	Sensor ID3("ID3",-0.7,-0.2,0.5);
	ID3.calculateSensorStats();
	ID3.print();
	
	cout<<endl;
	
	Machine A(ID1,ID2);
	A.calculateMachineStats();
	A.print();
	
	cout<<endl;
	
	Machine B(ID1,ID3);
	B.calculateMachineStats();
	B.print();
	
	if(A.compare(B)){
		cout << endl << "Machine A is OK " << endl;
	}	
	else{
		cout << endl << "Machine B is OK " << endl;
	}
	
	const Sensor ID4("ID4",0,0.3,5,0,0);  
	ID4.print();
	
	return 0;
}
