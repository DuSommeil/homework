
// Virtual 20. 
// Объяснить, что делает код, написать комментарии-заголовки и комментарии к коду. Написать программу иллюстрирующую работу этого кода.

#include <iostream>
using namespace std;
const int N=10;

class fig {
 protected: 
   float x0, y0; 
   float a, b;
 public:
	fig(float x1=0, float y1=0, float a1=0, float b1=0 ): 
	   x0(x1), y0(y1), a(a1), b(b1) {}
   	fig(fig& f): x0(f.x0), y0(f.y0),
		a(f.a), b(f.b) {}
	virtual fig* copyf() const = 0;
	virtual float plosh() const = 0;
	virtual ostream& prfig(ostream& os) {	
			return os << "x0 = " << x0 << ", y0 = " << y0; }
	friend ostream &operator<<(ostream &os, fig &f)
	{ return f.prfig(os); } 
};
class tre: public fig {
 public:
	tre(float x1, float y1, float a1, float b1): 
	   fig(x1,y1,a1,b1) {}
	tre(tre& f): fig(f) {}
	fig* copyf() const 
		{ return new tre(x0, y0, a, b);}
	float plosh() const	{ return a*b/2; }	
	ostream& prfig(ostream& os) {
	fig::prfig(os);
	return os << ", kat1 = " << a << ", kat2 = " << b << endl; }
 };
class pr: public fig {
 public:
	pr (float x1, float y1, float a1, float b1):
	fig(x1,y1,a1,b1) {}
	pr(pr& f): fig(f) {}
	fig* copyf() const 
		{ return new pr(x0, y0, a, b);}
	float plosh() const	{ return a*b; }
	ostream& prfig(ostream& os) {
	fig::prfig(os);
	return os << ", side1 = " << a << ", side2 = " << b << endl;}
};

class stk {
	int len;	
	int mlen;
	fig** v; 
   public:
	stk(int n): len(0), mlen((n > N) ? N : n)  { v = new fig*[mlen]; }
	stk(const stk& fm):len(fm.len), mlen(fm.mlen) {
		v = new fig*[mlen]; 
		for (int i=0; i<len; ++i) v[i] = fm.v[i]->copyf();
	}
	~stk() {
			for (int i = 0; i < len;) delete v[i++]; 
			delete [] v;
	}	
	friend ostream& operator<<(ostream& os, stk &fs);
	int get_size() { return len; }
	int get_msize() { return mlen; }
	int resize() {
		mlen *= 2; 
		fig** newv = new fig*[mlen];
		if (newv) {
		for (int i=0; i<len; ++i) newv[i]=v[i]; 
		delete[] v;
		v = newv; return 1; }
		cerr << "Error memory allocation!" << endl;
		return 0; } 
	fig* pop() { 
		if (!len) return 0;
		fig* f = v[0]; 
		for (int i = 1; i < len; ++i) v[i-1] = v[i];
		len--; return f; }  
	int push(const fig& f) {
		if (len == mlen) resize(); 
		for (int i = len; i > 0; --i) v[i] = v[i-1];
		len++;	// увеличиваем текущую длину
		v[0] = f.copyf(); return 1; }
};
ostream& operator<<(ostream& os, stk &f) {
	os << endl << "***** Stack of geometric objects: *****" << endl;
	for (int i=0; i < f.len;)
		os << "i = " << i << ", figure=" << *f.v[i++] << endl;
	return os;
}


