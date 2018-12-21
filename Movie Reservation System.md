//Movie Reservation FYP Using Doubly link list 
#include<iostream> 
#include<iomanip>
using namespace std;
struct link
{
int regular,silver,gold;
link *regularnext,*silvernext,*goldnext;
link *regularpre,*silverpre,*goldpre;
};
link *regularstart = NULL,*silverstart = NULL,*goldstart = NULL,*temp, *temp1, *temp2,*temp3;
int count=0,GoldCount=0,SilverCount=0,RegularCount=0;
int Gold=101,Silver=81,Regular=1;
void firstdisplay();
void ViewMoviesList();
void NewBooking(int,int);
void displayall();
void ViewRegularDisplay();
void ViewSilverDisplay();
void ViewGoldDisplay();
void update();
void Search();
//void deletebooking();

int main()
{
	firstdisplay();
	return 0;
}

void displayall()
{
	int k=0; 
    cout<<setw(50)<<"Regular\n\n";
	for(int i=0;i<7;i++)
	{   
	for(int j=0;j<10;j++)
	{
	cout<<"     "<<k+1;
	k++;
	}
	cout<<endl;
	}
	cout<<setw(50)<<"Silver\n\n";
	for(int i=0;i<3;i++)
	{   
	for(int j=0;j<10;j++)
	{
	cout<<"     "<<k+1;
	k++;
	}
	cout<<endl;
	}
	cout<<setw(50)<<"Gold\n\n";
	for(int i=0;i<2;i++)
	{   
	for(int j=0;j<10;j++)
	{
	cout<<"     "<<k+1;
	k++;
	}
	cout<<endl;
	}
	cout<<"\nPress B for Back Mian Menu ";
	cout<<"\nPress E for Exit\n";
	char bb;
	cin>>bb;
	if(bb=='b'||bb=='B')
	{
	system("cls");
	firstdisplay();
		
	}
	else
	{
		cout<<setw(60)<<"\n\n\nThankyou";
	}
	}

	void NewBooking(int n,int s)  // movie number  how many seats  
	{
	   temp1=regularstart; temp2=silverstart; temp3=goldstart;
	system("cls");
	A:
	cout<<"\nNote: Each Row have only 10 seats so if you want to check Seats press 'D'\n\n";
	int c=s;
	cout<<"\nPress 'R' for Regular\n";
	cout<<"\nPress 'S' for Silver\n";
	cout<<"\nPress 'G' for Gold\n";
	cout<<"\nChoose :";
	
	char choice;
	cin>>choice;
	if(choice=='d'||choice=='D')
	{
		system("cls");
	displayall();
	goto A;
	}
	else if(choice=='r'||choice=='R')
	{
		system("cls");
	cout<<setw(40)<<"Regular\n\n\n";
	for(int i=0;i<s;i++)
	{	
	temp1 = regularstart;
	regularstart = new link;
	cout <<"Input Seat NUMBER " <<i+1<<" Unique ID :";
	cin >>regularstart->regular;
	regularstart->regularpre =NULL;
	regularstart->regularnext = temp1;
	if(temp1!=NULL)
	{
	temp1->regularpre=regularstart;
	}
	count++;
	RegularCount++;
	}
	}
	else if(choice=='S'||choice=='s')  
	{
			system("cls");
	cout<<setw(40)<<"Silver\n\n\n";
	for(int i=0;i<s;i++)
	{	
	temp2 = silverstart;
	silverstart = new link;
	cout <<"Input Seat NUMBER " <<i+1<<" Unique ID :";
	cin >>silverstart->silver;
	silverstart->silverpre =NULL;
	silverstart->silvernext = temp2;
	if(temp2!=NULL)
	{
	temp2->silverpre=silverstart;
	}
	count++;
	SilverCount++;
	}
	}
	
	else if(choice=='G'||choice=='g')
	{
	system("cls");
	cout<<setw(40)<<"Gold\n\n\n";
	for(int i=0;i<s;i++)
	{	
	temp3 = goldstart;
	goldstart = new link;
	cout <<"Input Seat NUMBER " <<i+1<<" Unique ID :";
	cin >>goldstart->gold;
	goldstart->goldpre =NULL;
	goldstart->goldnext = temp3;
	if(temp3!=NULL)
	{
	temp3->goldpre=goldstart;
	}
	count++;
	GoldCount++;
	}
	}
	
	else{
		cout<<"Wrong input Press Again...\n";
		goto A;	
	}}
	

	
	  void ViewMoviesList(){
	  	cout<<"\n\n\n\n";
		cout<<"1.BATMAN                         |11:00 PM| |8:00 Am| \n";	
		cout<<"2.Ya Jawani phir nahi Ani        |04:00 PM| |9:00 Am| \n";
		cout<<"3.ANT-MAN AND THE WASP(2018)     |01:00 PM| |9:00 Am| \n";
		cout<<"\n\n\n\nIf you want to reseve ticket then press Y\n";
		cout<<"If you want to Exit press E\n";
		cout<<"If you want to move to Main Menu press M\n";
		char choice;
		cin>>choice;
		if(choice=='y'||choice=='Y')
		{
		cout<<"\nInput Movie Number :";
		int number,seats;
		cin>>number;	
		cout<<"\nHow many seats :";
		cin>>seats;
		 NewBooking(number,seats);
		}
			else if(choice=='e'||choice=='E')
		{
		cout<<"Thankyou";	
		}
			else if(choice=='m'||choice=='m'){
			system("cls");
		}
		else{
			system("cls");
			cout<<setw(60)<<"\n\nYou Input wrong button Try Again\n";	
		}
		}
	void ViewRegularDisplay(){
	if(regularstart == NULL)
	{
	cout <<"\nNo Seat Reserve\n";
	}
	else
	{
	cout<<setw(40)<<"Regular\n\n\n";
	temp = regularstart;
	int i = 0;
	while (temp != NULL)
	{
	cout << "\nSeat Number " << i+1<< " Reserve ID :" << temp->regular << endl;
	temp = temp->regularnext;
     i++;
	}
	}		   
	cout<<"\nFor Display All seats press A\n";
    char aa;
    cin>>aa;
    if(aa=='A'||aa=='a')
    {
    displayall();	
	}
	}
	void ViewSilverDisplay(){
	if(silverstart == NULL)
	{
	cout <<"\nNo Seat Reserve\n";
	}
	else
	{
	cout<<setw(40)<<"Silver\n\n\n";
	temp = silverstart;
	int i = 70;
	while (temp != NULL)
	{
	cout << "\nSeat Number " << i+1<< " Reserve ID :" << temp->silver << endl;
	temp = temp->silvernext;
	i++;
	}
	}
    cout<<"\nFor Display All seats press A\n";
    char aa;
    cin>>aa;
    if(aa=='A'||aa=='a')
    {
    displayall();	
	}
	}
		void ViewGoldDisplay(){
		if(goldstart == NULL)
	{
	cout <<"\nNo Seat Reserve\n";
	}
	else
	{
	cout<<setw(40)<<"Gold\n\n\n";
	temp = goldstart;
	int i = 100;
	while (temp != NULL)
	{
	cout << "\nSeat Number " << i+1<< " Reserve ID :" << temp->gold << endl;
	temp = temp->goldnext;
	i++;
	}
		}	
	    cout<<"\nFor Display All seats press A\n";
	    char aa;
	    cin>>aa;
	    if(aa=='A'||aa=='a')
	    {
	    displayall();	
		}
	}
	void update()
	{   
		system("cls");
	cout<<"Press R for Regular \n";
	cout<<"Press S for Silver \n";
	cout<<"Press g for Gold\n ";
	cout<<"Choose : ";	
	char choose;
	cin>>choose;
	switch(choose)
	{
	case 'r': case 'R':
		{
		int d,r, flag = 0;
	if (regularstart == NULL)
	{
	cout<<setw(40)<<"Regular\n\n\n";
	cout << "\nSeat is Already Empty\n";
	}
	else
	{
	cout<<setw(40)<<"Regular\n\n\n";
	cout << "\nInput Seat id which you want to Update:";
	cin >> d;
	cout << "\n\nInput New Id: ";
	cin >> r;
	temp = regularstart;
	while (temp != NULL)
	{
	if (temp->regular == d)
	{
	temp->regular = r;
	flag = 1;
	break;
	}
	temp=temp->regularnext;
	}
	
	}
	if (flag == 0)
	{
	cout << "\n Not Found Your Seat\n";
	}
	else
	{
		system("cls");
	cout << "\nSuccessfully Update Seat ID";
	
	}
		}
		case 's': case 'S':
		{
	int d,r, flag = 0;
	if (silverstart == NULL)
	{
	cout<<setw(40)<<"Silver\n\n\n";
	cout << "\nSeat is Already Empty\n";
	}
	else
	{
	cout<<setw(40)<<"Silver\n\n\n";
	cout << "\nInput Seat id which you want to Update:";
	cin >> d;
	cout << "\n\nInput New Id: ";
	cin >> r;
	temp = silverstart;
	while (temp != NULL)
	{
	if (temp->silver == d)
	{
	temp->silver = r;
	flag = 1;
	break;
	}
	temp=temp->silvernext;
	}
	
	}
	if (flag == 0)
	{
	cout << "\n Not Found Your Seat\n";
	}
	else
	{
		system("cls");
	cout << "\nSuccessfully Update Seat ID";
	
	}
		}
	case 'g': case 'G':
		{
	int d,r, flag = 0;
	if (goldstart == NULL)
	{
	cout<<setw(40)<<"Gold\n\n\n";
	cout << "\nSeat is Already Empty\n";
	}
	else
	{
	cout<<setw(40)<<"Gold\n\n\n";
	cout << "\nInput Seat id which you want to Update:";
	cin >> d;
	cout << "\n\nInput New Id: ";
	cin >> r;
	temp = goldstart;
	while (temp != NULL)
	{
	if (temp->gold == d)
	{
	temp->gold= r;
	flag = 1;
	break;
	}
	temp=temp->goldnext;
	}
	}
	if (flag == 0)
	{
	cout << "\n Not Found Your Seat\n";
	}
	else
	{
		system("cls");
	cout << "\nSuccessfully Update Seat ID";
	}
	}
		default:
			{
				cout<<"\n\nWrong input \n\n";
		cout<<"\nFor go to Main Menu press 'm' and for exit press any key :";
		char choice;
		cin>>choice;
		if(choice=='m'||'M')
		{
		firstdisplay();
		}
		else{
			system("cls");
			cout<<"Thankyou";
		}
			
	}
	}
	}
void Search()
{
		
	system("cls");
	A:
	cout<<"From Where you want to Search\n\n :";
	cout<<"Press R for Regular \n";
	cout<<"Press S for Silver \n";
	cout<<"Press g for Gold\n ";
	cout<<"Choose : ";	
	char choose;
	cin>>choose;
	switch(choose)
	{
	case 'r': case 'R':
		{
      int d,r, flag = 0;

if (regularstart == NULL)

{
cout<<setw(40)<<"Regular\n\n\n";
cout << "\nTheir is no seat reserve\n";
}
else
{
cout<<setw(40)<<"Regular\n\n\n";
cout << "\nInput Seat id which you want to Search:";
cin >> d;
int i=0;
temp = regularstart;
while (temp != NULL)
{
if (temp->regular == d)
{
	flag=1;
cout<<"Seat Number"<<i+1;
cout<<"\nSeat id"<<d;
i++;
break;
}
temp=temp->regularnext;
}
}
if (flag == 0)
{
cout << "\n Not Found Your Seat\n";	

	} 
		}
case 's': case 'S':
	{
	int d,r, flag = 0;

if (silverstart == NULL)

{
cout<<setw(40)<<"silver\n\n\n";
cout << "\nTheir is no seat reserve\n";
}
else
{
cout<<setw(40)<<"silver\n\n\n";
cout << "\nInput Seat id which you want to Search:";
cin >> d;
int i=0;
temp = silverstart;
while (temp != NULL)
{
if (temp->silver == d)
{
	flag=1;
cout<<"Seat Number"<<i+1;
cout<<"\nSeat id"<<d;
i++;
break;
}
temp=temp->silvernext;
}
}
if (flag == 0)
{
cout << "\n Not Found Your Seat\n";	

	} 
		}
	case 'g': case 'G':
	{
	int d,r, flag = 0;

if (goldstart == NULL)

{
cout<<setw(40)<<"Gold\n\n\n";
cout << "\nTheir is no seat reserve\n";
}
else
{
cout<<setw(40)<<"gold\n\n\n";
cout << "\nInput Seat id which you want to Search:";
cin >> d;
int i=0;
temp = goldstart;
while (temp != NULL)
{
if (temp->gold == d)
{
	flag=1;
cout<<"Seat Number"<<i+1;
cout<<"\nSeat id"<<d;
i++;
break;
}
temp=temp->goldnext;
}
}
if (flag == 0)
{
cout << "\n Not Found Your Seat\n";	

	} 
		}
		default:
			{
				cout<<"Not Found Try Again.....\n\n\n";
				goto A;
			}
	}	
	
	
	}
	
	void firstdisplay()
{   A:
	cout<<setw(60)<<"Movie Reservation System\n\n\n";
	cout<<"Select your choice:\n";
	cout<<"1. View Movies list and New Booking\n";     //  1
	cout<<"2. Check Regular Seats\n";                  //  2
	cout<<"3. Check Silver Seats\n";                  //  3
	cout<<"4. Check Gold Seats\n";                    // 4
	cout<<"5. Seats Information through search\n";
	cout<<"6. Display All Seats \n";                     //5
	cout<<"7. Update Seat\n";                           // 6
	cout<<"8. Exit\n";                                  // 7
	cout<<"Enter:";
	int choose;
	cin>>choose;
	system("cls");
	switch(choose)
	{
	case 1:                          //ok
	{
	ViewMoviesList();
	system("cls");
	goto A;
	break;
	  }	
	  	case 2:                    //ok
	{
	ViewRegularDisplay();	
			break;
		 }	
	case 3:                   //ok
	{

	ViewSilverDisplay();	
			break;
		 }
	case 4:                  //ok
	{

	ViewGoldDisplay();	
			break;
		 }
	case 5:                //ok
	{
	Search();
	break;
	  }
	case 6:            //ok
	{
displayall();
break;
	  }
	case 7:            //ok
	{
	update();
	cout<<"\nFor go to main menu press m and for exit press any key :";
	char choice;
	cin>>choice;
	if(choice=='m'||'M')
	{
	goto A;
	}
	else
	{
		system("cls");
		cout<<"Thankyou Your Program is Terminated";
	}
	break;
	  }
	  
	case 8:
	{
    cout<<"Thankyou Your Program is Terminated";
	 break;
	  }
	default:
	{
	cout<<"Alert: You press wrong button\n";
	goto A;
	  }
	}
}

//yasir Munir   032  Bcs-4C
