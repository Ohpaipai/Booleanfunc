#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<math.h>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<bitset>
using namespace std;
class BolleanFunction
{
public:
	BolleanFunction();//constructer
	~BolleanFunction();//destructure
	void inputin(int manyin);//intput howmanyinput
	void outputin(int manyout);//intput howmany output
	void givename(char name,int i);//give every input aname
	void giveoutputname(char name);//give output name
	void givemiofout(int i, int o);//to set my truthable
	int gethowmanyin();//get howmanyin
	int gethowmanyout();//get howmnayout
	int getmiofout(int i);//get mytruthtabla
	void setmapoftruth(string, int);
	int getmapoftruth(string);
	
private:
	int fofboolean[999];//my truthtable
	char numbername[10]; //myinpuat name
	char outname;//my outpuatname
	int howmanyin;//input number
	int howmanyout;//output number 
	map<string, int>mymap;
};

BolleanFunction::BolleanFunction()
{
	
	outname = 0;
	howmanyin = 0;
	howmanyout =0;
}

//to know howmany table 
void BolleanFunction::inputin(int manyin){
	
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

void BolleanFunction::givemiofout(int i, int o) {
	fofboolean[i] = o;

}

void BolleanFunction::setmapoftruth(string b, int t) {
	mymap.insert(pair<string, int>(b, t));
}


int BolleanFunction::getmapoftruth(string a) {
	map<string, int>::iterator it;
	it = mymap.find(a);
	return it->second;
}
