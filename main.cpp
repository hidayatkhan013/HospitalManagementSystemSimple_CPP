#include<iostream>
#include<conio.h>
#include <cstdlib>

using namespace std;

int index=0;
string Patient_name[50];
string entry_date[50];
string exit_date[50];
string diagnosis[50];
string medication[50];
string Doctor_name[50];
int No_of_days_in_hospital[50];

void Add_Patient(){
	int number=0;
	string write_date_string;
	char day[3],month[3],year[5];
	cout<<"\t\t     How Many Patients do you want to register : ";cin>>number;
	for(int i=0;i<number;i++){
		cout<<"\t\t     Enter Patients Name : ";cin>>Patient_name[index];
		cout<<"\t\t     Enter Patients Entry Date (DD/MM/YYYY) : ";
			cin.get(day,5,'/');
			cin.ignore(100,'/');
			cin.get(month,3,'/');
			cin.ignore(100,'/');
			cin.get(year,5,'\n');
			write_date_string=string(day)+"/"+string(month)+"/"+string(year);
			entry_date[index]=write_date_string;
			int num1 = atoi(day); 
		    int num2 = atoi(month); 
		    int num3 = atoi(year);   
		cout<<"\t\t     Enter Patients Exit Date (DD/MM/YYYY) : ";
		cin.get(day,5,'/');
		cin.ignore(100,'/');
		cin.get(month,3,'/');
		cin.ignore(100,'/');
		cin.get(year,5);
			write_date_string=string(day)+"/"+string(month)+"/"+string(year);
			exit_date[index]=write_date_string;
			int total_days=(atoi(day)-num1)+((atoi(month)-num2)*31)+((atoi(year)-num3)*365);
			No_of_days_in_hospital[index]=total_days;
		cout<<"\t\t     Enter Patients Patient diagnosis : ";cin>>diagnosis[index];
		cout<<"\t\t     Enter Patients medication : ";cin>>medication[index];
		cout<<"\t\t     Enter Patients Doctor : ";cin>>Doctor_name[index];
		cout<<endl;
		index++;
	}
	
}
void Display_Patient(){
	cout<<endl;
	cout<<endl;
	if(Patient_name[0]==""){
		cout<<"\t\t     No Patients present in system"<<endl;
	}
	else{
		cout<<"\t\t     Patients present in system is"<<endl;
	}
	
	for(int i=0;i<index;i++){
		cout<<"\t\t     Enter Patients Name : "<<Patient_name[i]<<endl;
	}
	
}

void Serach_Patient(string find_name){
	cout<<endl;
	bool flag=false;
	for(int i=0;i<index;i++){
		if(Patient_name[i]==find_name){
		cout<<"\t Patients Name : "<<Patient_name[i]<<endl;
		cout<<"\t Patients Patient diagnosis : "<<diagnosis[i]<<endl;
		cout<<"\t Patients medication : "<<medication[i]<<endl;
		cout<<"\t Patients Doctor : "<<Doctor_name[i]<<endl;
		cout<<"\t Patients No of Days : "<<No_of_days_in_hospital[i]<<endl;
		cout<<"\t Patients Fee : "<<No_of_days_in_hospital[i]*500<<endl;
				cout<<endl;
				flag=true;
		}
		
	}
	if(!flag){
				cout<<"\t Patients with Name "<<find_name<<" Not Found"<<endl;
		}
	
}

void login(){
	
	string pass ="";
   cout<<"\t\t------------------------------------------------------------";
   cout<<"\n\t\t\t     LOGIN HOSPITAL MANAGEMENT SYSTEM \n";	
   cout<<"\t\t------------------------------------------------------------\n\n";	
   cout << "\t\tEnter Password: ";cin>>pass;
   if(pass == "12345"){
      cout << "\n\n\t\tAccess Granted! \n";
      
      system ("CLS");
   }else{
      cout << "\n\n\t\tAccess Denied...\n\t\tPlease Try Again\n\n";
      system("CLS");
    login();
   }
	
	
}


int main(){
	login();
	while(1){
cout<<"\n\n\t\t\t HOSPITAL MANAGEMENT SYSTEM \n\n";
cout<<"\t\t _________________________________________________________________ \n";
cout<<"\t\t|                                           	                  |\n";
cout<<"\t\t|             1  >> Add New Patient                               |\n";
cout<<"\t\t|             2  >> Show All Patient                              |\n";
cout<<"\t\t|             3  >> Search Patient                                |\n";
cout<<"\t\t|             0  >> Exit the Program                              |\n";
cout<<"\t\t|_________________________________________________________________|\n\n";
int i;
cout<<"\t\t Please, Choose from above Options: ";cin>>i;
switch(i){
	case 0:
		cout<<"		----------Exiting----------  ";
		return 0;
	case 1:
		system("CLS");
		Add_Patient();
		break;
	case 2:
		system("CLS");
		Display_Patient();
		break;
	case 3:{
		system("CLS");
		string f_name;
		cout<<"		Enter Name of Patient to search : ";cin>>f_name;
		Serach_Patient(f_name);
		break;
	}
		
	default:
		cout<<"		Try again invalid entry "<<endl;
		break;
}

	
}
	
	return 0;
}
