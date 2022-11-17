#ifndef MACHINE_H
#define MACHINE_H
#include <string>
#include <iostream>
#include "Sensor.h"
#include <cmath>

using namespace std;

class Machine
{
	public:
		Machine(const Sensor &,const Sensor &,double PPV=0.0,double AF=0.0,double BF=0.0);
		double getPPV() const;
		double getAF() const;
		double getBF() const;
		void print() const;
		void calculateMachineStats();
		bool compare(const Machine &);
	private:
		const Sensor s1;
		const Sensor s2;
		double PPV;
		double AF;
		double BF;
		double getMax(double,double) const;
		double getMin(double,double) const;
};

#endif
