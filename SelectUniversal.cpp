#include "pch.h"
#include "SelectUniversal.h"

void SelectUniversal::ChangePos(SelectUniversal::BaseSelect* Base, int Sel, int& OldSelect) {
	for (; Sel < OldSelect; OldSelect++, Base->Next());
	Base->EndAction();
}

void SelectUniversal::SetSelect(int IdEdit, CWnd* Dialog, CString& Value) {
	CWnd* Wnd = Dialog->GetDlgItem(IdEdit);
	Wnd->SetFocus();
	((CEdit*)(Wnd))->SetSel(0, Value.GetLength());
}