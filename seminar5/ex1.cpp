#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};

class Book {

	char* author = nullptr;
	string title = "";
	int pages_no = 0;
	int* page_words_count = nullptr;
	bool online;
public:
	Book() {

	}

	Book(char* _author, string _title, int _pages_no, int* _page_words_count, bool _online) :
		title(_title), pages_no(_pages_no), online(_online) {

		this->author = new char[strlen(_author) + 1];
		strcpy_s(this->author, strlen(_author) + 1, _author);

		this->page_words_count = new int[_pages_no];
		for (int index = 0; index < _pages_no; index++)
		{
			this->page_words_count[index] = _page_words_count[index];
		}

	}

	void set_online(bool _online) {

		this->online = online;
	}

	void set_author(char* _author) {
		this->author = new char[strlen(_author) + 1];
		strcpy_s(this->author, strlen(_author) + 1, _author);

	}

	void set_title(string _title) {
		this->title = _title;

	}

	void set_page_words_count(int* _page_words_count, int _pages_no) {
		this->pages_no = _pages_no;
		this->page_words_count = new int[_pages_no];
		for (int index = 0; index < _pages_no; index++)
		{
			this->page_words_count[index] = _page_words_count[index];
		}

	}

	char* get_author() { return this->author; }
	string get_title() { return this->title; }
	int get_pages_no() { return this->pages_no; }
	int* get_page_word_count() { return this->page_words_count; }
	bool get_online() { return this->online; }

	Book(const Book& book) {
		this->author = book.author;
		this->title = book.title;
		this->pages_no = book.pages_no;
		this->page_words_count = book.page_words_count;
		this->online = book.online;

	}

	~Book() {
		delete[] this->author;
		delete[] this->page_words_count;

	}

};




class Student
{
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

public:
	
	//constructori
	Student()
	{

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	
	/*Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}*/

	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii


   Student(const Student& student)
   {
	   this->nume = student.nume;
	   this->adresa = student.adresa;
	   this->varsta = student.varsta;
	   this->an_studii = student.an_studii;
	   this->note = student.note;
	   this->numar_materii = student.numar_materii;
	   this->numar_matricol = student.numar_matricol;
	   this->finantare = student.finantare;

   }


   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	//
	void set_nume(string _nume) {
		this->nume = _nume;
	}

	void set_adresa(char* _adresa) {
		this->adresa = new char[20];
		strcpy_s(this->adresa, 20, "Bucuresti, Sector 1");
	}

	void set_varsta(int _varsta) {
		this->varsta = _varsta;
	}
	void set_an_studii(int alex) {
		this->an_studii = alex;
		}
	
	//
	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete this->adresa;
		delete this->note;
	}
private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	//Student s0;

	//s0.set_an_studii = "Anghel Mihai";

	///*s0.adresa = new char[20];
	//strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");*/

	//s0.set_varsta = 21;
	//s0.set_an_studii = 2;

	//de ce este generata eroarea?
	//s0.note = new int[20];
int pag[3] = { 1, 3, 5 };

	Book b;

	b.set_author((char*)"Eu");
	b.set_page_words_count(pag, 3);
	b.set_title("O aventura");
	b.set_online(true);

	Book b1 = Book((char*)"Alex", "alta aventura", 3, pag, true);

	//s0.set_nume("Alex");
	//s0.set_adresa((char*)"123");
	//s0.set_varsta(21);
	//s0.set_an_studii(2024);
	//s0.set_numar_matricol("A689867");
	//s0.set_finantare(finantare::BUGET_BURSA);

	//// discutie eroare invalid heap pointer
	//int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	//s0.set_note(note, 10);


	/*Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	Student s2 = s1;
	s2.set_nume("Ionescu C");*/
}