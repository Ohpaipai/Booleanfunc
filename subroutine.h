#pragma once
#include"booleanFunction.h"
using namespace std;
fstream ifile;
fstream ofile;
string readfilestring;
bool IsP, Ise;//is p or e the last word of line
int temofp = 0,howmanyp;//to count .p item
BolleanFunction mytruth; //my data_structure
int head = 0;//in McCluskey head
int tail = 0; //in McCluskey tail
int countofmc = 0; //McCluskey next tail - head
string con[100]; //McCluskey tem
set<string>mcfinal; //McCluskey final
bool iscoop = false; //is used for coopare
bool used = false;// is first to set
string tr;//my count mi
string patricstr;


void Petricksmethod();//Petrick's method
void truthRecursion(string t, int nowwhere, int truth, int num); //recurison give truth table
void readmyfileofP(); //readfile if got p
void readmyfileoutofP(); //readfile if weren't get p
void McCluskeyalgorithm(int);//McCluskeyalgorithm
string tob(int num);//dec to bin
void comparestring(string, string);//string to look is gray code
void countbtod(int,string,int);


void readmyfileofP() {
	int whichoneoflogic = 0;
	bool IsIN = false;
	string temformula;
	temformula.clear();
	for (int i = 0; i <readfilestring.length(); i++)
	{
		if (readfilestring[i] != ' '&& readfilestring[i] != '　') {
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
		if (readfilestring[i] != ' ' || readfilestring[i] != '　') {
			//the head is .
			if (readfilestring[i] == '.') {
				//////
#pragma region i

				if (readfilestring[i + 1] == 'i' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '　')) {
					string temforpla;
					int howmanyinput = 0;//howmany input
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' '&& readfilestring[j] != '　') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' ' && readfilestring[k] != '　')
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
				else if (readfilestring[i + 1] == 'o' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '　')) {//o
					string temforpla;
					int howmanyouput = 0;//howmany input
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' ' && readfilestring[j] != '　') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' ' && readfilestring[k] != '　')
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
				else if (readfilestring[i + 1] == 'e' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '　')) {
					Ise = true;//this program is over
					break;
				}
#pragma endregion
				//////
#pragma region p
				else if (readfilestring[i + 1] == 'p' && (readfilestring[i + 2] == ' ' || readfilestring[i + 2] == '　')) {
					string temforpla;
					temforpla.clear();//clear
					stringstream tem;
					tem.str("");//clear
					tem.clear();
					for (int j = i + 2; j < readfilestring.length(); j++)//howmany number
					{
						if (readfilestring[j] != ' '&&readfilestring[j] != '　') {
							for (int k = j; k < readfilestring.length(); k++)
							{
								if (readfilestring[k] != ' '&& readfilestring[k] != '　')
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
				else if (readfilestring[i + 1] == 'i' && readfilestring[i + 2] == 'l'&& readfilestring[i + 3] == 'b' && (readfilestring[i + 4] == ' ' || readfilestring[i + 4] == '　')) {
					int tocountin = 0;
					for (int j = i + 5; j < readfilestring.length(); j++)//howmany number
					{

						if (readfilestring[j] != ' ' && readfilestring[j] != '　') {
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
				else if (readfilestring[i + 1] == 'o' && readfilestring[i + 2] == 'b' && (readfilestring[i + 3] == ' ' || readfilestring[i + 3] == '　')) {
					int tocountout = 0;
					for (int j = i + 4; j < readfilestring.length(); j++)//howmany number
					{

						if (readfilestring[j] != ' ' && readfilestring[j] != '　') {
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
	//用數字去尋找我的klmn放到檔案作畫檢 放在set裡面 boolean 裡面有public建好set 在 countbtod做 (把map中資料結構delete(string,string)的
	set<string>::iterator it;
	for (it = mcfinal.begin(); it != mcfinal.end(); it++)
	{
		
	}
}

		