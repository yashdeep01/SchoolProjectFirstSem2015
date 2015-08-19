#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>

class Data{
	private:
		char item[10];
		int price;
	public:
		void input()
		{
			gets(item);
			cin>>price;
		}
		void show(int x,int y)
		{
			gotoxy(x,y);
			cout<<item;
			gotoxy(x+19,y);
			cout<<price;
		}
		char* retname()
		{
			return item;
		}
		int retage()
		{
			return price;
		}
};

void menu();
void borderMenu();
void borderstatic();
void foodMenu();

void main(){
	clrscr();
	char choice;

	borderMenu();
	for(int i=0;choice!='x';i++)
	{
		clrscr();
		menu();
		borderstatic();
		gotoxy(59,5);cout<<"Enter choice:";
		gotoxy(72,5);cin>>choice;
		switch(choice){
			case 'm':foodMenu();break;
			case 'o':orderMenu();break;
			case 'e':getBill();break;
			case 'x':break;
		       //	default://add default
		}
	}
}


void menu(){
	gotoxy(11,3);cout<<"ITEM";
	gotoxy(25,3);cout<<"PRICE";
	Data d;
	fstream f;
	f.open("data.dat",ios::in|ios::binary);
	int k=5;
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
			break;
		d.show(6,k);
		k++;
		//Check for more than 5 items
	}

	f.close();
	gotoxy(4,12);cout<<"m - Edit Menu";
	gotoxy(6,13);cout<<"o - Order Items";
	gotoxy(6,14);cout<<"e - extract previous bill";
	gotoxy(6,17);cout<<"x - exit";//Work on it
}
void foodMenu(){//Work the boxes
	clrscr();
	borderstatic();
	gotoxy(11,3);cout<<"1)Show Menu";
	gotoxy(11,4);cout<<"2)Edit Menu";
	gotoxy(11,5);cout<<"3)Go back To Main Menu";

	int choice;
	switch(choice){
			case 1:showFoodMenu();break;
			case 2:editMenu();break;
			case 3:break;
		}
}
void editMenu(){
	clrscr();
	showFoodMenu();
	borderstatic();
	gotoxy(4,12);cout<<"1)Add Items";
	gotoxy(4,13);cout<<"2)Remove Items";
	gotoxy(4,15);cout<<"3)Go Back";
	int choice=1;

	while(choice<3){
		cin>>choice;
		switch(choice){
			case 1:addItems();
			case 2:removeItems();
		}
	}
}
void borderMenu(){
	int x,y;//Set Accoringly to file size
	for(x=1;x<=80;x++)
	{
		gotoxy(x,1);cout<<"±";delay(10);
	}
	for(y=1;y<=24;y++)
	{
		gotoxy(80,y);cout<<"±";delay(10);
	}
	for(x=80;x>=1;x--)
	{
		gotoxy(x,24);cout<<"±";delay(10);
	}
	for(y=24;y>=1;y--)
	{
		gotoxy(1,y);cout<<"±";delay(10);
	}
	for(y=2;y<=23;y++)
	{
		gotoxy(55,y);cout<<"±";delay(10);
	}
}
void borderstatic(){
	int x,y;
	for(x=1;x<=80;x++)
	{
		gotoxy(x,1);cout<<"±";
		gotoxy(x,24);cout<<"±";
	}
	for(y=1;y<=24;y++)
	{
		gotoxy(80,y);cout<<"±";
		gotoxy(1,y);cout<<"±";
	}
	for(x=80;x>=1;x--)
	{
		gotoxy(x,24);cout<<"±";
	}
	for(y=2;y<=23;y++)
	{
		gotoxy(55,y);cout<<"±";
	}
}



//--------------F-Stream Here Onwards---------------//
void addItems()
{
	data d;
	fstream f;
	f.open("foodMenu.dat",ios::app|ios::binary);
	char c;
	do{
		d.input();
		f.write((char*)&d,sizeof(d));
		cout<<"Do You Wish To Add More Items?(y/n)";
		cin>>c;
	}while(c!='n');

	f.close();
}