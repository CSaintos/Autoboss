#pragma once

namespace ControlLayer {
	class BusinessCtr {
	protected:
		BusinessCtr();
		static BusinessCtr* businessCtr;
	private:
	public:
		// Can't be cloneable
		BusinessCtr(BusinessCtr& other) = delete;
		// Can't be assignable
		void operator=(const BusinessCtr&) = delete;
		// Gets BusinessLayer singleton object
		static BusinessCtr* GetInstance();

		/*
		Business Logic
		*/
	};
}