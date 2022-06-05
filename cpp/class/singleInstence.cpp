#include <iostream>
#include <thread>
using namespace std;

class singleInstance {
public:
	static singleInstance* GetsingleInstance() {
		if (instance == NULL) {
			mutex_t mutex;//mutex mlock; ��������
			pthread_mutex_lock(&mutex);//mlock.lock();
			if (instance == NULL) {
				instance = new singleInstance();
			}
			mutex_unlock(&mutex);//mlock.unlock();
		}
		return instance;
	};
	~singleInstance() {};
private:// �漰��������ĺ���������Ϊprivate
	singleInstance() {};
	singleInstance(const singleInstance& other) {};
	singleInstance& operator=(const singleInstance& other) { return *this; };
	static singleInstance* instance;
};

//����ʽ
singleInstance* singleInstance::instance = nullptr;

int main() {
	// ��Ϊû�а취�������󣬾͵ò��þ�̬��Ա�����ķ������ؾ�̬��Ա����
	singleInstance *s = singleInstance::GetsingleInstance();
	//singleInstance *s1 = new singleInstance(); // ����
	cout << "Hello World";
	return 0;
}