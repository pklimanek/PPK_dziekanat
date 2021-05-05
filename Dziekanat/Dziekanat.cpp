#include "Dziekanat.h"

void getStudentsResults(string fileName, StudentNode*& headStudents)
{
	ifstream file;
	file.open(fileName, ios::in);

	if (file.good())
	{
		Subject subject;
		getline(file, subject.name);
		getline(file, subject.teacher);
		while (!file.eof())
		{
			Student student;
			file >> student.name;
			file >> student.surname;
			file >> student.index;
			file >> subject.mark;
			file >> subject.date;
			file.get();
			addResult(headStudents, student, subject);
		}
	}
	else
	{
		cout << "Wyst¹pi³ b³¹d podczas odczytu pliku wejœciowego!" << endl;
	}
}

void addResult(StudentNode*& headStudents, Student student, Subject subject)
{
	StudentNode* p = headStudents;
	Student* newStudent = new Student{ student.name, student.surname, student.index, nullptr };
	while (p)
	{
		if (p->student->name == student.name && p->student->surname == student.surname) break;
		p = p->pNextStudent;
	}
	if (!p)
	{
		p = new StudentNode{ newStudent, nullptr };
		p->pNextStudent = headStudents;
		headStudents = p;
	}
	
	addSubject(p, subject);
}

void addSubject(StudentNode*& studentNode, Subject subject)
{
	SubjectNode* flag = nullptr;
	SubjectNode* p = studentNode->student->pSubjects;
	Subject* newSubject = new Subject{ subject.teacher, subject.name, subject.mark, subject.date };
	SubjectNode* subjectNode = new SubjectNode{ newSubject, nullptr };
	if (!p)
	{
		studentNode->student->pSubjects = subjectNode;
	}
	else
	{
		if (subject.name <= p->subject->name)
		{
			studentNode->student->pSubjects = new SubjectNode{ newSubject, p };
		}
		else
		{
			while (p)
			{
				if (!p->pNextSubject) {
					p->pNextSubject = new SubjectNode{ newSubject, p->pNextSubject };;
				}
				else {
					if (p->pNextSubject->subject->name >= subject.name) {
						p->pNextSubject = new SubjectNode{ newSubject, p->pNextSubject };
					}
					else {
						p = p->pNextSubject;
					}
				}

			}
		}
	}
}

void createStudentFiles(StudentNode*& headStudents)
{
	StudentNode* pStudents = headStudents;

	while (pStudents)
	{
		writeStudentResults(pStudents->student);
		pStudents = pStudents->pNextStudent;
	}
}

void writeStudentResults(Student* student)
{
	ofstream file;
	file.open(to_string(student->index) + ".txt", ios::out);

	if (file.good())
	{
		file << student->name << " " << student->surname << endl;
		file << "nr albumu: " << student->index << endl << endl;

		SubjectNode* pSubjects = student->pSubjects;

		while (pSubjects)
		{
			Subject* subject = pSubjects->subject;
			file << subject->teacher << " " << subject->name << " "
				<< subject->mark << " " << subject->date << endl;
			pSubjects = pSubjects->pNextSubject;
		}
	}
	file.close();
}

void deleteList(StudentNode*& headStudents) 
{
	while (headStudents) 
	{
		deleteList(headStudents->student->pSubjects);
		StudentNode* s = headStudents->pNextStudent;
		delete headStudents;
		headStudents = s;
	}
}

void deleteList(SubjectNode *& headSubjects) 
{
	while (headSubjects) 
	{
		SubjectNode *s = headSubjects->pNextSubject;
		delete headSubjects;
		headSubjects = s;
	}
}