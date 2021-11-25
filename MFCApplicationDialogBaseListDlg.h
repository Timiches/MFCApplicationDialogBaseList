// MFCApplicationDialogBaseListDlg.h: файл заголовка


#pragma once

#include "CInputUniversal.h"
#include"CInputStudent.h"
#include "Student.h"
#include "UniversalList.h"
#include "Defines.h"

// Диалоговое окно CMFCApplicationDialogBaseListDlg
class CMFCApplicationDialogBaseListDlg : public CDialogEx {

public:
	CMFCApplicationDialogBaseListDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONDIALOGBASELIST_DIALOG };
#endif
	CListBox	m_ListStudInfo;
	CListBox	m_ListStudents;
	CListBox	m_ListGroups;
	CString	m_StudName;
	CString	m_GroupName;
	CString BufferText;

	typedef UniversalList<Student> Group;
	typedef UniversalList<Group> Faculty;

	Group::IteratorList iteratorStudents;
	Faculty::IteratorList iteratorGroups;

	Faculty GroupList;
	Group* StudentList = new Group;
	Student* TempStud = new Student;

	CString SecName;
	CString FirName;
	CString MidName;
	int BirthYear;
	int Mark;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV

// Реализация
protected:
	HICON m_hIcon;

	int /*FontAveChar, MaxExtListStud,*/ OldStudSelect;

	CInputUniversal InputUniversal;
	CInputStudent InputStudent;

	void SetButtonState(WORD wID[], WORD len, bool State);
	bool SetFacultyBtnsEnable(bool State);
	bool SetGroupBtnsEnable(bool State);
	bool SetSelectedGroupBtnsEnable(bool State);
	bool SetSelectedStudentBtnsEnable(bool State);
	void SetEnableStudInf(bool State);
	void SetEnableStudents(bool State);
	void SetEnableGroups(bool State);
	void DisableFaculty();
	inline int GetStudSel(){
		return m_ListStudents.GetCurSel();
	}

	inline int GetGroupSel() {
		return m_ListGroups.GetCurSel();
	}

	// Созданные функции схемы сообщений
	CString GetUniversalName(CString caption);
	void DeleteAllGroups();
	//void OutStud();
	void OutStudInfo(Student& S);
	//void ChangeSelect(SelectUniversal::BaseSelect* Base, CListBox& ListBox, int& OldSelect, bool IsGroup);
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOk();

	void DelStudentList(bool Disable);
	void DelStudInfoList();

	bool ChekSimilarName();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMainFacultyCreate();
	afx_msg void OnBnClickedMainFacultyChangeName();
	afx_msg void OnBnClickedMainFacultyGetName();
	afx_msg void OnBnClickedMainFacultyDelete();
	afx_msg void OnBnClickedMainGroupAdd();
	afx_msg void OnBnClickedMainGroupChange();
	afx_msg void OnBnClickedMainGroupDelete();
	afx_msg void OnBnClickedMainStudentAdd();
	afx_msg void OnBnClickedMainStudentChange();
	afx_msg void OnBnClickedMainStudentDelete();
	afx_msg void OnBnClickedMainGroupDeleteAll();
	afx_msg void OnBnClickedMainStudentDeleteAll();
	afx_msg void OnBnClickedMainExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileExit();
	afx_msg void OnLbnSelchangeMainGroupList();
	afx_msg void OnLbnSelchangeMainStudentList();
	//afx_msg void OnLbnKillfocusMainStudent();
	//afx_msg void OnLbnKillfocusMainGroup();
	afx_msg void OnEnChangeMainGroup();
	afx_msg void OnEnChangeMainStudent();
};
