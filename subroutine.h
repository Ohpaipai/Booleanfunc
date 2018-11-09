#pragma once
#include"booleanFunction.h"
using namespace std;
string readfilestring;//READ PLA STRING
bool IsP, Ise;//is p or e the last word of line
int temofp = 0,howmanyp;//to count .p item
BolleanFunction mytruth; //my data_structure
int head = 0;//in McCluskey head
int tail = 0; //in McCluskey tail
int countofmc = 0; //McCluskey next tail - head
string con[100000]; //McCluskey tem
set<string>mcfinal; //McCluskey final
bool iscoop = false; //is used for coopare
bool used = false;// is first to set
string tr;//my count mi
fstream ipfile; //myfile function
fstream opfile; //myfile function
string  outputfinal1[100001];


void Petricksmethod();//Petrick's method
void truthRecursion(string t, int nowwhere, int truth, int num); //recurison give truth table
void readmyfileofP(); //readfile if got p
void readmyfileoutofP(); //readfile if weren't get p
void McCluskeyalgorithm(int);//McCluskeyalgorithm
string tob(int num);//dec to bin
void comparestring(string, string);//string to look is gray code
void countbtod(int,string,int); //make 100- -->8,9

void readmyfileofP() {
	int whichoneoflogic = 0;
	bool IsIN = false;
	string temformula;
	temformula.clear();
	for (int i = 0; i <readfilestring.length(); i++)
	{
		if (readfilestring[i] != ' '&& readfilestring[i] != '¡@') {
			//input
			
			if (!IsIN)//first to do the truthtable
			{
				temformula += readfilestring[i];
				whichoneoflogic++;
				if (whichoneoflogic >= mytruth.gethowmanyin()) {
					whichoneoflogic = 0;
					IsIN = true;
				}
			}
			else //and give then truth
			{


				if (readfilestring[i] == '1') {
					int mynum = temformula.length();
					truthRecursion(temformula, mynum - 1,1,0);
				}
				else if (readfilestring[i] == '0') {
					int mynum = temformula.length();
					truthRecursion(temformula, mynum - 1, 0, 0);
				}
				else if (readfilestring[i] == '-') {
					int mynum = temformula.length();
					truthRecursion(temformula, mynum - 1, -1, 0);
				}
			}
		}

	}
}


void readmyfileoutofP() {
	for (int i = 0; i<readfilestring.length(); i++)
	{

		//kill space
		if (readfilestring[i] != ' ' || readfilestring[i] != '¡@') {
			//the head is .
			if (readfilestring[i] == '.') {
				//////
#pragma region i

				if (readfilestring[i + 1] == 'i' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '¡@')) {
					string temforpla;
					int howmanyinput = 0;//howmany input
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' '&& readfilestring[j] != '¡@') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' ' && readfilestring[k] != '¡@')
									temforpla += readfilestring[k];
								else break;
							}
							break;
						}
					}
					tem << temforpla;
					tem >> howmanyinput;//howmany input
					mytruth.inputin(howmanyinput);
					for (int i = 0; i < pow(2,mytruth.gethowmanyin()); i++)
					{
						mytruth.givemiofout(i,0);
					}
					break;
				}
#pragma endregion
				//////
#pragma region o
				else if (readfilestring[i + 1] == 'o' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '¡@')) {//o
					string temforpla;
					int howmanyouput = 0;//howmany input
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' ' && readfilestring[j] != '¡@') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' ' && readfilestring[k] != '¡@')
									temforpla += readfilestring[k];
								else break;
							}
							break;
						}
					}
					tem << temforpla;
					tem >> howmanyouput;
					mytruth.outputin(howmanyouput);
					break;

				}
#pragma endregion
				//////
#pragma region e
				else if (readfilestring[i + 1] == 'e' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '¡@')) {
					Ise = true;//this program is over
					break;
				}
#pragma endregion
				//////
#pragma region p
				else if (readfilestring[i + 1] == 'p' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '¡@')) {
					string temforpla;
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' '&&readfilestring[j] != '¡@') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' '&& readfilestring[k] != '¡@')
									temforpla += readfilestring[k];
								else break;
							}
							break;
						}
					}
					tem << temforpla;
					tem >> howmanyp;//howmany p
					temofp = howmanyp;
					IsP = true;//the next input is p
					break;
				}
#pragma endregion
				//////
#pragma region ilb
				else if (readfilestring[i + 1] == 'i' && readfilestring[i + 2] == 'l'&& readfilestring[i + 3] == 'b' && (readfilestring[i + 4] == ' ' || readfilestring[i + 4] == '¡@')) {
					int tocountin = 0;
					for (int j = i + 5; j < readfilestring.length(); j++)//howmany number
					{

						if (readfilestring[j] != ' ' && readfilestring[j] != '¡@') {
							if (tocountin >= mytruth.gethowmanyin()) break;
							else {
								mytruth.givename(readfilestring[j], tocountin);//give name to inputnmae matrix
								tocountin += 1;
							}
						}
					}
					break;
				}

#pragma endregion
				//////
#pragma region ob
				else if (readfilestring[i + 1] == 'o' && readfilestring[i + 2] == 'b' && (readfilestring[i + 3] == ' ' || readfilestring[i + 3] == '¡@')) {
					int tocountout = 0;
					for (int j = i + 4; j < readfilestring.length(); j++)//howmany number
					{

						if (readfilestring[j] != ' ' && readfilestring[j] != '¡@') {
							if (tocountout >= mytruth.gethowmanyout()) break;
							else {
								mytruth.giveoutputname(readfilestring[j]);//give output name to outputname matrix
								break;
							}
						}
					}
					break;
				}
#pragma endregion
				/////
			}
			//to process "//"
			else if (readfilestring[i] == '/'&&readfilestring[i + 1] == '/') break;
		}

	}
}


void truthRecursion(string t, int nowwhere, int truth,int num) {
	if (nowwhere < 0) {
		mytruth.givemiofout(num, truth);
		return;
	}
	else {
		if (t[nowwhere] == '0') {
			truthRecursion(t, nowwhere - 1, truth, num);
		}
		else if (t[nowwhere] == '1') {
			num += pow(2, mytruth.gethowmanyin() - 1 - nowwhere);
			truthRecursion(t, nowwhere - 1, truth, num);
			num-= pow(2, mytruth.gethowmanyin() - 1 - nowwhere);
		}
		else if (t[nowwhere] == '-') {
			num += pow(2, mytruth.gethowmanyin() - 1 - nowwhere);
			truthRecursion(t, nowwhere - 1, truth, num);
			num -= pow(2, mytruth.gethowmanyin() - 1 - nowwhere);
			truthRecursion(t, nowwhere - 1, truth, num);
		}
	}
}


void McCluskeyalgorithm(int time) {
	if (time <=1) {
		for (int i =head; i <tail; i++)
		{
			//cout << con[i] << endl;
			mcfinal.insert(con[i]);
		}
		//cout << endl;
		set<string>::iterator it;
		for ( it = mcfinal.begin(); it !=mcfinal.end(); it++)
		{
			//cout << *it << endl;
			
			tr.clear();
			tr = "";
			countbtod(0,*it,0);
			mytruth.setmapoftruth(*it,tr);
			//cout << mytruth.numofpatric << endl;
		}
		return;
	}
	else {
		for (int i = head; i < tail; i++)
		{
			iscoop = false;
			
			for (int j =head; j < tail; j++)
			{
				if (i == j) {}
				else comparestring(con[i], con[j]);
			}

			if (iscoop == false){
				if (used==true) {
					set<string>::iterator it;
					int d = 0;
					for (it = mcfinal.begin(); it != mcfinal.end(); it++)
					{
						string a = *it;
						for (int k = 0; k <mytruth.gethowmanyin(); k++)
						{
							if (con[i][k] != a[k]) d++;
						}
					}
					if (d>1) mcfinal.insert(con[i]);

				}
				else {
					mcfinal.insert(con[i]);
					used = true;
				}
			}
		}
		head = tail;
		tail = countofmc;
		McCluskeyalgorithm(--time);
	}
}


string tob(int num) {
	string r,rr;
	rr.clear();
	r.clear();
	 bitset<sizeof(num)*8>s(num);
	 r = s.to_string();
	 for (int i = r.length()-1,j=0; i >=0&&j<mytruth.gethowmanyin(); i--,j++)
	 {
		 rr += r[i];
	 }
	 reverse(rr.begin(), rr.end());
	 return rr;
}

void countbtod(int time,string c,int num){
	if (time >= mytruth.gethowmanyin()) {
		stringstream ss;
		string d;
		ss << num;
		ss >> d;

		if (tr== "") {
			bool ind = false;
			for (int i = 0; i <mytruth.gethowmanydontcare(); i++)
			{
				//cout << "test:" << mytruth.getdontcarenum(i) << endl;
				if (num == mytruth.getdontcarenum(i)) {
					ind = true;
					break;
				}
			}
			if (ind == false) {
				tr += d;
				mynumoftruth.insert(d);
			
			}
		}
		else {
			bool ind = false;
			for (int i = 0; i <mytruth.gethowmanydontcare(); i++)
			{
				
				if (num == mytruth.getdontcarenum(i)) {
					ind = true;
					break;
				}
			}
			if (ind==false) {
				tr += ",";
				tr += d;
				mynumoftruth.insert(d);
			}
			
		}
	}
	else {
		if (c[time] == '0') {
			countbtod(time + 1, c, num);
		}
		else if (c[ time] == '1')
		{
			num += pow(2, mytruth.gethowmanyin() - 1 - time);
			countbtod( time + 1, c, num);
			num-= pow(2, mytruth.gethowmanyin() - 1 - time);
		}
		else if (c[time] == '-') {
			num += pow(2, mytruth.gethowmanyin() - 1 - time);
			countbtod( time + 1, c, num);
			num -= pow(2, mytruth.gethowmanyin() - 1 - time);
			countbtod( time + 1, c, num);
		}
	}
}


void comparestring(string a, string b){

	int d = 0;
	for (int i = 0; i <a.length(); i++)
	{
		if (a[i] != b[i]) d++;
	}

	if(d==1){
		for (int i = 0; i <a.length(); i++)
		{
			if (a[i] != b[i]) con[countofmc]+='-';
			else con[countofmc] += a[i];
			
		}
		countofmc++;
		iscoop = true;
	}
}


void Petricksmethod(){
	set<string>::iterator it;
	opfile.open("opfile.txt", ios::out);
#pragma region todoPAtrick
	for (it = mynumoftruth.begin(); it != mynumoftruth.end(); it++)
	{
		string ans;
		set<string>::iterator it2;
		for (it2 = mcfinal.begin(); it2 != mcfinal.end(); it2++)
		{
			//cout << *it2 << "  " << mytruth.getmapofpatric(*it2) << endl;;
			string a;
			a = mytruth.getmapoftruth(*it2);
			string ttt = "";
			for (int i = 0; i < a.length(); i++)
			{
				if (i + 1 == a.length())
				{
					ttt += a[i];
					if (ttt == *it) {
						opfile << mytruth.getmapofpatric(*it2)<<"+";

						break;
					}
					ttt.clear();
					ttt = "";

				}
				else if (a[i] == ',') {
					if (ttt == *it) {
						opfile << mytruth.getmapofpatric(*it2)<<"+";

						break;
					}
					ttt.clear();
					ttt = "";

				}
				else {
					if (a[i] != ' ' || a[i] != ',')
						ttt += a[i];
				}
			}


		}
		opfile << endl;
	}
#pragma endregion
#pragma region firstdecrease
	opfile.close();
	ipfile.open("opfile.txt", ios::in);
	bool canmodify = false;
	string readofopfile;
	string mainofmyfunction = "";
	string dous = "";
	short timeofp = 0;
	while (getline(ipfile, readofopfile)) {
		timeofp++;
		string lkk;
		if (timeofp % 2 == 0 || canmodify == true) {
			int timeoftime = 0;
			for (int i = 0; i < mainofmyfunction.length(); i++)
			{
				if (mainofmyfunction[i] == '+') {
					string lkp;
					for (int k = 0; k < readofopfile.length(); k++)
					{
						if (readofopfile[k] == '+') {

							dous += lkk + lkp + "+";


							lkp.clear();
							lkp = "";
						}
						else lkp += readofopfile[k];

					}
					lkk.clear();
					lkk = "";
				}
				else lkk += mainofmyfunction[i];

			}//end of main;
			canmodify = true;
			mainofmyfunction = dous;
#pragma endregion

#pragma region realdecration
			//to decoreation
			string getcom;
			string finalll;
			for (int y = 0; y < mainofmyfunction.length(); y++)
			{
				if (mainofmyfunction[y] == '+') {
					set<int>rr;
					for (int i1 = 0; i1 < getcom.length(); i1++)
					{
						for (int i2 = i1 + 1; i2 < getcom.length(); i2++)
						{
							if (getcom[i1] == getcom[i2]) {
								rr.insert(i2);
							}
						}
					}
					for (int i1 = 0; i1 < getcom.length(); i1++)
					{
						if (!rr.count(i1))
						{
							finalll += getcom[i1];
						}
					}
					finalll += '+';
					rr.clear();
					getcom.clear();
				}
				else {
					getcom += mainofmyfunction[y];
				}
			}
			mainofmyfunction = finalll;
			//
			dous.clear();
			dous = "";
		}
		else {
			mainofmyfunction = readofopfile;
		}
	}
	//cout << mainofmyfunction << endl;
	ipfile.close();
#pragma endregion

		//output
#pragma region chosewhicout
	string fout;
	int tocount = 0;
	int small = 9999;

	for (int i6 = 0; i6 < mainofmyfunction.length(); i6++)
	{
		if (mainofmyfunction[i6] == '+') {
			if (fout.length() < small) {
				small = fout.length();
				for (int p = 0; p < tocount; p++)
				{
					outputfinal1[p] = "";
				}
				tocount = 0;
				outputfinal1[tocount++] = fout;
				fout.clear();
				fout = "";
			}
			else if (fout.length() == small) {
				outputfinal1[tocount++] = fout;
				fout.clear();
				fout = "";
			}
			else {
				fout.clear();
				fout = "";
			}
		}
		else if (mainofmyfunction[i6] != '+')fout += mainofmyfunction[i6];
	}
	int smallofout = 999;
	string ouputpla = "";
	for (int p = 0; p < tocount; p++)
	{
		//cout << *it << endl;
		string iii = outputfinal1[p];
		int a = 0;
		for (int z = 0; z < iii.length(); z++)
		{
			a += mytruth.resent(iii[z]);
		}
		if (smallofout > a) {
			smallofout = a;
			ouputpla = iii;
		}
	}
#pragma endregion

		//cout << ouputpla << endl;
		//realout
		cout << "Total number of terms: " << ouputpla.length() << endl;
		cout << "Total number of literals: " << smallofout << endl;
		//cout << ".i " << mytruth.gethowmanyin() << endl;
		ofile<< ".i " << mytruth.gethowmanyin() << endl;
		//cout << ".o " << mytruth.gethowmanyout() << endl;
		ofile<< ".o " << mytruth.gethowmanyout() << endl;
		//cout << ".ilb ";
		/*for (int s = 0; s <mytruth.gethowmanyin(); s++)
		{
			if (s + 1 == mytruth.gethowmanyin()) {
				cout << mytruth.getmyname(s);
			}
			else {
				cout << mytruth.getmyname(s)<<" ";
			}
		}
		cout << endl;*/
		ofile << ".ilb ";
		for (int s = 0; s <mytruth.gethowmanyin(); s++)
		{
			if (s + 1 == mytruth.gethowmanyin()) {
				ofile << mytruth.getmyname(s);
			}
			else {
				ofile << mytruth.getmyname(s) << " ";
			}
		}
		ofile << endl;
		//cout << ".ob " << mytruth.getmynameout() << endl;
		ofile << ".ob " << mytruth.getmynameout() << endl;
		//cout << ".p " << ouputpla.length() << endl;
		ofile << ".p " << ouputpla.length() << endl;
		for (int i = 0; i < ouputpla.length(); i++)
		{
			mytruth.resetpla(ouputpla[i]);
			//cout << " 1" << endl;
			ofile <<" 1" <<endl;
		}
		//cout << ".e" << endl;
		ofile << ".e"  << endl;
		

		
}




		