
// MFCApplicationDialogBaseListDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplicationDialogBaseList.h"
#include "MFCApplicationDialogBaseListDlg.h"
#include "afxdialogex.h"
#include "Defines.h"
#include "SelectUniversal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCApplicationDialogBaseListDlg



CMFCApplicationDialogBaseListDlg::CMFCApplicationDialogBaseListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATIONDIALOGBASELIST_DIALOG, pParent)
{

	m_StudName = _T("");
	m_GroupName = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDialogBaseListDlg::DoDataExchange(CDataExchange* pDX) { //отвекчает за обмен данными между переменными и елемента управления в окне описаного идентификатором
	
	//DDX_Text - для обмена текстовыми данными,
	//DDX_Check - для обмена данными логического типа,
	//DDX_Radio - для обмена данными типа int с группой радиокнопок,
	//DDX_Control - для обмена данными типа CWnd с некоторым элементом управления.
	//Механизм DDV (Dialog Data Validation) позволяет устанавливать правила для вводимых значений.
	
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDLISTBOX_MAIN_STUDENT_INFO, m_ListStudInfo);
	DDX_Control(pDX, IDLISTBOX_MAIN_STUDENT, m_ListStudents);
	DDX_Control(pDX, IDLISTBOX_MAIN_GROUP, m_ListGroups);
	DDX_Text(pDX, IDEDITBOX_MAIN_STUDENT, m_StudName);
	DDX_Text(pDX, IDEDITBOX_MAIN_GROUP, m_GroupName);


}

BEGIN_MESSAGE_MAP(CMFCApplicationDialogBaseListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDBTN_MAIN_FACULTY_CREATE,OnBnClickedMainFacultyCreate)
	ON_BN_CLICKED(IDBTN_MAIN_FACULTY_CHANGE_NAME, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyChangeName)
	ON_BN_CLICKED(IDBTN_MAIN_FACULTY_GET_NAME, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyGetName)
	ON_BN_CLICKED(IDBTN_MAIN_FACULTY_DELETE, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyDelete)
	ON_BN_CLICKED(IDBTN_MAIN_GROUP_ADD, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupAdd)
	ON_BN_CLICKED(IDBTN_MAIN_GROUP_CHANGE, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupChange)
	ON_BN_CLICKED(IDBTN_MAIN_GROUP_DELETE, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupDelete)
	ON_BN_CLICKED(IDBTN_MAIN_STUDENT_ADD, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentAdd)
	ON_BN_CLICKED(IDBTN_MAIN_STUDENT_CHANGE, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentChange)
	ON_BN_CLICKED(IDBTN_MAIN_STUDENT_DELETE, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentDelete)
	ON_BN_CLICKED(IDBTN_MAIN_GROUP_DELETE_ALL, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupDeleteAll)
	ON_BN_CLICKED(IDBTN_MAIN_STUDENT_DELETE_ALL, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentDeleteAll)
	ON_BN_CLICKED(IDBTN_MAIN_EXIT, &CMFCApplicationDialogBaseListDlg::OnBnClickedMainExit)
	ON_COMMAND(ID_HELP_ABOUT, &CMFCApplicationDialogBaseListDlg::OnHelpAbout)
	ON_COMMAND(ID_FILE_EXIT, &CMFCApplicationDialogBaseListDlg::OnFileExit)
	ON_LBN_SELCHANGE(IDLISTBOX_MAIN_GROUP, &CMFCApplicationDialogBaseListDlg::OnLbnSelchangeMainGroupList)
	ON_LBN_SELCHANGE(IDLISTBOX_MAIN_STUDENT, &CMFCApplicationDialogBaseListDlg::OnLbnSelchangeMainStudentList)
	//ON_LBN_KILLFOCUS(IDLISTBOX_MAIN_STUDENT, &CMFCApplicationDialogBaseListDlg::OnLbnKillfocusMainStudent)
	//ON_LBN_KILLFOCUS(IDLISTBOX_MAIN_GROUP, &CMFCApplicationDialogBaseListDlg::OnLbnKillfocusMainGroup)
	ON_EN_CHANGE(IDEDITBOX_MAIN_GROUP, &CMFCApplicationDialogBaseListDlg::OnEnChangeMainGroup)
	ON_EN_CHANGE(IDEDITBOX_MAIN_STUDENT, &CMFCApplicationDialogBaseListDlg::OnEnChangeMainStudent)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplicationDialogBaseListDlg

BOOL CMFCApplicationDialogBaseListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	DisableFaculty();
	m_ListStudInfo.ModifyStyle(LBS_SORT, 0);

	return FALSE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplicationDialogBaseListDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplicationDialogBaseListDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else {
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplicationDialogBaseListDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}

CString CMFCApplicationDialogBaseListDlg::GetUniversalName(CString caption) {
	InputUniversal.Caption = caption;
	if (InputUniversal.DoModal() == IDOK)
		SetFacultyBtnsEnable(true);
	return InputUniversal.SetName;
}

void CMFCApplicationDialogBaseListDlg::DeleteAllGroups() {
	GroupList.DelAll();
	m_ListGroups.ResetContent();
	MessageBox(__TEXT("Deletion success!"), __TEXT("Success!"), MB_OK);

}

//void CMFCApplicationDialogBaseListDlg::OutStud() {
//	DelStudentList(false);
//	if (SetSelectedStudentBtnsEnable(!GroupList)) {
//		for (GroupList.SetHead(); GroupList.GetCurInf() == SUCCESS_OPER; OutStr(m_ListStudents, MaxExtListStud, S->SName), ++G);
//		G.GetHeadTailInf(S);
//		OutStudInfo(*S);
//		OldStudSelect = LB_ERR;
//	}
//}

void CMFCApplicationDialogBaseListDlg::OutStudInfo(Student& S) {
	CString Buf;
	m_ListStudInfo.ResetContent();

	Buf.Format(__TEXT("SecondName:       %s"), S.SecName);
	m_ListStudInfo.AddString((LPCTSTR)Buf);

	Buf.Format(__TEXT("Name:                  %s"), S.Name);
	m_ListStudInfo.AddString((LPCTSTR)Buf);

	Buf.Format(__TEXT("MidleName:          %s"), S.MidName);
	m_ListStudInfo.AddString((LPCTSTR)Buf);

	Buf.Format(__TEXT("Birth Year:           %i"), S.BirthYear);
	m_ListStudInfo.AddString((LPCTSTR)Buf);

	Buf.Format(__TEXT("Average Mark:     %i"), S.MidMark);
	m_ListStudInfo.AddString((LPCTSTR)Buf);

}

//void CMFCApplicationDialogBaseListDlg::ChangeSelect(SelectUniversal::BaseSelect *Base, CListBox& ListBox, int &OldSelect, bool IsGroup) {
//	int Sel = ListBox.GetCurSel();
//	if (Sel != LB_ERR && Sel != OldSelect) {
//		//SetSelectedActions(true);
//		if (OldSelect == LB_ERR)
//			Base->SetHead((OldSelect = Sel >= (OldSelect = ListBox.GetCount() - 1) >> 1 ? OldSelect : 0) == 0);
//		SelectUniversal::ChangePos(Base, Sel, OldSelect);
//		IsGroup ? OutStud(), SetGroupBtnsEnable(true) : OutStudInfo(*TempStud);
//	}
//}

//----------------------------------------SetEnable-----------------------------------------------------------------

void CMFCApplicationDialogBaseListDlg::SetButtonState(WORD BtnID[], WORD Length, bool State) {
	for (WORD i = 0; i < Length; i++)
		GetDlgItem(BtnID[i])->EnableWindow(State);
}

bool CMFCApplicationDialogBaseListDlg::SetFacultyBtnsEnable(bool State) {
	WORD wID[] = {IDBTN_MAIN_FACULTY_CHANGE_NAME, IDBTN_MAIN_FACULTY_GET_NAME, IDBTN_MAIN_FACULTY_DELETE, IDBTN_MAIN_GROUP_ADD, IDLISTBOX_MAIN_GROUP, IDEDITBOX_MAIN_GROUP};
	GetDlgItem(IDBTN_MAIN_FACULTY_CREATE)->EnableWindow(!State);
	SetButtonState(wID, _LENGTH(wID, WORD), State);
	GetDlgItem(IDEDITBOX_MAIN_GROUP)->SetWindowText("");
	return State;
}

bool CMFCApplicationDialogBaseListDlg::SetGroupBtnsEnable(bool State) {
	WORD wID[] = {IDBTN_MAIN_STUDENT_ADD, IDBTN_MAIN_GROUP_DELETE_ALL };
	SetButtonState(wID, _LENGTH(wID, WORD), State);
	return State;
}

bool CMFCApplicationDialogBaseListDlg::SetSelectedGroupBtnsEnable(bool State) {
	WORD wID[] = {IDBTN_MAIN_GROUP_CHANGE, IDBTN_MAIN_GROUP_DELETE, IDLISTBOX_MAIN_STUDENT,IDEDITBOX_MAIN_STUDENT };
	SetButtonState(wID, _LENGTH(wID, WORD), State);
	GetDlgItem(IDEDITBOX_MAIN_STUDENT)->SetWindowText("");
	return State;
}

bool CMFCApplicationDialogBaseListDlg::SetSelectedStudentBtnsEnable(bool State) {
	WORD wID[] = {IDBTN_MAIN_STUDENT_CHANGE, IDBTN_MAIN_STUDENT_DELETE, IDLISTBOX_MAIN_STUDENT_INFO, IDBTN_MAIN_STUDENT_DELETE_ALL };
	SetButtonState(wID, _LENGTH(wID, WORD), State);
	return State;
}

void CMFCApplicationDialogBaseListDlg::SetEnableStudInf(bool State) {
	m_ListStudInfo.ResetContent();
	SetSelectedStudentBtnsEnable(State);
}

void CMFCApplicationDialogBaseListDlg::SetEnableStudents(bool State) {
	m_ListStudents.ResetContent();
	SetSelectedGroupBtnsEnable(State);
	SetEnableStudInf(State);
}

void CMFCApplicationDialogBaseListDlg::SetEnableGroups(bool State) {
	m_ListGroups.ResetContent();
	SetGroupBtnsEnable(State);
	SetEnableStudents(State);
}

void CMFCApplicationDialogBaseListDlg::DisableFaculty() {
	SetFacultyBtnsEnable(false);
	SetEnableGroups(false);
}
//-----------------------------------------BlockEnter---------------------------------------------------

void CMFCApplicationDialogBaseListDlg::OnOk() {
	return;
}

void CMFCApplicationDialogBaseListDlg::DelStudentList(bool Disable) {
	DelStudInfoList();
	m_ListStudents.ResetContent();
	if (Disable) {
		SetSelectedStudentBtnsEnable(false);
	}
}

void CMFCApplicationDialogBaseListDlg::DelStudInfoList() {
	m_ListStudInfo.ResetContent();
}

bool CMFCApplicationDialogBaseListDlg::ChekSimilarName() {
	for (int i = 0; i < m_ListGroups.GetCount(); i++) {
		m_ListGroups.GetText(i, BufferText);
		if (BufferText == InputUniversal.SetName) {
			return false;
		}
	}
	return true;
}

//-----------------------------Work with faculty----------------------------------------

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyCreate() {
	GroupList.SetName(GetUniversalName(_T("Input faculty name:")));
}


void CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyChangeName() {
	GroupList.SetName(GetUniversalName(_T("Input new faculty name:")));
}


void CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyGetName() {
	MessageBox(GroupList.GetName(), _T("Faculty name"));
}


void CMFCApplicationDialogBaseListDlg::OnBnClickedMainFacultyDelete() {
	if (MessageBox(_T("Do you realy want to DELETE the FACULTY?"), _T("Deletion confirm"), MB_YESNO) == IDYES) {
		DeleteAllGroups();
		DisableFaculty();
	}
}

//-----------------------------Work with Groups---------------------------------------------

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupAdd() {
	InputUniversal.Caption = _T("Input group name:");
	if (InputUniversal.DoModal() == IDOK) {
		if (ChekSimilarName()) {
			Group TempStudentList((LPCTSTR)InputUniversal.SetName);
			GroupList.addBeginElem(TempStudentList);
			m_ListGroups.AddString((LPCTSTR)InputUniversal.SetName);
			GetDlgItem(IDBTN_MAIN_GROUP_DELETE_ALL)->EnableWindow(TRUE);
		}
		else {
			MessageBox(_T("This group already exists!"), _T("Error!"), MB_OK);
			OnBnClickedMainGroupAdd();
		}
	}
}

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupChange() {
	InputUniversal.Caption = _T("Input new group name:");
	if (InputUniversal.DoModal() == IDOK) {
		if (ChekSimilarName()) {
			m_ListGroups.DeleteString(m_ListGroups.GetCurSel());
			StudentList->SetName((LPCTSTR)InputUniversal.SetName);
			m_ListGroups.AddString((LPCTSTR)InputUniversal.SetName);
			
			int Sel = 0;
			
			m_ListGroups.GetText(Sel, BufferText);
			while (InputUniversal.SetName != BufferText) {
				Sel++;
				m_ListGroups.GetText(Sel, BufferText);
			}
			m_ListGroups.SetCurSel(Sel);

			Sel = m_ListStudents.GetCurSel();
			OnLbnSelchangeMainGroupList();
			if (Sel >= 0) {
				m_ListStudents.SetCurSel(Sel);
				OnLbnSelchangeMainStudentList();
			}
		}
		else {
			MessageBox(_T("This group already exists!"), _T("Error!"), MB_OK);
			OnBnClickedMainGroupChange();
		}
	}
}

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupDelete() {
	int Sel = m_ListGroups.GetCurSel();
	m_ListGroups.DeleteString(Sel);
	GroupList.DelCurElem();

	if (Sel - 1 >= 0) {
		Sel--;
		m_ListGroups.SetCurSel(Sel);
		OnLbnSelchangeMainGroupList();
		SetEnableStudInf(false);
	}
	else if (Sel == 0 && m_ListGroups.GetCount() != 0) {
		m_ListGroups.SetCurSel(Sel);
		OnLbnSelchangeMainGroupList();
		SetEnableStudInf(false);
	}
	else {
		SetGroupBtnsEnable(false);
		SetEnableStudents(false);
	}

	if(m_ListGroups.GetCount() > 0)
		GetDlgItem(IDBTN_MAIN_GROUP_DELETE_ALL)->EnableWindow(TRUE);
}

//---------------------------------Work with student----------------------------------------

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentAdd() {
	InputStudent.Action = CREATE;
	InputStudent.length = m_ListGroups.GetCount();
	InputStudent.CurSel = m_ListGroups.GetCurSel();
	InputStudent.GroupListRef = &GroupList;
	for (int i = 0; i < m_ListGroups.GetCount(); i++) {
		m_ListGroups.GetText(i, BufferText);
		InputStudent.BufferArray.Add(BufferText);
	}
	InputStudent.DoModal();
	m_ListGroups.SetCurSel(InputStudent.CurSel);
	OnLbnSelchangeMainGroupList();
}

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentChange() {
	InputStudent.Action = CHANGE;
	InputStudent.TempStudent = TempStud;
	for (int i = 0; i < m_ListGroups.GetCount(); i++) {
		m_ListGroups.GetText(i, BufferText);
		InputStudent.BufferArray.Add(BufferText);
	}
	if (InputStudent.DoModal() == IDOK) {
		m_ListStudents.DeleteString(m_ListStudents.GetCurSel());
		m_ListStudents.AddString((LPCTSTR)TempStud->SecName);

		SetEnableStudInf(false);

		int Sel = 0;

		m_ListStudents.GetText(Sel, BufferText);
		while (InputStudent.SecName != BufferText && Sel < m_ListStudents.GetCount()) {
			Sel++;
			m_ListStudents.GetText(Sel, BufferText);
		}
		m_ListStudents.SetCurSel(Sel);
		OnLbnSelchangeMainStudentList();
	}
}


void CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentDelete() {
	int Sel = m_ListStudents.GetCurSel();
	m_ListStudents.DeleteString(Sel);
	StudentList->DelCurElem();
	if (Sel - 1 >= 0) {
		Sel--;
		m_ListStudents.SetCurSel(Sel);
		OnLbnSelchangeMainStudentList();
	}
	else if (Sel == 0 && m_ListStudents.GetCount() != 0) {
		m_ListStudents.SetCurSel(Sel);
		OnLbnSelchangeMainStudentList();
	}
	else 
		SetEnableStudInf(false);
}

//-------------------------------------Delete all------------------------------------------------

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainGroupDeleteAll() {
	if (MessageBox(_T("Do you realy want to DELETE all GROUPS?"), _T("Deletion confirm"), MB_YESNO) == IDYES) {
		SetEnableGroups(false);
		DeleteAllGroups();
	}
}


void CMFCApplicationDialogBaseListDlg::OnBnClickedMainStudentDeleteAll() {
	if (MessageBox(_T("Do you realy want to DELETE all STUDENTS in selected group?"), _T("Deletion confirm"), MB_YESNO) == IDYES) {
		StudentList->DelAll();
		SetEnableStudents(false);
		m_StudName = __TEXT("");
		UpdateData(FALSE);
		MessageBox(_T("Deletion success!"), _T("Success!"), MB_OK);
	}
}

//----------------------------------------Exit------------------------------------------

void CMFCApplicationDialogBaseListDlg::OnBnClickedMainExit() {
	OnFileExit();
}

void CMFCApplicationDialogBaseListDlg::OnFileExit() {
	OnOK();
}

//-----------------------------------------Menu-----------------------------------------


void CMFCApplicationDialogBaseListDlg::OnHelpAbout() {
	CAboutDlg Dlg;
	Dlg.DoModal();
}

void CMFCApplicationDialogBaseListDlg::OnLbnSelchangeMainGroupList() {
	SetEnableStudInf(false);
	SetGroupBtnsEnable(true);
	//----------------------------------
	SetSelectedGroupBtnsEnable(true);
	m_ListStudents.ResetContent();
	int Sel = m_ListGroups.GetCurSel();
	GroupList.sort();
	GroupList.SetHead();
	for (int i = 0; i < Sel; i++, ++GroupList);
	GroupList.GetCurInf(StudentList);
	//---------------------------------- одинаковая часть
	if (StudentList->GetTail()) {
		GetDlgItem(IDBTN_MAIN_STUDENT_DELETE_ALL)->EnableWindow(TRUE);
		iteratorStudents = *StudentList;
		for (iteratorStudents.Begin(); !iteratorStudents.IsBegin(); ++iteratorStudents) {
			if (iteratorStudents.GetCurInfRef(TempStud))
				m_ListStudents.AddString((LPCTSTR)TempStud->SecName);
		}
	}
}

void CMFCApplicationDialogBaseListDlg::OnLbnSelchangeMainStudentList() {
	//----------------------------------
	SetSelectedStudentBtnsEnable(true);
	int Sel = m_ListStudents.GetCurSel();
	StudentList->sort();
	StudentList->SetHead();
	for (int i = 0; i < Sel; i++, ++(*StudentList));
	StudentList->GetCurInf(TempStud);
	//---------------------------------- одинаковая часть
	OutStudInfo(*TempStud);
}

void CMFCApplicationDialogBaseListDlg::OnEnChangeMainGroup() {
	int Srch;
	TCHAR Buf[MIN_BUF_SIZE];

	Buf[((CEdit*)(GetDlgItem(IDEDITBOX_MAIN_GROUP)))->GetLine(0, Buf)] = 0;
	if ((Srch = m_ListGroups.FindString(-1, Buf)) != LB_ERR) {
		m_ListGroups.SetCurSel(Srch);
		OnLbnSelchangeMainGroupList();
	}
}

void CMFCApplicationDialogBaseListDlg::OnEnChangeMainStudent() {
	int Srch;
	TCHAR Buf[MIN_BUF_SIZE];

	Buf[((CEdit*)(GetDlgItem(IDEDITBOX_MAIN_STUDENT)))->GetLine(0, Buf)] = 0;
	if ((Srch = m_ListStudents.FindString(-1, Buf)) != LB_ERR) {
		m_ListStudents.SetCurSel(Srch);
		OnLbnSelchangeMainStudentList();
	}
}
