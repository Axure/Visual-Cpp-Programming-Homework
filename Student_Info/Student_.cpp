// Student_.cpp: implementation of the Student_ class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <string>
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

Student::Student()
{

}

Student::~Student()
{

}


std::string Student::serialize() const
{
	std::string result;


	return result;
}


Student Student::deserialize(const std::string & input)
{
	Student newStudent;
	return newStudent;
}