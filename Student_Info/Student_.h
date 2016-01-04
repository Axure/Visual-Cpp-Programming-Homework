// Student_.h: interface for the Student_ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT__H__80608F71_DBE9_4C91_84DF_21408F3EDDCD__INCLUDED_)
#define AFX_STUDENT__H__80608F71_DBE9_4C91_84DF_21408F3EDDCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Student {
private:
	long student_id;
	std::string name;
	int gender;
	std::string department;
	int age;
protected:
	
public:

	void setStudentId(long _student_id) {
		this->student_id = _student_id;
	}
	long getStudentId() const {
		return this->student_id;
	}

	void setName(const std::string &_name) {
		this->name = _name;
	}
	std::string getName() const{
		return this->name;
	}

	void setGender(int _gender) {
		this->gender = _gender;
	}
	int getGender() const{
		return this->gender;
	}

	void setDepartment(const std::string &_department) {
		this->department = _department;
	}
	std::string getDepartment() const{
		return this->department;
	}

	void setAge(int _age) {
		this->age = _age;
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
