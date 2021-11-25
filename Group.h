//#include "stdafx.h"

#ifndef	GROUP_INCLUDE
#define GROUP_INCLUDE


#include <stdio.h>

#include "BaseList.h"

#include <windows.h>
#include <excpt.h>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

template <typename INF> class TGroup : public TBList<INF>
{

	//-----------------------------------------------------------------

	// Освобождение памяти, занимаемой под хранение названия группы
#ifndef MFC_USED
protected:

	TCHAR* GName;

	void DelGName()
	{
		__try
		{
			__try
			{
				*GName = 0;
			}
			__finally
			{
#ifdef	_DEBUG
#ifdef _CrtReportBlockType
				if (GName)
				{
					int BlockType = _BLOCK_TYPE(_CrtReportBlockType(GName));
					if (BlockType != _NORMAL_BLOCK && BlockType != _CLIENT_BLOCK)
						GName = NULL;
				}
#endif
#endif
			}

		}
		__except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? GName = NULL, EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
		{
		}

		delete[] GName;
		GName = NULL;
	}

#else
public:
	CString gName;

#endif
	//-----------------------------------------------------------------

	// Недоступный пользователю метод, возвращающий результат сравнения названий 2-ух групп


	//-----------------------------------------------------------------

	//-----------------------------------------------------------------

public:
	TGroup()
	{
#ifndef	MFC_USED
		GName = NULL;
#endif
	}

#ifndef	MFC_USED
	TGroup(const TCHAR* GroupName)
	{
		GName = NULL;
		SetGroupName(GroupName);
	}
#else
	TGroup(const CString& GroupName)
	{
		gName = GroupName;
	}
#endif

	//-----------------------------------------------------------------

	~TGroup()
	{
#ifndef	MFC_USED
		DelGName();
#endif
	}

	//-----------------------------------------------------------------

	// Методы для получения и изменения названия группы, а также свойство для доступа к этому поля класса


#ifndef	MFC_USED

	TCHAR* GetGroupName()
	{
		if (GName != NULL)
		{
			TCHAR* Name = new TCHAR[_tcslen(GName) + 1];
			_tcscpy(Name, GName);
			return Name;
		}
		return NULL;
	}

	void SetGroupName(const TCHAR* GroupName)
	{
		DelGName();
		GName = new TCHAR[_tcslen(GroupName) + 1];
		_tcscpy(GName, GroupName);
	}

	__declspec(property(get = GetGroupName, put = SetGroupName)) TCHAR* gName;
#endif

	//-----------------------------------------------------------------

	// Перегруженный оператор присваивания


	//-----------------------------------------------------------------

	// Перегруженные операции сравнения


};


#endif
