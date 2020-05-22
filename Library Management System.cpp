#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip> //Used this library to use setw function.
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
/******BOOKS CLASS*******/
class books
{
	char bno[10];
	char bname[50];
	char aname[50];
	public:
		void createbook()
		{
			cout<<"NEW BOOK ENTERY"<<endl;
			cout<<"ENTER BOOK NUMBER"<<endl;
			cin>>bno;
			cout<<"ENTER BOOK NAME"<<endl;
			gets(bname);
			cout<<"ENTER AUTHOUR NAME"<<endl;
			gets(aname);
		}
		void showbook()
		{
			cout<<"BOOK NUMBER:"<<bno<<endl;
			cout<<"BOOK NAME:"<<puts(bname)<<endl;
			cout<<"BOOK AUTHOUR:"<<puts(aname)<<endl;
		}
		void modifybook()
		{
			cout<<"BOOK NUMBER:"<<bno<<endl;
			cout<<"MODIFY BOOK NUMBER:"<<endl;
			gets(bname);
			cout<<"MODIFY BOOK AUTHOUR:"<<endl;
			gets(aname);
		}
		char* retbno()
		{
			return bno;
		}
		void report()
		{
			cout<<bno<<setw(70)<<bname<<setw(70)<<aname<<endl;
		}
};
/*****READER CLASS*****/
class reader
{
	char readno[10];
	char name[50];
	char rdbno[10];
	int token;
	public:
		void create_reader()
		{
			cout<<"NEW READER ENTERY:"<<endl;
			cout<<"ENTER READER NUMBER:"<<endl;
			cin>>readno;
			
		}
		void show_reader()
		{
			cout<<"READER NUMBER:"<<readno<<endl;
			cout<<"READER NAME:"<<puts(name)<<endl;
			cout<<"NO. OF BOOKES ISSUED:"<<token<<endl;
			if (token==1)
			{
				cout<<"BOOK NUMBER:"<<rdbno<<endl;
			}
		}
		void modify_reader()
		{
			cout<<"READER NUMBER:"<<readno<<endl;
			cout<<"MODIFY READER NAME:"<<endl;
			gets(name);
		}
		char* retrdrno()
		{
			return readno;
		}
		char* ret_red_bno()
		{
			return rdbno;
		}
		void adtoken()
		{
			token=1;
		}
		int rettoken()
		{
			return token;
		}
		void reset_token()
		{
			token=0;
		}
		void getrdno(char t[])
		{
			strcpy(rdbno,t);
		}
		void report()
		{
			cout<<readno<<setw(70)<<name<<setw(70)<<token<<endl;
		}
};
fstream fp,fp1;
books bk;
reader rd;
/*Declaring functions*/
void start();
void admin();
void writebook();
void writereader();
void displaybk(char n[]);
void displayrd(char n[]);
void modifybook();
void modifyreader();
void deletestudent();
/********START MENU*********/
int main()
{
	int n;
	start();
	do
	{
		cout<<endl<<endl;
		cout<<setw(60)<<"\t1.BOOK ISSUE"<<endl;  //used for setting alignement on the output screen.
		cout<<setw(60)<<"\t2.BOOK DEPOSIT"<<endl;
		cout<<setw(70)<<"\t3.ADMINISTRATION SECTION"<<endl;
		cout<<setw(60)<<"\t4.EXIT SYSTEM"<<endl<<endl;
		cout<<setw(70)<<"\tPLEASE SELECT OPTION BETWEEN 1 TO 4"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:
				//issue
				break;
			case 2:
				//deposit
				break;
			case 3:
				admin();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<setw(70)<<"INVALID CHOICE"<<endl;
		}
	}while(n!=4);
}
/*Defining functions*/
void start()
{
	//goto (35,11);
	cout<<setw(70)<<"LIBRARY MANAGEMENT SYSTEM"<<right<<endl;
}
void admin()
{
	//clrscr();
	int choice;
	cout<<"ADMINISTRATION MENU"<<endl;
	cout<<"\t 1.CREATE READER RECORD"<<endl;
	cout<<"\t 2.DISPLAY SPECIFIC READER RECORD"<<endl;
	cout<<"\t 3.DISPLAY ALL READER RECORD"<<endl;
	cout<<"\t 4.MODIFY READER RECORD"<<endl;
	cout<<"\t 5.DELETE READER RECORD"<<endl;
	cout<<"\t 6.INSERT BOOK"<<endl;
	cout<<"\t 7.DISPLAY SPECIFIC BOOK"<<endl;
	cout<<"\t 8.DISPLAY ALL BOOKS"<<endl;
	cout<<"\t 9.MODIFY BOOK RECORD"<<endl;
	cout<<"\t 10.DELETE BOOK RECORD"<<endl;
	cout<<"\t 11.BACK TO MAIN MENU"<<endl;
	cout<<"\t ENTER YOUR CHOICE"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			writereader();
			//write_reader();
			break;
		case 2:
			char num[10];
			cout<<"ENTER READER NUMBER"<<endl;
			cin>>num;
			//display_sp_reader();
			break;
		case 3:
			//display_all_reader();
			break;
		case 4:
			//modify_reader();
			break;
		case 5:
			//delete_reader();
			break;
		case 6:
			//insert_book();
			break;
		case 7:
			char book[10];
			cout<<"ENTER BOOK NUMBER"<<endl;
			cin>>book;
			//display_sp_book();
			break;
		case 8:
			//display_all_book();
			break;
		case 9:
			//modify_book();
			break;
		case 10:
			//delete_book();
		case 11:
			return;
			break;
		default:
			cout<<"INVALID CHOICE SELECT 1-11"<<endl;
			break;
	}
	admin();
}
void writebook()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		bk.createbook();
		fp.write((char*)&bk,sizeof(books));
		cout<<"WANT TO ADD MORE REPORT..? (y/n)"<<endl;
		cin>>ch;
	}while(ch!='n'||ch!='N');
	fp.close();
}
void writereader()
{
	char ch;
	fp.open("reader.dat",ios::out|ios::app);
	do
	{
		rd.create_reader();
		fp.write((char*)&rd,sizeof(reader));
		cout<<"WANT TO ADD MORE REPORT..? (y/n)"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void displaybk(char n[])
{
	cout<<"BOOK DETAILS:"<<endl;
	int flag=0;
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(books)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.showbook();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"BOOK NOT FOUND"<<endl;
		getch();
	}
	
}
void displayrd(char n[])
{
	cout<<"READER DETAILS:"<<endl;
	int flag=0;
	fp.open("reader.dat",ios::in);
	while(fp.read((char*)&rd,sizeof(reader)))
	{
		if(strcmpi(rd.retrdrno(),n)==0)
		{
			rd.show_reader();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"READER NOT FOUND"<<endl;
		getch();
	}
	
}
void modifybook()
{
	char n[50];
	int found=0;
	cout<<"MODIFY BOOK RECORD"<<endl;
	cout<<"ENTER BOOK NO:"<<endl;
	cin>>n;
	//fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(books)) && found==0)
	{
		if(strcmpi(bk.retbno(),n==0))
		{
			bk.showbook();
			cout<<"ENTER NEW BOOK DETAILS:"<<endl;
			bk.modifybook();
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(books));
			cout<<"RECORD UPDATED"<<endl;
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		cout<<"BOOK NOT FOUND"<<endl;
	}
}
void modifyreader()
{
	char n[50];
	int found=0;
	cout<<"MODIFY READER RECORD"<<endl;
	cout<<"ENTER READER NO:"<<endl;
	cin>>n;
	//fp.open("reader.dat",ios::in|ios::out);
	while(fp.read((char*)&rd,sizeof(reader)) && found==0)
	{
		if(strcmpi(rd.retrdrno(),n==0))
		{
			rd.show_reader();
			cout<<"ENTER NEW READER DETAILS:"<<endl;
			rd.modify_reader();
			int pos=-1*sizeof(rd);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&rd,sizeof(reader));
			cout<<"RECORD UPDATED"<<endl;
			found=1;
		}
	}
	fp.close();
	if(found==0)
	{
		cout<<"READER NOT FOUND"<<endl;
	}
}
void deletestudent()
{
	char n[10];
	int flag = 0;
	cout<<"DELETE READER RECORD"<<endl;
	cout<<"ENTER READER NO:"<<endl;
	cin>>n;
	fp.open("reader.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&rd,sizeof(reader)))
	{
		if(strcmpi(rd.retrdrno(),n)!=0)
		{
			fp2.write((char*)&rd,sizeof(reader));
			
		}
		else
		{
			flag=1;
		}
	}
	fp2.close();
	fp.close();
	remove("reader.dat");
	rename("temp.dat","reader.dat");
	if(flag==1)
	{
		cout<<"RECORD DELETED"<<endl;
	}
	else
	{
		cout<<"RECORD NOT FOUND"<<endl;
	}
}
