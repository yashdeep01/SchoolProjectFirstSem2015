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

class Item{
	char name[10];
	int price;
	public:

		void input()
		{
			cout<<"Enter Item Name:";
			gets(name);
			cout<<"Enter price of "<<name<<":";
			cin>>price;
		}
		void show()
		{
			cout<<name<<" "<<price<<endl;
		}
		char* getName()
		{
			return name;
		}
		int getPrice()
		{
			return price;
		}
};


void foodMenu();
void mainMenu();


void main(){
	clrscr();
	int r;
	mainMenu();
	getch();
}

void mainMenu(){
	int c=1;
	while(c!=2){
		cout<<"1.) Food Menu \ng - Generate Bill \ne - extract previous bill \nc - Cancel previous bill \nx - exit\n\nEnter Choice:";
		cin>>c;
		if (c==1)
		{
			foodMenu();
		}
	}

}

void foodMenu(){
	cout<<"1)Show Menu \n2)Add Items";
	int c;
	cin>>c;
	if(c==1){
		fstream f,g;
		Data d;
		char sent[100],price[10];
		f.open("foodMenu.txt",ios::in);
		g.open("price.txt",ios::in);
		while(!f.eof()){
			f.getline(sent,100,'\n');
			g.getline(price,100,'\n');

			cout<<sent<<"  "<<price<<endl;
		}
		g.close();
		f.close();
	}
	if (c==2){
		Item d;
		fstream itemName,price;
		itemName.open("foodMenu.txt",ios::app);
		price.open("price.txt",ios::app);
		d.input();//COMPLETE IT
		itemName<<d.getName()<<endl;
		price<<d.getPrice()<<endl;
		itemName.close();
		price.close();
	}
}