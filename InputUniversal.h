#pragma once


// Диалоговое окно InputUniversal

class InputUniversal : public CDialogEx
{
	DECLARE_DYNAMIC(InputUniversal)

public:
	InputUniversal(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~InputUniversal();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDDIALOD_UNIVERSAL_SET_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
