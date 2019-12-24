#include <iostream>

using namespace std;

template <typename T>
class SharedPtr
{
public:
	SharedPtr()
	{
		obj = NULL;
		count = 0;
	}

	SharedPtr(T* ptr)
	{
		obj = ptr;
		count++;
	}
	SharedPtr(const SharedPtr& r)
	{
		this->obj = r.obj;
		count++;
	}
	SharedPtr(SharedPtr&& r)
	{
		this->obj = r.obj;
		count++;
	}
	~SharedPtr()
	{
		delete obj;
		count = 0;
	}
	auto operator = (const SharedPtr& r)
	{
		count++;
		return r;
	}
	auto operator = (SharedPtr&& r)
	{
		count++;
		return r;
	}
	operator bool() const
	{
		return count != 0;
	}
	auto operator*() const -> T&
	{
		return *obj;
	}
	auto operator->() const -> T*
	{
		return obj;
	}
	auto get() -> T*
	{
		return obj;
	}
	void reset()
	{
		delete obj;
	}
	void reset(T* ptr)
	{
		obj = ptr;
	}
	void swap(SharedPtr& r)
	{
		SharedPtr p1 = new T();
		p1.obj = r.obj;
		r.obj = this->obj;
		this->obj = p1.obj;
		delete p1.obj;
	}
	size_t use_count() const
	{
		return count;
	}
private:
	T* obj;
	size_t count = 1;
};

int main()
{
	int* p = new int[5];
	/*SharedPtr<int> ptr1(p);
	SharedPtr<int> ptr2(ptr1);
	SharedPtr<int> ptr3(ptr2);
	SharedPtr<int> ptr4(ptr3);*/
	auto ptr1 = make_shared<int*>(p);
	//auto ptr2= make_shared<int>(ptr1);
	auto ptr2(ptr1);
	auto ptr3(ptr2);
	auto ptr4(ptr3);
	cout << ptr1.use_count() << endl;
	ptr3.reset();
	ptr4.reset();

	//SharedPtr<int> ptr5(ptr4);
	auto ptr5(ptr4);
	cout << ptr1.use_count() << endl;
	cout << ptr5.use_count() << endl;
	cout << ptr2.use_count() << endl;
	
	return 0;
}
