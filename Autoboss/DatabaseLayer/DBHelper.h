#pragma once

namespace DatabaseLayer {
	class DBHelper {
	private:
	public:
		DBHelper();
		void openDB();
		void closeDB();
	};
}