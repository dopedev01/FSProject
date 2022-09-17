#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class VehicalDetails
{
    public:
    string VNO,shortdes,model,buffer,regtype,typeofveh;
    void unpack();
    void read();
    void read_file();
    void write_file();
    void display();
    void pack();
    void repack();
    int del(string);
    void update(string);
    int search1(string);
    int research1(string);
}V;
class UserDetails
{
    public:
    string cust_username,cust_password,Email,Phno,address,buffer;
    void write_file();
    void pack();
    void read();
    int search1(string uname,string pword);
    void unpack();


}U;


void displayCheckedOut(){
	system("cat Checkout.txt");
}

int main()
{
    int ch,c,Vehical_Type;
    string Vno;
     string uname, pword,buffer;
    int choice;
    int a;
    while(1)
{
    cout<<"\n\n\t\t\t\t\t\t\t\t\t********VECHICAL PARKING MANAGMENT SYSTEM********\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout<<"\t\t\t\t\t\t\t\t\t|||||||||||||| Enter 1 to login    ||||||||||||||\n";
    cout<<"\t\t\t\t\t\t\t\t\t|||||||||||||| Enter 2 to register ||||||||||||||\n";
    cout<<"\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter your choice : ";
    cin>>choice;
       switch(choice)
        {
         case 1:cout << "\n\t\t\t\t\t\t\t\t\tEnter name: ";
        cin >> uname;
        cout << "\n\t\t\t\t\t\t\t\t\tEnter password: ";
        cin >> pword;
                if(U.search1(uname,pword))

                {
                    while(1)
                {
                    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||||| 1:CHECK-IN                  |||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||||| 2:CHECK-OUT                 |||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||||| 3:View Payment details      |||||||\n";
		    cout<<"\t\t\t\t\t\t\t\t\t||||||||||||| 4:View checked-out vehicles |||||||\n";
		    cout<<"\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
		    cout<<"\n\t\t\t\t\t\t\t\t\tEnter your choice : ";
                    cin>>ch;

            switch(ch)
        {
            case 1:
            	    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
            	    cout<<"\t\t\t\t\t\t\t\t\t||||||||||| 1:ENTER VEHICAL DETAILS    ||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||| 2:GET ALL VECHICAL DETAILS ||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||| 3:SEARCH VECHICAL DETAILS  ||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||| 4:MODIFY VEHICAL DETAILS   ||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t||||||||||| 5:DELETE VEHICAL DETAILS   ||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                    cout<<"\n\t\t\t\t\t\t\t\t\tEnter your choice : ";
                    cin>>c;
                    switch(c)
                    {

                        case 1: V.read();
                        V.pack();
                        V.write_file();
                        break;
                        case 2: V.read_file();
                        break;
                        case 3:cout<<"\t\t\t\t\t\t\t\t\tEnter VNO to search :";
                        cin>>Vno;
                        V.search1(Vno);
                        break;
                         case 4: cout<<"\t\t\t\t\t\t\t\t\tEnter Vno to search :";
                        cin>>Vno;
                        V.update(Vno);
                        break;
                        case 5: cout<<"\t\t\t\t\t\t\t\t\tEnter Vno to delete :";
                        cin>>Vno;
                        V.del(Vno);
                        break;
                        default : cout<<"\t\t\t\t\t\t\t\t\tInvalid input\n";
                        break;



                    }break;
                case 2:  cout<<"\n\t\t\t\t\t\t\t\t\tENTER VEHICAL NUMBER : ";
                         cin>>Vno;
                         a = V.search1(Vno);
                         V.unpack();
                         V.pack();
                         V.repack();
                         V.del(Vno);
			 if(a>0)cout<< endl<< "\n\t\t\t\t\t\t\t\t\t     ---- Vehicle checked out ----"<<endl;
                           break;
                case 3:
                    int vehicle_type;
                    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                    cout<<"\n\t\t\t\t\t\t\t\t\t 1-BIKE-AMOUNT FOR BIKE PARKING IS       -> 50";
                    cout<<"\n\t\t\t\t\t\t\t\t\t 2-CAR-AMOUNT FOR CAR PARKING IS         -> 70";
                    cout<<"\n\t\t\t\t\t\t\t\t\t 3-CRUZER-AMOUNT FOR CRUZER PARKING IS   -> 120";
                    cout<<"\n\t\t\t\t\t\t\t\t\t 4-TRUCK-AMOUNT FOR TRUCK PARKING IS     -> 170\n";
                    cout<<"\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                    cout << "\n\t\t\t\t\t\t\t\t\tEnter you choice for vehicle type : ";
                    cin>>vehicle_type;
                    if(vehicle_type >= 1 && vehicle_type<=4)
                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t_________________________________________________\n";
                        cout<<"\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                           cout << "\n\t\t\t\t\t\t\t\t\t>>>>>>> Total amount rs. ";
                    switch(vehicle_type){
                        case 1:
                            cout << "50.0 <<<<<<<<<<<<<<<<<<<"<<endl;
                            break;
                        case 2:
                            cout << "70.0 <<<<<<<<<<<<<<<<<<<"<<endl;
                            break;
                        case 3:
                            cout << "120.0 <<<<<<<<<<<<<<<<<<<"<<endl;break;
                        case 4: cout << "170.0 <<<<<<<<<<<<<<<<<<<"<<endl;break;
                        default: cout << "\n\t\t\t\t\t\t\t\t\tInvalid choice !!!!!"<<endl;
                    }
                    cout<<"\n\t\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||||||||||||||\n";
                    cout<<"\t\t\t\t\t\t\t\t\t_________________________________________________\n";
                    break;
		case 4:displayCheckedOut();

        }//switch
        }
    }
                break;
        case 2:U.read();
    U.pack();
    U.write_file();
                break;

        }

}
}

void VehicalDetails::read()
{

    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehical number :";
    cin>>VNO;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter VEHICAL NAME :";
    cin>>shortdes;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehical Model :";
    cin>>model;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehical Type of Registration :";
    cin>>regtype;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehical Type :";
    cin>>typeofveh;

}

void VehicalDetails::pack()
{
    buffer.erase();
    buffer+=VNO+"|"+shortdes+"|"+model+"|"+regtype+"|"+typeofveh+"$\n";
}

void VehicalDetails::read_file()
{
    fstream fp;
    fp.open("Project.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        unpack();
        if(!fp.eof())
            display();
    }
    fp.close();
}


void VehicalDetails::write_file()
{
    fstream fp;
    fp.open("Project.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
void VehicalDetails::display()
{
    cout<<"\t\t\t\t\t\t\t\t\tVehicalNo: "<<VNO<<" Short Description: "<<shortdes<<" Model: "<<model<<" Type of Vehical Registration: "<<regtype<<" Type of Vechical: "<<typeofveh<<endl;
}

void VehicalDetails::unpack()
{
    int i=0;
    VNO.erase();
    while(buffer[i]!='|')
        VNO+=buffer[i++];
    i++;
    shortdes.erase();
    while(buffer[i]!='|')
        shortdes+=buffer[i++];
    i++;
    model.erase();
    while(buffer[i]!='|')
    model+=buffer[i++];
    i++;
    regtype.erase();
    while(buffer[i]!='|')
    regtype+=buffer[i++];
    i++;
    typeofveh.erase();
    while(buffer[i]!='$')
    typeofveh+=buffer[i++];


}
int VehicalDetails::search1(string Vno)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("Project.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        recno++;
        unpack();
        if(VNO==Vno)
        {
            cout<<"\n\t\t\t\t\t\t\t\t\tRecord is : "<<buffer;
            cout<<"\n\t\t\t\t\t\t\t\t\tRecord Found at Position : "<<recno;
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
        cout<<"\t\t\t\t\t\t\t\t\tRecord not found\n";
    return pos;
}
int VehicalDetails::research1(string Vno)
{
    fstream fp;
    int recno=0,flag=0,pos=0;
    fp.open("Project.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        recno++;
        unpack();
        if(VNO==Vno)
        {
            cout<<"\n\t\t\t\t\t\t\t\t\tRecord is : "<<buffer;
            cout<<"\n\t\t\t\t\t\t\t\t\tRecord Found at Position : "<<recno;
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
        cout<<"\t\t\t\t\t\t\t\t\tRecord not found\n";
    return pos;
}
void VehicalDetails::update(string Vno)
{
    if(del(Vno))
    {
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter details to modify\n";
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehicle no : ";
        cin>>VNO;
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehicle Name : ";
        cin>>shortdes;
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehicle Model : ";
        cin>>model;
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehicle Type of registration : ";
        cin>>regtype;
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter Vehicle Type : ";
        cin>>typeofveh;
        pack();
        write_file();
    }
}
int VehicalDetails::del(string Vno)
{
    fstream fp;
    char mark='*',t;
    int pos,flag=0;
    pos=search1(Vno);
    if(pos)
    {
        fp.open("Project.txt",ios::in|ios::out);
        pos-=2;
        t=fp.get();
        while(t!='$'&&pos!=0)
        {
            pos--;
            fp.seekp(pos,ios::beg);
            t=fp.get();
        }
        if(pos!=0)
            fp.seekp(pos+2,ios::beg);
        else
            fp.seekp(pos,ios::beg);
            fp.put(mark);
            flag=1;
    }
    fp.close();
    if(!flag)
        return 0;
    else
        return 1;
}
void VehicalDetails::repack()
{
    fstream fp;
                            fp.open("Checkout.txt",ios::out|ios::app);
                            fp<<buffer;
                            fp.close();

}




void UserDetails::write_file()
{
    fstream fp;
    fp.open("cust_username_and_password.txt",ios::out|ios::app);
    fp<<buffer;
    fp.close();
}
void UserDetails::pack()
{
    buffer.erase();
    buffer+=cust_username+"|"+cust_password+"$\n";
}

void UserDetails::read()
{
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Username : ";
    cin>>cust_username;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter password : ";
    cin>>cust_password;
}
int UserDetails::search1(string uname,string pword)
{
    fstream fp;
    int recno=0,flag=0;
    fp.open("cust_username_and_password.txt",ios::in);
    while(!fp.eof())
    {
        buffer.erase();
        getline(fp,buffer);
        recno++;
        unpack();
        if(cust_username==uname && cust_password==pword)
        {
            cout<<"\n\t\t\t\t\t\t\t\t           ----*---- Login succesfull!!!! ----*----\n ";
            flag=1;
             return flag;

        }
    }
    fp.close();
    if(!flag)
        cout<<"\n\t\t\t\t\t\t\t\t           ----*---- Login not succesfull ----*----n";

    return flag;

}
void UserDetails::unpack()
{
    int i=0;
    cust_username.erase();

    while(buffer[i]!='|')
        cust_username+=buffer[i++];
    i++;
    cust_password.erase();
    while(buffer[i]!='$')
        cust_password+=buffer[i++];
}

