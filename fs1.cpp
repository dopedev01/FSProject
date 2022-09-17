#include<bits/stdc++.h>
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
    void time();
    void Depdisplay();
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

class Settings
{
    string VNO,Vowner_name,typeofveh,duration,buffer,cost;

public:
    void read();
    void pack();
    void unpack();
    void response(string);

}S;

int main()
{
    int ch,c,Vehical_Type;
    string Vno;
     string uname, pword,buffer;
    int choice;
    while(1)
{
    cout<<"                 ********VECHICAL MANAGMENT SYSTEM********\n";
    cout<<"enter 1 to login\n";
    cout<<"enter 2 to register\n";
    cin>>choice;
 /*1*/        switch(choice)
        {
         case 1:cout << "enter name: ";
        cin >> uname;
        cout << "enter password: ";
        cin >> pword;
                if(U.search1(uname,pword))
                    //cout<<"Login Succesfull \n";
                {
                    while(1)
                {
                    cout<<"\n1:CHECK-IN\n";
                    cout<<"\n2:CHECK-OUT\n";
                    cout<<"\n3:View Payment details\n";
                    cout<<"\n4:Departure timing\n";
                    cin>>ch;

          /*2*/    switch(ch)
        {
            case 1:  cout<<"\n1:ENTER VEHICAL DETAILS\n";
                    cout<<"\n2:GET ALL VECHICAL DETAILS\n";
                    cout<<"\n3:SEARCH VECHICAL DETAILS\n";
                    cout<<"\n4:MODIFY VEHICAL DETAILS\n";
                    cout<<"\n5:DELETE VEHICAL DETAILS\n";
                    cin>>c;
                  /*3*/  switch(c)
                    {

                        case 1: V.read();
                        V.pack();
                        V.write_file();
                        break;
                        case 2: V.read_file();
                        break;
                        case 3:cout<<"Enter VNO to search\n";
                        cin>>Vno;
                        V.search1(Vno);
                        break;
                         case 4: cout<<"Enter Vno to search\n";
                        cin>>Vno;
                        V.update(Vno);
                        break;
                        case 5: cout<<"Enter Vno to search\n";
                        cin>>Vno;
                        V.del(Vno);
                        break;




   /*3*/                   }break;
                case 2:  cout<<"\n1:ENTER VEHICAL NUMBER\n";
                         cin>>Vno;
                         V.search1(Vno);
                         V.unpack();
                         V.pack();
                         V.repack();
                         V.del(Vno);
                         V.time();
                           break;
                case 3:
                    cout<<"\nBIKE-AMOUNT FOR BIKE PARKING IS:50";
                    cout<<"\nCAR-AMOUNT FOR CAR PARKING IS:70";
                    cout<<"\nCRUZER-AMOUNT FOR CRUZER PARKING IS:120";
                    cout<<"\nTRUCK-AMOUNT FOR TRUCK PARKING IS:170";
                    V.Depdisplay();
                    break;
                    case 4:V.time();
                    break;
                   

        }//switch
        }
    }
                break;
        case 2:U.read();
    U.pack();
    U.write_file();
                break;
        case 3:while(1)
                {
                    string i;
                    cout<<"Enter Yes to continue\n";
                    cin>>i;
                    if(i=="yes")
                    {
                        S.read();
                        S.pack();
                        S.unpack();
                    }

                }

    /*1*/     }

}
}

void VehicalDetails::read()
{

    cout<<"Enter Vehical number\n";
    cin>>VNO;
    cout<<"Enter VEHICAL NAME\n";
    cin>>shortdes;
    cout<<"Enter Vehical Model\n";
    cin>>model;
    cout<<"Enter Vehical Type of Registration\n";
    cin>>regtype;
    cout<<"Enter Vehical Type\n";
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
    cout<<"VehicalNo:"<<VNO<<" Short Description:"<<shortdes<<" Model:"<<model<<"Type of Vehical Registration:"<<regtype<<"Type of Vechical:"<<typeofveh<<endl;
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
            cout<<"\nRecord is "<<buffer;
            cout<<"\nRecord Found at Position "<<recno;
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
        cout<<"Record not found\n";
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
            cout<<"\nRecord is "<<buffer;
            cout<<"\nRecord Found at Position "<<recno;
            pos=fp.tellg();
            flag=1;
            return pos;
        }
    }
    fp.close();
    if(!flag)
        cout<<"Record not found\n";
    return pos;
}
void VehicalDetails::update(string Vno)
{
    if(del(Vno))
    {
        cout<<"\nEnter details to modify\n";

        cin>>VNO>>shortdes>>model>>regtype>>typeofveh;
        //buffer.erase();
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
void VehicalDetails::time(){
string t;
cout<<endl<<"Enter Departure time:";
cin>>t;
cout<<t<<endl;
}


void VehicalDetails::Depdisplay(){
fstream fp;
fp.open("Checkout.txt",ios::in);
     
        getline(fp,buffer);
      
            
            if(typeofveh =="bike"){
            cout<<"Amount:50 rs";  
            }
            else if(typeofveh =="car"){
            cout<<"Amount:70 rs"; 
            } 
            else if(typeofveh =="cruzer"){
            cout<<"Amount:100 rs";  
            }
            else{
            cout<<"Amount:170 rs"; 
            }
     
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
    cout<<"Enter Username\n";
    cin>>cust_username;
    cout<<"Enter password\n";
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
            //cout<<"\nRecord is "<<buffer;
            cout<<"login succesfull\n ";//<<recno;
            flag=1;
             return flag;

        }
    }
    fp.close();
    if(!flag)
        cout<<"Login not succesfull\n";

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
void Settings::read()
{
    S.VNO=V.VNO;
    S.Vowner_name=U.cust_username;
    S.typeofveh=V.typeofveh;
}
void Settings::pack()
{
    fstream fp;
    buffer.erase();
    buffer+=VNO+"|"+Vowner_name+"|"+typeofveh+"|"+duration+"|"+cost+"$\n";

}
void Settings::unpack()
{
    S.VNO=V.VNO;
    S.Vowner_name=U.cust_username;
    S.typeofveh=V.typeofveh;
    cout<<"Vehical number is:\n"<<S.VNO;             
    cout<<"Customer name is:\n"<<S.Vowner_name;
    cout<<"Vehical number is\n:"<<S.typeofveh;

}
void Settings::response(string yes)
{
    fstream fp;
    string i;
    cout<<"Enter Yes to view";
    cin>>i;
}
