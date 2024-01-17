package Pack1;

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