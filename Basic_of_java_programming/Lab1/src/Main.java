class Int {

	private int value = 0;

	void increment() {
		++value;
	}

	void decrement() {
		--value;
	}

	void add(Int n) {
		value = value + n.value;
	}

	void substract(Int n) {
		value = value - n.value;
	}


	public String toString() {
		return "Value = " + value;
	}
}

class Fractions {

	private int numerator;
	private int denominator;

	Fractions() {
		this.numerator = 0;
		this.denominator = 0;
	}


	Fractions(int numerator, int denominator) {
		this.numerator = numerator;
		this.denominator = denominator;
	}

	public void setFractions(int numerator, int denominator) {
		this.numerator = numerator;
		this.denominator = denominator;
	}

	public int nod(int a, int b) {
		if(a == 0 || b == 0) {
			return 0;
		}

		int remainder;
		while(b != 0) {
			remainder = a % b;
			a = b;
			b = remainder;
		}

		return a;
	}

	private int nok(int a, int b) {
		if(a == 0 || b == 0) {
			return 0;
		}
		int nok = (a * b) / nod(a, b);
		
		return nok;
	}

	Fractions substract(Fractions n) {
		int nok = nok(this.denominator, n.denominator);
		int factorFirst = nok / this.denominator;
		int factorSecond = nok / n.denominator;

		int resNumerator = this.numerator * factorFirst - n.numerator * factorSecond;

		if(resNumerator == 0) {
			nok = 0;
		}

		Fractions res = new Fractions();
		res.setFractions(resNumerator, nok);

		return res;
	} 

	Fractions expon(int degree) {
		Fractions res = new Fractions();

		if(degree > 0) {
			for(int i = 0; i < degree; ++i) {
				res.numerator = this.numerator * this.numerator;
				res.denominator = this.denominator * this.denominator;
			}
		}

		if(degree < 0) {
			for(int i = 0; i < degree; ++i) {
				res.numerator = this.denominator * this.denominator;
				res.denominator = this.numerator * this.numerator;
			}
		}

		return res;
	}

	public String toString() {
		return "Fractions = " + this.numerator + "/" + this.denominator;
	} 

	void printFraction() {
		System.out.println(this.numerator + "/" + this.denominator);
	}
}


class Main {
	public static void main(String args[]) {
		Fractions a = new Fractions(3, 7);
		Fractions b = new Fractions(-1, 5);
		Fractions c = new Fractions();

		/*Int first = new Int();
		Int second = new Int();

		first.increment();
		first.increment();

		System.out.println(second);
		second.add(first);

		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		second.decrement();
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		second.increment();
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		
		System.out.println(second);
		second.add(second);
		*/
		

		c = a.substract(b);
		System.out.println(c);

		c = c.expon(2);
		System.out.println(c);

	}
}