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

//****************Prototypes**********************//
void borderMenu();
void borderstatic();
void smallBorder();
void smallBorderStatic();

void menu();
void editMenu();

void addItems();
void showMenu();
//************End*Of*Prototypes*******************//

void main(){
	clrscr();
	char choice;
	smallBorder();

	//borderMenu();
	for(int i=0;choice!='x';i++)
	{
		clrscr();
		menu();
		smallBorderStatic();
		gotoxy(59,10);cout<<"Enter choice:";
		gotoxy(72,10);cin>>choice;
		switch(choice){
			case 'm':editMenu();break;
			case 'o':break;
			case 'e':break;
			case 'x':break;
		       //	default://add default
		}
	}
}


//-------------Borders------------//
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
void smallBorder(){
	int x,y;//Set Accoringly to file size
	for(x=0;x<=55;x++)
	{
		gotoxy(x+20,6);cout<<"±";delay(10);
	}
	for(y=0;y<=12;y++)
	{
		gotoxy(75,y+6);cout<<"±";delay(10);
	}
	for(x=55;x>=0;x--)
	{
		gotoxy(x+20,18);cout<<"±";delay(10);
	}
	for(y=12;y>=0;y--)
	{
		gotoxy(20,y+6);cout<<"±";delay(10);
	}
	for(y=6;y<=18;y++)
	{
		gotoxy(55,y);cout<<"±";delay(10);
	}
}
void smallBorderStatic(){
	int x,y;//Set Accoringly to file size
	for(x=0;x<=55;x++)
	{
		gotoxy(x+20,6);cout<<"±";
	}
	for(y=0;y<=12;y++)
	{
		gotoxy(75,y+6);cout<<"±";
	}
	for(x=55;x>=0;x--)
	{
		gotoxy(x+20,18);cout<<"±";
	}
	for(y=12;y>=0;y--)
	{
		gotoxy(20,y+6);cout<<"±";
	}
	for(y=6;y<=18;y++)
	{
		gotoxy(55,y);cout<<"±";
	}
}
//-------------Menus-------------//
void menu(){
	gotoxy(24,10);cout<<"m - Edit Menu";
	gotoxy(24,11);cout<<"o - Order Items";
	gotoxy(24,12);cout<<"e - extract previous bill";
	gotoxy(24,13);cout<<"x - exit";//Work on it
}
void editMenu(){
	int c;
	borderMenu();
	do
	{

		clrscr();
		borderstatic();
		for (int i = 0; i <=55 ;++i){
			gotoxy(i,19);cout<<(char)177;
		}

		gotoxy(11,3);cout<<"ITEM";
		gotoxy(25,3);cout<<"PRICE";
		showMenu();

		gotoxy(6,20);cout<<"1)Add Items";
		gotoxy(6,21);cout<<"2)Delete Items";
		gotoxy(6,22);cout<<"3)Go Back";



		gotoxy(59,10);cout<<"Enter choice:";
		gotoxy(72,10);cin>>c;
				switch(c){
				case 1:addItems();break;
				case 2:break;
				case 3:break;
		}
	} while (c!=3);
}
//-------------------FSTREAM---------------------//
void addItems(){
	Data d;
	fstream f;
	f.open("foodMenu.dat",ios::app|ios::binary);
	char c;
	int k=0;
	do{
		d.input();
		f.write((char*)&d,sizeof(d));
		gotoxy(45,13+k);cout<<"Do You Wish To Add More Items?(y/n)";
		cin>>c;
		k++;
	}while(c!='n');
	showMenu();
	f.close();
}
void showMenu(){
	Data d;
	fstream f;
	f.open("foodMenu.dat",ios::in|ios::binary);

	int k=5;
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
			break;
		d.show(6,k);
		k++;
	}
	f.close();
}