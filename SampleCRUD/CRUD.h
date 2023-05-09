#pragma once
#include <pqxx/pqxx> 
class PostgresCRUD {
public:
	PostgresCRUD();
	pqxx::connection getConnection();
	std::string createTable(std::string createQuery);
	std::string insertRecord(std::string insertQuery);
	std::string updateRecord(std::string updateQuery);
	void getRecords(std::string fetchQuery);
	std::string deleteRecord(std::string deleteQuery);
};

