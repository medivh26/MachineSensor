#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <iostream>

using namespace std;

class Sensor
{
	public:
		Sensor(string id,double T1=0.0,double T2=0.0,double T3=0.0,double rms=0,double sra=0);
		void setT1(double);
		void setT2(double);
		void setT3(double);
		void setID(string);
		double getT1(void) const;
		double getT2(void) const;
		double getT3(void) const;
		double getRMS(void) const;
		double getSRA(void) const;
		string getID(void) const;
		void calculateSensorStats();
		void print() const;
	private:
		double t1;
		double t2;
		double t3;
		double RMS;
		double SRA;
		string ID;
};

#endif
