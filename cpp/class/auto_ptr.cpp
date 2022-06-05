
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <memory>



using namespace std;


class Test
{
public:
	Test() {
		name = NULL;
	};
	Test(const char * strname) {
		name = new char[strlen(strname) + 1];
		strcpy(name, strname);
	}

	Test& operator = (const char * namestr) {
		if (name != NULL) {
			delete name;
		}
		name = new char[strlen(namestr) + 1];
		strcpy(name, namestr);
		return *this;
	}

	void ShowName() { cout << name << endl; }

	~Test() {
		if (name != NULL) {
			delete name;
		}
		name = NULL;
		cout << "delete name" << endl;
	};

public:
	char* name;
};



template<class T>

class SmartPtr
{
public:
	SmartPtr(T *p = 0);
	SmartPtr(const SmartPtr& str);
	SmartPtr& operator = (const SmartPtr& rhs);
	T* operator -> ();
	T& operator * ();
	~SmartPtr();
private:
	void decrRef() {
		if (--*m_pRef == 0) {
			delete m_ptr;
			delete m_pRef;
		}
	}
	T *m_ptr;
	size_t *m_pRef;
};

template<class T>
SmartPtr<T>::SmartPtr(T *p) {
	m_ptr = p;
	m_pRef = new size_t(1);
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& src) {
	m_ptr = src.m_ptr;
	m_pRef++;
	m_pRef = src.m_pRef;
}

template<class T>
SmartPtr<T>::~SmartPtr() {
	decrRef();
	std::cout << "smart des" << std::endl;
}

template<class T>
T* SmartPtr<T>::operator -> () {
	if (m_ptr)
		return m_ptr;

	throw std::runtime_error("access through NULL pointer");
}

template<class T>
T& SmartPtr<T>::operator * () {
	if (m_ptr)
		return *m_ptr;

	throw std::runtime_error("access through NULL pointer");
}template<class T>

SmartPtr<T>& SmartPtr<T>::operator = (const SmartPtr<T>& rhs) {
	++*rhs.m_pRef;
	decrRef();
	m_ptr = rhs.m_ptr;
	m_pRef = rhs.m_pRef;
	return *this;
}

int main() {

	//auto_ptr<Test> TestPtr(new Test("Terry"));

	//TestPtr->ShowName();

	//*TestPtr = "David";

	//TestPtr->ShowName();

	//int y = 1;
	//int x = 0;
	//y = y / x;
	SmartPtr<Test> t1;
	SmartPtr<Test> t2(new Test("hello"));
	SmartPtr<Test> t3(new Test("jordan"));

	t2->ShowName();
	*t2 = "david";
	t2->ShowName();

	t2 = t3;

	system("pause");
	return 0;
}
