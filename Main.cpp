#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <fstream.h>

class order{
	char item;
	int qty;
	public:
		order();
		char getItem(){
			return item;
		}
		int getQty(){
			return qty;
		}
		~order();
};
class Item
{
		char name[10];
		int price;
	public:
	
		void input()
		{
			gets(name);
			cin>>price;
		}
		void show()
		{
			cout<<name<<" "<<price<<endl;
		}
		char* retname()
		{
			return name;
		}
		int retage()
		{
			return price;
		}
};
void foodMenu();
void mainMenu();


void main(){
	clrscr();

	fstream f;
	int r;
	foodMenu();
	cout<<endl;
	getch();
}

void mainMenu(){
	cout<<"1.) Food Menu \ng - Generate Bill \ne - extract previous bill \nc - Cancel previous bill \nx - exit";
}

void foodMenu(){
	cout<<"1)Show Menu \n2)Add Items";
	int c;
	cin>>c;
	if(c==1){
		fstream f;
		Item d;
		f.open("foodMenu.txt",ios::in);
		while(f){
			f.read(); //COMPLETE IT
			if(f.eof())
				break;
			d.show();
		}
	}
	if (c==2)
	{
		Item d;
		fstream f;
		f.open("foodMenu.txt",ios::app);
		d.input();//COMPLETE IT
		f.write();		
		f.close();
	}
	f.close();
}