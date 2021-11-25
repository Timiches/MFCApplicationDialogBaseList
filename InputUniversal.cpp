// InputUniversal.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationDialogBaseList.h"
#include "InputUniversal.h"
#include "afxdialogex.h"


// Диалоговое окно InputUniversal

IMPLEMENT_DYNAMIC(InputUniversal, CDialogEx)

InputUniversal::InputUniversal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDDIALOD_UNIVERSAL_SET_NAME, pParent)
{

}

InputUniversal::~InputUniversal()
{
}

void InputUniversal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InputUniversal, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений InputUniversal
