#pragma once

#include "Defines.h"
#include <iostream>
#include <tchar.h>


class Student {
public:
	TCHAR* Name;
	TCHAR* SecName;
	TCHAR* MidName;
	int BirthYear;
	int MidMark;

	Student() {
		Name = NULL;
		SecName = NULL;
		MidName = NULL;
		BirthYear = NULL;
		MidMark = NULL;
	}

	Student(Student &NewStudent) {
		Name = NULL;
		SecName = NULL;
		MidName = NULL;
		BirthYear = NULL;
		MidMark = NULL;

		SetTcharText(this->Name, NewStudent.Name);
		SetTcharText(this->SecName, NewStudent.SecName);
		SetTcharText(this->MidName, NewStudent.MidName);
		setBirthYear(NewStudent.BirthYear);
		setMark(NewStudent.MidMark);
	}

	Student(const TCHAR* Name, const TCHAR* SecName, const TCHAR* MidName, int BirthYear, int MidMark) {
		SetTcharText(this->Name, Name);
		SetTcharText(this->SecName, SecName);
		SetTcharText(this->MidName, MidName);
		setBirthYear(BirthYear);
		setMark(MidMark);
	}

	void setFirstName(const TCHAR* Name) {
		SetTcharText(this->Name, Name);
	}

	void setSecondName(const TCHAR* SecName) {
		SetTcharText(this->SecName, SecName);
	}

	void setMidName(const TCHAR* MidName) {
		SetTcharText(this->MidName, MidName);
	}

	void setBirthYear(int BirthYear) {
		if (MIN_BIRTH_YEAR < BirthYear && BirthYear < MAX_BIRTH_YEAR)
			this->BirthYear = BirthYear;
	}

	void setMark(int MidMark) {
		if (MIN_MARK <= MidMark && MidMark <= MAX_MARK)
			this->MidMark = MidMark;
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

	~Student() {
		delete Name;
		delete SecName;
		delete MidName;
	}

	Student& operator=(const Student& New) {
		if (this != &New) {
			SetTcharText(this->Name, New.Name);
			SetTcharText(this->SecName, New.SecName);
			SetTcharText(this->MidName, New.MidName);
			setMark(New.MidMark);
			setBirthYear(New.BirthYear);
		}
		return *this;
	}

	bool operator == (Student& St) {
		return	compare(*this, St) == 0;
	}

	bool operator != (Student& St) {
		return compare(*this, St) != 0;
	}

	bool operator> (Student& St) {
		return	compare(*this, St) > 0;
	}

	bool operator>= (Student& St) {
		return	compare(*this, St) >= 0;
	}

	bool operator< (Student& St) {
		return	compare(*this, St) < 0;
	}

	bool operator<= (Student& St) {
		return	compare(*this, St) <= 0;
	}

	int compare(const Student& FirStud, const Student& SecStud) {
		int result = 0;
		if ((result = DeepCompare(FirStud.SecName, SecStud.SecName)) == 0) {
			if ((result = DeepCompare(FirStud.Name, SecStud.Name)) == 0)
				return DeepCompare(FirStud.MidName, SecStud.MidName);
		}
		return result;
	}

	int DeepCompare(TCHAR* First, TCHAR* Second) {
		if (First != NULL) {
			return Second != NULL ? _tcscmp(First, Second) : 1;
		}
		return Second != NULL ? -1 : 0;
	}

	friend tostream& operator<<(tostream& out, const Student& Stud){
		if (Stud.SecName != NULL)
			out << Stud.SecName << _T(" ");

		if (Stud.Name != NULL)
			out << Stud.Name << _T(" ");

		if (Stud.MidName != NULL)
			out << Stud.MidName << _T(" ");

		out << Stud.BirthYear << _T(" ");
		out << Stud.MidMark;
		return out;
	}

	friend tistream& operator>>(tistream& in, Student& Stud){
		TCHAR input[BUF_SIZE];

		in >> input;
		Stud.setSecondName(input);

		in >> input;
		Stud.setFirstName(input);

		in >> input;
		Stud.setMidName(input);

		unsigned year;
		in >> year;
		Stud.setBirthYear(year);

		float mark;
		in >> mark;
		Stud.setMark(mark);

		return in;
	}
	
	
	
};