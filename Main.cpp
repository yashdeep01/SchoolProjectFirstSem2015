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
	char name[100];
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
void orderMenu();
void readFoodMenu();

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

void readFoodMenu(){
	fstream f,g;
	char sent[100],price[100];
	f.open("foodMenu.txt",ios::in);
	g.open("price.txt",ios::in);
	int i=1;
	while(!f.eof()){
		f.getline(sent,100,'\n');
		g.getline(price,100,'\n');
		cout<<i<<". "<<sent<<"  "<<price<<endl;
	}
	i++;
	g.close();
	f.close();
}
void foodMenu(){
	int c=1;
	while(c<4){
		cout<<"1)Show Menu \n2)Add Items \n3)Order Items";
		cin>>c;
		if(c==1){
			readFoodMenu();
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
		if (c==3)
		{
			orderMenu();
		}
	}
}

void orderMenu(){
	int j=1;
	int cost;
	clrscr();
	cout<<"Menu\n";
	readFoodMenu();
	while(j!=9){
		cout<<"\nadd corresponing items by number\npress x to exit\n";
		cin>>j;
		int Quantity;
		cout<<"Enter Quantity:";cin>>Quantity;
		char sent[100];
		fstream price;
		int l=1;
		for (int i = 1; i <= j; ++i)
		{
			price.getline(sent,100,'\n');
			if(i==j)
			{
				cost=((int)sent) * Quantity;
			}
		}

	}
}