#include <iostream>
#include <Windows.h>

using namespace std;

class MyComplex
{
private:
	double Re, Im;
public:
	MyComplex(double InitRe = 0, double InitIm = 0)
	{
		Re = InitRe;
		Im = InitIm;
	};

	~MyComplex()
	{
		//cout << "Destrutor\n";
	}
	//Перешрузка оператора вывода
	friend istream& operator >> (istream& o, MyComplex& B)
	{
		double a, b;
		o >> a >> b;
		B.SetRe(a);
		B.SetIm(b);
		return o;
	}
	//перегрузка оператора ввода
	friend ostream& operator << (ostream& o, MyComplex& b)
	{
		o << "Real:" << b.GetRe() << "Imagen:" << b.GetIm();
		return o;
	}
	//Операто сложения 2 экземпляров класса
	friend MyComplex& operator + (MyComplex a, MyComplex b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() + b.GetRe());    // c.Re = a.Re + b.Re;
		c.SetIm(a.GetIm() + b.GetIm());
		return c;
	}
	//Оператор сложеня для экземпляра класса и любого числа
	friend MyComplex operator + (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() + b);
		c.SetIm(a.GetIm());
		return c;
	}
	//Оператор присваивания
	MyComplex& operator = (MyComplex b)
	{
		Re = b.GetRe();
		Im = b.GetIm();
		return(*this);
	}
	//Оператор сложения для любого числа и экземпляра класса
	friend MyComplex operator + (double a, MyComplex b)
	{
		return(b + a);
	}
	//Оператор вычитания для экземпляров класса
	friend MyComplex operator - (MyComplex a, MyComplex b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() - b.GetRe());    // c.Re = a.Re + b.Re;
		c.SetIm(a.GetIm() - b.GetIm());
		return c;
	}
	//оператор вычитания для экземпляра класса и числа
	friend MyComplex operator - (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() - b);
		c.SetIm(a.GetIm());
		return c;
	}
	//оператор вычитания для числа и экземпляра класса
	friend MyComplex operator - (double b, MyComplex a)
	{
		return(a - b); 
	}
	//Умножение экземпляров
	friend MyComplex operator* (MyComplex a, MyComplex b)
	{
		MyComplex c;
		c.SetRe((a.GetRe() * b.GetRe()) - (a.GetIm() * b.GetIm()));
		c.SetIm((a.GetRe() * b.GetIm()) + (b.GetRe() * a.GetIm()));
		return c;
	}
	//Умножение экземпляра и числа
	friend MyComplex operator* (MyComplex a, double b)
	{
		MyComplex c;
		c.SetRe(a.GetRe() * b);
		c.SetIm(a.GetIm());
		return c;
	}
	//Умножение числа и экземпляра 
	friend MyComplex operator* (double b, MyComplex a)
	{
		return (a * b);
	}
	double GetRe()
	{
		return Re;
	}
	double GetIm()
	{
		return Im;
	}
	int SetRe(double newVal)
	{
		Re = newVal;
		return 1;
	}
	int SetIm(double newVal)
	{
		Im = newVal;
		return 1;
	}
};

void main()
{
	MyComplex A(1, 1), B, C(1), D;
	C = A + B;
	cout << "C:  " << C << "\n";
	C = A + 10.5;
	cout << "C:  " << C << "\n";
	C = 10.5 + A;
	cout << "C:  " << C << "\n";
	C = A + B + C + D;
	cout << "C:  " << C << "\n";
	C = A = B = C;
	cout << "C:  " << C << "\n";
	C = C - A - B;
	cout << "C:  " << C << "\n";
	C = A * B;
	cout << "C:  " << C << "\n";
	cin >> A >> B >> C;
	cout << "A:  " << A << "\n";
	cout << "B:  " << B << "\n";
	cout << "C:  " << C << "\n";
	system("pause");
	
}
