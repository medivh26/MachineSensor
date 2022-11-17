#include "Sensor.h"
#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

Sensor::Sensor(string id,double T1,double T2,double T3,double rms,double sra):RMS(rms),SRA(sra)
{
	setT1(T1);
	setT2(T2);
	setT3(T3);
	setID(id);
	cout<<"Sensor Object Constructor for: "<<getID()<<endl;
}
void Sensor::setT1(double T1)
{
	if(T1<=1 && T1>=-1){
		t1=T1;
	}
	else
		throw std::invalid_argument("Invalid syntax.");
}
void Sensor::setT2(double T2)
{
	if(T2<=1 && T2>=-1){
		t2=T2;
	}
	else
		throw std::invalid_argument("Invalid syntax.");
}
void Sensor::setT3(double T3)
{
	if(T3<=1 && T3>=-1){
		t3=T3;
	}
	else
		throw std::invalid_argument("Invalid syntax.");
}
void Sensor::setID(string id)
{
	ID=id;
}
double Sensor::getT1(void) const
{
	return t1;
}
double Sensor::getT2(void) const
{
	return t2;
}
double Sensor::getT3(void) const
{
	return t3;
}
double Sensor::getRMS(void) const
{
	return RMS;
}
double Sensor::getSRA(void) const
{
	return SRA;
}
string Sensor::getID(void) const
{
	return ID;
}
void Sensor::calculateSensorStats()
{
	RMS=sqrt((1.0/3.0)*(pow(getT1(),2)+pow(getT2(),2)+pow(getT3(),2)));
	SRA=pow((1.0/3.0)*(sqrt(abs(getT1()))+sqrt(abs(getT2()))+sqrt(abs(getT3()))),2);
}

void Sensor::print() const
{
	cout<<getID()<<"***"<<getT1()<<"  "<<getT2()<<"  "<<getT3()<<"***"<<getRMS()<<","<<getSRA()<<endl;
}





