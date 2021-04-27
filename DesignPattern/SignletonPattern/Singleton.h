#ifndef __SINGLETON__
#define __SINGLETON__ 
#include <pthread.h>
//not safe
namespace s1
{
class Singleton
{
public:
	static Singleton * getInstance(){
		if(instance == NULL){
			instance = new Singleton();
		}
		return instance;
	}

private:
	static Singleton * instance;
	Singleton(){};
	Singleton(const Singleton& tmp){};
	Singleton& operator = (const Singleton& tmp){};
};

Singleton* Singleton::instance = NULL;
} /* s1 */ 

//懒汉模式
namespace s2
{
class Singleton
{
public:
	static Singleton * getInstance(){
		//双重判断会更好
		if(instance == NULL){
			pthread_mutex_lock(&mutex);
			if(instance == NULL){
				instance = new Singleton();
			}
			pthread_mutex_unlock(&mutex);
		}
		return instance;
	}

private:
	static pthread_mutex_t mutex;
	static Singleton* instance;
	Singleton(){
		pthread_mutex_init(&mutex, NULL);
	}
	Singleton(const Singleton& tmp){};
	Singleton& operator = (const Singleton& tmp){};
};

Singleton* Singleton::instance = NULL;
pthread_mutex_t Singleton::mutex;
} /* s2 */ 

//在静态成员函数中实例化对象
namespace s3
{
	class Singleton
	{
	public:
		static Singleton * getInstance(){
			static Singleton instance;
			return &instance;
		}

	private:
		static pthread_mutex_t mutex;
		Singleton(){
			pthread_mutex_init(&mutex, NULL);
		};
		Singleton(const Singleton& tmp){};
		Singleton& operator = (const Singleton& tmp){};
	};

	pthread_mutex_t Singleton::mutex;
} /* s3 */ 

//饿汉模式
namespace s4
{
	class Singleton
	{
	public:
		static Singleton * getInstance(){
			return instance;
		}
	protected:
		Singleton(){};
	private:
		static Singleton * instance;
		Singleton(const Singleton& tmep){};
		Singleton& operator = (const Singleton& tmep){};
	};
	Singleton* Singleton::instance = new Singleton();
	
} /* s4 */ 

#endif /* ifndef __SINGLETON__ */

