#include"subroutine.h"
int main(int argc, char *argv[])
{
	//ifile.open(argv[1], ios::in );//inputfile cmd
	//ofile.open(argv[2], ios::out);//outputfile cmd
	ifile.open("input.pla", ios::in);//input test
	//ofile.open("output.dot", ios::out);//output test
	while (getline(ifile,readfilestring))//read a line once again
	{
		if (IsP)
		{
			readmyfileofP();//process my file
			temofp -= 1;
			if (temofp <= 0) IsP = false;
		}
		else
			readmyfileoutofP();//process my file
		if (Ise) break;//the end of the file
	}
	head = 0;
	tail = pow(2,mytruth.gethowmanyin());
	int jt = 0;
	for (int i = 0; i < tail; i++)
	{
		if (mytruth.getmiofout(i) == 1 || mytruth.getmiofout(i) == -1)
		{
			//cout << i << endl;
			con[jt] = tob(i);
			//cout << con[jt] << endl;
			jt++;
		}
	}
	
	tail = jt;
	countofmc = tail;
	head = 0;
	mcfinal.clear();
	McCluskeyalgorithm(mytruth.gethowmanyin());
	ifile.close();
	//ofile.close();
	system("PAUSE");
	return 0;
}
