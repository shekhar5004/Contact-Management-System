#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
 

class contact
{
  private:
  char fname[50],lname[50],address[50],email[50];
  long long phNo;

  public:
  void createContact()
  {
    cout<<"Enter your first Name"<<" ";
    cin>>fname;
    cout<<"Enter your last Name"<<" ";
    cin>>lname;
    cout<<"Enter your phone number"<<" ";
    cin>>phNo;
    cout<<"Enter address:"<<" ";
    cin>>address;
    cout<<"Enter email:"<<" ";
    cin>>email;
  }
  void showContact()
  {
    cout<<"<Name:"<<" "<<fname<<" "<<lname<<endl;
    cout<<"Phone:"<<" "<<phNo<<endl;
    cout<<"Address:"<<" "<<address<<endl;
    cout<<"Email:"<<" "<<email<<endl;

  }
  void writeOnFile()
  {
    char ch;
    ofstream f1;
    f1.open("CMS.dat",ios::binary|ios::app);
    do
    {
    cout<<"Call create contact"<<" ";  
    createContact();
    cout<<"done";
    f1.write(reinterpret_cast<char*>(this),sizeof(*this));
    cout<<"Do you have next data?(y/n)";
    cin>>ch;
    }while(ch=='y');
    cout<<"Contact has been successfully created...";
    f1.close();
  }
  void readOnFile()
  {
    ifstream f2;
    f2.open("CMS.dat",ios::binary);
    cout<<endl;
    cout<<"====================================";
    cout<<endl;
    cout<<"List of Contact";
    cout<<endl;
    cout<<"====================================";
    cout<<endl;
    while(!f2.eof())
    {
      if(f2.read(reinterpret_cast<char*>(this),sizeof(*this)));
      {
        showContact();
        cout<<endl;
        cout<<"=============================";
        cout<<endl;
      }
      
    }
    f2.close();
  }
  void searchOnFile()
  {
    ifstream f3;
    long long phone;
    cout<<"Enter phone no.";
    cin>>phone;
    f3.open("CMS.dat",ios::binary);
    while(!f3.eof())
    {
        
      if (f3.read(reinterpret_cast<char*>(this),sizeof(*this)))
      {
         cout<<"Entered"<<" ";
          if(phone==phNo)
          {
          
            showContact();
            return ;
          }
           cout<<f3.eof()<<endl;
      } 
    }
    cout<<endl<<"No record found";
    f3.close();
  }
  void deleteFromFile()
  {
    long long phone;
    int flag=0;
    ofstream f4;
    ifstream f5;
    
    f5.open("CMS.dat",ios::binary);
    f4.open("temp.dat",ios::binary);
    cout<<"Enter phone no. to delete::"<<" ";
    cin>>phone;

    while(!f5.eof())
    {
      if(f5.read(reinterpret_cast<char*>(this),sizeof(*this)))
      {
        if(phNo!=phone)
        {
          f4.write(reinterpret_cast<char*>(this),sizeof(*this));
        }
        else
        flag=1;
      }
    }
    f4.close();
    f5.close();
    remove("CMS.dat");
    rename("temp.dat","CMS.dat");
    flag==1?cout<<"\tContact Deleted....":cout<<"\tContact Not found";

  }
  void editContact()
{
   long long phone;
   fstream f6;
   cout<<"Edit Contact";
   cout<<endl;
   cout<<"================================";
   cout<<endl;
   cout<<"Enter the phone number to be edit"<<" ";
   cin>>phone;
   f6.open("CMS.dat",ios::binary|ios::out|ios::in);
  while(!f6.eof())
  {
    if(f6.read(reinterpret_cast<char*>(this),sizeof(*this)))
    {
      if(phone==phNo)
      {
        cout<<"Enter new record"<<endl;
        createContact();
        int pos=-1*sizeof(*this);
        f6.seekp(pos,ios::cur);
        f6.write(reinterpret_cast<char*>(this),sizeof(*this)); 
        cout<<endl<<endl<<"\tContact Successfully Updated....";
        // return ;
      }
    }
  } 
   cout<<"Enter new record"<<endl;
   cout<<"\n\nRecord Found";
   f6.close();
 }
  
};
int main()
{
  system("cls");
  system("color 3D");
  cout<<"\n\n\n\n\n\n\n\n\n\t\t*Welcome to Contact Management System*";
  getch();
  while(1)
  {
    contact c1;
    int choice;
    system("cls");
    system("color 03");
    cout<<"\nContact Management System";
    cout<<"\n\nMain Menu";
    cout<<"\n===================================\n";
    cout<<"[1] Add a new Contact\n";
    cout<<"[2] List All Contact\n";
    cout<<"[3] Search for all Contact\n";
    cout<<"[4] Edit a Contact";
    cout<<"[5] Delete a Contact";
    cout<<"[6] Exit";
    cout<<"\n===================================\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
    system("cls");
    c1.writeOnFile();
    cout<<"Contact Created"<<endl;
    break;
    case 2:
    system("cls");
    c1.readOnFile();
    break;
    case 3:
    system("cls");
    cout<<"switchcalled"<<endl;
    c1.searchOnFile();
    cout<<"switchdone"<<endl;
    break;
    case 4:
    cout<<"switchcalled"<<endl;
    system("cls");
    c1.editContact();
    cout<<"switchdone"<<endl;
    break;
    case 5:
    system("cls");
    c1.deleteFromFile();
    break;
    case 0:
    system("cls");
    cout<<"\n\n\n\t\t\tThank you for using CMS"<<endl<<endl;
    exit(0);
    break;
    default: 
    continue;
    }
    int opt;
    cout<<"\n\n..::Enter the Choice:\n[1] Main Menu\t\t[0]Exit\n";
    cin>>opt;
    switch(opt)
    {
     case 0:
    system("cls");
    cout<<"\n\n\n\t\t\tThank you for using CMS"<<endl<<endl;
    exit(0);
    break;
    default: 
    continue;

    }
  }
  return 0;
}
