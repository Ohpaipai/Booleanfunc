#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
class BolleanFunction
{
public:
	BolleanFunction();
	~BolleanFunction();
	void inputin(int manyin);
	void outputin(int manyout);
	void givename(char name,int i);
	void giveoutputname(char name);
	void givemiofout(int i, char o);
	int gethowmanyin();
	int gethowmanyout();
	int getmiofout(int i);
private:
	int *fofboolean;
	char *numbername;
	char outname;
	int howmanyin;
	int howmanyout;
};

BolleanFunction::BolleanFunction()
{
	fofboolean = nullptr;
	numbername = nullptr;
	outname = 0;
	howmanyin = 0;
	howmanyout =0;
}

//to know howmany table 
void BolleanFunction::inputin(int manyin){
	fofboolean = new int(pow(2,manyin));
	numbername = new char(manyin);
	howmanyin = manyin;
}

//to know howmany output
void BolleanFunction::outputin(int manyout){
	howmanyout = manyout;
	
}

void BolleanFunction::givename(char name, int i) {
	numbername[i] = name;
}

BolleanFunction::~BolleanFunction()
{
	delete fofboolean;
	delete numbername;
	outname = 0;
	howmanyin = 0;
	howmanyout = 0;
}

int BolleanFunction::gethowmanyin() {
	return howmanyin;
}

int BolleanFunction::gethowmanyout() {
	return howmanyout;
}

int BolleanFunction::getmiofout(int i) {
	return fofboolean[i];
}

void BolleanFunction::giveoutputname(char name) {
	outname = name;
}

void BolleanFunction::givemiofout(int i, char o) {
	if (o == '1') {
		fofboolean[i] = 1;
	}
	else if (o == '0') {
		fofboolean[i] = 0;
	}
	else if (o == '-') {
		fofboolean[i] = -1;
	}
}