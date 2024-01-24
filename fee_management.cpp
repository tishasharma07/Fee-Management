#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
using namespace std;
class student
{
    int rollno;
    char name[50];
    char gender[50];
    char batch[50];
    char mobileno[50];
    float totalfees;
    float recieved;
public:
    friend void search_batch();
    friend void add_record();
    friend void search_gender();
    friend void remove_student();
    friend void accept_partialfees();
    friend void search_mobile();
    void accept()
    {
      //  cout<<endl<<"Enter Roll Number::";
        //cin>>rollno;
        cout<<endl<<"Enter Name::";
        cin>>name;
        cout<<endl<<"Enter Gender::";
        cin>>gender;
        cout<<endl<<"Enter Batch::";
        cin>>batch;
        cout<<endl<<"Enter Mobile Number::";
        cin>>mobileno;
        cout<<endl<<"Enter Total_Fees::";
        cin>>totalfees;
        cout<<endl<<"Fees Recieved::";
        cin>>recieved;
    }
    void display()
    {
        cout<<endl<<rollno<<setw(20)<<name<<setw(12)<<gender<<setw(25)<<batch<<setw(15)<<mobileno<<setw(10)<<totalfees<<setw(15)<<recieved<<setw(12)<<totalfees-recieved;
    }
};
student obj;//global object available for all functions
void add_record()
    {int rno;
    cout<<endl<<"Enter Rollno::";
    cin>>rno;
    bool flag=false;
    fstream rd;
    rd.open("feefile.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
        {
        rd.read((char *)&obj,sizeof(obj));

        if(obj.rollno==rno)
        {
            cout<<endl<<"duplicate entries not allowed";
            cout<<endl<<"enter valid rollno";
            flag=true;
        }
        }
    if(flag==false)
{    obj.rollno=rno;
        fstream wr;
        wr.open("feefile.txt",ios::app);
        obj.accept();
        wr.write((char *)&obj,sizeof(obj));
        wr.close();
        cout<<endl<<"File written successfully";
    }
 rd.close();
}
void all_student()
{
    fstream rd;
    rd.open("feefile.txt",ios::in);
    rd.seekg(0,ios::end);
    int total=rd.tellg();
    //cout<<total;
    //cout<<endl<<"size of object is"<<sizeof(obj);
    int n=total/sizeof(obj);
    //cout<<endl<<"no. of objects "<<n;
    rd.seekg(0,ios::beg);
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    cout<<endl<<"Roll no"<<"             Name"<<"      Gender"<<"                    Batch"<<"     Mobile Number"<<"  Total_Fees"<<"    Recieved"<<"    Balance";
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
       // cout<<endl<<"******************************************";
    }
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
}
void search_batch()
{  char b[50];
    cout<<endl<<"Enter Batch::";
    cin>>b;
    fstream rd;
    rd.open("feefile.txt",ios::in);
    rd.seekg(0,ios::end);
    int total=rd.tellg();
    int n=total/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    cout<<endl<<"Roll no"<<"             Name"<<"      Gender"<<"                    Batch"<<"     Mobile Number"<<"  Total_Fees"<<"    Recieved"<<"    Balance";
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(b,obj.batch)==0)
        {
            obj.display();
        }

    }
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
}
void search_gender()
{
 char a[50];
    cout<<endl<<"Enter Gender::";
    cin>>a;
    fstream rd;
    rd.open("feefile.txt",ios::in);
    rd.seekg(0,ios::end);
    int total=rd.tellg();
    int n=total/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    cout<<endl<<"Roll no"<<"             Name"<<"      Gender"<<"                    Batch"<<"     Mobile Number"<<"  Total_Fees"<<"    Recieved"<<"    Balance";
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(a,obj.gender)==0)
        {
            obj.display();
        }

    }
    cout<<endl<<"------------------------------------------------------------------------------------------------------------------------";

}
void remove_student()
{
    fstream rd,wr;
    rd.open("feefile.txt",ios::in);
    wr.open("temp.txt",ios::out);
    int rno;
    cout<<endl<<"Enter Roll No->";
    cin>>rno;
    rd.seekg(0,ios::end);
    int t=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=t;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.rollno==rno)
        {
            cout<<endl<<"Student Record Removed Successfully";
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("feefile.txt");
    rename("temp.txt","feefile.txt");
}
void accept_partialfees()
{int rno;
int amt;
cout<<endl<<"enter rollno";
cin>>rno;
cout<<endl<<"enter amount";
cin>>amt;
fstream rd,wr;
    rd.open("feefile.txt",ios::in);
    wr.open("temp.txt",ios::out);
    rd.seekg(0,ios::end);
    int t=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=t;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.rollno==rno)
        {
            float balance=obj.totalfees-obj.recieved;
            if(balance>=amt)
            {
                obj.recieved=obj.recieved+amt;
                cout<<endl<<"Balance Updated";
            }
            else
            {
               cout<<endl<<"Fees already cleared";
            }


        }
            wr.write((char*)&obj,sizeof(obj));

    }
    rd.close();
    wr.close();
    remove("feefile.txt");
    rename("temp.txt","feefile.txt");
}
void search_mobile()
{
    char m[50];
    cout<<endl<<"Enter mobile no::";
    cin>>m;
    fstream rd;
    rd.open("feefile.txt",ios::in);
    rd.seekg(0,ios::end);
    int total=rd.tellg();
    int n=total/sizeof(obj);
    rd.seekg(0,ios::beg);
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    cout<<endl<<"Roll no"<<"             Name"<<"      Gender"<<"                    Batch"<<"     Mobile Number"<<"  Total_Fees"<<"    Recieved"<<"    Balance";
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(m,obj.mobileno)==0)
        {
            obj.display();
        }

    }
    cout<<endl<<"-----------------------------------------------------------------------------------------------------------------------";
}
int main()
{{int ch;

do{cout<<endl<<"*****MENU*****";
    cout<<endl<<"press 1 to Add_record";
    cout<<endl<<"press 2 to View_record";
    cout<<endl<<"press 3 to Search record by Batch";
    cout<<endl<<"press 4 to Search record by Gender";
    cout<<endl<<"press 5 to Search record by Mobile Number";
    cout<<endl<<"press 6 to Remove Student";
    cout<<endl<<"press 7 to Accept Partial_fees";
    //cout<<endl<<"press 7 to search by email";
    cout<<endl<<"press 8 to exit";

    cout<<endl<<"enter your choice b/w (1-8):";
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                add_record();
                break;
            }
          case 2:
            {
                all_student();
                  break;
            }
           case 3:
            {
                search_batch();
                  break;
            }
           case 4:
            {
                search_gender();
                  break;
            }
            case 5:
            {search_mobile();
              break;

            }
           case 6:
            {remove_student();
              break;

            }
           case 7:
            {accept_partialfees();
              break;

            }
           /*case 7:
            {search_email();
              break;
            }*/
            case 8:
            { cout<<endl<<"---------------------------------------------------END---------------------------------------------------------------";
             exit(0);
                  break;

            }
            default:
               cout<<endl<<"invalid character";
            }
    }while(ch!=8);

}
}

