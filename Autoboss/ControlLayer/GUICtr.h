#pragma once

namespace ControlLayer {
	class GUICtr {
	protected:
		GUICtr();
		static GUICtr* guiCtr;
	private:
	public:
		// Can't be cloneable
		GUICtr(GUICtr& other) = delete;
		// Can't be assignable
		void operator=(const GUICtr&) = delete;
		// Gets GUICtr singleton object
		static GUICtr* GetInstance();

		/*
		Business Logic
		*/
	};
}