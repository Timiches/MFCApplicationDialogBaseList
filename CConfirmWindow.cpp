// CConfirmWindow.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationDialogBaseList.h"
#include "CConfirmWindow.h"
#include "afxdialogex.h"


// Диалоговое окно CConfirmWindow

IMPLEMENT_DYNAMIC(CConfirmWindow, CDialogEx)

CConfirmWindow::CConfirmWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDDIALOG_CONFIRM, pParent)
	, label(_T(""))
{

}

CConfirmWindow::~CConfirmWindow()
{
}

void CConfirmWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDTXT_CONFIRM, label);
}

BOOL CConfirmWindow::OnInitDialog() {
	CDialogEx::OnInitDialog();

	SetWindowText(Caption);

	return TRUE;
}

void CConfirmWindow::OnOK(){
	CDialog::OnOK();
}

void CConfirmWindow::OnCancel(){
	CDialog::OnCancel();
}

BEGIN_MESSAGE_MAP(CConfirmWindow, CDialogEx)
	ON_BN_CLICKED(IDBTN_CONFIRM_YES, &CConfirmWindow::OnBnClickedConfirmYes)
	ON_BN_CLICKED(IDBTN_CONFIRM_NO, &CConfirmWindow::OnBnClickedConfirmNo)
END_MESSAGE_MAP()


// Обработчики сообщений CConfirmWindow


void CConfirmWindow::OnBnClickedConfirmYes(){
	CConfirmWindow::OnOK();
}


void CConfirmWindow::OnBnClickedConfirmNo(){
	CConfirmWindow::OnCancel();
}
