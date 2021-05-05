#ifndef DZIEKANAT_H_
#define DZIEKANAT_H_
/** @file */

/**
*	Za��czone bibiolteki, kt�re zosta�y u�yte w projekcie.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <xstring>

/**
*	Wyszczeg�lnienie, kt�re obiekty z przestrzeni nazw std, zosta�y u�yte w projekcie.
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
*	Struktura Date przechowywuj�ca dat�.
*	Data rodziela si� na rok, miesi�c oraz dzie�.
*/
struct Date
{
	int year;
	int month;
	int day;
};

/**
*	Struktura Subject przechowuj�ca dane o Przedmiocie.
*	Przedmiot charakteryzuje si� polami takimi jak: prowadz�cy (wyk�adowca), nazwa przedmiotu, ocena z danego przedmiotu (unikatowa dla ka�dego studenta), a tak�e data dokonania wpisu.
*/
struct Subject
{
	string teacher;
	string name;
	float mark;
	string date;
};

/**
*	Struktura w�z�a listy Przedmiot�w.
*	W�ze� posiada wska�nik na Przedmiot, oraz wska�nik na nast�pny element listy (nast�pny w�ze�).
*/
struct SubjectNode
{
	Subject* subject;
	SubjectNode* pNextSubject;
};

/**
*	Struktura przechowuj�ca osob� (Studenta).
*	Student charakteryzuje si� imieniem, nazwiskiem oraz numerem indeksu. Struktura posiada r�wnie� wska�nik na g�ow� listy Przedmiot�w danego Studenta.
*/
struct Student
{
	string name;
	string surname;
	int index;
	SubjectNode* pSubjects;
};

/**
*	Struktura w�z�a listy Student�w.
*	W�ze� posiada wska�nik na Studenta, oraz wska�nik na nast�pny element listy (nast�pny w�ze�).
*/
struct StudentNode
{
	Student* student;
	StudentNode* pNextStudent;
};

/**
 *  Funkcja odczytuj�ca protok� z podanego pliku tekstowego i wywo�uj�ca kolejn� funkcj� (dodania do listy Student�w).
 *	@param fileName nazwa pliku tekstowego
 *	@param headStudents g�owa struktury reprezentuj�cej Studenta
 */
void getStudentsResults(string fileName, StudentNode*& headStudents);

/**
 *  Funkcja dodaj�ca do listy Student�w danego Studenta i wywo�uj�ca kolejn� funkcj� (dodania do listy Przedmiot�w).
 *	@param headStudents g�owa struktury reprezentuj�cej Studenta
 *	@param student obiekt struktury Studenta, kt�rego chcemy doda� do listy
 *	@param subject obiekt struktury Przedmiotu, kt�ry przekazujemy do kolejnej funkcji
 */
void addResult(StudentNode*& headStudents, Student student, Subject subject);

/**
 *  Funkcja dodaj�ca Przedmiot do listy Przedmiot�w danego Studenta z zachowaniem kolejno�ci alfabetycznej.
 *	@param studentNode g�owa struktury reprezentuj�cej Studenta
 *	@param subject obiekt struktury Przedmiotu, kt�ry dodajemy do listy
 */
void addSubject(StudentNode*& studentNode, Subject subject);

/**
 *  Funkcja przeszukuj�ca list� Student�w i wywo�uj�ca dla ka�dego Studenta kolejn� funkcj�, tworz�c� plik Studenta.
 *	@param headStudents g�owa struktury reprezentuj�cej Studenta
 */
void createStudentFiles(StudentNode*& headStudents);

/**
 *  Funkcja tworz�ca plik Studenta, kt�ry zawiera jego wyniki z poszczeg�lnych Przedmiot�w.
 *	@param student wska�nik na obiekt struktury Studenta
 */
void writeStudentResults(Student* student);

/**
 *  Funkcja zwalniaj�ca pami�c w li�cie Student�w (usuni�cie listy).
 *	@param headStudents g�owa struktury reprezentuj�cej Studenta
 */
void deleteList(StudentNode*& headStudents);

/**
 *  description Funkcja zwalniaj�ca pami�c w li�cie Przedmiot�w (usuni�cie listy).
 *	@param headSubjects g�owa struktury reprezentuj�cej Przedmiot
 */
void deleteList(SubjectNode*& headSubjects);

#endif