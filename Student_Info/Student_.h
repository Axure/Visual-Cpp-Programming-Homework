// Student_.h: interface for the Student_ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT__H__80608F71_DBE9_4C91_84DF_21408F3EDDCD__INCLUDED_)
#define AFX_STUDENT__H__80608F71_DBE9_4C91_84DF_21408F3EDDCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iosfwd>
#include <sstream>
#include <cassert>

class Student {
private:
	long student_id;
	std::string name;
	int gender;
	std::string department;
	int age;
protected:
	
public:
	static char forbiddenChars[2];
	static int numberOfForbiddenChars;
	void setStudentId(long _student_id) {
		this->student_id = _student_id;
	}
	void setStudentId(std::string _student_id) {
		std::istringstream(_student_id) >>this->student_id;
	}
	long getStudentId() const {
		return this->student_id;
	}

	void setName(const std::string &_name) {
		for (int i = 0; i < Student::numberOfForbiddenChars; ++i) {
			if (_name.find(Student::forbiddenChars[i]) != std::string::npos) {
				std::ostringstream osstream;
				osstream << "Name contains " << Student::forbiddenChars[i] << "!";
				throw std::runtime_error(osstream.str());
			}
		}
		this->name = _name;
	}
	std::string getName() const{
		return this->name;
	}

	void setGender(int _gender) {
		this->gender = _gender;
	}
	void setGender(std::string _gender) {
		std::istringstream(_gender) >>this->gender;
	}
	int getGender() const{
		return this->gender;
	}

	void setDepartment(const std::string &_department) {
		for (int i = 0; i < Student::numberOfForbiddenChars; ++i) {
			if (_department.find(Student::forbiddenChars[i]) != std::string::npos) {
				std::ostringstream osstream;
				osstream << "Department name contains " << Student::forbiddenChars[i] << "!";
				throw std::runtime_error(osstream.str());
			}
		}
		this->department = _department;
	}
	std::string getDepartment() const{
		return this->department;
	}

	void setAge(int _age) {
		this->age = _age;
	}
	void setAge(std::string _age) {
		std::istringstream(_age) >>this->age;
	}
	int getAge() const{
		return this->age;
	}
	
	std::string toStr() {
		std::stringstream osstream;
		osstream
			<< "student id: " << this->student_id
			<< ", name: " << this->name
			<< ", gender: " << this->gender
			<< ", department: " << this->department
			<< ", age: " << this->age << std::endl;
		return osstream.str();
	}
	
	Student();
	virtual ~Student();

	std::string serialize() const;
	static Student deserialize(const std::string & input);
};

#endif // !defined(AFX_STUDENT__H__80608F71_DBE9_4C91_84DF_21408F3EDDCD__INCLUDED_)
