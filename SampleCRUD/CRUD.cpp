#include <iostream>
#include <pqxx/pqxx> 
#include "CRUD.h"

using namespace std;
using namespace pqxx;


	PostgresCRUD::PostgresCRUD() {

	}
	connection PostgresCRUD::getConnection()
	{
		connection c("dbname = sql_demo user = postgres password = exterro-123456 \
      hostaddr = 127.0.0.1 port = 5432");
		
		return c;
	}
	string  PostgresCRUD::createTable(string createQuery)
	{
		connection c = getConnection();
		work w(c);
		w.exec(createQuery);
		w.commit();
		return "Table Created Successfully";
	}
	string  PostgresCRUD::insertRecord(string insertQuery)
	{
		connection c = getConnection();
		work w(c);
		w.exec(insertQuery);
		w.commit();
		return "Inserted Successfully";
	}

	string PostgresCRUD::updateRecord(string updateQuery)
	{
		connection c = getConnection();
		work w(c);
		w.exec(updateQuery);
		w.commit();
		return "Updated Successfully";
	}

	void PostgresCRUD::getRecords(string fetchQuery)
	{
		connection c = getConnection();
		work w(c);
		result rows = w.exec(fetchQuery);
		for (int i = 0; i < rows.size(); i++) {
			auto [column1, column2, column3] = rows[i].as<string, string, string>();
			cout << column1 << "\t" << column2 << "\t" << column3 << "\n";
		}
		w.commit();
	}

	
	std::string PostgresCRUD::deleteRecord(std::string deleteQuery)
	{
		pqxx::connection c = getConnection();
		pqxx::work w(c);
		w.exec(deleteQuery);
		w.commit();
		return "Deleted Successfully";
	}





