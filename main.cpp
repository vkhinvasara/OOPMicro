#include <iostream>
#include <windows.h>
#include <sstream>

using namespace std;

         const int lim=200;
         const int PRS=10;
         const int MRC=5;
         int prs_quo[lim];

class Management //Master Class of all other classes mentioned above
{

private:

        int current=-1;
        int alottedRooms[PRS][lim];
        int customer_id[lim],cus=1; //To track customer id(s)
        int sum[MRC][PRS][lim];
        int rate[5]={12000,30000,45000,70000,17000};
        int room_qt[MRC][PRS][lim];
        int total_days[PRS][lim];
        int zipcode[PRS][lim],guest_qty[PRS][lim],arrivalDate[3][PRS][lim],birthdate[3][PRS][lim],prof_id[PRS][lim],phone[PRS][lim],days[PRS][lim];
        int room_no[MRC][PRS][lim];
        int total_amt[PRS][lim],no[PRS][lim]={0};
        int total_rooms[PRS][lim];
        string name[PRS][lim],last_name[PRS][lim],address[PRS][lim],city[PRS][lim],car_lic[PRS][lim];
        string user[lim],pass[lim];
        string email[PRS][lim];
        string roomOptions[5]={"Single Room","Junior Suite","Penthouse suite","Presidential Suite","Standard Room"};
        string selectedRooms[MRC][PRS][lim];
        bool loginStatus[PRS][lim]={0},reservationStat[PRS][lim]={0};


        int PRSSub=prs_quo[current];
        int MRCSub=no[PRSSub][current];

public:

void displayOptions()
        {
            int x;
            system("cls");
            if(!checkLoginStatus())
                {
                cout<<"1.Login"<<endl;
                cout<<"2.Register new user"<<endl;
                cout<<"Enter choice"<<endl;
                cin>>x;
                }
            else
            {
            cout<<"Customer Id:"<<customer_id[current]<<"  User-Name:"<<user[current]<<endl;
            cout<<"1.Reserve a new room"<<endl;
            cout<<"2.Checkout and pay"<<endl;
            cout<<"3.Check reservation status"<<endl;
            cout<<"4.Cancel active reservation"<<endl;
            cout<<"5.Log Out"<<endl;
            cout<<"Enter choice"<<endl;
            cin>>x;
            }
            reservationOpt(x);
        }
 void reservationOpt(int x)
{
            if(!checkLoginStatus())
                {
                    switch(x)
                    {
                        case 1:
                            login();
                            break;
                        case 2:
                            registernew();
                            break;
                        default:
                            cout<<"Enter a valid Option!"<<endl;
                            displayOptions();
                    }
                }
            else{
                switch(x){
                    case 1:
                        reservationInfo();
                        break;
                    case 2:
                        checkout();
                        break;
                    case 3:
                        cancelReservation();
                        break;
                    case 4:
                        showStatus();
                        break;
                    case 5:
                        setLoginStatus(false);
                        system("cls");
                        for (int i=0;i<5;i++)
                        {
                            system("cls");
                            cout<<"Logging out";
                            for(int j=0;j<7;j++)
                            {
                                cout<<".";
                                Sleep(250);
                            }
                        }
                        displayOptions();
                        break;
                default:
                    cout<<"Enter a valid Option!"<<endl;
                    displayOptions();
            }

        }
}
void login()
{
            system("cls");

            string password,username,dummy;
            int x;
            cout<<"LOGIN"<<endl;
            cout<<"User-name/Customer Id:";
            cin>>dummy;

                if(dummy.size()>3)
                {
                    for(int i=1;i<=lim;i++)
                    {
                        if(user[i]==dummy)
                            x=i;
                    }
                }
                else
                {
                    stringstream st(dummy);
                    st>>x;
                    username=user[x];
                }

        cout<<"Password:";
        cin>>password;

            if(password!=pass[x])
            {
                cout<<"Incorrect user-name or password"<<endl;
                char op;
                    cout<<"Register as new user?(Y/N)"<<endl;
                    cin>>op;
                    if((char)toupper(op)=='Y')
                        registernew();
                    else if((char)toupper(op)=='N')
                        reservationOpt(1);
                    else
                        cout<<"Incorrect choice"<<endl;

                login();
            }
            else
            {
                cout<<"Login successful"<<endl;
                current=x;
                setLoginStatus(true);
                Sleep(2000);
                displayOptions();
            }
}

void registernew()
    {
        system("cls");
        cout<<"Enter user name and password"<<endl;
        cout<<"User-name:";
        cin>>user[cus];
        cout<<"Password:";
        cin>>pass[cus];

            while(pass[cus].size()<8)
            {
                cout<<"Size of your password should be a minimum of 8 characters!!!"<<endl;
                cout<<"Re-Enter password..."<<endl;
                cout<<"Password:";
                cin>>pass[cus];
            }

            for(int i=0;i<cus;i++)
            {
                if(user[i]==user[cus])
                {
                    cout<<"User-name already exists, enter a different user-name"<<endl;
                    Sleep(2500);
                    registernew();
                }
                else
                {
                customer_id[cus]=cus;
                cout<<"Your customer id is "<<customer_id[cus]<<endl;
                cus++;
                Sleep(3000);
                break;
                }
            }

        displayOptions();
    }
void setLoginStatus(bool status)
    {
        loginStatus[PRSSub][current]=status;
    }

bool checkLoginStatus()
    {
        return loginStatus[PRSSub][current];
    }
void showStatus()
    {
            cout<<"Reservation Status:";
            if(reservationStat)
                cout<<"Confirmed"<<endl;
            else
                cout<<"Pending/Canceled"<<endl;
            Sleep(3000);
            displayOptions();
    }
void reservationInfo()
   {
       system("cls");
       if(no[PRSSub][current]<1)
       {
        cout<<"Enter details:"<<endl;
        cout<<"First Name:";
        cin>>name[PRSSub][current];
        cout<<"Last Name:";
        cin>>last_name[PRSSub][current];
        cout<<"Address:";
        cin>>address[PRSSub][current];
        cout<<"City Of Origin:";
        cin>>city[PRSSub][current];
        cout<<"Zip Code:";
        cin>>zipcode[PRSSub][current];
        cout<<"Car License Id if any(Enter 0 if none):";
        cin>>car_lic[PRSSub][current];
        cout<<"Enter the number of guests which intend to reside:";
        cin>>guest_qty[PRSSub][current];
        cout<<"Arrival Date(DD MM YY):"<<endl;
        cin>>arrivalDate[0][PRSSub][current]>>arrivalDate[1][PRSSub][current]>>arrivalDate[2][PRSSub][current];
        cout<<"Days of stay:"<<endl;
        cin>>days[PRSSub][current];
        cout<<"BirthDate(DD MM YY):"<<endl;
        cin>>birthdate[0][PRSSub][current]>>birthdate[1][PRSSub][current]>>birthdate[2][PRSSub][current];
        cout<<"Enter your personal id number"<<endl;
        cin>>prof_id[PRSSub][current];
        cout<<"Phone Number:";
        cin>>phone[PRSSub][current];
        cout<<"Email: ";
        cin>>email[PRSSub][current];
       }
       else
        {
            cout<<"Rest Details are already saved"<<endl;
        }

        cout<<"Enter the type of room you wish to stay in....";
        Sleep(3000);
        roomType();
        cout<<"Details Entered! Wait for the option window to checkout in..."<<endl;
        for(int i=10000;i>0;i=i-1000)
        {
            cout<<i/1000<<"  ";
            Sleep(1000);
        }
        displayOptions();

   }
void roomType()
       {
           system("cls");
           int type,room_qty;
           cout<<"1. Single Room: Room with a single bed and a attached bathroom(12,000)"<<endl;
           cout<<"2. Junior Suite: Small Living Room with a double bedroom(30,000)"<<endl;
           cout<<"3. Penthouse suite: Top floor suite with a open area with a private pool(45,000)"<<endl;
           cout<<"4. Presidential suite: Separate living room with a separate kitchen(70,000)"<<endl;
           cout<<"5. Standard room: Simple room with a double bed and attached bathroom(17,000)"<<endl;
           cout<<endl;
           cout<<"Enter the serial number of the room you have chosen:"<<endl;
           cin>>type;
           cout<<"Enter the number of rooms you want to book"<<endl;
           cin>>room_qty;

           if(type>5&&type<1)
           {
               cout<<"Invalid Entry, enter a valid choice!"<<endl;
               roomType();
           }

           while((guest_qty[PRSSub][current]/room_qty)>2.0)//This will increase the number of rooms if guest qty>2 for each room
           {
                room_qty++;
                cout<<"Only one room can be booked for two people\n(+1 Room added of the same category)"<<endl;
                if(guest_qty[PRSSub][current]/room_qty>2 && guest_qty[PRSSub][current]/room_qty<3)
                    break;
           }

            room_qt[MRCSub][PRSSub][current]= room_qty;
            sum[MRCSub][PRSSub][current]=(rate[type-1])*(room_qt[MRCSub][PRSSub][current]); //To calculate the total amount to be paid by the customer excluding tax
            selectedRooms[MRCSub][PRSSub][current]=roomOptions[type-1]; //For calculating customers bill

           int calcRooms=type*10+(room_qt[MRCSub][PRSSub][current]);

           for(int i=room_qty;i>0;i--)
            {
                room_no[i][PRSSub][current]=calcRooms;
                calcRooms--;
            }
          MRCSub++;
          no[PRSSub][current]++;
       }


void checkout()
{
    if(no[PRSSub][current]==0)
       {
         cout<<"No rooms booked yet"<<endl;
         cout<<"Go to main menu?(Y)"<<endl;
         char op;
         cin>>op;
         if((char)toupper(op)=='Y')
            displayOptions();
         else
            cout<<"Invalid choice, going to main display menu"<<endl;
         displayOptions();
       }
   else{
            if(!reservationStat[PRSSub][current])
            {
                total_amt[PRSSub][current]={0};
                total_rooms[PRSSub][current]={0};
                cout<<"Invoice"<<endl<<endl;
                for(int i=0;i<no[PRSSub][current];i++)
                {
                    total_amt[PRSSub][current]+=sum[i][PRSSub][current]*days[PRSSub][current];
                    total_rooms[PRSSub][current]+=room_qt[i][PRSSub][current];
                    cout<<i+1<<"."<<selectedRooms[i][PRSSub][current]<<endl;
                    cout<<"No of Rooms Booked:"<<room_qt[i][PRSSub][current]<<endl;
                    cout<<"Day(s) of stay:"<<days[PRSSub][current]<<endl;
                    cout<<"Amount(per room):"<<sum[i][PRSSub][current]/room_qt[i][PRSSub][current]<<endl;;
                    cout<<"Amount x Quantity x Day(s):"<<(sum[i][PRSSub][current]*days[PRSSub][current])<<endl<<endl;
                }
                cout<<"Total rooms booked:"<<total_rooms[PRSSub][current]<<endl;
                cout<<"Total Amount:"<<total_amt[PRSSub][current]<<endl;
                cout<<"Final Amount including taxes:"<<total_amt[PRSSub][current]*1.18<<endl;
                cout<<"Confirm payment?(Y/N)"<<endl;
                char o;
                cin>>o;

                if((char)toupper(o)=='Y')
                    {
                        system("cls");
                    }
                else
                {
                    while((char)toupper(o)!='N')
                    {
                        cout<<"Invalid choice!"<<endl;
                        cout<<"Enter Y to confirm payment N to exit to menu"<<endl;
                        cin>>o;
                    }
                     if((char)toupper(o)=='N')
                    {
                        system("cls");
                        displayOptions();
                    }
                }

                cout<<"Customer ID:"<<customer_id[current]<<endl;
                cout<<"Room No Allotted:"<<endl;
                for(int i=0;i<total_rooms[PRSSub][current];i++)
                    {
                        cout<< room_no[i][PRSSub][current]<<" ";
                        alottedRooms[PRSSub][current]=room_no[i][PRSSub][current];
                    }
                reservationStat[PRSSub][current]=true;
                cout<<endl;
                prs_quo[current]++;
                PRSSub++;
                char op;
                cout<<"Enter Y to return to the main menu and N to exit"<<endl;
                cin>>op;

                    if((char)toupper(op)=='Y')
                        displayOptions();
                    else if((char)toupper(op)=='N')
                        reservationOpt(5);
                    else
                    {
                        while((char)toupper(op)!='Y'||(char)toupper(op)!='N')
                        {
                            cout<<"Invalid choice!"<<endl;
                            cout<<"Enter Y to return to the main menu and N to exit"<<endl;
                            cin>>op;
                        }
                        if((char)toupper(op)=='Y')
                            displayOptions();
                        else if((char)toupper(op)=='N')
                            reservationOpt(5);
                    }
            }
            else
            {
                cout<<"Your Room is booked"<<endl;
                cout<<"For a total of ";
                for(int i=0;i<=MRCSub;i++)
                    total_days[PRSSub][current]+=days[PRSSub][current];
                cout<<total_days[PRSSub][current]<<" Days"<<endl;
                cout<<"On ";
                    for(int i=0;i<=MRCSub;i++)
                    {
                            if(i>0)cout<<" , ";
                        for(int j=0;j<3;j++)
                            cout<<arrivalDate[j][i][current]<<"|";
                    }
            }
            displayOptions();

    }
}



void cancelReservation()
{
        string password;
        cout<<"Enter password to cancel reservation"<<endl;
        while(password!=pass[current])
        {
        cin>>password;
        if(password==pass[current])
        {
            reservationStat[PRSSub][current]=false;
            for(int i=0;i<no[PRSSub][current];i++)
            {
                room_qt[i][PRSSub][current]={0};
                sum[i][PRSSub][current]={0};
                room_no[i][PRSSub][current]={0};
                selectedRooms[i][PRSSub][current]={""};
            }

                alottedRooms[PRSSub][current]={0};
                total_amt[PRSSub][current]={0};
                total_rooms[PRSSub][current]={0};
                no[PRSSub][current]=0;
                MRCSub=0;

            cout<<"Your Reservation is canceled"<<endl;
        }
        else
        {
            cout<<"Incorrect password, re enter"<<endl;
        }
    }
}
};


int main()
{
    Management m;
    m.displayOptions();
    return 0;
}
