#include<iostream>
#include<fstream> // For File Handling

using namespace std;

class temp {
	string name,phone,address,description,target;
	bool flag = true;
	fstream myFile;
	public:
		void addContact();
		void showAll();
		void searchContact();
}cms;


int main () {
	
	char option;
	cout << "\n\n\n\t\t---Welcome to CMS created by Safi---" << endl;
	cout << "\t\t\t1 -- Add Contact" << endl 
	     << "\t\t\t2 -- Show All Contact" << endl
	     << "\t\t\t3 -- Search Contact" << endl
	     << "\t\t\t0 -- Exit" << endl;
	cin >> option;
	cin.ignore();
	
	switch (option) {
		case '1': 
			cms.addContact();
			break;
		case '2':
			cms.showAll();
			break;
		case '3':
			cms.searchContact();
			break;
		case '0':
			cout << "Program Closed Successfully!";
			return 0;
}
	cout << endl;
	
	system("pause");
}

void temp :: addContact() {
	cout << "Enter Name :: " << endl; getline(cin, name);
	cout << "Enter Phone Number :: " << endl; getline(cin, phone);
	cout << "Enter Address :: " << endl; getline(cin, address);
	cout << "Enter Description :: " << endl; getline(cin, description);
	
	myFile.open("data.csv", ios :: out | ios :: app);
	
    if(myFile.is_open()) {
        myFile<<name<<","<<phone<<","<<address<<","<<description<<"\n";
        myFile.close();
    }

	cout << "Contact Added and Program Closed Successfully!";
} 

void temp :: showAll() {
	
	myFile.open("data.csv", ios :: in);
	
	if(myFile.is_open()) {
		
		getline(myFile,name,',');
		getline(myFile,phone,',');
		getline(myFile,address,',');
		getline(myFile,description,'\n');
	
	while(!myFile.eof()){
		cout << "Name is :: " << name <<endl;
		cout << "Phone is :: " << phone <<endl;
		cout << "Address is :: " << address <<endl;
		cout << "Description is :: " << description << endl << "-----------" << endl;
		
		getline(myFile,name,',');
		getline(myFile,phone,',');
		getline(myFile,address,',');
		getline(myFile,description,'\n');
	}
		cout <<  "All Contacts showed and Program Closed Successfully!";
	}
	else {
		cout <<  "No Data Available and Program Closed Successfully!";
	}
	myFile.close();
}

void temp :: searchContact() {
	cout << "Enter user phone to search other details :: ";
	cin >> target;
	
	myFile.open("data.csv", ios :: in);
	
	if(myFile.is_open()) {
		
		getline(myFile,name,',');
		getline(myFile,phone,',');
		getline(myFile,address,',');
		getline(myFile,description,'\n');
	
	while(!myFile.eof()){
		if(target == phone) {
			cout << "Name is :: " << name <<endl;
			cout << "Phone is :: " << phone <<endl;
			cout << "Address is :: " << address <<endl;
			cout << "Description is :: " << description << endl << "-----------" << endl;
			cout << endl <<  "Data Found and Program Closed Successfully!";
			flag = false;
			break;
		}
		getline(myFile,name,',');
		getline(myFile,phone,',');
		getline(myFile,address,',');
		getline(myFile,description,'\n');
	}
	
	}
	
	if(flag == true) {
		cout <<  "Data not Found and Program Closed Successfully!";
	}
	
	myFile.close();
	
}
