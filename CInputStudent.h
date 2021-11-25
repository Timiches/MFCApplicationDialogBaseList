#pragma once

#include "Student.h"
#include "UniversalList.h"
// Диалоговое окно CInputStudent

class CInputStudent : public CDialogEx {
	DECLARE_DYNAMIC(CInputStudent)

public:
	CInputStudent(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CInputStudent();

	int Action = NULL;
	CComboBox	m_GroupsList;

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDDIALOG_STUDENT_CREATE };
#endif
	typedef UniversalList<Student> Group;
	typedef UniversalList<Group> Faculty;

	CString BufferText;
	CArray<CString, CString> BufferArray;
	int length;
	int CurSel;

	Student* TempStudent;
	Faculty* GroupListRef;
	Group* TempGroup;

	CString SecName;
	CString FirName;
	CString MidName;
	int BirthYear;
	int Mark;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual BOOL OnInitDialog();
	//void ResetData();
	void TrimBoth(CString Str);
	void AddStudent();
	void SetActiveSurName();
	void ChangeStudent();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStudentCreateOk();
	afx_msg void OnBnClickedStudentCreateCancel();
	afx_msg void OnBnClickedStudentCreateNext();
};
