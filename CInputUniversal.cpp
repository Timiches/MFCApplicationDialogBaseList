// CInputUniversal.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationDialogBaseList.h"
#include "CInputUniversal.h"
#include "afxdialogex.h"
#include "Defines.h"
#include "Student.h"
#include "UniversalList.h"

// Диалоговое окно CInputUniversal

IMPLEMENT_DYNAMIC(CInputUniversal, CDialogEx)

CInputUniversal::CInputUniversal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDDIALOD_UNIVERSAL_SET_NAME, pParent)
	, SetName(_T(""))
{

}

CInputUniversal::~CInputUniversal()
{
}

void CInputUniversal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDEDITF_UNIVERSAL_SET_NAME, SetName);
}


BOOL CInputUniversal::OnInitDialog() {
	CDialogEx::OnInitDialog();

	SetWindowText(Caption);
	GetDlgItem(IDEDITF_UNIVERSAL_SET_NAME)->SetWindowText(_T(""));
	GetDlgItem(IDEDITF_UNIVERSAL_SET_NAME)->SetFocus();

	return FALSE;
}

BEGIN_MESSAGE_MAP(CInputUniversal, CDialogEx)
	ON_BN_CLICKED(IDBTN_UNIVERSAL_SET_NAME_OK, &CInputUniversal::OnBnClickedUniversalSetNameOk)
	ON_BN_CLICKED(IDBTN_UNIVERSAL_SET_NAME_NO, &CInputUniversal::OnBnClickedUniversalSetNameNo)
END_MESSAGE_MAP()


// Обработчики сообщений CInputUniversal


void CInputUniversal::OnBnClickedUniversalSetNameOk(){
	UpdateData(TRUE);
	SetName.TrimLeft();
	SetName.TrimRight();
	if (SetName != __TEXT("")) {
		CDialog::OnOK();
	}
	else
		this->MessageBox(__TEXT("You must enter the name!"), __TEXT("Error"), MB_OK | MB_ICONWARNING);
}


void CInputUniversal::OnBnClickedUniversalSetNameNo(){
	CDialog::OnCancel();
}
