#pragma once

class DatabaseCtr {
protected:
	DatabaseCtr();
	static DatabaseCtr* databaseCtr;
private:
public:
	// Do not clone
	inline DatabaseCtr(DatabaseCtr& other) = delete;
	// Do not assign
	void operator=(const DatabaseCtr&) = delete;
	// Control access to the singleton
	static DatabaseCtr* GetInstance();

	/*
	Business Logic
	*/

};