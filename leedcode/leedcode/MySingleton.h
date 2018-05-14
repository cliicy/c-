#include <memory>
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton * Instance()
	{
		if (0 == _instance.get())
		{
			_instance = new Singleton;
		}
		return _instance.get();
	}
protected:
	Singleton(void)
	{
		cout << "Create Singleton" << endl;
	}
	virtual ~Singleton(void)
	{
		cout << "Destory singleton" << endl;
	}
	friend class auto_ptr < Singleton > ;
	static auto_ptr<Singleton> _instance;
};

auto_ptr<Singleton> Singleton::_instance;


/*
class MySingleton{
public:
	static MySingleton* Instance(){
		if (_instance == 0){
			_instance = new MySingleton;
		}
		return _instance;
	}
protected:
	MySingleton(void){

	}
	virtual ~MySingleton(void){

	}

	static MySingleton* _instance;
};
*/