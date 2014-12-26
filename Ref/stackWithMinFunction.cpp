#include <iostream>
#include <stack>

using namespace std;

template <typename T> class StackWithMin {
	public:
		StackWithMin() {}
		virtual ~StackWithMin() {}

		T& top();

		void push(const T& value);
		void pop();

		const T& min() const;

	private:
		stack<T> dataStack;
		stack<T> minStack;
};

template <typename T> void StackWithMin<T>::push(const T& value) {
	dataStack.push(value);
	if(minStack.size() == 0 || value < m.top()) {
		minStack.push(value);
	} else {
		minStack.push(minStack.top());
	}
}

template <typename T> void StackWithMin<T>::pop() {
	assert(minStack.size() > 0 && dataStack.size() > 0);

	dataStack.pop();
	minStack.pop();
}

template <typename T> const T& StackWithMin<T>::min() const {
	assert(minStack.size() > 0 && dataStack.size() > 0);
	return minStack.top();
}

template <typename T> T& StackWithMin<T>::top() {
	assert(minStack.size() > 0 && dataStack.size() > 0);
	return dataStack.top();
}

