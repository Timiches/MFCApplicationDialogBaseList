// CInputStudent.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationDialogBaseList.h"
#include "CInputStudent.h"
#include "afxdialogex.h"
#include "Defines.h"


// Диалоговое окно CInputStudent

IMPLEMENT_DYNAMIC(CInputStudent, CDialogEx)

CInputStudent::CInputStudent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDDIALOG_STUDENT_CREATE, pParent)
{

}

CInputStudent::~CInputStudent()
{
}

void CInputStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDLISTBOX_STUDENT_CREATE_GROUPS, m_GroupsList);
	DDX_Text(pDX, IDEDITF_IDEDITF_STUDENT_CREATE_SECNAME, SecName);
	DDX_Text(pDX, IDEDITF_STUDENT_CREATE_NAME, FirName);
	DDX_Text(pDX, IDEDITF_STUDENT_CREATE_MIDNAME, MidName);
	DDX_Text(pDX, IDEDITF_STUDENT_CREATE_BIRTHYEAR, BirthYear);
	DDV_MinMaxUInt(pDX, BirthYear, 1900, 2020);
	DDX_Text(pDX, IDEDITF_STUDENT_CREATE_MARK, Mark);
	DDV_MinMaxUInt(pDX, Mark, 0, 100);
}

BOOL CInputStudent::OnInitDialog() {
	CDialogEx::OnInitDialog();

	if (Action == CREATE) {
		SetDefID(IDBTN_STUDENT_CREATE_NEXT);
		GetDlgItem(IDBTN_STUDENT_CREATE_NEXT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDLISTBOX_STUDENT_CREATE_GROUPS)->EnableWindow(TRUE);
	}
	else {
		SetDefID(IDBTN_STUDENT_CREATE_OK);
		GetDlgItem(IDBTN_STUDENT_CREATE_NEXT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDLISTBOX_STUDENT_CREATE_GROUPS)->EnableWindow(FALSE);
	}
	/*Action == CREATE ? GetDlgItem(IDBTN_STUDENT_CREATE_NEXT)->ShowWindow(SW_SHOW) : GetDlgItem(IDBTN_STUDENT_CREATE_NEXT)->ShowWindow(SW_HIDE); 
	Action == CREATE ? GetDlgItem(IDLISTBOX_STUDENT_CREATE_GROUPS)->EnableWindow(TRUE) : GetDlgItem(IDLISTBOX_STUDENT_CREATE_GROUPS)->EnableWindow(FALSE);
	GetDlgItem(IDBTN_STUDENT_CREATE_NEXT)->ModifyStyle(BS_DEFPUSHBUTTON, BS_PUSHBUTTON, 1);*/
	
	m_GroupsList.ResetContent();
	for (int i = 0; i < length; i++) {
		m_GroupsList.AddString((LPCTSTR)BufferArray.GetAt(i));
	}
	m_GroupsList.SetCurSel(CurSel);
	BufferArray.RemoveAll();
	SetActiveSurName();

	return FALSE;
}

//void CInputStudent::ResetData(){
//	m_GroupsList.ResetContent();
//	SecName.
//	FirName.ResetContent();
//	MidName.ResetContent();
//	BirthYear.ResetContent();
//	Mark.ResetContent();
//}

void CInputStudent::TrimBoth(CString Str) {
	Str.TrimLeft();
	Str.TrimRight();
}

void CInputStudent::AddStudent() {
	TrimBoth(SecName);
	TrimBoth(FirName);
	TrimBoth(MidName);

	TempGroup = new Group(BufferText);
	GroupListRef->find(*TempGroup);
	GroupListRef->GetCurInf(TempGroup);
	TempStudent = new Student(FirName, SecName, MidName, BirthYear, Mark);
	TempGroup->addBeginElem(*TempStudent);
	delete TempStudent;
}

void CInputStudent::ChangeStudent() {
	TrimBoth(SecName);
	TrimBoth(FirName);
	TrimBoth(MidName);

	TempStudent->setFirstName(FirName);
	TempStudent->setSecondName(SecName);
	TempStudent->setMidName(MidName);
	TempStudent->setBirthYear(BirthYear);
	TempStudent->setMark(Mark);
}

void CInputStudent::SetActiveSurName() {
	CWnd* Wnd = GetDlgItem(IDEDITF_IDEDITF_STUDENT_CREATE_SECNAME);

	Wnd->SetFocus();
	((CEdit*)(Wnd))->SetSel(0, 100);
}

BEGIN_MESSAGE_MAP(CInputStudent, CDialogEx)
	ON_BN_CLICKED(IDBTN_STUDENT_CREATE_OK, &CInputStudent::OnBnClickedStudentCreateOk)
	ON_BN_CLICKED(IDBTN_STUDENT_CREATE_CANCEL, &CInputStudent::OnBnClickedStudentCreateCancel)
	ON_BN_CLICKED(IDBTN_STUDENT_CREATE_NEXT, &CInputStudent::OnBnClickedStudentCreateNext)
END_MESSAGE_MAP()


// Обработчики сообщений CInputStudent


void CInputStudent::OnBnClickedStudentCreateOk() {
	if (UpdateData() == TRUE) {
		m_GroupsList.GetLBText(m_GroupsList.GetCurSel(), BufferText);
		Action == CREATE ? AddStudent() : ChangeStudent();
		CurSel = m_GroupsList.GetCurSel();
		CInputStudent::OnOK();
	}
}


void CInputStudent::OnBnClickedStudentCreateCancel() {
	CInputStudent::OnCancel();
}


void CInputStudent::OnBnClickedStudentCreateNext() {
	if (UpdateData() == TRUE) {
		m_GroupsList.GetLBText(m_GroupsList.GetCurSel(), BufferText);
		AddStudent();
		SetActiveSurName();
	}
}
