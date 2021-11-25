#pragma once

#include"BaseList.h"
#include "Defines.h"
#include <tchar.h>

template <typename InfType>
class UniversalList : public List<InfType> {
private:
	TCHAR* Caption;
public:
	UniversalList() : List<InfType>(){
		Caption = NULL;
	}

	UniversalList(UniversalList &List) {
		Caption = NULL;
		SetName(List.Caption);
	}

	UniversalList(const TCHAR *Caption) {
		this->Caption = NULL;
		SetName(Caption);
	}

	~UniversalList() {
		delete Caption;
	}

	void SetName(const TCHAR* Caption) {
		SetTcharText(this->Caption, Caption);
	}

	void SetTcharText(TCHAR* &Old, const TCHAR* New) {
		delete Old;
		if (New == NULL) {
			Old = NULL;
		}
		else {
			Old = new TCHAR[_tcslen(New) + 1];
			_tcscpy_s(Old, _tcslen(New) + 1, New);
		}
	}

	TCHAR* GetName() {
		if (Caption)
			return this->Caption; // возвращ€ть копию (желательно)
		else {
			this->SetName(ERROR_NULL_TEXT);
			return this->Caption;
		}
	}

	int DeepCompare(TCHAR* First, TCHAR* Second) {
		if (First != NULL) {
			return Second != NULL ? _tcscmp(First, Second) : 1;
		}
		return Second != NULL ? -1 : 0;
	}

	UniversalList<InfType>& operator=(UniversalList<InfType>& OldList) {
		if (this != &OldList) {
			SetName(OldList.Caption);
			List<InfType>::operator=(OldList);
		}
		return *this;
	}

	bool operator == (UniversalList<InfType>& AnotherGroup){
		return	DeepCompare(this->Caption, AnotherGroup.Caption) == 0;
	}

	bool operator != (UniversalList<InfType>& AnotherGroup) {
		return DeepCompare(this->Caption, AnotherGroup.Caption) != 0;
	}

	bool operator> (UniversalList<InfType>& AnotherGroup) {
		return	DeepCompare(this->Caption, AnotherGroup.Caption) > 0;
	}

	bool operator>= (UniversalList<InfType>& AnotherGroup) {
		return	DeepCompare(this->Caption, AnotherGroup.Caption) >= 0;
	}

	bool operator< (UniversalList<InfType>& AnotherGroup) {
		return	DeepCompare(this->Caption, AnotherGroup.Caption) < 0;
	}

	bool operator<= (UniversalList<InfType>& AnotherGroup) {
		return	DeepCompare(this->Caption, AnotherGroup.Caption) <= 0;
	}

	friend tostream& operator<<(tostream& out, const UniversalList<InfType>& Inf) {
		if (Inf.Caption != NULL)
			out << Inf.Caption << _T(" ");
		return out;
	}

	friend tistream& operator>>(tistream& in, UniversalList<InfType>& Inf) {
		TCHAR input[BUF_SIZE];

		in >> input;
		Inf.SetName(input);

		return in;
	}
};