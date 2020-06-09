#include <iostream>
#include <fstream> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
using std::string;
void Printall(string words[], string name, int number);
void input(string words[], string name, int number);
void remove(string word[], char letter, int number);
void Print(string words[], int number);
void entercharacter(char &b);
int randomnumber();


int main(int argc, char const *argv[])
{	
	if(argc==4)
	{
		int com= 0;
		com = atoi(argv[3]);
		int num= 1;
		num = atoi(argv[2]);
		string a[num];
		input(a,argv[1],num);
		if(com==1)
		{
			
			Printall(a, argv[1], num);
		}
		else if (com==2)
		{
			cout << "Word length: " << randomnumber()<< endl;
			char b ='a';
			entercharacter(b);
			remove(a, b, num );
			Print(a, num);

		} 
		else if (com==3)
		{
			int rnumber = randomnumber();
			cout << "Word length: " << rnumber << endl;
			
			for (int i=0; i < 5; i++)
			{
				char b ='a';
				entercharacter(b);
				remove(a, b, num );
			}
			for (int i =0 ; i< num-1 ; i++)
			{

		
				if(a[i]!=" " && a[i][rnumber-1]!=0 && a[i][rnumber]==0)
				{
					cout << "You have lost the game, following was the word: " << "\"" << a[i] << "\"" << endl;
					
					break;
				}
			}
			


			

		} 


	}
	else 
	{
		return 0;
	}
	/*srand(time(0));
	string a[65197];
	input(a,"english.txt",65197);
	int rnumber = rand()%4 + 3; 
	cout << "Word length is " << rnumber << endl ; 
	string letter;
	for (int i=0; i < rnumber; i++)
	{
		cout << "Enter character" << endl;
		cin >> letter;
		if (letter[1]!=0)
		{
			cout<< "You have entered more than one characters, please try again" << endl;
			main();
		} 
		else
		{
			remove(a,letter[0],65197);
		}
	}
	for (int i =0 ; i< 65197-1 ; i++)
	{
		
		if(a[i]!="0")
		{
			cout << "The word was: " << a[i] << endl;
			break;
		}
	}*/

}
void Printall(string words[], string name, int number)
{
	ifstream x;
	x.open(name.c_str());
	for (int i =0 ; i< number ; i++)
	{
		x>> words[i];
		cout << words[i] << endl;
	}
}
void input(string words[], string name, int number)
{
	ifstream x;
	x.open(name.c_str());
	for (int i =0 ; i< number; i++)
	{
		x>> words[i];
	}
}

void remove(string word[], char letter, int number)
{
	for (int i =0 ; i< number; i++)
	{
		int j=0;
		while (word[i][j]!= 0)
		{
			if(word[i][j]==letter)
			{
				word[i]=" ";
			}

			j++;
		}
	}
}
void Print(string words[], int number)
{
	for (int i =0 ; i< number; i++)
	{
		cout << words[i] << endl;
	}
}
int randomnumber()
{
	srand(time(0));
	int rnumber = rand()%4 + 3;
	return rnumber;
}
void entercharacter(char &b)
{
	cout << "Enter a character: ";
	string a= "";
	cin >> a;
	if (a[1]!=0)
	{
		cout << "You entered more than one character" << endl;
		entercharacter(b);
	}
	else 
	{
		b= a[0];
	}
}
