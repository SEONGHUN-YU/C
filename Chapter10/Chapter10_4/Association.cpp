#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor; // forward declaration, m_doctors �����ذ� #1 ��

class Patient
{
private:
	string p_name;
	vector<Doctor*> m_doctors; // �� �κп��� Doctor�� ���ٰ� ��, ���漱������ ó�� #1 ��

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
		// Doctor���� friend�� Patient�� �ɾ��༭ Doctor�� ->d_name�� ���� ��������
		for (auto& ele : m_doctors) cout << "Meet doctor : " << ele->d_name << endl;
		// �� ��Ȳ������ error�� ���µ�, ���漱�� �Ǿ��ֱ⿡ Doctor�� d_name�� ���� �𸥴ٴ� ����,
		// �Լ��� ����ο� ���Ǻθ� �и��ؼ�, ���漱������ ó���ؾ� �� #2 ��
	}*/
	
	void meetDoctors(); // ���漱������ �ذ��� ��� #2 ��

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
		// ���� ��������, �� �ʵ�, �� �ʿ��� friend �ɾ���� ��
	}

	friend class Patient;
};

void Patient::meetDoctors() // ���Ǻθ� Doctor ������ ������ ������ -> ���漱�����ֱ� ���� #2 ��
{
	for (auto& ele : m_doctors) cout << "Meet doctor : " << ele->d_name << endl;
}

int main()
{
	// Doctor ���� Doctor : reflexive association �̶�� �θ���
	// Node ���� Node ??

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