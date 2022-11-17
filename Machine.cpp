#include "Machine.h"
#include "Sensor.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

Machine::Machine(const Sensor &s1,const Sensor &s2,double PPV,double AF,double BF):s1(s1),s2(s2),PPV(PPV),AF(AF),BF(BF)
{
}

double Machine::getPPV() const
{
	return PPV;
}
double Machine::getAF() const
{
	return AF;
}
double Machine::getBF() const
{
	return BF;
}
void Machine::print() const
{
	cout<<"PPV: "<<getPPV()<<endl;
	cout<<"AF: "<<getAF()<<endl;
	cout<<"BF: "<<getBF()<<endl;
}
double Machine::getMax(double s1,double s2) const
{
	double max=std::max(s1,s2);
	return max;
}
double Machine::getMin(double s1,double s2) const
{
	double min=std::min(s1,s2);
	return min;
}

void Machine::calculateMachineStats()
{
	PPV=(getMax(s1.getRMS(),s2.getRMS()))-(getMin(s1.getRMS(),s2.getRMS()));
	AF=(getMax(s1.getRMS(),s2.getRMS()))/(getMin(s1.getSRA(),s2.getSRA()));
	BF=(getMax(s1.getSRA(),s2.getSRA()))/(getMin(s1.getRMS(),s2.getRMS()));
}

bool Machine::compare(const Machine &f)
{
	if(abs(f.getPPV()-getPPV()) < 0.5 && abs(f.getAF()-getAF()) < 0.5 && abs(f.getBF()-getBF()) < 0.5 )
		return 1;
	else
		return 0;
}




