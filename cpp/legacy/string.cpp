#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class String
{
public:
	//默认构造函数
	String(const char* str = nullptr);
	//默认复制构造函数
	String(const String& str);
	//默认赋值操作符
	String& operator=(const String&);

	void show();

	~String();

private:
	char* m_data;
	int	m_size;
};

String::String(const char* str)
{
	printf("init\n");
	if (str == nullptr) {
		m_data = new char[1];
		m_size = 0;
		m_data[0] = '\0';
	}
	else {
		m_size = strlen(str);
		m_data = new char[m_size + 1];
		strcpy(m_data, str);
	}
}

String::String(const String& str)
{
	printf("copy\n");
	m_size = str.m_size;
	m_data = new char[m_size + 1];
	strcpy(m_data, str.m_data);
}

String::~String()
{
	delete[] m_data;
}

String& String::operator=(const String& str) {
	//自赋值检查

	printf("assign\n");
	if (this == &str) {
		return *this;
	}
	delete[] m_data;
	m_size = str.m_size;
	m_data = new char[m_size + 1];
	strcpy(m_data, str.m_data);
	return *this;
}

void String::show() {
	printf("%s", m_data);
}





int main() {
	

	String a("string\n");
	String b("hello dear\n");
	String c(a);
	

	a.show();
	b.show();
	c.show();

	c = b;
	c.show();

	String d = b;
	d.show();







	system("pause");
	return 0;
}