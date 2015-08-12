#include <iostream.h>
#include <string.h>
#include <conio.h>
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

void menu();


void main(){

	fstream f;
	int r;

	
	for(int i=0;r!=-1;i++){
		menu();
		r=input(d,i);
		if(r==0)
		{
			clrscr();
			cash[i]=summary(d,i,0);   //cash is an array in main(), not in summary.
		}                                //it helps to record to amt entered to extract a bill later
		else if(r==-1)
		{
			clrscr();
			cout<<"Bye...";
		}
		else if(r>0)   // r>0 is possible only when it has returned anatural no.,ie,bill no.
		{
			summary(d,r-1,cash[r-1]); //cash as a parameter
			i--;                     //we recordered it above
		}
	}
}

void menu(){
	cout<<"ITEM";
	cout<<"PRICE";
	cout<<"1. McVeggie        Rs.60";
	cout<<"2. McAlooTikki     Rs.25";
	cout<<"3. McChicken       Rs.70";
	cout<<"4. Cold Coffee     Rs.30";
	cout<<"5. Soft Serve      Rs.15";
	cout<<"1,2..- order corresponding item";
	cout<<"c - cancel the previous item";
	cout<<"z - generate bill";
	cout<<"e - extract previous bill";
	cout<<"x - exit";
}
