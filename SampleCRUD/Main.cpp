#include "CRUD.h"
#include <iostream>

using namespace std;

int main() {
	
	try {
		int option;
		string query;
		PostgresCRUD postgres;

		cout << "Welcome to Basic CRUD on PostGresSQL" << endl;
		cout << "Enter your Option for the CRUD operation" << endl;

		cin >> option;
		switch (option) {
		case 1:
			cout << "Create a Table"<<endl;
			query = "create table person(pid int primary key,fname varchar(20),lname varchar(20))";
			cout << postgres.createTable(query) << endl;
			break;
		case 2:
			cout << "Insert a Record" << endl;
			query = "insert into person(pid,fname,lname) values(3,'Preethi','Zinda')";
			cout << postgres.insertRecord(query) << endl;
			break;
		case 3:
			cout << "Update a Record" << endl;
			query = "update person set lname = 'Smitha' where pid=3";
			cout << postgres.updateRecord(query) << endl;
			break;
		case 4:
			cout << "Delete a Record" << endl;
			query = "delete from person where pid=2";
			cout << postgres.deleteRecord(query) << endl;
			break;
		case 5:
			cout << "Viewing the Records" << endl;
			query = "select * from person";
			postgres.getRecords(query);
			break;
		default:
			cout << "Enter a Valid option" << endl;
			break;
		}
		return 0;
	}
	catch (const std::exception& e) {
		cerr << e.what() << std::endl;
		return 1;
	}
}

