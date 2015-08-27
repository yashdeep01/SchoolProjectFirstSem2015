#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <stdlib.h>

//********************Need For Items On Next Page**************************//

class Data
{
	private:
		char item[20];
		int price;
	public:
		void input(int k)
		{
			gotoxy(39,k);cout<<"Enter Item Name:";
			gotoxy(56,k);gets(item);
			gotoxy(39,k+1);cout<<"Enter Item Price:";
			gotoxy(57,k+1);cin>>price;
		}
		void show(int x,int y)
		{
			gotoxy(x,y);
			cout<<item;
			gotoxy(x+19,y);
			cout<<price;
		}
		char* retItem()
		{
			return item;
		}
		int retPrice()
		{
			return price;
		}
};

//****************Prototypes**********************//
void borderMenu();
void borderstatic();
void smallBorder();
void smallBorderStatic();
void borderbill();

void menu();
void editMenu();
void orderMenu();
void extract();

void addItems();
void showMenu();
void deleteItem();
void showBill(int order[50]);
//************End*Of*Prototypes*******************//

void main()
{
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
			case 'o':orderMenu();break;
			case 'e':extract();break;
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
		gotoxy(35,y);cout<<"±";delay(10);
	}
}
void borderstatic()
{
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
		gotoxy(35,y);cout<<"±";
	}
}
void smallBorder()
{
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
void smallBorderStatic()
{
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
void borderbill()
{
	int x,y;                 //x,y are independent variables
	for(x=0;x<=39;x++)
	{
		gotoxy(2*x+1,1);cout<<"";
		gotoxy(2*x+1,24);cout<<"";
	}
	for(y=0;y<=11;y++)
	{
		gotoxy(1,2*y+1);cout<<"";
		gotoxy(1,2*y+2);cout<<"";
		gotoxy(79,2*y+1);cout<<"";
		gotoxy(79,2*y+2);cout<<"";
	}
}
//-------------Menus-------------//
void menu(){
	gotoxy(24,10);cout<<"m - Edit Menu";
	gotoxy(24,11);cout<<"o - Order Items";
	gotoxy(24,12);cout<<"e - extract previous bill";
	gotoxy(24,13);cout<<"x - exit";//Work on it
}
void editMenu()
{
	clrscr();
	int c;
	borderMenu();
	do
	{
		clrscr();
		borderstatic();
		for (int i = 1; i <=35 ;++i)
		{
			gotoxy(i,17);cout<<(char)177;
		}

		gotoxy(11,3);cout<<"ITEM";
		gotoxy(25,3);cout<<"PRICE";
		showMenu();

		gotoxy(6,19);cout<<"1)Add Items";
		gotoxy(6,20);cout<<"2)Delete Items";
		gotoxy(6,21);cout<<"3)Go Back";
		gotoxy(6,22);cout<<"4)Go To Next Page Of Menu";//Do It



		gotoxy(39,3);cout<<"Enter choice : ";
		gotoxy(52,3);cin>>c;
		switch(c)
		{
			case 1:addItems();break;
			case 2:deleteItem();break;
			case 3:break;
		}
	} while (c!=3);
}
void orderMenu()
{
	clrscr();
	char c[100];
	borderMenu();

	int k=3,order[50]={0};

	clrscr();
	borderstatic();
	for (int i = 1; i <=35 ;++i)
	{
		gotoxy(i,17);cout<<(char)177;
	}
	gotoxy(11,3);cout<<"ITEM";
	gotoxy(25,3);cout<<"PRICE";
	showMenu();

	gotoxy(6,19);cout<<"1,2..... Add Items Accordingly";
	gotoxy(6,20);cout<<"c)Cancel previous Item";
	gotoxy(6,21);cout<<"z)Generate Bill";
	gotoxy(6,22);cout<<"b)Go Back";
	gotoxy(6,23);cout<<"n)Go To Next Page Of Menu";//Do It

	int last=0,lastquantity=0;
	do
	{
		gotoxy(39,k);cout<<"Enter choice:";
		gotoxy(52,k);cin>>c;

		if(atoi(c)>=1 && atoi(c)<=50)
		{
			//order
			int x=atoi(c);
			gotoxy(39,k+1);cout<<"Enter quantity:";

			int quantity;
			gotoxy(54,k+1);cin>>quantity;
			order[x-1]=quantity;

			last = x-1;
			lastquantity = quantity;
		}
		else if(c[0]=='b')
		{
		}
		else if(c[0]=='c')
		{
			order[last]=order[last]-lastquantity;
			gotoxy(39,k-2);cout<<"                      ";
			gotoxy(39,k-1);cout<<"                      ";
			gotoxy(39,k);  cout<<"                      ";
			k=k-4;
		}

		else if(c[0]=='z')
		{
			//generateBill(order);
			showBill(order);
			break;
		}

		else if(c[0]=='n')
		{//Code It
			getch();
		}


		k+=2;
	}while(c[0]!='b');
}
//-------------------FSTREAM---------------------//
void extract()
{
	int bill_no,i=1,fsize,dsize,pos;
	cout<<"Enter bill no. ";
	cin>>bill_no;
	fstream f;
	f.open("foodMenu.dat",ios::in|ios::binary);
	fsize=f.tellg(0,ios::end);
	dsize=sizeof(d);
	pos=fsize/dsize;
	while(i<=pos)
	{
		if(bill_no==i)
		{

void addItems()
{
	Data d;
	fstream f;
	f.open("foodMenu.dat",ios::app|ios::binary);
	char c;
	int k=4;
	do
	{
		d.input(k);
		f.write((char*)&d,sizeof(d));
		gotoxy(39,k+2);cout<<"Do You Wish To Add More Items?(y/n):";
		gotoxy(76,k+2);cin>>c;
		k+=3;
		showMenu();
	}while(c!='n');
	showMenu();
	f.close();
}
void showMenu()
{
	Data d;
	fstream f;
	f.open("foodMenu.dat",ios::in|ios::binary);

	int k=5;
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
			break;
		gotoxy(2,k);cout<<k-4;
		d.show(6,k);
		k++;
	}
	f.close();
}
void deleteItem()
{
	Data d;
	fstream f1,f2;
	char item[20];
	int k=4;
	gotoxy(39,k);cout<<"Enter Item Name:";
	gotoxy(56,k);gets(item);
	f1.open("foodMenu.dat",ios::in|ios::binary);  //org file
	f2.open("temp.dat",ios::out|ios::binary);  //temp file
	while(f1)
	{
		f1.read((char*)&d,sizeof(d));
		if(f1.eof())
			break;
		if(strcmp(d.retItem(),item)!=0)
			f2.write((char*)&d,sizeof(d));  //transfer
	}
	f1.close();
	f2.close();
	remove("foodMenu.dat");	//stdio.h  - remove org
	rename("temp.dat","foodMenu.dat");  // - rename new created file to org
}
void showBill(int order[50])
{
	clrscr();
	borderbill();
	Data d;
	fstream f;
	int price[50]={0},total=0,k=0,cash=0,i;

	gotoxy(21,3);cout<<"ITEM             PRICE     QTY   TOTAL";
	int y=4;
	f.open("foodMenu.dat",ios::in|ios::binary);
	while(f)
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
			break;
		if(order[k]>0)
		{
		    d.show(20,y);
		    gotoxy(43,y); cout<<"      "<<order[k]<<"     "<<order[k]*d.retPrice();
		    total+=order[k]*d.retPrice();
			y++;
		}
		k=k+1;
	}

	double vat=0.125,svtax=0.048,gtotal;
	int total_due;

	k=k+5;
	gotoxy(22,k);cout<<"Sub total          = "<<total; k++;
	gotoxy(22,k);cout<<"VAT (12.5%)        = "<<vat*total; k++;
	gotoxy(22,k);cout<<"Service tax (4.8%) = "<<svtax*total; k++;
	gotoxy(22,k);cout<<"Total              = "<<total*(1+vat+svtax); k++;
	gtotal=total*(1+vat+svtax);
	gotoxy(22,k);cout<<"Rounding off       = ";

	if(gtotal-(int)gtotal<0.5)
	{
		gotoxy(43,k);cout<<(int)gtotal-gtotal; k++;
		total_due=(int)gtotal;
	}
	else
	{
		gotoxy(43,k);cout<<-1*(gtotal-(int)(gtotal+1)); k++;
		total_due=(int)gtotal+1;
	}

	gotoxy(22,k);cout<<"Total Due          = "<<total_due; k=k+2;
	gotoxy(22,k);cout<<"Cash tendered      = ";

	gotoxy(43,k);cin>>cash; k++;
	while(cash<total_due)
	{
		gotoxy(22,k);cout<<"Enter a value > "<<total_due<<" = ";
		gotoxy(43,k);cin>>cash;   k++;  //if he enters less cash
	}
	gotoxy(22,k);cout<<"Change             = "<<cash-total_due;
	delay(200);
	for(i=8;i<=24;i++)
	{
		gotoxy(2*i+7,21);cout<<"";  //border for thank u
		if(cash==0);
			delay(5);
	}
	gotoxy(23,22);cout<<"Thank you! Please visit us again.";
	gotoxy(25,23);cout<<"<Press any key to continue>";


	getch();

}