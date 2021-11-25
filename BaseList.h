#include "Defines.h"
#include <iostream>

using namespace std;

template<class InfType, class ListType> class Iterator;

template <typename InfType>
class List{
	friend Iterator<InfType, List<InfType>>;

	struct Elem {
		InfType Inf; //Информационная часть с шаблонным типом даных
		Elem* Next; // указатель на следующий элемент

		Elem() {

		}

		Elem(InfType &Inf, Elem* Next) {
			this->Inf = Inf;
			this->Next = Next;
		}

		Elem(InfType &Inf):Inf(Inf){
		}
	};

protected:
	Elem* Tail, *CurPosition;

	void MergeSort(Elem*& FirElemOfList) {
		Elem* head = FirElemOfList, * list1, * list2;
		if (head == NULL || head->Next == NULL) { //Если пришел "массив" без или с одним элементом
			return; // то выходим из функции.
		}
		FindMid(head, list1, list2); //делим список
		MergeSort(list1);
		MergeSort(list2);
		FirElemOfList = MergeSubListSort(list1, list2);
	}

	void FindMid(Elem* head, Elem*& list1, Elem*& list2) { //Делит список пополам
		Elem *Hare, *Turtle;
		if (head == NULL || head->Next == NULL) { //Проверка на наличие всего одного элемента списка или его полное отсутсвие.
			list1 = head;
			list2 = NULL;
			return;
		} else {
			Turtle = head; //"Черепахе" присвоим первый элемент и она будет двигатся со скоростью а
			Hare = head->Next; // "Зайцу" присвоим второй элемент и он будет двигатся со скоростью 2а
			while (Hare != NULL) { // Пока заяц не добежит до конца ( пока не встанет на нулевой элемент). --Если условие срабатывает здесь, то список не четный--
				Hare = Hare->Next;
				if (Hare != NULL) { //--Если условие срабатывает здесь, то список четный--
					Turtle = Turtle->Next;
					Hare = Hare->Next;
				}
			}
			list1 = head; // Первый список начинается с головы
			list2 = Turtle->Next; // а второй список - со следующего элемента от черепахи (таким образом черепаха выступает разделителем)
			Turtle->Next = NULL; // и обрываем связь между этими двумя списками
		}
	}

	Elem* MergeSubListSort(Elem* list1, Elem* list2) {
		Elem* TempHead = new Elem; //временный список
		Elem* Temp = TempHead;
		while (list1 != NULL && list2 != NULL) {
			if (list1->Inf >= list2->Inf) {
				Temp->Next = list2;
				Temp = list2;
				list2 = list2->Next;
			}
			else{
				Temp->Next = list1;
				Temp = list1;
				list1 = list1->Next;
			}
		}
		Temp->Next = list1 ? list1 : list2; //если один из списков закончился, то последующие элементы отсортированого списка будут остаткакми элементов другого списка(если существует список номер 1, то дальше будет он, если нет - то второй)
		return TempHead->Next;
	}

public:
	typedef Iterator<InfType, List<InfType>> IteratorList; //Псевдоним

	List() {
		Tail = CurPosition = NULL;
	}

	List(List &list) {
		Tail = CurPosition = NULL;
		*this = list;
	}

	~List() {
		DelAll();
	}

	void addBeginElem(InfType &x) {
		Elem* NewElem = new Elem(x);
		Tail ? NewElem->Next = Tail->Next : Tail = NewElem;
		Tail->Next = NewElem;
	}

	void addEndElem(InfType &x) {
		Elem* NewElem = new Elem(x);
		Tail ? NewElem->Next = Tail->Next : Tail = NewElem;
		Tail->Next = NewElem;
		Tail = NewElem;
	}

	void AddSortedElement(InfType &x) { // Новое, с проверкой на хвост
		if (Tail) {
			Elem* NewElem = new Elem(x);
			if (Tail->Inf < x) {
				NewElem->Next = Tail->Next;
				Tail->Next = NewElem;
				Tail = NewElem;
				return;
			}

			CurPosition = Tail;
			Elem* Temp = Tail->Next;
			do {
				Temp = Temp->Next;
				CurPosition = CurPosition->Next;
			} while (Temp->Inf < x);
			NewElem->Next = Temp;
			CurPosition->Next = NewElem;
		}
	}

	void SortCurElem() {
		if (CurPosition) {
			Elem* Temp, * PreTemp, * PreCur;
			PreCur = PreTemp = Tail;
			Temp = Tail->Next;
			if (CurPosition->Inf > Temp->Inf) {
				do {
					PreTemp = Temp;
					Temp = Temp->Next;
				} while (CurPosition->Inf >= Temp->Inf && Temp != CurPosition);
			}
			if (Temp == CurPosition) {
				PreCur = PreTemp;
				do {
					PreTemp = Temp;
					Temp = Temp->Next;
				} while (CurPosition->Inf >= Temp->Inf && PreTemp != Tail);
			} else {
				while (Temp->Next != CurPosition) {
					Temp = Temp->Next;
				}
				PreCur = Temp;
			}
			if (PreTemp != CurPosition) {
				PreCur->Next = CurPosition->Next;
				CurPosition->Next = PreTemp->Next;
				PreTemp->Next = CurPosition;
				if (CurPosition->Inf >= Tail->Inf)
					Tail = CurPosition;
			}
		}
	}

	void sort() {
		if (Tail) { // Существует ли список (точнее его хвост, как обязательный элемент)
			Elem* Head = Tail->Next; //Обзываем следующий элемент от хвоста "головой"
			Elem* Temp = Head;
			Tail->Next = NULL; // Разрываем кольцо
			MergeSort(Head); // Отправляем сортироватся
			while (Temp->Next){
				Temp = Temp->Next; //Идем по отсортированому списку
			} //пока не найдем хвост (пока существует элемент после Temp).
			Tail = Temp; //Нашли хвост (даем этому элементу звание "последний")
			Tail->Next = Head; //и закольцевали.
		}
	}

	bool find(InfType &x) {
		if (Tail) {
			Elem *Temp = Tail;
			do {
				if (Temp->Inf == x) {
					CurPosition = Temp;
					return true;
				}
				Temp = Temp->Next;
			} while (Temp != Tail);
		}
		CurPosition = NULL;
		return false;
	}

	bool SetHead() {
		if (Tail) {
			CurPosition = Tail->Next;
			return true;
		}
		CurPosition = NULL;
		return false;
	}

	bool SetTail() {
		CurPosition = Tail;
		return Tail == NULL;
	}

	bool GetTail() {
		if(Tail)
			return true;
		return false;
	}

	bool GetCurInf(InfType &Inf) {
		if (CurPosition) {
			Inf = CurPosition->Inf;
			return true;
		}
		return false;
	}

	bool GetCurInf(InfType* &Inf) {
		if (CurPosition) {
			Inf = &CurPosition->Inf;
			return true;
		}
		return false;
	}

	bool DelElem(InfType& Inf) {
		if (Tail) {
			Elem* Prev = Tail;
			Elem* Temp = Tail->Next;
			do {
				if (Temp->Inf == Inf) {
					if (Temp == Tail) {
						Tail = Tail->Next != Tail ? Prev : NULL ;
					}
					Prev->Next = Temp->Next;
					delete Temp;
					return true;
				}
				Prev = Prev->Next;
				Temp = Temp->Next;
			} while (Prev != Tail);
		}
		return false;
	}

	bool DelCurElem() {
		if (Tail) {
			Elem* Temp = CurPosition;
			do {
				Temp = Temp->Next;
			} while (Temp->Next != CurPosition);
			Temp->Next = CurPosition->Next;

			if (CurPosition == Tail) {
				if (Tail->Next == Tail)
					Temp = NULL;
				Tail = Temp;
			}
			delete CurPosition;
			CurPosition = Temp;
			return true;
		}
		return false;
	}

	void DelAll() {
		if (Tail) {
			CurPosition = Tail->Next; //Разрываем закольцованность
			Tail->Next = NULL;
			Tail = CurPosition;
			while (Tail) { //и по очереди удаляе элементы,
				CurPosition = Tail;
				Tail = Tail->Next;
				delete CurPosition;
			}
			Tail = CurPosition = NULL; //а потом и переменные.
		}
	}

	bool operator!() {
		return Tail != NULL;
	}

	List<InfType>& operator= (List<InfType>& OldList) {
		if (this != &OldList) {
			if (Tail) {
				if (OldList.Tail) {
					Elem* OldTemp = OldList.Tail, * NewTemp = Tail;
					Elem* OldHead = OldList.Tail->Next, * NewHead = Tail->Next;
					do {
						NewTemp = NewTemp->Next;
						OldTemp = OldTemp->Next;
						NewTemp->Inf = OldTemp->Inf;
					} while (OldTemp->Next != OldHead && NewTemp->Next != NewHead);
					while (OldTemp->Next != OldHead) {
						OldTemp = OldTemp->Next;
						addEndElem(OldTemp->Inf);
						NewTemp = NewTemp->Next;
					}
					if (NewTemp->Next != NewHead) {
						Elem* ToDel = NewTemp;
						CurPosition = NewTemp->Next;
						while (CurPosition->Next != NewHead) {
							ToDel = CurPosition;
							CurPosition = CurPosition->Next;
							delete ToDel;
						}
						delete CurPosition;
						NewTemp->Next = NewHead;
						Tail = NewTemp;
					}
				}
				else
					DelAll();
			}			
			else {
				Elem* OldTemp = OldList.Tail;
				do {
					CurPosition = OldTemp = OldTemp->Next;
					addEndElem(OldTemp->Inf);
				} while (OldTemp != OldList.Tail);
			}
		}
		return *this;
	}

	List<InfType>& operator++(){
		CurPosition = CurPosition ? CurPosition->Next : Tail;
		return *this;
	}
};

template <class InfType, class ListType> class Iterator { 
private:
	typename ListType::Elem *Tail, *CurPos;
	bool Flag = true;
public:

	Iterator() {
		Tail = CurPos = NULL;
	}

	Iterator(Iterator &iterator) {
		*this = iterator;
	}

	Iterator(ListType &list) {
		*this = list;
	}

	Iterator& operator=(Iterator &iterator) {
		Tail = iterator.Tail;
		CurPos = iterator.CurPos;
		return *this;
	}

	Iterator& operator=(ListType & list) {
		Tail = list.Tail;
		CurPos = list.Tail->Next;
		return *this;
	}

	Iterator& operator++(){
		if (CurPos) {
			CurPos = CurPos->Next;
			Flag = true;
		}
		return *this;
	}

	bool operator !(){
			return CurPos != NULL;
	}

	bool GetCurInf(InfType& Inf){
		if (CurPos){
			Inf = CurPos->Inf;
			return true;
		}
		return false;
	}

	bool GetCurInfRef(InfType*& Inf){
		if (CurPos){
			Inf = &(CurPos->Inf);
			return true;
		}
		return false;
	}

	bool Begin() {
		if (Tail) {
			CurPos = Tail->Next;
			Flag = false;
			return true;
		}
		CurPos = NULL;
		return false;
	}

	bool End() {
		CurPos = Tail;
		Flag = false;
		return Tail != NULL;
	}

	bool IsEnd() {
		return CurPos == Tail && Flag;
	}

	bool IsBegin() {
		return Tail != NULL && CurPos == Tail->Next && Flag;
	}

	bool IsNotEmpty(){
		return Tail != NULL;
	}
};