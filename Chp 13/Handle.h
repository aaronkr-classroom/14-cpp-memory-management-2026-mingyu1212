#pragma once
// Handle.h

#ifndef GUARD_HANDLE_H
#define GUARD_HANDLE_H

template <class T> class Handle {
public:
	// 생성자
	Handle() : p(0){}
	Handle(const Handle& s) : p(0) { if (s.p) p = s.p->clone(); }

	// 할당 연산자
	Handle& operator=(const Handle&);
	//소멸자
	~Handle() { delete p; }

	Handle(T* t) : p(t) {}

	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;
private:
	T* p;
};

#include <stdexcept>

using namespace std;

template <class T> Handle<T>& Handle<T>::operator=(const Handle& rhs) {
	if (&rhs != this) {
		delete p;
		p = rhs.p ? rhs.p->clone() : 0;
	}
	return *this;
}

template <class T> T& Handle <T>::operator*() const {
	if (p)
		return *p;
	throw runtime_error("unvound Handle");
}

template <class T> T* Handle <T>::operator->() const {
	if (p)
		return p;
	throw runtime_error("unvound Handle");
}



#endif