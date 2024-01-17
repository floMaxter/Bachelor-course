#include <iostream>
using namespace std;

class MyString
{
public:
	//конструктор без параметров
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	//конструктор с параметрами, при создании объекта класса необходимо переcлать строку которую он будет хранить
	MyString(char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	
	}

	~MyString()
	{
		delete[] this->str;
	}

	//Конструктор копий
	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	//Конструктор переноса
	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;

		other.str = nullptr;
	}


	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString operator +(const MyString& other)
	{
		MyString newstr;

		int thisLegth = strlen(this->str);
		int otherLength = strlen(other.str);

		newstr.str = new char[thisLegth + otherLength + 1];

		int i = 0;
		for (; i < thisLegth; i++)
		{
			newstr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newstr.str[i] = other.str[j];
		}
		newstr.str[thisLegth + otherLength] = '\0';

		return newstr;
	}

	void Print()
	{
		std::cout << str << std::endl;
	}

	int Length()
	{
		return length;
	}

	bool operator==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const MyString& other)
	{
		return (!this->operator==(other));
	}

	char& operator[](int index)
	{
		return this->str[index];
	}


private:
	char* str;
	int length;
};

int main()
{
	char* tmp1 = NULL;
	char arr1[] = "Hello,";
	tmp1 = arr1;
	char* tmp2 = NULL;
	char arr2[] = " World!";
	tmp2 = arr2;

	MyString str(tmp1);

	MyString str2(tmp2);

	MyString res;
	res = str + str2;

	
	
	int m = 0;
	m = m;
	
	return 0;
}