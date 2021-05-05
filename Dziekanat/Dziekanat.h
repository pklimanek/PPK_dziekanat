#ifndef DZIEKANAT_H_
#define DZIEKANAT_H_
/** @file */

/**
*	Za³¹czone bibiolteki, które zosta³y u¿yte w projekcie.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <xstring>

/**
*	Wyszczególnienie, które obiekty z przestrzeni nazw std, zosta³y u¿yte w projekcie.
*/
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::endl;
using std::cin;
using std::cout;
using std::to_string;

/**
*	Struktura Date przechowywuj¹ca datê.
*	Data rodziela siê na rok, miesi¹c oraz dzieñ.
*/
struct Date
{
	int year;
	int month;
	int day;
};

/**
*	Struktura Subject przechowuj¹ca dane o Przedmiocie.
*	Przedmiot charakteryzuje siê polami takimi jak: prowadz¹cy (wyk³adowca), nazwa przedmiotu, ocena z danego przedmiotu (unikatowa dla ka¿dego studenta), a tak¿e data dokonania wpisu.
*/
struct Subject
{
	string teacher;
	string name;
	float mark;
	string date;
};

/**
*	Struktura wêz³a listy Przedmiotów.
*	Wêze³ posiada wskaŸnik na Przedmiot, oraz wskaŸnik na nastêpny element listy (nastêpny wêze³).
*/
struct SubjectNode
{
	Subject* subject;
	SubjectNode* pNextSubject;
};

/**
*	Struktura przechowuj¹ca osobê (Studenta).
*	Student charakteryzuje siê imieniem, nazwiskiem oraz numerem indeksu. Struktura posiada równie¿ wskaŸnik na g³owê listy Przedmiotów danego Studenta.
*/
struct Student
{
	string name;
	string surname;
	int index;
	SubjectNode* pSubjects;
};

/**
*	Struktura wêz³a listy Studentów.
*	Wêze³ posiada wskaŸnik na Studenta, oraz wskaŸnik na nastêpny element listy (nastêpny wêze³).
*/
struct StudentNode
{
	Student* student;
	StudentNode* pNextStudent;
};

/**
 *  Funkcja odczytuj¹ca protokó³ z podanego pliku tekstowego i wywo³uj¹ca kolejn¹ funkcjê (dodania do listy Studentów).
 *	@param fileName nazwa pliku tekstowego
 *	@param headStudents g³owa struktury reprezentuj¹cej Studenta
 */
void getStudentsResults(string fileName, StudentNode*& headStudents);

/**
 *  Funkcja dodaj¹ca do listy Studentów danego Studenta i wywo³uj¹ca kolejn¹ funkcjê (dodania do listy Przedmiotów).
 *	@param headStudents g³owa struktury reprezentuj¹cej Studenta
 *	@param student obiekt struktury Studenta, którego chcemy dodaæ do listy
 *	@param subject obiekt struktury Przedmiotu, który przekazujemy do kolejnej funkcji
 */
void addResult(StudentNode*& headStudents, Student student, Subject subject);

/**
 *  Funkcja dodaj¹ca Przedmiot do listy Przedmiotów danego Studenta z zachowaniem kolejnoœci alfabetycznej.
 *	@param studentNode g³owa struktury reprezentuj¹cej Studenta
 *	@param subject obiekt struktury Przedmiotu, który dodajemy do listy
 */
void addSubject(StudentNode*& studentNode, Subject subject);

/**
 *  Funkcja przeszukuj¹ca listê Studentów i wywo³uj¹ca dla ka¿dego Studenta kolejn¹ funkcjê, tworz¹c¹ plik Studenta.
 *	@param headStudents g³owa struktury reprezentuj¹cej Studenta
 */
void createStudentFiles(StudentNode*& headStudents);

/**
 *  Funkcja tworz¹ca plik Studenta, który zawiera jego wyniki z poszczególnych Przedmiotów.
 *	@param student wskaŸnik na obiekt struktury Studenta
 */
void writeStudentResults(Student* student);

/**
 *  Funkcja zwalniaj¹ca pamiêc w liœcie Studentów (usuniêcie listy).
 *	@param headStudents g³owa struktury reprezentuj¹cej Studenta
 */
void deleteList(StudentNode*& headStudents);

/**
 *  description Funkcja zwalniaj¹ca pamiêc w liœcie Przedmiotów (usuniêcie listy).
 *	@param headSubjects g³owa struktury reprezentuj¹cej Przedmiot
 */
void deleteList(SubjectNode*& headSubjects);

#endif