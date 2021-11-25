
// MFCApplicationDialogBaseList.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы
//#include "Student.h"
//#include "UniversalList.h"
//#include "BaseList.h"
//
//typedef UniversalList<Student> Group;
//typedef UniversalList<Group> Faculty;
//
//Group::IteratorList iteratorGroup;
//Faculty::IteratorList iteratorFaculty;
//
//Faculty MainFaculty;
// CMFCApplicationDialogBaseListApp:
// Сведения о реализации этого класса: MFCApplicationDialogBaseList.cpp
//

class CMFCApplicationDialogBaseListApp : public CWinApp
{
public:
	CMFCApplicationDialogBaseListApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationDialogBaseListApp theApp;
