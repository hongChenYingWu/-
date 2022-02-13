//自己的通用的数组类
#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray {
public:
	//有参构造 参数 容量
	MyArray(int capacity) {
		this->capacity = capacity;
		size = 0;
		pAddress = new T[this->capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr) {
		capacity = arr.capacity;
		size = arr.size;
		//深拷贝
		pAddress = new T[arr.capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < size; i++) {
			pAddress[i] = arr.pAddress[i];
		}
	}
	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray&arr) {
		//先判断原来堆区是否有数据，如果有先释放
		if (pAddress != NULL) {
			delete[] pAddress;
			pAddress = NULL;
			capacity = 0;
			size = 0;
		}
		//深拷贝
		capacity = arr.capacity;
		size = arr.size;
		pAddress = new T[arr.capacity];
		for(int i = 0; i < size; i++) {
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//尾插法
	void push_back(const T& val) {
		//判断容量是否等于大小
		if (capacity == size) {
			return;
		}
		pAddress[size] = val;//在数组末尾插入数据
		size++;//更新数组大小
	}
	//尾删法
	void pop_back() {
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (size == 0) {
			return;
		}
		size--;
	}
	//通过下标方式访问数组中的元素，如arr[0]=100
	T& operator[](int index) {
		return pAddress[index];
	}
	//返回数组容量
	int getCapacity() {
		return capacity;
	}
	//返回数组大小
	int getSize() {
		return size;
	}
	//析构函数
	~MyArray() {
		if (pAddress != NULL) {
			delete[] pAddress;
			pAddress = NULL;
		}
	}
private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int capacity; //数组容量
	int size;//数组大小
};
