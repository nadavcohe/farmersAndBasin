enum math_type{ NUMBER,VERIABLE,FUNCTION};


class MathClass{
private:
	mathClass *left;
	mathClass *right;
	
	protected:
		set_left(mathClass *a);
	
	protected:
	MathClass(mathClass *l,mathClass *r) : left(l) , right(r) {};
		
	

}

template <class T>
class Math_NUM : public mathClass{
	private:
		T data;
	public:
		Math_NUM(T dat) : data(dat) , MathClass(NULL,NULL) {
			
		}
}

class Math_OPERATOR : public mathClass{


}

class Math_Func : public mathClass{


}

class Equation{
	map<char,float> variables;
	MathClass * middle;

}