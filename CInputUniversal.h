#pragma once


// Диалоговое окно CInputUniversal

class CInputUniversal : public CDialogEx
{
	DECLARE_DYNAMIC(CInputUniversal)

public:
	CInputUniversal(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CInputUniversal();

	CString Caption = _T("Input name");
	CString Name;
	int Type = NULL;
	int Action = NULL;
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDDIALOD_UNIVERSAL_SET_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUniversalSetNameOk();
	afx_msg void OnBnClickedUniversalSetNameNo();
	CString SetName;
};
