
#include <iostream>
#include <mutex>
#include <string>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton;
		}
		return Instance;
	}

	int test_int() const
	{
		return TestInt;
	}

	void set_test_int(int test_int)
	{		
		TestInt = test_int;
	}
	
private:
	Singleton() {};
	~Singleton() {};
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

private:
	class GCInstance
	{
		public:
			~GCInstance()
			{
				if (Singleton::Instance != nullptr)
				{
					delete Singleton::Instance;
				}			
			}
	};
	static GCInstance GCInstance;
	
private:
	int TestInt;
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;

//void main()
//{
//	Singleton::GetInstance()->set_test_int(10);
//	Singleton::GetInstance()->set_test_int(120);
//	Singleton::GetInstance()->set_test_int(130);
//
//	cout << Singleton::GetInstance()->test_int() << endl;	
//}