// DBHelper.h
#pragma once
//#include <sql.h>
//#include <sqlext.h>

namespace DatabaseLayer {
	class DBHelper {
	private:
	public:
		inline DBHelper() {}
		void openDB();
		void closeDB();
	};
}