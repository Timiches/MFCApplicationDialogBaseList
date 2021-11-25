#pragma once
#include "Resource.h"

// Диалоговое окно CConfirmWindow

class CConfirmWindow : public CDialogEx
{
	DECLARE_DYNAMIC(CConfirmWindow)

public:
	CConfirmWindow(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CConfirmWindow();

	CString Caption = _T("Confirn this!!!");
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDDIALOG_CONFIRM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConfirmYes();
	afx_msg void OnBnClickedConfirmNo();
	CString label;
};
