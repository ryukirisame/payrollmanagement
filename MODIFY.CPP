#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>


class employee
{ char a[12];
  int n;
  char name[50];
  double regno;
  char gender[7];
  char address[100];
  char position[20];
  int joined;
  int res_ret;
  int dobday;
  int dobmonth;
  int dobyear;
  int count;
  char status[10];
  int leave[12];
  double sal[12];
  double deduct[12];
  double bonus[12];
  double paid[12];
  double tbonus;
  double tmpaid[12];
  double tax[12];
  double tsal;
  int tleave;
  double tdeduct;
  double ttax;
  double typaid;
  public:
   employee()
   {
     strcpy(name,"N/A");
     strcpy(gender,"N/A");
     strcpy(address,"N/A");
     strcpy(position,"N/A");
     tsal=0,tleave=0,tdeduct=0,ttax=0,typaid=0,tbonus=0,count=0;

   }

  int getmonthdata();
  void getbasicdata();
  void monthcalc();
  void yearcalc();
  void display();
  double getregno()
  {  return regno;
  }
  double reducecount()
  { count--; return count;}
  double increasecount()
  { count++; return count;}
  int getcount()
  {  return count;
  }

};  //class ends
  int employee::getmonthdata()
{   while(1)              //while loop starts
  {
    cout<<"Enter current month:";
    gets(a);
    if(strcmpi(a,"january")==0)
    {n=0; break;}
    if(strcmpi(a,"february")==0)
    {n=1; break;}
    if(strcmpi(a,"march")==0)
    {n=2; break;}
    if(strcmpi(a,"april")==0)
    {n=3; break;}
    if(strcmpi(a,"may")==0)
    {n=4; break;}
    if(strcmpi(a,"june")==0)
    {n=5; break;}
    if(strcmpi(a,"july")==0)
    {n=6; break;}
    if(strcmpi(a,"august")==0)
    {n=7; break;}
    if(strcmpi(a,"september")==0)
    {n=8; break;}
    if(strcmpi(a,"october")==0)
    {n=9; break;}
    if(strcmpi(a,"november")==0)
    {n=10; break;}
    if(strcmpi(a,"december")==0)
    {n=11; break;}
    else
    cout<<"wrong input,re-enter:";
    }   //while loop ends
    for(int loop12=0;loop12<80;loop12++)
    {
       cout<<"-";
    }

    for(int i=0;i<=n;i++)
    {
       cout<<"For month "<<i+1<<":"<<endl;
       cout<<"Enter salary:";
       cin>>sal[i];
       cout<<"Enter bonus:";
       cin>>bonus[i];
       cout<<"Enter total deduction:";
       cin>>deduct[i];
       cout<<"Enter total tax:";
       cin>>tax[i];
       cout<<"Enter total leave taken:";
       cin>>leave[i];
       for(int loop13=0;loop13<80;loop13++)
       cout<<".";
    } clrscr();   return(0);
} //getmonthdata funtion ends
void employee::getbasicdata()
    {
      cout<<"Enter name:";
      gets(name);
      cout<<"Enter gender:";
      gets(gender);
      cout<<"Enter ID number:";
      cin>>regno;
      cout<<"Date of birth...\n    Enter day:";
      cin>>dobday;
      cout<<"    Enter month:";
      cin>>dobmonth;
      cout<<"    Enter year:";
      cin>>dobyear;
      cout<<"Enter address:";
      gets(address);
      cout<<"Enter employee's position in company:";
      gets(position);
      cout<<"Year joined:";
      cin>>joined;
      cout<<"Enter employee's status(working/resigned/retired):";
      gets(status);
      if(!strcmpi(status,"working")==0)
      { cout<<"Enter the year the employee resigned/retired:";
	while(1)
	{
	 cin>>res_ret;
	 if(res_ret<joined)
	 { cout<<"Please enter valid data:";
	 }
	 else
	 break;
	}
      }

    }     //getbasicdata funtion ends
void employee::monthcalc()  //monthcalc starts
{
     for(int p=0;p<=n;p++)
     {
       tmpaid[p]=(sal[p]+bonus[p])-(deduct[p]+tax[p]);
     }
}   // month calc ends
void employee::yearcalc() //year calc starts
{
      for(int r=0;r<=n;r++)
     {
       tsal=tsal+sal[r]+bonus[r];
       tleave=tleave+leave[r];
       ttax=ttax+tax[r];
       tdeduct=tdeduct+deduct[r];
       tbonus=tbonus+bonus[r];
     }
     typaid=tsal-(tdeduct+ttax);

}   //year calc ends
   void employee::display()      //diplay fuction starts
{
   cout<<"Name:"<<name<<endl;
   cout<<"Gender:"<<gender<<endl;
   cout<<"Date of birth:"<<dobday<<"/"<<dobmonth<<"/"<<dobyear<<endl;
   cout<<"Address:"<<address<<endl;
   cout<<"Position:"<<position<<endl;
   cout<<"Joined:"<<joined<<endl;
   if(!strcmpi(status,"working")==0)
  {   cout<<"Year resigned/retired:"<<res_ret<<endl;
  }
   else
   cout<<"Status:Working"<<endl;
   int ch;
   cout<<"\n1.For monthly detail"<<endl;
   cout<<"2.For yearly detail\n";
   cout<<"Enter your choice:";
   cin>>ch;    cout<<endl;
   if(ch==1)  //for month choice
   {  for(int loop_1=0;loop_1<80;loop_1++)
       cout<<"-";       int ans_3;
      for(int v=0;v<=n;v++)
     {
       cout<<"Month:"<<v+1<<endl;
       cout<<"Total leave taken:"<<leave[v]<<endl;
       cout<<"Salary:"<<sal[v]<<endl;
       cout<<"Bonus:"<<bonus[v]<<endl;
       cout<<"Deduction:"<<deduct[v]<<endl;
       cout<<"Total tax:"<<tax[v]<<endl;
       cout<<"Total paid:"<<tmpaid[v]<<endl;
       if(v==n)
       {  for(int loop_1=0;loop_1<80;loop_1++)
       cout<<"-";
	  cout<<"This is what we have.\n";}
       else
       {
       cout<<"Press 1 to see next month's data or Press any number to stop checking out:";
       cin>>ans_3;
       if(ans_3!=1)
       {break;}
	}
	for(int loop_9=0;loop_9<80;loop_9++)
	{cout<<"-";}
     }
       cout<<endl; int ans1;
      cout<<"Press 1 to return to Home:";
      cin>>ans1;
      clrscr();  cout<<endl;


  }    //month display ends

     if(ch==2)    //for year choice
  {  for(int loop_2=0;loop_2<80;loop_2++)
      cout<<"-";
     cout<<"Total leave:"<<tleave<<endl;
     cout<<"Total deductions:"<<tdeduct<<endl;
     cout<<"Total tax:"<<ttax<<endl;
     cout<<"Total bonus:"<<tbonus<<endl;
     cout<<"Total paid:"<<typaid<<endl;
      for(int loop2=0;loop2<80;loop2++)
       {cout<<"-";}   int ans_2;
       cout<<"Press 1 to return to Home:";
       cin>>ans_2;
       clrscr(); cout<<endl;
  }
}  //display funtion ends
double writerecord(employee write)   //data write funtion
{  double ct3=0;
  fstream fs("employ.dat",ios::app|ios::binary);
  char ans='y';
  while(ans=='y'||ans=='Y')
  { 	cout<<"\nCreate new record..."<<endl;
	for(int loop_8=0;loop_8<80;loop_8++)
	 cout<<"-";
    write.getbasicdata();
    write.getmonthdata();
    write.monthcalc();
    write.yearcalc();
    fs.write((char*)&write,sizeof(write));  ct3++;
    cout<<"\nWant to add more records(Y/N):";
    cin>>ans;
    clrscr();
    cout<<endl;

  } clrscr();
  fs.close();   return ct3;
}   //data write funtion ends
void readrecord(int reg)    // data read funtion starts
{  employee x;   int y;
int f=0;
   fstream fs;
   fs.open("employ.dat",ios::app|ios::in);
   while(1)
{
   fs.read((char*)&x,sizeof(x));
   if(fs.eof())
   break;
   else if(x.getregno()==reg)
  {f=1; x.display();}
}

    if(f==0)
   { for(int loop_5=0;loop_5<80;loop_5++)
	cout<<"-";
    cout<<"Data not found\n";
    for(loop_5=0;loop_5<80;loop_5++)
	cout<<"-";
    cout<<"Press any number to return to Home:";
    cin>>y;
    clrscr();
    return;
    }
  fs.close();
}   // data read function ends
void searchrecord()    //searchrecord funtion starts
{  employee ea;   int f=0;    int t=0;
 cout<<"\nSearch records...\n";
  for(int loop10=0;loop10<80;loop10++)
  cout<<"-";
  fstream fs("employ.dat",ios::in);
  double searchreg;
  cout<<"Enter ID number:";
  cin>>searchreg;
  while(1)   //while loop starts
  {  fs.read((char*)&ea,sizeof(ea));
  if(fs.eof())
  break;

       double abcd=ea.getregno();
	if(abcd==searchreg)
       { f=1;
       cout<<"Records found"<<endl;
	int go;
	cout<<"Press 1 to see employee's data:";
	cin>>go; cout<<endl;
	for(int loop_5=0;loop_5<80;loop_5++)
	cout<<"-";
	if(go==1)
	  {
	    ea.display(); return;}
	}  //if part ends


	}   //while loop ends
fs.close();
for(int loop_5=0;loop_5<80;loop_5++)
	cout<<"-";
 if(f==0)
 cout<<"Data not found\n";
 for(loop_5=0;loop_5<80;loop_5++)
	cout<<"-";
 cout<<"\nPress any number to return to Home:";
 cin>>t;
  clrscr(); return;
}  //search records funtion ends
double deleterecord(employee e)     //delete record funtion starts
{  double ct_1;
    clrscr();
    cout<<"\nDelete a record...\n";
    for(int loop11=0;loop11<80;loop11++)
    cout<<"-";
    int f=0;      int regit;
    cout<<"Enter registration number:";     cin>>regit;
   fstream fs1("employ.dat",ios::in);
   fstream fs2("temp.dat",ios::app|ios::binary);
   while(1) //while loop starts
  {  fs1.read((char*)&e,sizeof(e));
   if(fs1.eof())
     {break;}

     if(e.getregno()!=regit)
     { fs2.write((char*)&e,sizeof(e));
     }
    else
    {f=1; }
   }    //while loop ends
      if(f==1)
     { for(int loop_6=0;loop_6<80;loop_6++)
      cout<<"-";
      cout<<"Deleted"<<endl;   ct_1=1;
      for(loop_6=0;loop_6<80;loop_6++)
      cout<<"-";  }
      else
   {   for(int loop_6=0;loop_6<80;loop_6++)
      cout<<"-";
      cout<<"Record not found"<<endl; ct_1=0;
      for(loop_6=0;loop_6<80;loop_6++)
      cout<<"-";   }
      fs1.close();
      fs2.close();
      remove("employ.dat");
      rename("temp.dat","employ.dat");
     return ct_1;

  }   //delete record funtion ends

  void showtime(double countemp)
  { //  using namespace std;

    time_t now=time(0);
   // cout<<"Number of sec since january 1,1970:"<<now<<endl;
    tm*ltm=localtime(&now);
    cout<<"Year:"<<1900+ltm->tm_year<<endl;
    cout<<"Month:"<<1+ltm->tm_mon<<endl;
    cout<<"Day:"<<ltm->tm_mday<<endl;
    cout<<"Time:"<<ltm->tm_hour<<":";
    cout<<1+ltm->tm_min<<":";
    cout<<1+ltm->tm_sec<<endl;
    cout<<"Number of employees currently working in the company:"<<countemp<<endl;
  }


  int init()   // initalizing funtion starts
{  clrscr();    employee e;   int reg;  int num=0; int k=0;  int mp;
    double ct;      int f;    int f2;
  int cho;
  while(1)
  { cout<<endl;

    for(int loop_12=0;loop_12<80;loop_12++)
   cout<<"*";
   cout<<"\t\t      WELCOME TO PAYROLL MANAGEMENT SYSTEM\n";
   for(int loop_7=0;loop_7<80;loop_7++)
   cout<<"*";
    ct=e.getcount();
   showtime(ct);
   for(loop_12=0;loop_12<80;loop_12++)
   cout<<"*";
    cout<<"\n\t\t\t\t    MENU"<<endl;
     for(loop_12=0;loop_12<80;loop_12++)
   cout<<"-";
    cout<<"1.Create new record\n2.See record\n3.Search record\n4.Delete record\n5.Exit\n\n";
    cout<<"Enter your choice:";
    cin>>cho;
    switch(cho)
    {  case 1:
      { clrscr();


       f2=writerecord(e);
	for(int loop_30=0;loop_30<f2;loop_30++)
	{e.increasecount(); }
	break;  }
       case 2:
      { clrscr();
       cout<<"\nSee records...\n";
	for(int loop_9=0;loop_9<80;loop_9++)
	 cout<<"-";

       cout<<"Enter Employee's ID number:";
       cin>>reg;
       readrecord(reg);
       break;
      }
       case 3:
     { clrscr();
       searchrecord();  break;}
     case 4:
       {f=deleterecord(e);
	 cout<<"Press any number to return to Home:";
	 cin>>mp;
	 clrscr();
	 if(f==1)
	 { e.reducecount();}
	 break;
	 }
       case 5:
       exit(0);  break;
    }  //switch ends
    }  //while loop ends
} //initializing funtion ends

void main()
{
  init();
  getch();
}