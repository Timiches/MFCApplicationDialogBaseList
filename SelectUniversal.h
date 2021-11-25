#ifndef  ADD_DEFINES
#define ADD_DEFINES


#include "UniversalList.h"
#include "afxdialogex.h"


namespace SelectUniversal {
	class BaseSelect {
	public:
		virtual void Next() = 0;
		virtual void SetHead(bool IsHead) = 0;
		virtual void EndAction() = 0;
	};

	template <class Inf> class SelectElem : BaseSelect {
	public:
		UniversalList<Inf>* Group;
		Inf** Student;

		SelectElem(UniversalList<Inf>* DroupVal, Inf*& StudentVal) : Group(DroupVal), Student(&StudentVal) {}

		void Next() {
			++(*Group);
		}

		void SetStart() {
			Group->SetHead();
		}

		void EndAction() {
			Group->GetCurInf(*Student);
		}
	};

	void ChangePos(BaseSelect *Base, int Sel, int &OldSelect);
	void SetSelect(int IDEdit, CWnd * Dialog, CString&Value);
}

#endif
