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
set<string>mynumoftruth;
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
	void setmapoftruth(string, string); //set 1001--> K L M N
	char getmapofpatric(string); //GET MY K L M N
	string getmapoftruth(string);//GET 100- ->8,9
	static int numofpatric;//K L M ....
	int gethowmanydontcare() { //get howmany don't care
		return howmanydontcare;
	}
	int getdontcarenum(int a) {//get don't care
		return dontcare[a];
	}
	set<string>patricnum;
private:
	int fofboolean[1024] = {0};//my truthtable
	char numbername[10] = { 0 }; //myinpuat name
	int dontcare[1024] = { 0 };
	int howmanydontcare =0 ;
	char outname;//my outpuatname
	int howmanyin;//input number
	int howmanyout;//output number 
	map<string,string>mymap;
	map<string, char>mymapofpatrick;
	
};

int BolleanFunction::numofpatric = 75;

BolleanFunction::BolleanFunction()
{
	
	outname = 0;
	howmanyin = 0;
	howmanyout =0;
	howmanydontcare = 0;
	
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
	howmanydontcare = 0;
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
	if (o == -1) {
		dontcare[howmanydontcare] = i;
		howmanydontcare++;
	}

}

void BolleanFunction::setmapoftruth(string b,string t) {
	mymap.insert(pair<string, string>(b,t));
	string a;
	for (int i = 0; i < howmanyin; i++)
	{
		if (b[i] != '-') {
			if (b[i] == '0') a += toupper(numbername[i]);
			else if (b[i] == '1') a += tolower(numbername[i]);
		}
	}
	mymapofpatrick.insert(pair<string,char>(a,numofpatric++));
	
}


string BolleanFunction::getmapoftruth(string a) {
	map<string,string>::iterator it;
	it = mymap.find(a);
	return it->second;
}


char BolleanFunction::getmapofpatric(string b) {
	map<string, char>::iterator it;
	string a;
	for (int i = 0; i < howmanyin; i++)
	{
		if (b[i] != '-') {
			if (b[i] == '0') a += toupper(numbername[i]);
			else if (b[i] == '1') a += tolower(numbername[i]);
		}
	}
	it = mymapofpatrick.find(a);
	return it->second;
}