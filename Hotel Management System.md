#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
 
using namespace std;
 
class Hotel
{
	int room_number;
	char name[30];
	char address[50];
	char phone[10];
 
	public:
	
	void add_customer()
 	{
     	cout<<"\nEnter The Room Number: ";
        cin>>room_number;
        cout<<"\nEnter The Customer's name: ";
        cin.ignore();
        cin.getline(name,30);
        cout<<"\nEnter The Customer's address: ";
        cin.ignore();
        cin.getline(address,50);
        cout<<"\nEnter The Customer's phone #: ";
        cin.ignore();
        cin.getline(phone,10);
        cout<<"\t\t\n\nCustomer added Successfully...";
    }
	
	void show_customer()
	{
 		cout<<"\nRoom Number: "<<room_number;
   		cout<<"\nCustomer's Name: "<<name;
     	cout<<"\nCustomer's Address: "<<address;
     	cout<<"\nCustomer's Phone: "<<phone;
    }
    
	void modify_customer_record()
    {
        cout<<"\nRoom number : "<<room_number;
        cout<<"\nModify Customer's Name : ";
        cin.ignore();
        cin.getline(name,30);
        cout<<"\nModify Customer's address: ";
        cin.ignore();
        cin.getline(address,50);
        cout<<"\nModify Customer's phone #: ";
        cin.ignore();
        cin.getline(phone,10);
     }
     
     int getRoomNumber()
     {
     	return room_number;
     }
     char* getName()
     {
     	return name;
     }
     char* getAddress()
     {
     	return address;
     }
     
     char* getPhone()
     {
     	return phone;
     }
     void report()
     {
	 	cout<<room_number<<setw(10)<<name<<setw(20)<<address<<setw(20)<<phone<<endl;
     }
};
 
fstream fp;
Hotel h;
 
void save_customer()
{
	system("cls");
 	int option;
  	fp.open("hotel.dat",ios::out|ios::app);
   	do
    {
    	h.add_customer();
     	fp.write((char*)&h,sizeof(Hotel));
      	cout<<"\nPress 1 to add more customers.";
       	cout<<"\nPress 2 to return to main menu.\n";
        cout<<"Option: ";
        cin>>option;
     }while(option == 1);
     
     fp.close();
}
 
 
void display_a_customer(int r_number)
{
          system("cls");
          cout<<"\nCustomer DETAILS\n";
          int check=0;
          fp.open("hotel.dat",ios::in);
          while(fp.read((char*)&h,sizeof(Hotel)))
          {
                    if(h.getRoomNumber()==r_number)
                    {
                               h.show_customer();
                              check=1;
                    }
          }
          fp.close();
          if(check==0)
          	cout<<"\n\nCustomer does not exist";
        getch();
}
 
void modify_customer()
{
          system("cls");
          int r_number;
          int found=0;
          cout<<"\n\n\tMODIFY CUSTOMER'S RECORD";
          cout<<"\n\n\tEnter The room number: ";
          cin>>r_number;
          fp.open("hotel.dat",ios::in|ios::out);
          while(fp.read((char*)&h,sizeof(Hotel)) && found==0)
          {
                    if(h.getRoomNumber()==r_number)
                    {
                               h.show_customer();
                               cout<<"\nEnter Customer's new information"<<endl;
                               h.modify_customer_record();
                               int pos=-1*sizeof(h);
                              fp.seekp(pos,ios::cur);
                              fp.write((char*)&h,sizeof(Hotel));
                              cout<<"\n\n\t Record Updated Successfully...";
                              found=1;
                    }
          }
          fp.close();
          if(found==0)
                    cout<<"\n\n Record Not Found ";
          getch();
}
 
 
void delete_customer()
{
          system("cls");
          char r_number;
          int flag=0;
          cout<<"\n\n\n\tDELETE CUSTOMER";
          cout<<"\n\nEnter The Room # of the Customer you wan to delete: ";
          cin>>r_number;
          fp.open("hotel.dat",ios::in|ios::out);
          fstream fp2;
          fp2.open("Temp.dat",ios::out);
          fp.seekg(0,ios::beg);
          while(fp.read((char*)&h,sizeof(Hotel)))
          {
                    if(h.getRoomNumber()==r_number)  
                    {
                               fp2.write((char*)&h,sizeof(Hotel));
                    }
                    else
                              flag=1;
          }
          fp2.close();
          fp.close();
          remove("hotel.dat");
          rename("Temp.dat","hotel.dat");
          if(flag==1)
                    cout<<"\n\n\tRecord Deleted ...";
          else
                    cout<<"\n\nRecord not found";
          getch();
}
 
 
void display_all_customer()
{
              system("cls");
          fp.open("hotel.dat",ios::in);
          if(!fp)
          {
                    cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
                    getch();
                    return;
          }
          cout<<"\n\n\t\tCUSTOMER LIST\n\n";
          cout<<"==================================================================\n";
          cout<<"\tRoom Number."<<setw(10)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Phone"<<endl;
          cout<<"==================================================================\n";
          while(fp.read((char*)&h,sizeof(Hotel)))
          {
                    h.report();
          }
          fp.close();
          getch();
}
 
 
void main_menu()
{
	int option;
 
	for(;;)
	{
 
           cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\tPress 1 to BOOK A ROOM";
                cout<<"\n\t\tPress 2 to DISPLAY ALL ROOMS ALLOTTED";
                cout<<"\n\t\tPress 3 to DISPLAY SPECIFIC CUSTOMER RECORD";
                cout<<"\n\t\tPress 4 to MODIFY CUSTOMER RECORD";
                cout<<"\n\t\tPress 5 to DELETE CUSTOMER RECORD";
                 cout<<"\n\t\tPress 6 to Exit";
 cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
 cout<<"\n\t\tOption: ";
 cin>>option;
 switch(option)
          {
                    case 1:save_customer();
					  system("cls");
                             break;
                    case 2: display_all_customer();
					system("cls");
                            break;
                    case 3:
                              int r_number;
                               system("cls");
                  		      cout<<"\n\n\tPlease Enter Customer's Room Number: ";
                              cin>>r_number;
                              display_a_customer(r_number);
                              break;
                    case 4:modify_customer();
					system("cls");
                           break;
                    case 5: delete_customer();
					system("cls");
                           break;
                    case 6: exit(0);
     					   break;
                    default:cout<<"\a";
          }
	}
	
}
 
void intro()
{
     system("color 05");
     system("cls");
  cout<<"\t\t\t\t*\t*";
  cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";
}
 
 
int main(int argc, char *argv[])
{
	intro();
	main_menu();
	return 0;
}
