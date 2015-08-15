#include <fstream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
struct order
{
	char item;
	int qty;
};
void menu();
void borderbill();
void bordermenu();
void borderstatic();
void logo();
int summary(order d[100][100],int x,int cash);       //x is the bill no.
int input(order d[100][100],int x);
void makeBill(order d[100][100],int cash,int billnumber);
void showBill(int billnumber);

void main()
{
	clrscr();
	logo();
	delay(1500);
	clrscr();
	bordermenu();
	delay(100);
	order d[100][100];     //2-D Array. x-axis is bill no., y-axis is various items.
	int r,cash[100];
	for(int i=0;r!=-1;i++)
	{
		menu();
		borderstatic();		 //i is the bill no.
		r=input(d,i);
		if(r==0)
		{
			clrscr();
			cash[i]=summary(d,i,0);   //cash is an array in main(), not in summary.
		}                                //it helps to record to amt entered to extract a bill later
		else if(r==-1)
		{
			clrscr();
			gotoxy(38,12);cout<<"Bye...";
			delay(1000);
		}
		else if(r>0)   // r>0 is possible only when it has returned anatural no.,ie,bill no.
		{
			showBill(r-1);
			i--;                     //we recordered it above
		}
	}
}

void logo()
{
  cout<<"\n"<<"\n"<<"\n";
  cout<<"			      °±±± Û         °±±± Û            \n";    delay(50);
  cout<<"			     °±±±±± Û       °±±±±± Û           \n";    delay(50);
  cout<<"			   °±± Û  °±± Û    °±± Û°±± Û          \n";    delay(50);
  cout<<"			  °±± Û	   °±± Û  °±± Û  °±± Û         \n";    delay(50);
  cout<<"			 °±± Û	    °±± Û°±± Û    °±± Û        \n";    delay(50);
  cout<<"			°±± Û	     °±±±± Û       °±± Û       \n";    delay(50);
  cout<<"			°±± Û	     °°±±± Û        °±± Û      \n";    delay(50);
  cout<<"			°±± Û	      °±± Û         °±± Û      \n";    delay(50);
  cout<<"			°±± Û	      °±± Û         °±± Û      \n";    delay(50);
  cout<<"			°±± Û         °±± Û         °±± Û      \n";    delay(50);
  cout<<"			°±± Û         °±± Û         °±± Û      \n";    delay(50);
  cout<<"			°±±± Û        ÜÜÜÜÛ         °±± Û      \n";    delay(50);
  cout<<"			°±±± Û                      °±± Û      \n";    delay(50);
  cout<<"			°°±±± Û                    °±±± Û      \n";    delay(50);
  cout<<"			ÜÜÜÜÜÜÛ                   ÜÜÜÜÜÜÛ       \n";    delay(1200);
  delay(1500);

  clrscr();
  gotoxy(20,10);cout<<"Welcome to McDonald's!";  delay(1200);
  clrscr();
  gotoxy(30,8);cout<<"At our very own...";       delay(1000);
  gotoxy(40,10);cout<<"Computer Lab!";

}

void menu()
{
	gotoxy(11,3);cout<<"ITEM";
	gotoxy(25,3);cout<<"PRICE";
	gotoxy(6,5);cout<<"1. McVeggie        Rs.60";
	gotoxy(6,6);cout<<"2. McAlooTikki     Rs.25";
	gotoxy(6,7);cout<<"3. McChicken       Rs.70";
	gotoxy(6,8);cout<<"4. Cold Coffee     Rs.30";
	gotoxy(6,9);cout<<"5. Soft Serve      Rs.15";
	gotoxy(4,12);cout<<"1,2..- order corresponding item";
	gotoxy(6,13);cout<<"c - cancel the previous item";
	gotoxy(6,14);cout<<"z - generate bill";
	gotoxy(6,15);cout<<"e - extract previous bill";
	gotoxy(6,18);cout<<"x - exit";
}

void bordermenu()
{
	int x,y;
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
//this function is diff from bordermenu as it doesn't animate and does not have delay();
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
		gotoxy(55,y);cout<<"±";
	}
}
//this is the border that appears in the bill
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
int input(order d[100][100],int x)
{
	int b,y=0;
	gotoxy(59,5);cout<<"Bill no. "<<x+1<<"\n"; //x+1 because it gets values starting from 0
	do                                        //whereas user thinks bill nos. should start from 1
	{
		gotoxy(59,2*y+5);cout<<"Enter choice ";
		gotoxy(72,2*y+5);cin>>d[x][y].item;
		if(d[x][y].item>='1' && d[x][y].item<='5')  //before asking for qty we need to know
		{                                           //what the user has entered
			gotoxy(59,2*y+6);cout<<"Enter qty ";
			gotoxy(72,2*y+6);cin>>d[x][y].qty;
			y++;
		}
		else if(d[x][y].item=='c')   //c for cancel
		{
			y--;          //item order is disturbed.just to balance that
			gotoxy(72,2*y+5);cout<<" ";
			gotoxy(59,2*y+6);cout<<"\t\t "; //to clear the previous
			gotoxy(59,2*y+7);cout<<"\t\t"; //enter choice & qty stmts.
		}
		else if(d[x][y].item=='z')
		{       clrscr();
			return 0;
		}
		else if(d[x][y].item=='e' && x==0)
		{
				gotoxy(59,2*y+5);cout<<"You have not";
				gotoxy(59,2*y+6);cout<<"generated any";
				gotoxy(59,2*y+7);cout<<"bill yet!";
				gotoxy(59,2*y+9);cout<<"<Press enter>";
				getch();
				gotoxy(59,2*y+5);cout<<"\t\t";
				gotoxy(59,2*y+6);cout<<"\t\t";
				gotoxy(59,2*y+7);cout<<"\t\t";
				gotoxy(59,2*y+9);cout<<"\t\t";
			}
		else if(d[x][y].item=='e' && x>0)
		{
				clrscr();
				gotoxy(32,12);cout<<"Enter bill no. ";
				gotoxy(47,12);cin>>b;  //b is bill no.
				clrscr();
				while(b>x || b<=0) //b > current bill no.
				{
					gotoxy(30,11);cout<<"Bill does not exist.";
					gotoxy(30,12);cout<<"Please enter again = ";
					gotoxy(51,12);cin>>b;
					clrscr();
				}
				return b;
		}
		else if(d[x][y].item=='x')
			return -1;
		else         //if he enters anything rubbish
		{
			gotoxy(59,2*y+5);cout<<"Incorrect Value";
			gotoxy(59,2*y+6);cout<<"Please Enter Again.";   delay(800);
			gotoxy(59,2*y+5);cout<<"\t\t  ";  //above stmts. deleted after a time
			gotoxy(59,2*y+6);cout<<"\t\t     ";
		}                               //when block of code gets over, it goes up bcoz of loop &
	}while(d[x][y].item!='x');          // it auto. asks for a choice

}
//this fn is used to extract, generate n total the bill.
int summary(order d[100][100],int x,int cash)
{
	borderbill();
	double total,vat=0.125,svtax=0.048,gtotal;
	int i,total_due,change,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,y=0,k=5;
	a1=a2=b1=b2=c1=c2=d1=d2=e1=e2=0; //a2,b2.. no. of occurences of items
					 //a1,b1..sum of indivdual items
	gotoxy(62,2);cout<<"Bill no. = "<<x+1<<"\n";
	for(y=0;d[x][y].item!='z';y++)
	{
		switch(d[x][y].item)
		{
			case '1':a1=a1+(60*d[x][y].qty);
				a2=a2+d[x][y].qty;
				break;
			case '2':b1=b1+(25*d[x][y].qty);
				b2=b2+d[x][y].qty;
				break;
			case '3':c1=c1+(70*d[x][y].qty);
				c2=c2+d[x][y].qty;
				break;
			case '4':d1=d1+(30*d[x][y].qty);
				d2=d2+d[x][y].qty;
				break;
			case '5':e1=e1+(15*d[x][y].qty);
				e2=e2+d[x][y].qty;
		}
	}
	gotoxy(21,3);cout<<"ITEM         PRICE   QTY   TOTAL";
	if(a2>0)
	{
	       gotoxy(20,k);
	       cout<<"McVeggie      Rs.60    "<<a2<<"     "<<a1;
	       k++; //to make next item come in next line
	}           //k is the y of gotoxy(x,y);
	if(b2>0)
	{
		gotoxy(20,k);
		cout<<"McAlooTikki   Rs.25    "<<b2<<"     "<<b1;
		k++;
	}
	if(c2>0)
	{
		gotoxy(20,k);
		cout<<"McChicken     Rs.70    "<<c2<<"     "<<c1;
		k++;
	}
	if(d2>0)
	{       gotoxy(20,k);
		cout<<"Cold Coffee   Rs.30    "<<d2<<"     "<<d1;
		k++;
	}
	if(e2>0)
	{	gotoxy(20,k);
		cout<<"Soft Serve    Rs.15    "<<e2<<"     "<<e1;
		k++;
	}
	k=k+1;           //to leave 1 line xtra
	total=a1+b1+c1+d1+e1;
	gotoxy(22,k);cout<<"Sub total          = "<<total; k++;
	gotoxy(22,k);cout<<"VAT (12.5%)        = "<<vat*total; k++;
	gotoxy(22,k);cout<<"Service tax (4.8%) = "<<svtax*total; k++;
	gotoxy(22,k);cout<<"Total              = "<<total*(1+vat+svtax); k++;
	gtotal=total*(1+vat+svtax);
	gotoxy(22,k);cout<<"Rounding off       = ";
	if(gtotal-(int)gtotal<0.5)     //calculations...
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
	if(cash==0)   //eq with 0 to know its a new bill
	{
		gotoxy(43,k);cin>>cash; k++;
	}
	else      //old bill getting extracted
	{
		gotoxy(43,k);cout<<cash; k++; //here cash is not needed to be array
	}
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
	makeBill(d,cash,x);
	clrscr();
	return cash;  //cash returned without caring its new/old bill
}                     //because if its a new bill cash is stored in main in cash[i];
		     //n if its old, let it be stored again
void makeBill(order d[100][100],int cash,int billnumber)
{
	int x=billnumber;
	double total,vat=0.125,svtax=0.048,gtotal;
	int i,total_due,change,a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,y=0,k=5;
	a1=a2=b1=b2=c1=c2=d1=d2=e1=e2=0;
	for(y=0;d[x][y].item!='z';y++)
	{
		switch(d[x][y].item)
		{
			case '1':a1=a1+(60*d[x][y].qty);
				a2=a2+d[x][y].qty;
				break;
			case '2':b1=b1+(25*d[x][y].qty);
				b2=b2+d[x][y].qty;
				break;
			case '3':c1=c1+(70*d[x][y].qty);
				c2=c2+d[x][y].qty;
				break;
			case '4':d1=d1+(30*d[x][y].qty);
				d2=d2+d[x][y].qty;
				break;
			case '5':e1=e1+(15*d[x][y].qty);
				e2=e2+d[x][y].qty;
		}
	}
	fstream bill;
	char c[10];
	itoa(billnumber,c,10);
	strcat(c,".txt");
	bill.open(c,ios::out);

	bill<<" ITEM         PRICE   QTY   TOTAL"<<"\n";
	if(a2>0)
	{
	    bill<<"McVeggie      Rs.60    "<<a2<<"     "<<a1<<"\n";
	}
	if(b2>0)
	{
		bill<<"McAlooTikki   Rs.25    "<<b2<<"     "<<b1<<"\n";
	}
	if(c2>0)
	{
		bill<<"McChicken     Rs.70    "<<c2<<"     "<<c1<<"\n";
	}
	if(d2>0)
	{   
		bill<<"Cold Coffee   Rs.30    "<<d2<<"     "<<d1<<"\n";
	}
	if(e2>0)
	{	
		bill<<"Soft Serve    Rs.15    "<<e2<<"     "<<e1<<"\n";
	}
	total=a1+b1+c1+d1+e1;
	bill<<"Sub total          = "<<total<<"\n";
	bill<<"VAT (12.5%)        = "<<vat*total<<"\n";
	bill<<"Service tax (4.8%) = "<<svtax*total<<"\n";
	bill<<"Total              = "<<total*(1+vat+svtax)<<"\n";
	gtotal=total*(1+vat+svtax);
	bill<<"Rounding off       = "<<"\n";
	if(gtotal-(int)gtotal<0.5)     //calculations...
	{
		gotoxy(43,k);cout<<(int)gtotal-gtotal; k++;
		total_due=(int)gtotal;
	}
	else
	{
		gotoxy(43,k);cout<<-1*(gtotal-(int)(gtotal+1)); k++;
		total_due=(int)gtotal+1;
	}
	bill<<"Total Due          = "<<total_due<<"\n"<<"\n"; 
	
	bill<<"Cash tendered      = ";
	bill<<cash<<"\n";
	bill<<"Change             = "<<cash-total_due<<"\n";
	bill.close();
}
void showBill(int billnumber){
	clrscr();
	fstream bill;
	char c[100];
	itoa(billnumber,c,10);

	strcat(c,".txt");

	fstream f;
	f.open(c,ios::in);
	char sent[100];
	while(!f.eof()){
		f.getline(sent,100,'\n');
		cout<<sent<<endl;
	}
	f.close();
	getch();
	clrscr();
}
