# baitaplonlthdt
bai tap lon
//TRUONG TAN HOAN
//6151071048
//NHOM 33 ÐOC FILE TXT
//209->240
//695->709
#include<conio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class EN_Person{
	private:
		string Name, Date, Address, Sex;
	public:
		EN_Person();
		~EN_Person();
		string getName();
		string getSex();
		string getAddress();
		string getDate();
		virtual void Inputs();
		virtual void Outputs();
		virtual void Add();
		virtual void Search();
		virtual void Sort();
		virtual void Delete();
};
EN_Person::EN_Person(){
	Name = "";
	Date = "";
	Address = "";
	Sex = "";
}
EN_Person::~EN_Person(){
	Name = "";
	Date = "";
	Address = "";
	Sex = "";
}
string EN_Person::getName(){
	return Name;
}
string EN_Person::getSex(){
	return Sex;
}
string EN_Person::getDate(){
	return Date;
}
string EN_Person::getAddress(){
	return Address;
}
void EN_Person::Inputs(){
	cout<<"\tFull name: "; fflush(stdin); getline(cin,Name);
	cout<<"\tSex: "; fflush(stdin); getline(cin,Sex);
	cout<<"\tDate: "; fflush(stdin); getline(cin,Date);
	cout<<"\tAddress: ";fflush(stdin); getline(cin,Address);
	
}
void EN_Person::Outputs(){
	cout<<left<<setw(30)<<Name<<setw(15)<<Sex<<setw(20)<<Date<<setw(20)<<Address;
}
void EN_Person::Add(){
}
void EN_Person::Delete(){
}
void EN_Person::Search(){
}
void EN_Person::Sort(){
}

class EN_Student:public EN_Person{
	private:
		EN_Student *STD;
		string Code, Class;
		float Score;
		int NumberEN_Students, Size;
	public:
		EN_Student();
		EN_Student(int m);
		~EN_Student();
		string getCode();
		float getScore();
		string getClass();
		void InputEN_Student();
		void Inputs();
		void Output();
		void Outputs();
		void Search();
		void Sort();
		void Add();
		void Delete();
		void ExportFile();
		void ReadFile();
		void Edit();
};
EN_Student::EN_Student(){
	STD = NULL;
	NumberEN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
EN_Student::EN_Student(int m){
	STD = new EN_Student [m];
	NumberEN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
EN_Student::~EN_Student(){
	delete [] STD;
	NumberEN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
string EN_Student::getCode(){
	return Code;
}
float EN_Student::getScore(){
	return Score;
}
string EN_Student::getClass(){
	return Class;
}

void EN_Student::InputEN_Student(){
	EN_Person::Inputs();
	cout<<"\tCode: "; fflush(stdin); getline(cin,Code);
	cout<<"\tClass: "; fflush(stdin); getline(cin,Class);
	cout<<"\tmedium score: "; cin>>Score;
}
void EN_Student::Inputs(){
	cout<<"Enter the number of Students: "; cin>>NumberEN_Students;
	cout<<endl;
	STD = new EN_Student [NumberEN_Students];
	for(int i=0; i<NumberEN_Students; i++){
		cout<<"\n\tEnter information of Student "<<i+1<<":"<<endl;
		STD[i].InputEN_Student();
		Size++;
	}
}
void EN_Student::Output(){
	EN_Person::Outputs();
	cout<<setw(20)<<Code<<setw(35)<<Class<<setw(10)<<Score;
}
void EN_Student::Outputs(){
	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
	<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
	for(int i=0; i<Size; i++){
		cout<<"\t"<<left<<setw(10)<<i+1;
		STD[i].Output();
		cout<<endl;
	}
	cout<<"\n\tnumber of students: "<<Size<<endl;
}

void EN_Student::Edit(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           CHUONG TRINH CHINH SUA       **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. Theo so thu tu                     **";
    cout<<"\n\t\t\t\t**  2. Theo ten                           **";
    cout<<"\n\t\t\t\t**  3. Theo so ma so sinh vien            **";
    cout<<"\n\t\t\t\t**  0. Thoat                              **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	string name;
	string mssv;
	cout<<"\n\tNhap lua chon cua ban: "; cin>>chooseSearch;
	switch(chooseSearch){
		case 1:
			int stt;
			cout<<"Edit student: "; cin>>stt;
			STD[stt-1].InputEN_Student();
			break;
		case 2:	
			cout<<"Name of student: "; fflush(stdin); getline(cin,name);
			for(int i=0; i<Size; i++){
				if ( name == STD[i].getName() ){
					STD[i].InputEN_Student();
				}
			}
			break;
		case 3:
			
			cout<<"Code of student: "; fflush(stdin); getline(cin,mssv);
			for(int i=0; i<Size; i++){
				if ( mssv == STD[i].getCode() ){
					STD[i].InputEN_Student();
				}
			}
			break;
			
		case 0:
			break;
			
		default:
			cout<<"\nThis function is not available! Please choose again!!!"<<endl;
			break;				
	}
}

void EN_Student::ExportFile(){
    
    ofstream file("Student_EN.txt");
    file<<endl<<setw(90)<<"********************"<<endl;
    file<<setw(90)<<"*** LIST STUDENS ***"<<endl;
    file<<setw(90)<<"********************"<<endl<<endl;
    file<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
	<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
	for(int i=0; i<Size; i++){
		file<<"\t"<<left<<setw(10)<<i+1
		<<left<<setw(30)<<STD[i].getName()<<setw(15)<<STD[i].getSex()
		<<setw(20)<<STD[i].getDate()<<setw(20)<<STD[i].getAddress()
		<<setw(20)<<STD[i].Code<<setw(35)<<STD[i].Class<<setw(10)<<STD[i].Score<<endl;
	}
	file<<"\n\tnumber of students: "<<Size<<endl;
    
    
    file.close();
}
 void EN_Student::ReadFile(){
 	ifstream ifs("Student_EN.txt");
   
    if(!ifs){
        cerr << "Error: file not opened." << endl;
    }
  
    char chr;

    while(ifs  >> chr){ 
        cout << chr << endl;
    }
    ifs.close();
 	/*ifstream infile; 
    infile.open("Student_EN.txt"); 
    cout << "\n===========================\n" ; 
    cout << "Doc du lieu co trong file!" << endl; infile >> data; 
    // ghi du lieu tren man hinh. 
    cout << data << endl; 
    // tiep tuc doc va hien thi du lieu. 
    infile >> data; cout << data << endl; 
    // dong file da mo. 
    infile.close();*/
 }

void EN_Student::Search(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           FUNCTION SEARCH              **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. By name                            **";
    cout<<"\n\t\t\t\t**  2. By code                            **";
    cout<<"\n\t\t\t\t**  3. By sex                             **";
    cout<<"\n\t\t\t\t**  4. By class                           **";
    cout<<"\n\t\t\t\t**  5. By address                         **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	int Count = 0;
	string Find;
	cout<<"\n\tEnter your selection: "; cin>>chooseSearch;
	switch(chooseSearch){
	case 1:
		cout<<"\nYou have selected the search function by name...\n"<<endl;
		cout<<"\n\tEnter name of Students: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
    	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
		<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
    	for (int i=0; i<Size; i++){
   			if (Find == STD[i].getName()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tFound "<<Count<<" students\n"<<endl;
		break;
							
	case 2:
		cout<<"\nYou have selected the search function by code...\n"<<endl;
		cout<<"\n\tEnter code of Student: "; fflush(stdin); getline (cin,Find);
		cout<<"\n\tStudent found\n"<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
		<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getCode()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
			}
		}
		break;
	case 3:
		cout<<"\nYou have selected the search function by sex...\n"<<endl;
		cout<<"\n\tEnter sex of Students: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
		<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getSex()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tFound "<<Count<<" students\n"<<endl;
		break;
	case 4:
		cout<<"\nYou have selected the search function by class...\n"<<endl;
		cout<<"\n\tEnter class of Students: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
		<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getClass()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tFound "<<Count<<" students\n"<<endl;
		break;
	case 5:
		cout<<"\nYou have selected the search function by address...\n"<<endl;
		cout<<"\n\tEnter address of Students: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
		<<"Date"<<setw(20)<<"Address"<<setw(20)<<"Code"<<setw(35)<<"Class"<<setw(10)<<"Score"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getAddress()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tFound "<<Count<<" students\n"<<endl;
		break;
	default:
		cout<<"\nThis function is not available! Please choose again!!!"<<endl;
		break;
	}
}
void EN_Student::Sort(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           FUNCTION SORT                **";
  	cout<<"\n\t\t\t\t**                                        **";
	cout<<"\n\t\t\t\t**  1. By name                            **";
	cout<<"\n\t\t\t\t**  2. By code                            **";
	cout<<"\n\t\t\t\t**  3. by medium score                    **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSort;
	cout<<"\n\tEnter your selection: "; cin>>chooseSort;
	switch(chooseSort){		
		case 1:
			cout<<"\nYou have selected the function to sort by name...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**               TYPE SORT                **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort;
      		cout<<"\n\tEnter your selection: "; cin>>TypeSort; cout<<endl;
			switch(TypeSort){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getName() > STD[j].getName()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getName() < STD[j].getName()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nThis program is not available!!!"<<endl;
					break;
			}
			cout<<"\nPress any key to return to the menu...\n";
			getch();
			break;			
		case 2:
			cout<<"\nYou have selected the function to sort by code...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**               TYPE SORT                **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort2;
      		cout<<"\n\tEnter your selection: "; cin>>TypeSort2; cout<<endl;
			switch(TypeSort2){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getCode() > STD[j].getCode()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
    							cout<<endl;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getCode() < STD[j].getCode()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
    							cout<<endl;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nThis program is not available!!!"<<endl;
					break;
			}
    		cout<<"\nPress any key to return to the menu...\n";
			getch();
			break;			
		case 3:
			cout<<"\nYou have selected the function to sort by score...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**               TYPE SORT                **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort3;
      		cout<<"\n\tEnter your selection: "; cin>>TypeSort3; cout<<endl;
			switch(TypeSort3){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getScore () > STD[j].getScore()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getScore () < STD[j].getScore()){
    							EN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nThis program is not available!!!"<<endl;
					break;	
			}
    		cout<<"\nPress any key to return to the menu...\n";
			getch();
			break;
		default:
			cout<<"\nThis function is not available! Please choose again!!!"<<endl;
			break;
				
	}
}
void EN_Student::Add(){
	int Num;
	cout<<"\nEEnter the amount to add: "; cin>>Num;
    EN_Student *Temp = new EN_Student [Size];
    for (int i=0; i<Size; i++){
    		Temp[i] = STD[i];
	}
	STD = new EN_Student [Size*2+Num];
	for (int i=0; i<Size; i++){
    	STD[i] = Temp[i];
	}
	for(int i=0; i<Num; i++){
		cout<<"\n\tAdd information of student "<<Size+1<<":"<<endl;
		STD[Size].InputEN_Student();
		Size++;
	}  				
    cout<<"\nSuccessfully added."<<endl;
    delete [] Temp;
}
void EN_Student::Delete(){
	string Erase;
	int Num2;
	cout<<"\nEnter the amount to delete: "; cin>>Num2;
	for(int i=0; i<Num2; i++){
		cout<<"\n\tEnter code of Student: "; fflush(stdin); getline (cin,Erase);
		for (int i=0; i<Size; i++){
    		if (Erase == STD[i].getCode()){
    			for (i; i<Size-1; i++){
    				for(int j=i+1; j<Size; j++){
    					STD[i] = STD[j];
					}
				}
			}
		}
		cout<<"\nSuccessfully deleted."<<endl;
		Size = Size - 1;
	}
}

class EN_Consultant:public EN_Person{
	private:
		EN_Consultant *C;
		int Lesson;
		string PhoneNumber, Charge;
		int NumberEN_Consultants, Size2;
	public:
		EN_Consultant();
		EN_Consultant(int m);
		~EN_Consultant();
		void InputEN_Consultant();
		void Inputs();
		void Output();
		void Outputs();
		void Search();
		void Sort();
		void Add();
		void Delete();
		void ExportFile();
		void ReadFile();
		void Edit();
		string getPhone();
};



EN_Consultant::EN_Consultant(){
	C = NULL;
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberEN_Consultants = 0;
}
EN_Consultant::EN_Consultant(int m){
	C = new EN_Consultant [m];
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberEN_Consultants = 0;
}
EN_Consultant::~EN_Consultant(){
	delete [] C;
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberEN_Consultants = 0;
}

string EN_Consultant::getPhone(){
	return PhoneNumber;
}

void EN_Consultant::InputEN_Consultant(){
	EN_Person::Inputs();
	cout<<"\tCharge of class: "; fflush(stdin); getline(cin,Charge);
	cout<<"\tLesson: "; cin>>Lesson;
	cout<<"\tPhone number: "; fflush(stdin); getline(cin,PhoneNumber);
}
void EN_Consultant::Inputs(){
	cout<<"Enter the number of Consultant: "; cin>>NumberEN_Consultants;
	cout<<endl;
	C = new EN_Consultant[NumberEN_Consultants];
	for(int i=0; i<NumberEN_Consultants; i++){
		cout<<"\n\tEnter information of Consultant "<<i+1<<": "<<endl;
		C[i].InputEN_Consultant();
		Size2++;
	}
}
void EN_Consultant::Output(){
	EN_Person::Outputs();
	cout<<left<<setw(15)<<Lesson<<setw(20)<<PhoneNumber<<setw(40)<<Charge;
}
void EN_Consultant::Outputs(){
	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
	<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Lesson"<<setw(20)<<"PhoneNumber"<<setw(40)<<"Charge"<<endl;
	for(int i=0; i<Size2; i++){				
		cout<<"\t"<<left<<setw(10)<<i+1;
		C[i].Output();
		cout<<endl;
	}
	cout<<"\n\tnumber of consultants: "<<Size2<<endl;
}

void EN_Consultant::Edit(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           FUNCTION EDIT                **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. By ordinal numbers                 **";
    cout<<"\n\t\t\t\t**  2. By name                            **";
    cout<<"\n\t\t\t\t**  3. By phone number                    **";
    cout<<"\n\t\t\t\t**  0. Exit                               **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	string name;
	string phone;
	cout<<"\n\tEnter your selection: "; cin>>chooseSearch;
	switch(chooseSearch){
		case 1:
			int stt;
			cout<<"Edit consultant: "; cin>>stt;
			C[stt-1].InputEN_Consultant();
			break;
		case 2:	
			cout<<"Name of consultant: "; fflush(stdin); getline(cin,name);
			for(int i=0; i<Size2; i++){
				if ( name == C[i].getName() ){
					C[i].InputEN_Consultant();
				}
			}
			break;	
		case 3:
			
			cout<<"Phone Number of consultant: "; fflush(stdin); getline(cin,phone);
			for(int i=0; i<Size2; i++){
				if ( phone == C[i].getPhone() ){
					C[i].InputEN_Consultant();
				}
			}
			break;
			
		case 0:
			break;
			
		default:
			cout<<"\nThis function is not available! Please choose again!!!"<<endl;
			break;				
	}
}


void EN_Consultant::ExportFile(){
    
    ofstream file("Consultant_EN.txt");
    file<<endl<<setw(90)<<"***********************"<<endl;
    file<<setw(90)<<"*** LIST CONSULTANT ***"<<endl;
    file<<setw(90)<<"***********************"<<endl<<endl;
    file<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(10)<<"Sex"<<setw(20)
	<<"Date"<<setw(20)<<"Address"<<setw(10)<<"Lesson"<<setw(20)<<"PhoneNumber"<<setw(40)<<"Charge"<<endl;
	for(int i=0; i<Size2; i++){
		file<<"\t"<<left<<setw(10)<<i+1
		<<left<<setw(30)<<C[i].getName()<<setw(10)<<C[i].getSex()
		<<setw(20)<<C[i].getDate()<<setw(20)<<C[i].getAddress()
		<<setw(10)<<C[i].Lesson<<setw(20)<<C[i].PhoneNumber<<setw(40)<<C[i].Charge<<endl;
	}
	file<<"\n\tnumber of consultants: "<<Size2<<endl;
    
    
    file.close();
}
void EN_Consultant::ReadFile(){
	ifstream ifs("Consultant_EN.txt");
   
    if(!ifs){
        cerr << "Error: file not opened." << endl;
    }
  
    char chr;

    while(ifs  >> chr){ 
        cout << chr << endl;
    }
    ifs.close();
}

void EN_Consultant::Search(){
	string SearchEN_Consultant;
	cout<<"\n\tEnter name of consultant: "; fflush(stdin); getline (cin,SearchEN_Consultant);
	cout<<"\n\tConsultant found"<<endl;
    cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Name"<<setw(15)<<"Sex"<<setw(20)
	<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Lesson"<<setw(20)<<"PhoneNumber"<<setw(40)<<"Charge"<<endl;
    for (int i=0; i<Size2; i++){
   		if (SearchEN_Consultant == C[i].getName()){
			cout<<"\t"<<left<<setw(10)<<i+1;
			C[i].Output();
			cout<<endl;
		}
	}
}
void EN_Consultant::Sort(){
	for(int i=0; i<Size2-1; i++){
    	for(int j=i+1; j<Size2; j++){
    		if (C[i].getName() < C[j].getName()){
    			EN_Consultant temp = C[i];
    			C[i] = C[j];
    			C[j] = temp;
    			cout<<endl;
			}
		}
	}
	Outputs();
}
void EN_Consultant::Add(){
	int AddNum;
	cout<<"\nEnter the amount to add: "; cin>>AddNum;
    EN_Consultant *Temp = new EN_Consultant [Size2];
    for (int i=0; i<Size2; i++){
    		Temp[i] = C[i];
	}
	C = new EN_Consultant [Size2*2+AddNum];
	for (int i=0; i<Size2; i++){
    	C[i] = Temp[i];
	}
	for(int i=0; i<AddNum; i++){
		cout<<"\n\tAdd information of Consultant "<<Size2+1<<":"<<endl;
		C[Size2].InputEN_Consultant();
		Size2++;
	}  				
    cout<<"\nSuccessfully added."<<endl;
    delete [] Temp;
}
void EN_Consultant::Delete(){
	string DeleteEN_Consultant;
	int DeleteNum;
	cout<<"\nEnter the amount to delete: "; cin>>DeleteNum;
	for(int i=0; i<DeleteNum; i++){
		cout<<"\n\tEnter name of Consultant: "; fflush(stdin); getline (cin,DeleteEN_Consultant);
		for (int i=0; i<Size2; i++){
    		if (DeleteEN_Consultant == C[i].getName()){
    			for (i; i<Size2-1; i++){
    				for(int j=i+1; j<Size2; j++){
    					C[i] = C[j];
					}
				}
			}
		}
		cout<<"\nSuccessfully deleted."<<endl;
		Size2 = Size2 - 1;
	}
}

class Manage{
	private:
		EN_Student s;
		EN_Consultant c;
		EN_Person *P;
	public:
		Manage();
		~Manage();
		void M_InputList(int Program);
		void M_OutputList(int Program);
		void M_Add(int Program);
		void M_Search(int Program);
		void M_Sort(int Program);
		void M_Delete(int Program);
		void M_ExportFile(int Program);
		void M_ReadFile(int Program);
		void M_Edit(int Program);
};
Manage::Manage(){
}

Manage::~Manage(){
}

void Manage::M_Edit(int Program){
	if(Program == 1){
		s.Edit();
	}else{
		c.Edit();
	}
}

void Manage::M_InputList(int Program){
    if(Program == 1){
		P = &s;
		P->Inputs();
	}else{
		P = &c;
		P->Inputs();
	}
}
void Manage::M_OutputList(int Program){
	if(Program == 1){
		P = &s;
		P->Outputs();
	}else{
		P = &c;
		P->Outputs();
	}
}

void Manage::M_ExportFile(int Program){
	
	if(Program == 1){
		s.ExportFile();
	}else{
		c.ExportFile();
	}
}

void Manage::M_ReadFile(int Program){
	
	if(Program == 1){
		s.ReadFile();
	}else{
		c.ExportFile();
	}
}
 



void Manage::M_Search(int Program){
	if(Program == 1){
		P = &s;
		P->Search();
	}else{
		P = &c;
		P->Search();
	}
}
void Manage::M_Sort(int Program){
	if(Program == 1){
		P = &s;
		P->Sort();
	}else{
		P = &c;
		P->Sort();
	}
}
void Manage::M_Add(int Program){
	if(Program == 1){
		P = &s;
		P->Add();
	}else{
		P = &c;
		P->Add();
	}
}
void Manage::M_Delete(int Program){
	if(Program == 1){
		P = &s;
		P->Delete();
	}else{
		P = &c;
		P->Delete();
	}
}

void MenuEN_Consultant(){
	cout<<"\n\t\t\t\t*********************************************************";
    cout<<"\n\t\t\t\t**            Consultant MANAGEMENT PROGRAM            **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t**  1. Enter Consultant list                           **";
    cout<<"\n\t\t\t\t**  2. Show list                                       **";
   	cout<<"\n\t\t\t\t**  3. Search Consultant                               **";
    cout<<"\n\t\t\t\t**  4. Sort Consultant                                 **";
    cout<<"\n\t\t\t\t**  5. Add Consultant                                  **";
    cout<<"\n\t\t\t\t**  6. Delete Consultant                               **";
    cout<<"\n\t\t\t\t**  7. Export to txt file                              **";
    cout<<"\n\t\t\t\t**  8. Edit                                            **";
    cout<<"\n\t\t\t\t**  9. Read file                                       **";
    cout<<"\n\t\t\t\t**  0. Exit                                            **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t*********************************************************";
}

void MenuEN_Student(){
	cout<<"\n\t\t\t\t*********************************************************";
    cout<<"\n\t\t\t\t**              STUDENT MANAGEMENT PROGRAM             **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t**  1. Enter Student list                              **";
    cout<<"\n\t\t\t\t**  2. Show list                                       **";
   	cout<<"\n\t\t\t\t**  3. Search Student                                  **";
    cout<<"\n\t\t\t\t**  4. Sort Student                                    **";
    cout<<"\n\t\t\t\t**  5. Add Student                                     **";
    cout<<"\n\t\t\t\t**  6. Delete Student                                  **";
    cout<<"\n\t\t\t\t**  7. Export to txt file                              **";
    cout<<"\n\t\t\t\t**  8. Edit                                            **";
    cout<<"\n\t\t\t\t**  9. ReadFile                                        **";
    cout<<"\n\t\t\t\t**  0. Exit                                            **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t*********************************************************";
}

void Menu(int Program){
	Manage M;
	while(true){
		if(Program == 1){
			MenuEN_Student();
		}else{
			MenuEN_Consultant();
		}
    	int choose;
    	cout<<"\n\tEnter your selection: "; cin>>choose;
    	switch(choose){
    		case 1:
    			cout<<"\nYou have selected the add list function...\n"<<endl;
    			M.M_InputList(Program);
    			cout<<"\nSuccessfully entered."<<endl;				
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 2:
				cout<<"\nYou have selected the list display function..."<<endl<<endl;
				M.M_OutputList(Program);
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 3:
				cout<<"\nYou have selected the search function..."<<endl;
				M.M_Search(Program);
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 4:
				cout<<"\nYou have selected the sort function..."<<endl;
				M.M_Sort(Program);
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 5:
				cout<<"\nYou have selected the add function..."<<endl;
				M.M_Add(Program);
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 6:
				cout<<"\nYou have selected the delete function..."<<endl;
				M.M_Delete(Program);
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 7:
				cout<<"\nYou have selected the function to export to txt file..."<<endl;
				M.M_ExportFile(Program);
				cout<<"\nExported file successfully...\n";
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 8:
				cout<<"\nYou have selected the edit function..."<<endl;
				M.M_Edit(Program);
				cout<<"\nEdit successfully...\n";
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 9:
				cout<<"\nYou have selected the function to export to txt file..."<<endl;
				M.M_ReadFile(Program);
				cout<<"\nExported file successfully...\n";
				cout<<"\nPress any key to return to the menu...\n";
				getch();
				break;
			case 0:
				cout<<"\nYou have selected an exit program!!!"<<endl;
				return ;
			default:
				cout<<"\nThis program is not available! Please choose again!!!"<<endl;
				cout<<"\nPress any key to return to the menu.\n";
				getch();
				break;		
		}
	}
}

void EN(){
	int Program;
	while(true){
		cout<<"\n\t\t\t\t*************************************************";
    	cout<<"\n\t\t\t\t**              MANAGEMENT PROGRAM             **";
   		cout<<"\n\t\t\t\t**                                             **";
    	cout<<"\n\t\t\t\t**        1. Student                           **";
    	cout<<"\n\t\t\t\t**        2. Consultant                        **";
    	cout<<"\n\t\t\t\t**        0. Exit                              **";
    	cout<<"\n\t\t\t\t**                                             **";
    	cout<<"\n\t\t\t\t*************************************************";
    	cout<<"\n\tEnter your selection: "; cin>>Program;
    	switch(Program){
    		case 1:
    			Menu(Program);
    			system("pause");
    			break;
    		case 2:
    			Menu(Program);
    			system("pause");
    			break;
    		case 0:
    			return ;
    		default:
    			cout<<"\nThis program is not available! Please choose again!!!"<<endl;
				system("pause");
				break;
		}
	}
}

//===============================================TIENG VIET==========================================
class VN_Person{
	private:
		string Name, Date, Address, Sex;
	public:
		VN_Person();
		~VN_Person();
		string getName();
		string getSex();
		string getAddress();
		string getDate();
		virtual void Inputs();
		virtual void Outputs();
		virtual void Add();
		virtual void Search();
		virtual void Sort();
		virtual void Delete();
};
VN_Person::VN_Person(){
	Name = "";
	Date = "";
	Address = "";
	Sex = "";
}
VN_Person::~VN_Person(){
	Name = "";
	Date = "";
	Address = "";
	Sex = "";
}
string VN_Person::getName(){
	return Name;
}
string VN_Person::getSex(){
	return Sex;
}
string VN_Person::getAddress(){
	return Address;
}
string VN_Person::getDate(){
	return Date;
}
void VN_Person::Inputs(){
	cout<<"\tHo ten: "; fflush(stdin); getline(cin,Name);
	cout<<"\tGioi tinh: "; fflush(stdin); getline(cin,Sex);
	cout<<"\tNgay sinh: "; fflush(stdin); getline(cin,Date);
	cout<<"\tDia chi: ";fflush(stdin); getline(cin,Address);
}
void VN_Person::Outputs(){
	cout<<left<<setw(30)<<Name<<setw(15)<<Sex<<setw(20)<<Date<<setw(20)<<Address;
}
void VN_Person::Add(){
}
void VN_Person::Delete(){
}
void VN_Person::Search(){
}
void VN_Person::Sort(){
}
class VN_Student:public VN_Person{
	private:
		VN_Student *STD;
		string Code, Class;
		float Score;
		int NumberVN_Students, Size;
	public:
		VN_Student();
		VN_Student(int m);
		~VN_Student();
		string getCode();
		float getScore();
		string getClass();
		void InputVN_Student();
		void Inputs();
		void Output();
		void Outputs();
		void Search();
		void Sort();
		void Add();
		void Delete();
		void ExportFile();
		void Edit();
};
VN_Student::VN_Student(){
	STD = NULL;
	NumberVN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
VN_Student::VN_Student(int m){
	STD = new VN_Student [m];
	NumberVN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
VN_Student::~VN_Student(){
	delete [] STD;
	NumberVN_Students = 0;
	Code = "";
	Class = "";
	Score = 0;
	Size = 0;
}
string VN_Student::getCode(){
	return Code;
}
float VN_Student::getScore(){
	return Score;
}
string VN_Student::getClass(){
	return Class;
}

void VN_Student::Edit(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           CHUONG TRINH CHINH SUA       **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. Theo so thu tu                     **";
    cout<<"\n\t\t\t\t**  2. Theo ten                           **";
    cout<<"\n\t\t\t\t**  3. Theo so ma so sinh vien            **";
    cout<<"\n\t\t\t\t**  0. Thoat                              **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	string name;
	string mssv;
	cout<<"\n\tNhap lua chon cua ban: "; cin>>chooseSearch;
	switch(chooseSearch){
		case 1:
			int stt;
			cout<<"Sinh vien thu: "; cin>>stt;
			STD[stt-1].InputVN_Student();
			break;
		case 2:	
			cout<<"Ho ten cua sinh vien: "; fflush(stdin); getline(cin,name);
			for(int i=0; i<Size; i++){
				if ( name == STD[i].getName() ){
					STD[i].InputVN_Student();
				}
			}
			break;
		case 3:
			
			cout<<"Ma so sinh vien: "; fflush(stdin); getline(cin,mssv);
			for(int i=0; i<Size; i++){
				if ( mssv == STD[i].getCode() ){
					STD[i].InputVN_Student();
				}
			}
			break;
			
		case 0:
			break;
			
		default:
			cout<<"\nKhong co chuc nang nay! Vui long nhap lai!!!"<<endl;
			break;				
	}
}

void VN_Student::InputVN_Student(){
	VN_Person::Inputs();
	cout<<"\tMa so sinh vien: "; fflush(stdin); getline(cin,Code);
	cout<<"\tLop: "; fflush(stdin); getline(cin,Class);
	cout<<"\tDiem trung binh: "; cin>>Score;
}
void VN_Student::Inputs(){
	cout<<"Nhap so luong sinh vien: "; cin>>NumberVN_Students;
	cout<<endl;
	STD = new VN_Student [NumberVN_Students];
	for(int i=0; i<NumberVN_Students; i++){
		cout<<"\n\tNhap thong tin sinh vien "<<i+1<<":"<<endl;
		STD[i].InputVN_Student();
		Size++;
	}
}
void VN_Student::Output(){
	VN_Person::Outputs();
	cout<<setw(20)<<Code<<setw(35)<<Class<<setw(10)<<Score;
}
void VN_Student::Outputs(){
	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
	<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
	for(int i=0; i<Size; i++){
		cout<<"\t"<<left<<setw(10)<<i+1;
		STD[i].Output();
		cout<<endl;
	}
	cout<<"\n\tSo luong sinh vien: "<<Size<<endl;
}

void VN_Student::ExportFile(){
    
    ofstream file("Student_Vi.txt");
    file<<endl<<setw(90)<<"***************************"<<endl;
    file<<setw(90)<<"*** DANH SACH SINH VIEN ***"<<endl;
    file<<setw(90)<<"***************************"<<endl<<endl;
    file<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
	<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
	for(int i=0; i<Size; i++){
		file<<"\t"<<left<<setw(10)<<i+1
		<<left<<setw(30)<<STD[i].getName()<<setw(15)<<STD[i].getSex()<<setw(20)<<STD[i].getDate()<<setw(20)<<STD[i].getAddress()
		<<setw(20)<<STD[i].Code<<setw(35)<<STD[i].Class<<setw(10)<<STD[i].Score<<endl;
	}
	file<<"\n\tSo luong sinh vien: "<<Size<<endl;
    
    
    file.close();
}

void VN_Student::Search(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           CHUC NANG TIM KIEM           **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. Ten                                **";
    cout<<"\n\t\t\t\t**  2. Ma so sinh vien                    **";
    cout<<"\n\t\t\t\t**  3. Gioi tinh                          **";
    cout<<"\n\t\t\t\t**  4. Lop                                **";
    cout<<"\n\t\t\t\t**  5. Que quan                           **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	int Count = 0;
	string Find;
	cout<<"\n\tNhap lua chon cua ban: "; cin>>chooseSearch;
	switch(chooseSearch){
	case 1:
		cout<<"\nBan da lua chon chuc nang tim kiem theo ten...\n"<<endl;
		cout<<"\n\tNhap ten can tim: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
    	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
		<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
    	for (int i=0; i<Size; i++){
   			if (Find == STD[i].getName()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tDa tim thay "<<Count<<" sinh vien."<<endl;
		break;
							
	case 2:
		cout<<"\nBan da lua chon chuc nang tim kiem theo ma so sinh vien...\n"<<endl;
		cout<<"\n\tNhap ma so sinh vien can tim: "; fflush(stdin); getline (cin,Find);
		cout<<"\n\tSinh vien duoc tim thay\n"<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
		<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getCode()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
			}
		}
		break;
	case 3:
		cout<<"\nBan da lua chon chuc nang tim kiem theo gioi tinh...\n"<<endl;
		cout<<"\n\tNhap gioi tinh sinh vien can tim: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
		<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getSex()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tDa tim thay "<<Count<<" sinh vien."<<endl;
		break;
	case 4:
		cout<<"\nBan da lua chon chuc nang tim kiem theo Lop...\n"<<endl;
		cout<<"\n\tNhap lop sinh vien can tim: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
		<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getClass()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tDa tim thay "<<Count<<" sinh vien."<<endl;
		break;
	case 5:
		cout<<"\nBan da lua chon chuc nang tim kiem theo dia chi...\n"<<endl;
		cout<<"\n\tNhap dia chi sinh vien can tim: "; fflush(stdin); getline (cin,Find);
		cout<<endl;
		cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho Ten"<<setw(15)<<"Gioi tinh"<<setw(20)
		<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(20)<<"MSSV"<<setw(35)<<"Lop"<<setw(10)<<"DiemTB"<<endl;
		for (int i=0; i<Size; i++){
    		if (Find == STD[i].getAddress()){
				cout<<"\t"<<left<<setw(10)<<i+1;
				STD[i].Output();
				cout<<endl;
				Count++;
			}
		}
		cout<<"\n\tDa tim thay "<<Count<<" sinh vien."<<endl;
		break;
	default:
		cout<<"\nKhong co chuc nang nay! Vui long chon lai!!!"<<endl;
		break;
	}
}
void VN_Student::Sort(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           CHUC NANG SAP XEP            **";
  	cout<<"\n\t\t\t\t**                                        **";
	cout<<"\n\t\t\t\t**  1. Theo ten                           **";
	cout<<"\n\t\t\t\t**  2. Theo ma so sinh vien               **";
	cout<<"\n\t\t\t\t**  3. Theo diem trung binh               **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSort;
	cout<<"\n\tNhap lua chon cua ban: "; cin>>chooseSort;
	switch(chooseSort){		
		case 1:
			cout<<"\nBan da lua chon chuc nang sap xep theo ten...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**               KIEU SAP XEP             **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort;
      		cout<<"\n\tNhap lua chon cua ban: "; cin>>TypeSort; cout<<endl;
			switch(TypeSort){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getName() > STD[j].getName()){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getName() < STD[j].getName()){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nKhong co chuc nang nay!!!"<<endl;
					break;
			}
			cout<<"\nNhan phim bat ki de tro lai menu...\n";
			getch();
			break;			
		case 2:
			cout<<"\nBan da lua chon chuc nang sap xep theo ma so sinh vien...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**              KIEU SAP XEP              **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort2;
      		cout<<"\n\tNhap lua chon cua ban: "; cin>>TypeSort2; cout<<endl;
			switch(TypeSort2){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getCode() > STD[j].getCode()){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
    							cout<<endl;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getCode() < STD[j].getCode()){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
    							cout<<endl;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nKhong co chuc nang nay!!!"<<endl;
					break;
			}
    		cout<<"\nNhan phim bat ki de tro lai menu...\n";
			getch();
			break;			
		case 3:
			cout<<"\nBan da lua chon chuc nang sap xep theo diem trung binh...\n"<<endl;
			cout<<"\n\t\t\t\t********************************************";
   			cout<<"\n\t\t\t\t**              KIEU SAP XEP              **";
  			cout<<"\n\t\t\t\t**                                        **";
	  		cout<<"\n\t\t\t\t**       1. A - Z                         **";
	  		cout<<"\n\t\t\t\t**       2. Z - A                         **";
	  		cout<<"\n\t\t\t\t**                                        **";
      		cout<<"\n\t\t\t\t********************************************";
      		int TypeSort3;
      		cout<<"\n\tNhap lua chon cua ban: "; cin>>TypeSort3; cout<<endl;
			switch(TypeSort3){
				case 1:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getScore () > STD[j].getScore () ){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				case 2:
					for(int i=0; i<Size-1; i++){
    					for(int j=i+1; j<Size; j++){
    						if (STD[i].getScore () < STD[j].getScore () ){
    							VN_Student temp = STD[i];
    							STD[i] = STD[j];
    							STD[j] = temp;
							}
						}
					}
					Outputs();
					break;
				default:
					cout<<"\nKhong co chuc nang nay!!!"<<endl;
					break;	
			}
    		cout<<"\nNhan phim bat ki de tro lai menu...\n";
			getch();
			break;
		default:
			cout<<"\nKhong co chuc nang nay! Vui long chon lai!!!"<<endl;
			break;
				
	}
}
void VN_Student::Add(){
	int Num;
	cout<<"\nNhap so luong can them: "; cin>>Num;
    VN_Student *Temp = new VN_Student [Size];
    for (int i=0; i<Size; i++){
    		Temp[i] = STD[i];
	}
	STD = new VN_Student [Size*2+Num];
	for (int i=0; i<Size; i++){
    	STD[i] = Temp[i];
	}
	for(int i=0; i<Num; i++){
		cout<<"\n\tNhap thong tin sinh vien "<<Size+1<<":"<<endl;
		STD[Size].InputVN_Student();
		Size++;
	}  				
    cout<<"\nDa them thanh cong."<<endl;
    delete [] Temp;
}
void VN_Student::Delete(){
	string Erase;
	int Num2;
	cout<<"\nNhap so luong can xoa: "; cin>>Num2;
	for(int i=0; i<Num2; i++){
		cout<<"\n\tNhap ma so sinh vien: "; fflush(stdin); getline (cin,Erase);
		for (int i=0; i<Size; i++){
    		if (Erase == STD[i].getCode()){
    			for (i; i<Size-1; i++){
    				for(int j=i+1; j<Size; j++){
    					STD[i] = STD[j];
					}
				}
			}
		}
		cout<<"\nDa xoa thanh cong."<<endl;
		Size = Size - 1;
	}
}

class VN_Consultant:public VN_Person{
	private:
		VN_Consultant *C;
		int Lesson;
		string PhoneNumber, Charge;
		int NumberVN_Consultants, Size2;
	public:
		VN_Consultant();
		VN_Consultant(int m);
		~VN_Consultant();
		void InputVN_Consultant();
		void Inputs();
		void Output();
		void Outputs();
		void Search();
		void Sort();
		void Add();
		void Delete();
		void ExportFile();
		void Edit();
		string getPhone();
};
VN_Consultant::VN_Consultant(){
	C = NULL;
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberVN_Consultants = 0;
}
VN_Consultant::VN_Consultant(int m){
	C = new VN_Consultant [m];
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberVN_Consultants = 0;
}
VN_Consultant::~VN_Consultant(){
	delete [] C;
	Lesson = 0;
	PhoneNumber = "";
	Charge = "";
	Size2 = 0;
	NumberVN_Consultants = 0;
}

string VN_Consultant::getPhone(){
	return PhoneNumber;
}

void VN_Consultant::InputVN_Consultant(){
	VN_Person::Inputs();
	cout<<"\tCo van hoc tap cua lop: "; fflush(stdin); getline(cin,Charge);
	cout<<"\tSo tiet day: "; cin>>Lesson;
	cout<<"\tSo dien thoai: "; fflush(stdin); getline(cin,PhoneNumber);
}
void VN_Consultant::Inputs(){
	cout<<"Nhap so luong co van hoc tap: "; cin>>NumberVN_Consultants;
	cout<<endl;
	C = new VN_Consultant[NumberVN_Consultants];
	for(int i=0; i<NumberVN_Consultants; i++){
		cout<<"\n\tNhap thong tin cua co van hoc tap "<<i+1<<": "<<endl;
		C[i].InputVN_Consultant();
		Size2++;
	}
}
void VN_Consultant::Output(){
	VN_Person::Outputs();
	cout<<left<<setw(15)<<Lesson<<setw(20)<<PhoneNumber<<setw(40)<<Charge;
}
void VN_Consultant::Outputs(){
	cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho ten"<<setw(15)<<"Gioi tinh"<<setw(20)<<"Ngay sinh"
	<<setw(20)<<"Dia chi"<<setw(15)<<"So Tiet Day"<<setw(20)<<"So Dien Thoai"<<setw(40)<<"Co van"<<endl;
	for(int i=0; i<Size2; i++){				
		cout<<"\t"<<left<<setw(10)<<i+1;
		C[i].Output();
		cout<<endl;
	}
	cout<<"\n\tSo luong co van hoc tap: "<<Size2<<endl;
}

void VN_Consultant::ExportFile(){
    
    ofstream file("Consultant_Vi.txt");
    file<<endl<<setw(90)<<"********************************"<<endl;
    file<<setw(90)<<"*** DANH SACH CO VAN HOC TAP ***"<<endl;
    file<<setw(90)<<"********************************"<<endl<<endl;
    file<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho ten"<<setw(15)<<"Gioi tinh"<<setw(20)<<"Ngay sinh"
	<<setw(20)<<"Dia chi"<<setw(15)<<"So Tiet Day"<<setw(20)<<"So Dien Thoai"<<setw(40)<<"Co van"<<endl;
	for(int i=0; i<Size2; i++){
		file<<"\t"<<left<<setw(10)<<i+1
		<<left<<setw(30)<<C[i].getName()<<setw(15)<<C[i].getSex()<<setw(20)<<C[i].getDate()<<setw(20)<<C[i].getAddress()
		<<setw(15)<<C[i].Lesson<<setw(20)<<C[i].PhoneNumber<<setw(40)<<C[i].Charge<<endl;
	}
	file<<"\n\tSo luong co van hoc tap: "<<Size2<<endl;
    
    
    file.close();
}

void VN_Consultant::Edit(){
	cout<<"\n\t\t\t\t********************************************";
   	cout<<"\n\t\t\t\t**           CHUONG TRINH CHINH SUA       **";
  	cout<<"\n\t\t\t\t**                                        **";
  	cout<<"\n\t\t\t\t**  1. Theo so thu tu                     **";
    cout<<"\n\t\t\t\t**  2. Theo ten                           **";
    cout<<"\n\t\t\t\t**  3. Theo so dien thoai                 **";
    cout<<"\n\t\t\t\t**  0. Thoat                              **";
	cout<<"\n\t\t\t\t**                                        **";
    cout<<"\n\t\t\t\t********************************************";
	int chooseSearch;
	string name;
	string phone;
	cout<<"\n\tNhap lua chon cua ban: "; cin>>chooseSearch;
	switch(chooseSearch){
		case 1:
			int stt;
			cout<<"Co van hoc tap thu: "; cin>>stt;
			C[stt-1].InputVN_Consultant();
			break;
		case 2:	
			cout<<"Ten cua co van hoc tap: "; fflush(stdin); getline(cin,name);
			for(int i=0; i<Size2; i++){
				if ( name == C[i].getName() ){
					C[i].InputVN_Consultant();
				}
			}
			break;	
		case 3:
			
			cout<<"So dien thoai cua co van hoc tap: "; fflush(stdin); getline(cin,phone);
			for(int i=0; i<Size2; i++){
				if ( phone == C[i].getPhone() ){
					C[i].InputVN_Consultant();
				}
			}
			break;
			
		case 0:
			break;
			
		default:
			cout<<"\nKhong co chuc nang nay! Vui long nhap lai!!!"<<endl;
			break;				
	}
}

void VN_Consultant::Search(){
	string SearchVN_Consultant;
	cout<<"\n\tNhap ten can tim: "; fflush(stdin); getline (cin,SearchVN_Consultant);
	cout<<"\n\t___Da tim thay___\n"<<endl;
    cout<<"\t"<<left<<setw(10)<<"STT"<<setw(30)<<"Ho ten"<<setw(15)<<"Gioi tinh"<<setw(20)
	<<"Ngay sinh"<<setw(20)<<"Dia chi"<<setw(15)<<"So Tiet Day"<<setw(20)<<"So Dien Thoai"<<setw(40)<<"Co van"<<endl;
    for (int i=0; i<Size2; i++){
   		if (SearchVN_Consultant == C[i].getName()){
			cout<<"\t"<<left<<setw(10)<<i+1;
			C[i].Output();
			cout<<endl;
		}
	}
}
void VN_Consultant::Sort(){
	for(int i=0; i<Size2-1; i++){
    	for(int j=i+1; j<Size2; j++){
    		if (C[i].getName() < C[j].getName()){
    			VN_Consultant temp = C[i];
    			C[i] = C[j];
    			C[j] = temp;
    			cout<<endl;
			}
		}
	}
	Outputs();
}
void VN_Consultant::Add(){
	int AddNum;
	cout<<"\nNhap so luong can them: "; cin>>AddNum;
    VN_Consultant *Temp = new VN_Consultant [Size2];
    for (int i=0; i<Size2; i++){
    		Temp[i] = C[i];
	}
	C = new VN_Consultant [Size2*2+AddNum];
	for (int i=0; i<Size2; i++){
    	C[i] = Temp[i];
	}
	for(int i=0; i<AddNum; i++){
		cout<<"\n\tNhap thong tin co van hoc tap "<<Size2+1<<":"<<endl;
		C[Size2].InputVN_Consultant();
		Size2++;
	}  				
    cout<<"\nDa them thanh cong."<<endl;
    delete [] Temp;
}
void VN_Consultant::Delete(){
	string DeleteVN_Consultant;
	int DeleteNum;
	cout<<"\nNhap so luong can xoa: "; cin>>DeleteNum;
	for(int i=0; i<DeleteNum; i++){
		cout<<"\n\tNhap ten can xoa: "; fflush(stdin); getline (cin,DeleteVN_Consultant);
		for (int i=0; i<Size2; i++){
    		if (DeleteVN_Consultant == C[i].getName()){
    			for (i; i<Size2-1; i++){
    				for(int j=i+1; j<Size2; j++){
    					C[i] = C[j];
					}
				}
			}
		}
		cout<<"\nDa xoa thanh cong."<<endl;
		Size2 = Size2 - 1;
	}
}

class VN_Manage{
	private:
		VN_Student s;
		VN_Consultant c;
		VN_Person *P;
	public:
		VN_Manage();
		VN_Manage(int m);
		~VN_Manage();
		void M_InputList(int Program);
		void M_OutputList(int Program);
		void M_Add(int Program);
		void M_Search(int Program);
		void M_Sort(int Program);
		void M_Delete(int Program);
		void M_ExportFile(int Program);
		void M_Edit(int Program);
};
VN_Manage::VN_Manage(){
}

VN_Manage::~VN_Manage(){
}

void VN_Manage::M_Edit(int Program){
	if(Program == 1){
		s.Edit();
	}else{
		c.Edit();
	}
}

void VN_Manage::M_InputList(int Program){
    if(Program == 1){
		P = &s;
		P->Inputs();
	}else{
		P = &c;
		P->Inputs();
	}
}
void VN_Manage::M_OutputList(int Program){
	if(Program == 1){
		P = &s;
		P->Outputs();
	}else{
		P = &c;
		P->Outputs();
	}
}

void VN_Manage::M_ExportFile(int Program){
	
	if(Program == 1){
		s.ExportFile();
	}else{
		c.ExportFile();
	}
}

void VN_Manage::M_Search(int Program){
	if(Program == 1){
		P = &s;
		P->Search();
	}else{
		P = &c;
		P->Search();
	}
}
void VN_Manage::M_Sort(int Program){
	if(Program == 1){
		P = &s;
		P->Sort();
	}else{
		P = &c;
		P->Sort();
	}
}
void VN_Manage::M_Add(int Program){
	if(Program == 1){
		P = &s;
		P->Add();
	}else{
		P = &c;
		P->Add();
	}
}
void VN_Manage::M_Delete(int Program){
	if(Program == 1){
		P = &s;
		P->Delete();
	}else{
		P = &c;
		P->Delete();
	}
}

void MenuVN_Consultant(){
	cout<<"\n\t\t\t\t*********************************************************";
    cout<<"\n\t\t\t\t**         CHUONG TRINH  QUAN LY CO VAN HOC TAP        **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t**  1. Nhap danh sach co van hoc tap                   **";
    cout<<"\n\t\t\t\t**  2. Hien thi danh sach                              **";
   	cout<<"\n\t\t\t\t**  3. Tim kiem co van hoc tap                         **";
    cout<<"\n\t\t\t\t**  4. Sap xep co van hoc tap                          **";
    cout<<"\n\t\t\t\t**  5. Them co van hoc tap                             **";
    cout<<"\n\t\t\t\t**  6. Xoa co van hoc tap                              **";
    cout<<"\n\t\t\t\t**  7. Xuat sang tep txt                               **";
    cout<<"\n\t\t\t\t**  8. Chinh sua                                       **";
    cout<<"\n\t\t\t\t**  0. Thoat                                           **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t*********************************************************";
}

void MenuVN_Student(){
	cout<<"\n\t\t\t\t*********************************************************";
    cout<<"\n\t\t\t\t**           CHUONG TRINH  QUAN LY SINH VIEN           **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t**  1. Nhap danh sach sinh vien                        **";
    cout<<"\n\t\t\t\t**  2. Hien thi danh sach                              **";
   	cout<<"\n\t\t\t\t**  3. Tim kiem sinh vien                              **";
    cout<<"\n\t\t\t\t**  4. Sap xep sinh vien                               **";
    cout<<"\n\t\t\t\t**  5. Them sinh vien                                  **";
    cout<<"\n\t\t\t\t**  6. Xoa sinh vien                                   **";
    cout<<"\n\t\t\t\t**  7. Xuat sang tep txt                               **";
    cout<<"\n\t\t\t\t**  8. Chinh sua                                       **";
    cout<<"\n\t\t\t\t**  0. Thoat                                           **";
    cout<<"\n\t\t\t\t**                                                     **";
    cout<<"\n\t\t\t\t*********************************************************";
}

void VN_Menu(int Program){
	VN_Manage M;
	while(true){
		if(Program == 1){
			MenuVN_Student();
		}else{
			MenuVN_Consultant();
		}
    	int choose;
    	cout<<"\n\tNhap lua chon cua ban: "; cin>>choose;
    	switch(choose){
    		case 1:
    			cout<<"\nBan da lua chon chuc nang nhap danh sach...\n"<<endl;
    			M.M_InputList(Program);
    			cout<<"\nNhap thanh cong."<<endl;				
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 2:
				cout<<"\nBan da lua chon chuc nang hien thi danh sach..."<<endl<<endl;
				M.M_OutputList(Program);
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 3:
				cout<<"\nBan da lua chon chuc nang tim kiem..."<<endl;
				M.M_Search(Program);
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 4:
				cout<<"\nBan da lua chon chuc nang sap xep..."<<endl;
				M.M_Sort(Program);
				break;
			case 5:
				cout<<"\nBan da lua chon chuc nang them..."<<endl;
				M.M_Add(Program);
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 6:
				cout<<"\nBan da lua chon chuc nang xoa..."<<endl;
				M.M_Delete(Program);
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 7:
				cout<<"\nBan da lua chon chuc Xuat sang tep txt..."<<endl;
				M.M_ExportFile(Program);
				cout<<"\nDa xuat file thanh cong...\n";
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			case 8:
				cout<<"\nBan da lua chon chuc chinh sua..."<<endl;
				M.M_Edit(Program);
				cout<<"\nChinh sua thanh cong...\n";
				cout<<"\nNhan phim bat ki de tro lai menu...\n";
				getch();
				break;
			
			case 0:
				cout<<"\nBan da lua chon chuc nang thoat chuong trinh!!!"<<endl;
				return ;
			default:
				cout<<"\nKhong co chuc nang nay! Vui long chon lai!!!"<<endl;
				cout<<"\nNhan phim bat ki de tro lai menu.\n";
				getch();
				break;		
		}
	}
}

void Vi(){
	int Program;
	while(true){
		cout<<"\n\t\t\t\t*************************************************";
    	cout<<"\n\t\t\t\t**             CHUONG TRINH QUAN LY            **";
   		cout<<"\n\t\t\t\t**                                             **";
    	cout<<"\n\t\t\t\t**        1. Sinh vien                         **";
    	cout<<"\n\t\t\t\t**        2. Co van hoc tap                    **";
    	cout<<"\n\t\t\t\t**        0. Thoat                             **";
    	cout<<"\n\t\t\t\t**                                             **";
    	cout<<"\n\t\t\t\t*************************************************";
    	cout<<"\n\tNhap lua chon cua ban: "; cin>>Program;
    	switch(Program){
    		case 1:
    			VN_Menu(Program);
    			system("pause");
    			break;
    		case 2:
    			VN_Menu(Program);
    			system("pause");
    			break;
    		case 0:
    			return ;
    		default:
    			cout<<"\nKhong co chuc nang nay! Vui long chon lai!!!"<<endl;
				system("pause");
				break;
		}
	}
}

int main(){
	system("color A");
	
	int Language;
	cout<<"\n\t"<<"1. English | 2. Tieng Viet "<<endl;
	cout<<"\n\tEnter your selection: "; cin>>Language;
	while(Language != 1 && Language != 2){
		cout<<"Please re-enter: "; cin>>Language;
	}
	if(Language == 1){
		EN();
	}else{
		Vi();
	}
}

