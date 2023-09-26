#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string* name;
public:
	virtual void output() const { cout << "Name:" << *name << endl; }
	Person(string n): name(new string(n)){}
	Person() :name(new string("TBD")){}
	~Person() {
		cout << "==> (Person) Destructor was called" << endl;
		delete name;
	}
	Person(Person& p) {
		cout << "==> (Person) Copy Constructor was called" << endl;
		name = new string(*(p.name));
	}
	Person& operator =(Person& p) {
		cout << "==> (Person) Assignment Operator was called" << endl;
		name = new string(*(p.name));
		return p;
	}
};

class Student : public Person {
private:
	int* id;
public:
	Student(): id(new int(0)) {}
	Student(string n, int x) :Person(n), id(new int(x)) {}
	void output() const override {
		cout << "Name: " << *name << endl << "ID: " << *id << endl;
	}
	~Student() {
		cout << "==> (Student) Destructor was called" << endl;
		delete id;
	}
	Student(Student& s) {
		cout << "==> (Student) Copy Constructor was called" << endl;
		name = new string(*(s.name));
		id = new int(*(s.id));
	}
	Student& operator =(Student& s) {
		cout << "==> (Student) Assignment Operator was called" << endl;
		name = new string(*(s.name));
		id = s.id;
		return s;
	}
};

class Instructor: public Person {
private:
	string *department;
public:
	Instructor() :Person(), department(new string("TBD")) {}
	Instructor(string n, string d) :Person(n), department(new string(d)) {}
	void output() const override{
		cout << "Name: " << *name << endl << "Department: " << *department << endl;
	}
};

int main() {
	cout << endl;
	Person** a = new Person * [4];
	a[0] = new Student("David", 1212);
	a[1] = new Instructor("Sam", "Math");
	a[2] = new Student("Tom", 2345);
	a[3] = new Instructor("Jack", "History");
	for (int i = 0; i < 4; i++) {
		a[i]->output();
		cout << endl;
	}
	cout << endl;
	return 0;
}