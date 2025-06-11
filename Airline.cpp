
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype> 
#include<unordered_map>
#include<sstream>
#include<conio.h>
#include<fstream>
#include<map>
using namespace std;

void book();
void cancel();
void check();
void register1();
void login();
void menu();
void exit();
void displayticket();
void domestic();
void international();
string doj;
void cancel(){
string name; 

int targetTicket;
system("cls");
cout<<"\n\tEnter Your Full Name : ";
cin.ignore();
getline(cin, name);
cout<<"\n\tEnter the ticket no. : ";
cin>>targetTicket;
string filename = "flights.txt";
    ifstream infile(filename);

    if (!infile) {
        cerr << "Error opening file!" << endl;
        
    }

    string content, line;
    string ticketNumber, statusToReplace, replacement;
   
    bool found = false;
int x1 = 1;
int temp3;
    while (getline(infile, line)) {
        
        if (line.find("Ticket No. : " + targetTicket) != string::npos) {
            stringstream ss2(line);
            
            string word1;
            ss2>>word1>>word1>>word1>>temp3;
            if(temp3 == targetTicket)
            found = true;
        }

        if (found && line.find("Status :") != string::npos && x1 == 1) {
            if (line.find("Conformed") != string::npos) {
                line.replace(line.find("Conformed"), 9, "Cancelled");  
                cout << "\n\tYour ticket has been cancelled." << endl;
                x1 = 0;
            } 
          
            found = false;  
            

        }

        content += line + "\n";
    }

    infile.close();

   
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file for writing!" << endl;
        
    }

    outfile << content;
    outfile.close();
    cout<<"\n\n\tGo to Main menu......?(press any key)";
     _getch();
     menu();
}
int x = 1612;
int src, dest;
map<string, string> detail;
bool verify(string name, string pass){

    ifstream read("flightdata.txt");
  string line;
  bool login = false;

  while(getline(read, line)){
        if(line.find("Name: " + name) != string::npos){
            detail["Name"] = line.substr(6);
            getline(read, line);
            detail["Birth"] = line.substr(15);
            getline(read, line);
            detail["Gender"] = line.substr(8);
            getline(read, line);
            detail["Nation"] = line.substr(13);
            getline(read, line);
            getline(read, line);

            getline(read, line);
            getline(read, line);
            detail["Password"] = line.substr(10);
        }
        if(detail["Password"] == pass){
            return true;
        } else {
            return false;
        }
  }
  
}
class Payment {
    protected :
    long int bank,card,date,cvv,user_id;
    char password[10];
    
    public :
    
    void pay_detail()
    {  
        system("cls");
        int choice1;
           cout << "\n\nHow would you like to pay ?\n";
        cout << "\n\1.Debit Card(1) \n\2.Credit Card(2) \n\3.Net Banking(3)";
        cout << "\n\nEnter your choice : ";
        cin >> choice1;
        
        switch(choice1)
        {
        case 1:
            cout << "\nEnter card no.: ";
            cin >> card;
            cout << "\nEnter expiry date: ";
            cin >> date;
            cout << "\nEnter CVV no.: ";
            cin >> cvv;
            cout << "\nTransaction Successful !\n";
            break;
        case 2:
            cout << "\nEnter card no.: ";
            cin >> card;
            cout << "\nEnter expiry date: ";
            cin >> date;
            cout << "\nEnter password: ";
            cin >> password;
            cout << "\nTransaction Successful !\n"; // tell the price also;
            break;
        case 3:
            cout << "Banks Available: \1.SBI(1) \2.Union(2) \3.HDFC(3) \4.IDBI(4) \5.Maharashtra Bank(5)";
            cout << "\nSelect your bank: ";
            cin >> bank;
            cout << "\nYou have selected: " << bank<<") Bank";
            cout << "\nEnter user id: ";
            cin >> user_id;
            cout << "\nEnter password: ";
            cin >> password;
            cout << "\nTransaction Successful, Transaction NO. "<<x<<"\n";
            break;
        default:
            cout << "\nWrong input entered.\nTry again\n\n";
             pay_detail();
        }
        x++;
        cout<<"\nPress any key to continue..."<<endl;
        _getch();
        displayticket();
    }
    
    };
    int traveler;
    map<int, int> prices;
void login(){
    int z = 0;
    system("cls");
    if(z == 1)  cout<<"\n\tWrong input! Please try again";
   
    cout<<endl<<endl;
    string name, password;
    cout<<"\t Loging to your account : \n";
    cout<<"-----------------------------------------------\n";
    cout << "\t Enter Full Name : ";
    cin.ignore();
    getline(cin, name);
    cout<<endl;
    cout << "\t Enter Password : ";
    cin >> password;
    if(verify(name, password)){
        cout<<"\n\t Login Successfull !";
        cout << "\n\n\t Press any key to proceed for payment...";
    _getch();
    Payment payment;
    payment.pay_detail();
    } else {
z = 1;
login();
    }
}
int y=0;
int ticketno = 1; 
ofstream tic("ticketcounter.txt", ios::app);
void writeTicket(int ticketno) {                       // tic should be in function not global
    tic << ticketno << endl;  
}
void displayticket(){
    system("cls");
    cout<<"\n\n";
    cout<<"\tName: "<< detail["Name"] <<"    "<<"DOB: "<< detail["Birth"] <<"    "<<"Nationality: "<< detail["Nation"] <<"    "<<"Gender: "<< detail["Gender"] <<endl;
    string city1, city2;
    switch(src){
        case 1:
        city1 = "London";
        break;
        case 2:
        city1 = "Dubai";
        break;
        case 3:
        city1 = "Tokyo";
        break;
        case 4:
        city1 = "Singapore";
        break;
        case 5:
        city1 = "NewYork";
        break;
        case 6:
        city1 = "Mumbai";
        break;
        case 7:
        city1 = "Delhi";
        break;
        case 8:
        city1 = "Chennai";
        break;
        case 9:
        city1 = "Kolkata";
        break;
        default: 
displayticket();
    }

    switch(dest){
        case 1:
        city2 = "London";
        break;
        case 2:
        city2 = "Dubai";
        break;
        case 3:
        city2 = "Tokyo";
        break;
        case 4:
        city2 = "Singapore";
        break;
        case 5:
        city2 = "NewYork";
        break;
        case 6:
        city2 = "Mumbai";
        break;
        case 7:
        city2 = "Delhi";
        break;
        case 8:
        city2 = "Chennai";
        break;
        case 9:
        city2 = "Kolkata";
        break;
        default:

        displayticket();

    }

    /*ifstream tick("flights.txt");
    string line;
    while(getline(cin, line)){
  
    }*/
    
    ofstream file1("flights.txt", ios::app);
    file1<<"Name : "<<detail["Name"]<<endl;
    file1<<"Password : "<<detail["Password"]<<endl;
    
    ifstream ticno("ticketcounter.txt");
       string tick2;
       int tick3;
       int z=0;
       while(getline(ticno, tick2)){
        stringstream ss1(tick2);
        ss1>>tick3;
        z=1;
       }
       if(z != 0){
       tick3++; 
       ticketno  = tick3;}
    ticno.close();
    writeTicket(ticketno);
    file1<<"Ticket No. : "<<ticketno<<endl; 
    
    
          file1<<"Starting City : "<<city1<<" -------------> "<<"Destination City : "<<city2<<endl;
          file1<<"Date of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
          cout <<"\n\tUSER ID : "<<x<<endl;
          

          cout<<"\tTicket No. : "<<ticketno<<endl;
          ticketno++;
          x++;
    switch(y){
        case 1: 
        
        cout <<"\n\tFlight Details :"<<endl;
        cout<<"\tStarting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
        cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
        
        cout << "\tVistara"<<endl;
        
        cout << "\tDeparture Time : 10:00"<<endl;
        cout<<"\tArrival Time: 14:05"<<endl;
        cout<<"\tNumber of people traveling : "<<traveler<<endl;
       cout<<"\tPrice : "<<prices[y]*traveler<<endl;
          
          
          file1 << "Vistara"<<endl;
          
          file1 << "Departure Time : 10:00"<<endl;
          file1<<"Arrival Time: 14:05"<<endl;
          file1<<"Number of people traveling : "<<traveler<<endl;
          file1<<"Price : "<<prices[y]*traveler<<endl;
        
        break;
        
        case 2: 
        
        cout <<"\n\tFlight Details :"<<endl;
        cout<<"\tStarting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
        cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
                    cout << "\tAir India"<<endl;
                   
                    cout << "\tDeparture Time : 14:00"<<endl;
                    cout<<"\tArrival Time: 18:05"<<endl;
                    cout<<"\tNumber of people traveling : "<<traveler<<endl;
                    cout<<"\tPrice : "<<prices[y]*traveler<<endl;
                    file1 << "Air India"<<endl;
                   
                    file1 << "Departure Time : 14:00"<<endl;
                    file1<<"Arrival Time: 18:05"<<endl;
                    file1<<"Number of people traveling : "<<traveler<<endl;
                    file1<<"Price : "<<prices[y]*traveler<<endl;
        break;
        
        case 3:
        
        cout <<"\n\tFlight Details :"<<endl;
        cout<<"\t Starting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
        cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
                    cout << "\tEmirats" << endl;
                
                    cout << "\tDeparture Time : 18:00" << endl;
                    cout<<"\tArrival Time: 22:05" << endl;  
                    cout<<"\tNumber of people traveling : "<<traveler<<endl;
                    cout<<"\tPrice : "<<prices[y]*traveler<<endl;  
                    
                    file1 << "Emirats" << endl;
                
                    file1 << "Departure Time : 18:00" << endl;
                    file1<<"Arrival Time: 22:05" << endl;  
                    file1<<"Number of people traveling : "<<traveler<<endl;
                    file1<<"Price : "<<prices[y]*traveler<<endl;   
        break;
        case 4: 
       
        cout << "\n\tFlight Details :"<<endl;
        cout<<"\t Starting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
        cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
        cout << "\tAir India"<<endl;
        
        cout << "\tDeparture Time : 08:00"<<endl;
        cout<<"\tArrival Time: 11:05"<<endl;
        cout<<"\tNumber of people traveling : "<<traveler<<endl;
        cout<<"\tPrice : "<<prices[1]*traveler<<endl;
        file1 << "Air India"<<endl;
        
        file1 << "Departure Time : 08:00"<<endl;
        file1<<"Arrival Time: 11:05"<<endl;
        file1<<"Number of people traveling : "<<traveler<<endl;
                    file1<<"Price : "<<prices[1]*traveler<<endl;
        
    break;
        
    case 5:
    
    cout <<"\n\tFlight Details :"<<endl;
    cout<<"\t Starting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
    cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
                    cout << "\tIndigo"<<endl;
                   
                    cout << "\tDeparture Time : 14:00"<<endl;
                    cout<<"\tArrival Time: 17:05"<<endl;
                    cout<<"\tNumber of people traveling : "<<traveler<<endl;
                    cout<<"\tPrice : "<<prices[2]*traveler<<endl;
                    file1 << "Indigo"<<endl;
                   
                    file1 << "Departure Time : 14:00"<<endl;
                    file1<<"Arrival Time: 17:05"<<endl;
                    file1<<"Number of people traveling : "<<traveler<<endl;
                    file1<<"Price : "<<prices[2]*traveler<<endl;
                  
    break;
    
    case 6:
    
    cout << "\n\tFlight Details :" << endl;
    cout<<"\t Starting City : "<<city1<<" -------------------->>> "<<"Destination City : "<<city2<<endl;
    cout<<"\tDate of jouney: "<<doj[0]<<doj[1]<<" / "<<doj[2]<<doj[3]<<" / "<<doj[4]<<doj[5]<<endl;
                    cout << "\tSpicejet" << endl;
                
                    cout << "\tDeparture Time : 19:00" << endl;
                    cout<<"\tArrival Time: 22:05" << endl;
                    cout<<"\tNumber of people traveling : "<<traveler<<endl;
                    cout<<"\tPrice : "<<prices[3]*traveler<<endl;
                    file1 << "Spicejet" << endl;
                
                    file1 << "Departure Time : 19:00" << endl;
                    file1<<"Arrival Time: 22:05" << endl;  
                    file1<<"Number of people traveling : "<<traveler<<endl;
                    file1<<"Price : "<<prices[3]*traveler<<endl;            
    break;
    }
    
    file1<< "Status : Conformed" <<endl;
    file1<<"----------------------------------------"<<endl;
    file1.close();
    cout<<endl;
    cout<<"\t\t\t Thank you for using us, Have a happy journey.";
    cout<<"\n\n";
    cout<<"\t----------------------------------------------------------------";
     cout<<"\n\t\t\tGo to Main menu......?(press any key)";
     cout<<"\n";
      cout<<"\t----------------------------------------------------------------";
      cout<<"\n\t";
     _getch();
     menu();
}
void register1(){
   string st, pass, name, gender, nation, email, address, doj;
   string phone;
    cout<<endl;
    cout<<"\n\t Already register ?(yes/no) ";
    cin>>st;
    if( st == "yes") {
    login();    
        
    }
system("cls");
cout<<"\n\n\t Tell Us About Yourself : "<<endl;
cout<<"\n\t Full Name : ";
cin.ignore();
getline(cin, name);
cout<<"\n\t Date Of Birth : ";
cin>>doj;

int t=0;
while(t == 0){
    cout<<"\n\t Gender : ";
cin>>gender;
for (char &c : gender) {  
    c = tolower(c);    
}
t++;
if(gender == "male" || gender == "female"){

} else {
    cout<<"\n\t Please enter right gender(male, female)";
t--;
}
}
cout<<"\n\t Nationality : ";
cin>>nation;
cout<<"\n\t Email id : ";    // email must be valid
cin>>email;
int p=0;
while(p == 0){
cout<<"\n\t Phone No. : ";  
cin>>phone;
p++;  
if(phone.size() != 10){
    cout<<"\n\t Please enter the valid phone no.";
    p--;
    
}
for (char c : phone) {
    if (!isdigit(c)) {    // Check if any character is NOT a digit
       cout<<"\n\t It must consists of only digits";
       p = 0;
    }
}  
}            //  for phone number should be 10 digit
cout<<"\n\t Address : ";
cin.ignore();  
    getline(cin, address);

cout<<"\n\t Create Strong Pasword : ";    
cin>>pass;       //Creat a condition so to get strong password
cout<<"\n---------------------------------------------------------";
cout<<"\n\t Registration Successfull";
ofstream file("flightdata.txt", ios::app);
if (!file) {  // If file opening failed
    cout << "\n Error: Could not open file for writing!" << endl;
    
}
file << "Name: " << name << "\n";
detail["Name"] = name;
    file<<"Date Of Birth: "<< doj <<"\n";
    detail["Birth"] = doj;
    file<<"Gender: "<< gender <<"\n";
    detail["Gender"] = gender;
    file<<"Nationality: "<< nation <<"\n";
    detail["Nation"] = nation;
    file << "Email: " << email << "\n";
    file << "Phone: " << phone << "\n";
    file<<"Address: "<< address <<"\n";
    file << "Password: " <<pass << "\n";
    detail["Password"] = pass;
    file << x << "\n";
    file << "-------------------------\n";
    file.close();
cout << "\n\tPress any key to proceed for payment...";
    _getch();
    Payment payment;
    payment.pay_detail();

}

void check(){
  string name;
  int ticket1;
  system("cls");
  cout<<"\n\t\tCheck you ticket here";
  cout<<"\n\n\t Enter Your Full Name : ";
  cin.ignore();
  getline(cin, name);
  cout<<"\n\t Enter the Ticket No. : ";
  cin>>ticket1;
cout<<"\n ------------------------------------------------------------------ ";
  cout<<"\n\n";

  ifstream file("flights.txt");
  if (!file.is_open()) {
    cerr << "Error: Unable to open file" << endl;
    menu();
}
  string data;
  int ticket;
 
  bool found = false;
  while(getline(file, data)){
       if(data.find("Name : " + name) != string::npos){

             getline(file, data);
             getline(file,data);
            stringstream ss(data);
            string temp;
            ss >> temp >> temp >> temp >> ticket;
                if(ticket1 == ticket){
                    found = true;
                    cout<<"\tFlight Details : "<<endl;
                getline(file, data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl;
                getline(file, data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl; 
                getline(file,data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl;
                getline(file,data);
                cout<<"\t"<<data<<endl;
                
                if(data.find("Cancelled") != string::npos){
                                 cout<<"\n\t\t Ticket was cancelled and is no longer available";                   
                } 
                } 
             break;
       }
  
  }
  if (!found) {
    cout << "\n\tNo matching record found for Name: " << name << " and Ticket No.: " << ticket1 << endl;
}
  file.close();
  cout<<"\n\n\tGo to Main menu......?(press any key)";
  _getch();
  menu();
}
void exit(){
    system("cls");
    cout<<endl<<endl;
cout<<"\t\t\t\t Thank You for visting. See you again!.";
}

void international(){
    
    
    cout << "Enter DateOfJourney(DDMMYY) : ";
    cin >> doj;
    cout<<"\n";
    cout << "\1.London(1) \2.Dubai(2) \3.Tokyo(3) \4.Singapore(4) \5.NewYork(5) " << endl << endl;
    cout << "\tEnter Source : ";
    cin >> src;
    cout << "\n\tEnter destination : " ;
    cin >> dest;
    cout<<"\n------------------------------------------------------------------------\n";
    cout << "\t \t \t  Flights Found" << endl << endl;

    if((src==1 && dest==3) || (src==3 && dest==1))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";

        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25000\tRefundable\n";
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.21500\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24000\tRefundable\n";
        prices[1] = 25000;
        prices[2] = 21500;
        prices[3] = 24000;
    }

    else if((src==1 && dest==4) || (src==4 && dest==1))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.25500\tRefundable\n";
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.21300\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.24650\t\tRefundable\n"; 
        prices[1] = 25500;
        prices[2] = 21300;
        prices[3] = 24650;
    }

    else if((src==1 && dest==5) || (src==5 || dest==1))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.52500\tRefundable\n";
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.59420\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.64892\tRefundable\n";
        prices[1] = 52500;
        prices[2] = 59420;
        prices[3] = 64892;
    }

    else if((src==2 && dest==3) || (src==3 && dest==2))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.17800\tRefundable\n";
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.14900\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs.18700\tRefundable\n";
        prices[1] = 17800;
        prices[2] = 14900;
        prices[3] = 18700;
    }

    else if((src==2 && dest==4) || (src==4 && dest==2))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.32000\tRefundable\n";                                     
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.38500\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs41259\tRefundable\n";     
        prices[1] = 32000;
        prices[2] = 38500;
        prices[3] = 41259;
    }

    else if(src==2 && dest==5 || (src==5 && dest==2))
    {
        cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
        cout << "\1.Vistara(1)\t10:00\t\t14:05\t\tRs.32500\tRefundable\n";
        cout << "\2.Air India(2)\t14:00\t\t18:05\t\tRs.47550\tRefundable\n";
        cout << "\3.Emirates(3)\t18:00\t\t22:05\t\tRs51478\tRefundable\n";
        prices[1] = 32500;
        prices[2] = 47550;
        prices[3] = 51478;

    }
    else if(src==dest)
    {
        cout << "wrong input entered.\nTry again\n\n\n"<< endl;
       international();
    }
    else
        {
        cout << "Wrong input entered.\nTry again\n\n\n";
        international();
        
    }
    int s;
    cout<<endl;
cout<<"\t \t \t Select Airline : ";
cin>>s;

switch(s){
   
case 1:
y=1;
break;

case 2:
y=2;
break;

case 3:
y=3;
break;

default: 
system("cls");
cout<<"\n\t\t\t\t Wrong Input Try again!";
international();

}
int test=0;
while(test == 0){
cout<<"\n\tEnter the number of people traveling : ";
cin>>traveler;
test++;
if (traveler <= 0) {
    cout << "\n\tInvalid number of travelers. Please enter a valid number." << endl;
    test--;
}
}
cout << "\n\tPress any key to continue...";
    _getch();
    system("cls");
register1(); 
}

void menu(){
    int x;
    system("cls");
    cout<<"\n";
    cout <<"\t\t\t\t\t  <><><><><><><><><><><><><><><><><><><><><><><>\n";
    cout << "\t\t\t\t\t  Book your Flight tickets at affordable prices!" << endl;
    cout <<"\t\t\t\t\t  <><><><><><><><><><><><><><><><><><><><><><><>";
    
    cout << "\n\n\t\t\t\t\t\t\t1.Book Flight(1) \n\t\t\t\t\t\t\t2.Cancel Fight(2) \n\t\t\t\t\t\t\t3.Check Ticket(3) \n\t\t\t\t\t\t\t4.Exit(4)" << endl;
    cout << "\n\t\t\t\t\t\t Please enter your choice: ";
           cin>>x;
     switch(x){
       case 1: 
       book();
       break;

       case 2: 
       cancel();
       break;

       case 3:
       check();
       break;

       case 4:
       exit();

     }       
}

void book(){
    int x;
    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t1.Domestic Fights(1) \n\t\t\t\t\t\t\t2.International Flights(2)" << endl;
              cout << "\n\t\t\t\t\t\t Please enter your option : ";
              cin>>x;
              system("cls");
              switch(x){
                    case 1:
                    domestic();
                    break;
                    case 2:
                    international();
                    break;
                    default: 

                    cout<<"\n\tWrong input please enter 1 or 2 \n";
                    book();
              }
}

void domestic(){
   
    cout << "\nEnter Date Of Journey(DDMMYY)." << " Please enter a valid date. ";
    
        cin >> doj;
        cout<<endl;
        cout << "\1.Mumbai(6) \t\2.Indraprast(New Delhi)(7) \t\3.Chennai(8) \t\4.Kolkata(9)" << endl << endl;
        cout << "\tEnter starting city : ";
        cin >> src;
        cout << "\tEnter destination : ";
        cin >> dest;
        if((src==6 && dest==7) || (src==7 && dest==6))
        {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
            prices[1] = 5000;
            prices[2] = 5500; 
            prices[3] = 6000;
        }

        else if((src==6 && dest==8) || (src==8 && dest==6))
        {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.5500\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
            prices[1] = 5000;
            prices[2] = 5500;
            prices[3] = 6000;
        }

        else if((src==6 && dest==9) || (src==9 && dest==6))
        {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.4000\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.4250\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.6100\t\tRefundable\n";
            prices[1] = 4000;
            prices[2] = 4250;
            prices[3] = 6100;
        }

        else if((src==7 && dest==8) || (src==8 && dest==7))
        {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.5400\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.2500\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.2890\t\tRefundable\n";
            prices[1] = 5400;
            prices[2] = 2500;
            prices[3] = 2829;
        }

        else if((src==7 && dest==9) || (src==9 && dest==7))
        {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.5000\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.4500\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.6000\t\tRefundable\n";
            prices[1] = 5000;
            prices[2] = 4500;
            prices[3] = 6000;
        }
        else if((src==8 && dest==9) || (src==9 && dest==8))
         {
            cout << "\t \t \tFlights Found." << endl << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.Air India(1)\t08:00\t\t11:05\t\tRs.5800\t\tRefundable\n";
            cout << "\2.Indigo(2)\t14:00\t\t17:05\t\tRs.5508\t\tRefundable\n";
            cout << "\3.Spicejet(3)\t19:00\t\t22:05\t\tRs.6050\t\tRefundable\n";
            prices[1] = 5800;
            prices[2] = 5508;
            prices[3] = 6050; 
        }
        else if(src==dest)
        {
            system("cls");
            cout << "\nSource and destination can't be same.\nTry again\n\n\n" << endl;
            domestic();
        }
        else
        {
            system("cls");
            cout <<"\nWrong input entered\nTry again\n\n\n" << endl;
            domestic();
        }
        int s;
        cout<<endl;
cout<<"\t \t \t Select Airline : ";
cin>>s;
cout<<"\n\t Flight Selected Successfully!";
switch(s){
    
case 1: 
    y=4;
break;
    
case 2:
y=5;      
break;

case 3:
y=6;      
break;

default: 
system("cls");
cout<<"\n\t\t\t\t Wrong Input Try again!";
domestic();
}
int test=0;
while(test == 0){
cout<<"\n\tEnter the number of people traveling : ";
cin>>traveler;
test++;
if (traveler <= 0) {
    cout << "\n\tInvalid number of travelers. Please enter a valid number." << endl;
    test--;
}
}
cout << "\n\tPress any key to continue...";
    _getch();
    system("cls");
register1(); 
}
int main(){

    // AIRLINE (PROJECT-4)
    cout<<"\t\t\t\t\t\t\t  NAMASKAR !  \n";

cout<<"\t\t\t\t Fast, Secure, and Reliable flight booking - Get ready to take off! \n\n";
menu();

}



