import java.util.Scanner;

class Matrix 
{
	protected int row;
	protected int column;
	protected int arr[][];


	Matrix() {
		row = 0;
		column = 0;
		arr = null;
	}

	Matrix(int row, int column) {
		this.row = row;
		this.column = column;
		arr = new int[row][column];
	}


	public void setSize(int row, int column) {
		this.row = row;
		this.column = column;
	}


	public int getRow() {
		return this.row;
	}


	public int getColumn() {
		return this.column;
	}

	//Выделение памяти для объекта
	public void memoryAllocation(int row, int column) {
		this.arr = new int[row][column];
	}


	public void setElement(int row, int column, int value) {
		arr[row][column] = value;
	}


	public int getElement(int row, int column) {
		return arr[row][column];
	}


	public Matrix sum(Matrix other) throws ExceptionMatrix{
		Matrix res = new Matrix(this.row, this.column);
		int value = 0;

		if((this.row != other.row) || (this.column != other.column)) {
			ExceptionMatrix ex = new ExceptionMatrix("Matrix sizes are different");
			throw ex;
		}
		
		for(int i = 0; i < this.row; ++i) {
			for(int j = 0; j < this.column; ++j) {
				value = this.getElement(i, j) + other.getElement(i, j);
				res.setElement(i, j, value);
			}
		}

		return res;
	}


	public Matrix product(Matrix other) throws ExceptionMatrix {
		Matrix res = new Matrix(this.row, this.column);
		int value = 0;

		if(this.column != other.row) {
			ExceptionMatrix ex = new ExceptionMatrix("Wrong dimension!");
			throw ex;
		}
		
		for(int i = 0; i < this.getRow(); ++i) {
			for(int j = 0; j < other.getColumn(); ++j) {
				for(int inner = 0; inner < this.getColumn(); ++inner) {
					value = res.getElement(i,j) + this.getElement(i, inner) * other.getElement(inner, j);
					res.setElement(i, j, value);
				}
			}
		}

		return res;
	}


	public boolean equals(Matrix other) {
		boolean res = false;
		boolean comp = true;

		if((this.row == other.row) && (this.column == other.column)) 
		{
			loop:for(int i = 0; i < this.row && comp == true; ++i) {
				for(int j = 0; j < this.column; ++j) {
					comp = this.getElement(i, j) == other.getElement(i, j) ? true : false;
					if(!comp) {
						break loop;
					}
				}
			}

			if(comp) {
				res = true; 
			}

			return res; 
		}

		return res;
	}


	public String toString() {
		StringBuffer sb = new StringBuffer();

		for(int i = 0; i < this.row; ++i) {
			sb.append("[ ");
			for(int j = 0; j < this.column; ++j) {
				sb.append(this.getElement(i, j) + " ");
			}
			sb.append("]");
			sb.append("\n");
		}

		return sb.substring(0);
	}
}



class SquareMatrix extends Matrix {

	
	SquareMatrix() {
		super();
	}


	SquareMatrix(int row, int column) throws ExceptionMatrix {
		
		super(row, column);

		if(row != column) {
			ExceptionMatrix ex = new ExceptionMatrix("This is not square matrix");
			throw ex;
		}

		for(int i = 0; i < this.row; ++i) {
			for(int j = 0; j < this.column; ++j) {
				if(i == j) {
					arr[i][j] = 1;
                }
            }
        }
	}

	//@Override
	public SquareMatrix sum(SquareMatrix other) throws ExceptionMatrix{
		SquareMatrix res = new SquareMatrix(this.row, this.column);
		int value = 0;

		if(this.row != other.row) {
			ExceptionMatrix ex = new ExceptionMatrix("Matrix sizes are different");
			throw ex;
		}
		
		for(int i = 0; i < this.row; ++i) {
			for(int j = 0; j < this.column; ++j) {
				value = this.getElement(i, j) + other.getElement(i, j);
				res.setElement(i, j, value);
			}
		}

		return res;
	}


}



class ExceptionMatrix extends Exception {

	private String message;

    public ExceptionMatrix(String message) {
            this.message = message;
    }

    public String getMessage() {
            return message;
   	}
}


class Main {

	public static void fillingSize(Matrix mat) {
		Scanner sc = new Scanner(System.in); 
		int row = 0;
		int column = 0;

		System.out.print("Enter matrix row: ");
		
		while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
		}
		row = sc.nextInt();

		System.out.print("Enter matrix column: ");
		
		while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
		}

		column = sc.nextInt();
		mat.setSize(row, column);
		System.out.println();

		//Выделение памяти в экзмемпляре класса для значений
		mat.memoryAllocation(row, column);
	}


	public static void fillingCells(Matrix mat) {
		Scanner sc = new Scanner(System.in); 
		int value = 0;
		
		System.out.println(mat);
		System.out.println("Enter matrix values: ");

		for(int i = 0; i < mat.getRow(); ++i) {
			for(int j = 0; j < mat.getColumn(); ++j) {
				while(!sc.hasNextInt()) {
					System.out.println("Enter an integer!");
					sc.next();
				}

				value = sc.nextInt();
				mat.setElement(i, j, value);
				System.out.println(mat);
			}
		}
	}


	public static int fillingDegree() {
		Scanner sc = new Scanner(System.in);
		int deg = 1;

		System.out.println("Enter Matrix degree: ");

		while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
		}
		deg = sc.nextInt();

		return deg;
	}


	public static void main(String args[]) {
		
		
		Matrix firstMatr = new Matrix();
		Matrix secondMatr = new Matrix();
		Matrix resultMatr = new Matrix();
		

		/*
		Считывание размера матрицы в экземпляр класса,
		с последующей записью значений в ее поля.
		*/

		fillingSize(firstMatr);
		fillingCells(firstMatr);

		fillingSize(secondMatr);
		fillingCells(secondMatr);


		try {
			resultMatr = firstMatr.sum(secondMatr);

			System.out.println("Sum result:");
			System.out.println(resultMatr);
		}
		catch(ExceptionMatrix ex) {
			System.out.println(ex.getMessage());
			System.out.println();
		}


		try {
			resultMatr = firstMatr.product(secondMatr);
			
			System.out.println("Product result:");
			System.out.println(resultMatr);
		}
		catch(ExceptionMatrix ex) {
			System.out.println(ex.getMessage());
			System.out.println();
		}

		finally {
			boolean eq = firstMatr.equals(secondMatr);

			if(eq) {
				System.out.println("The matrices are equal.");
			}
			else {
				System.out.println("The matrices are not equal.");
			}
		}


		
		/*
		Scanner sc = new Scanner(System.in);
		int sizeMatr = 0;
		int value = 0;

		System.out.print("Enter matrix size: ");
		
		while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
		}
		sizeMatr = sc.nextInt();
		System.out.println();


		try {
			SquareMatrix firstSquareMatrix = new SquareMatrix(sizeMatr, sizeMatr);

			System.out.println(firstSquareMatrix);
			System.out.println("Enter matrix values: ");

			for(int i = 0; i < firstSquareMatrix.getRow(); ++i) {
				for(int j = 0; j < firstSquareMatrix.getColumn(); ++j) {
					while(!sc.hasNextInt()) {
						System.out.println("Enter an integer!");
						sc.next();
					}

					value = sc.nextInt();
					firstSquareMatrix.setElement(i, j, value);
					System.out.println(firstSquareMatrix);
			}
		}
		}
		catch(ExceptionMatrix ex) {
			System.out.println(ex.getMessage());
			System.out.println();
		}

		

		SquareMatrix secondSquareMatrix = new SquareMatrix();
		SquareMatrix resSquareMatrix = new SquareMatrix();
		*/


	}
}