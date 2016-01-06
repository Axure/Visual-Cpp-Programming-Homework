// Student_.cpp: implementation of the Student_ class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string>
#include <sstream>
#include "Student_Info.h"
#include "Student_.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
char Student::forbiddenChars[2] = {'\'', ';'};
int Student::numberOfForbiddenChars = 2;

Student::Student()
{

}

Student::~Student()
{

}


std::string Student::serialize() const
{
	std::ostringstream osstream;
	osstream
		<< this->getStudentId() << ", "
		<< this->getName() << ", "
		<< this->getGender() << ", "
		<< this->getDepartment() << ", "
		<< this->getAge() << ";";
	//std::string result;
	return osstream.str();
}


Student Student::deserialize(const std::string & input)
{
	Student newStudent;
	Student *pNewStudent;
	std::stringstream lineStream(input);
    std::string cell;
	
	std::getline(lineStream, cell, ',');
	pNewStudent->setStudentId(cell);
	std::getline(lineStream, cell, ',');
	pNewStudent->setName(cell);
	std::getline(lineStream, cell, ',');
	pNewStudent->setGender(cell);
	std::getline(lineStream, cell, ',');
	pNewStudent->setDepartment(cell);
	std::getline(lineStream, cell, ';');
	pNewStudent->setAge(cell);



	return newStudent;
}