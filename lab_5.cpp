#include <iostream>

using namespace std;

template <class T>
class stack
{
public:
	stack()
	{
		top_elem = NULL;
	}

	template <typename ... Args>
	void push_emplace(Args&&... value)
	{
		Stack* velem = new Stack;
		velem->elem = T(forward<Args>(value)...);
		velem->p = top_elem;
		top_elem = velem;
	}

	void push(T&& value)
	{
		Stack* velem = new Stack;
		velem->elem = value;
		velem->p = top_elem;
		top_elem = velem;
	}
	void push(const T& value)
	{
		Stack* velem = new Stack;
		velem->elem = value;
		velem->p = top_elem;
		top_elem = velem;
	}
	void pop()
	{
		T temp = top_elem->elem;
		Stack* pelem = top_elem;
		top_elem = top_elem->p;
		delete pelem;
	}
	const T& head() const
	{
		return top_elem->elem;
	}

private:
	struct Stack
	{
		T elem;
		Stack* p;
	};
	Stack* top_elem;
};

int main()
{
	stack <int> a;
	a.push(6);
	a.push(5);
	a.push(9);
	cout << a.head() << endl;
	a.pop();
	cout << a.head() << endl;
	a.push_emplace<int>(8);
	cout << a.head() << endl;
}
