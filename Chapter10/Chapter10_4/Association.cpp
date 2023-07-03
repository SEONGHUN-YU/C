#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor; // forward declaration, m_doctors 문제해결 #1 ★

class Patient
{
private:
	string p_name;
	vector<Doctor*> m_doctors; // 이 부분에서 Doctor가 없다고 함, 전방선언으로 처리 #1 ★

public:
	Patient(string name_in)
		: p_name(name_in)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	/*void meetDoctors()
	{
		// Doctor에서 friend로 Patient를 걸어줘서 Doctor의 ->d_name이 접근 가능해짐
		for (auto& ele : m_doctors) cout << "Meet doctor : " << ele->d_name << endl;
		// 현 상황에서는 error가 나는데, 전방선언만 되어있기에 Doctor의 d_name이 뭔지 모른다는 내용,
		// 함수의 선언부와 정의부를 분리해서, 전방선언으로 처리해야 함 #2 ♥
	}*/
	
	void meetDoctors(); // 전방선언으로 해결한 모습 #2 ♥

	friend class Doctor;
};

class Doctor
{
private:
	string d_name;
	vector<Patient*> m_patients;

public:
	Doctor(string name_in)
		: d_name(name_in)
	{}

	void addPatient(Patient* new_patient)
	{
		m_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto& ele : m_patients) cout << "Meet patient : " << ele->p_name << endl;
		// 위와 마찬가지, 이 쪽도, 저 쪽에서 friend 걸어줘야 함
	}

	friend class Patient;
};

void Patient::meetDoctors() // 정의부를 Doctor 밑으로 빼내서 선언함 -> 전방선언해주기 위함 #2 ♥
{
	for (auto& ele : m_doctors) cout << "Meet doctor : " << ele->d_name << endl;
}

int main()
{
	// Doctor 속의 Doctor : reflexive association 이라고 부른다
	// Node 속의 Node ??

	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("Violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// patients meet doctors
	p1->meetDoctors();

	// doctors meet patients
	d1->meetPatients();

	// deletes
	delete p1, p2, p3;
	delete d1, d2;

	return 0;
}