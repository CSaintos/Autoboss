#include "GUIHelper.h"
#include <afxwin.h>

using namespace GUILayer;

class CMyFrame : public CFrameWnd {
   public:
      CMyFrame() {
         Create(NULL, _T("MFC Application Tutorial"), WS_SYSMENU, CRect(90, 120, 550, 480));
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

void GUIHelper::test() {
    CExample theApp;
}