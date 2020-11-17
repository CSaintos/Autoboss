#include "GUIHelper.h"
#include <afxwin.h>

using namespace GUILayer;

//int main(){
//    CExample;
//	return 0;
//}

class CMyFrame : public CFrameWnd {
   public:
      CMyFrame() {
         Create(NULL, _T("MFC Application Tutorial"));
      }
};

class CExample : public CWinApp {
   BOOL InitInstance() {
      CMyFrame *Frame = new CMyFrame();
      m_pMainWnd = Frame;
      
      Frame->ShowWindow(SW_NORMAL);
      Frame->UpdateWindow();
      
      return TRUE;
   }
};