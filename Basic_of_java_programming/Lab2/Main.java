 import java.util.Scanner;


class SquareMatrix {
        private int size;
        private int arr[][]; 

        SquareMatrix() {
                size = 0;
                arr = null;
        }

        
        SquareMatrix(int value) {
                this.size = value;
                arr = new int[value][value];

                for(int i = 0; i < this.size; ++i) {
                	arr[i][i] = 1;
                }
        }
        

        SquareMatrix(int size, int start) {
            this.size = size;
            arr = new int[size][size];

            int value = start;

            for(int i = 0; i < this.size; ++i) {
                arr[0][i] = value;
                value++;
            }
            for(int j = 1; j < this.size; ++j) {
                arr[j][size - 1] = value;
                value++;
            }
            for(int k = size - 2; k >= 0; --k) {
                arr[size - 1][k] = value;
                value++;
            }
            for(int l = size - 2; l > 0; --l) {
                arr[l][0] = value;
                value++;
            }

            int rowTmp = 1;
            int columnTmp = 1;

            while(value < size * size) {

                //Движение вправо
                while(arr[rowTmp][columnTmp + 1] == 0) {
                    arr[rowTmp][columnTmp] = value;

                    value++;
                    columnTmp++;
                }

                //Движение вниз
                while(arr[rowTmp + 1][columnTmp] == 0) {
                    arr[rowTmp][columnTmp] = value;

                    value++;
                    rowTmp++;
                }

                //Движение влево
                while(arr[rowTmp][columnTmp - 1] == 0) {
                    arr[rowTmp][columnTmp] = value;

                    value++;
                    columnTmp--;                    
                }

                //Движение вверх
                while(arr[rowTmp - 1][columnTmp] == 0) {
                    arr[rowTmp][columnTmp] = value;

                    value++;
                    rowTmp--;
                } 
            }

            for(int i = 0; i < this.size; ++i) {
                for(int j = 0; j < this.size; ++j) {
                    if(arr[i][j] == 0) {
                        arr[i][j] = value;
                    }
                }
            }
        }

        public void setSize(int size) {
                this.size = size;
        }


        public int getSize() {
                return this.size;
        }

        //Выделение памяти для объекта
        public void memoryAllocation(int size) {
                this.arr = new int[size][size];
        }

        public void setElement(int row, int column, int value) {
                arr[row][column] = value;
        }


        public int getElement(int row, int column) {
                return arr[row][column];
        }

        
        public SquareMatrix sum(SquareMatrix other) {
                SquareMatrix res = new SquareMatrix(this.size);
                int value = 0;

                if(this.size != other.size) {
                        RuntimeException ex = new RuntimeException("The sizes of matrices for addition are different!");
                        throw ex;
                }

                for(int i = 0; i < this.size; ++i) {
                        for(int j = 0; j < this.size; ++j) {
                                value = this.getElement(i, j) + other.getElement(i, j);
                                res.setElement(i, j, value);
                        }
                }

                return res;
        }

        
        public SquareMatrix product(SquareMatrix other) {
                SquareMatrix res = new SquareMatrix(this.size);
                int value = 0;

                if(this.size != other.size) {
                        RuntimeException ex = new RuntimeException("The dimensions of the matrices for the product are different!");
                        throw ex;
                }
                
                for(int i = 0; i < this.size; ++i) {
                        for(int j = 0; j < this.size; ++j) {
                                for(int inner = 0; inner < this.size; ++inner) {
                                        value = res.getElement(i,j) + this.getElement(i, inner) * other.getElement(inner, j);
                                        res.setElement(i, j, value);
                                }
                        }
                }

                return res;
        }

        
        public SquareMatrix exponentiation(int deg) throws MyExceptionMatrix {
                SquareMatrix res = new SquareMatrix(this.size);
                SquareMatrix tmp = new SquareMatrix(this.size);
                
                int value = 0;

                if(deg < 0) {
                        MyExceptionMatrix ex = new MyExceptionMatrix(-1, "Degree less than zero!");
                        throw ex;
                }
                else if(deg == 0) {
                    for(int i = 0; i < res.getSize(); ++i) {
                        res.setElement(i, i, 1);
                    }
                }
                else if(deg == 1) {
                        for(int i = 0; i < res.getSize(); ++i) {
                                for(int j = 0; j < res.getSize(); ++j) {
                                        value = this.getElement(i, j);
                                        res.setElement(i,j, value);
                                }
                        }
                }
                else {
                        for(int i = 0; i < res.getSize(); ++i) {
                                for(int j = 0; j < res.getSize(); ++j) {
                                        value = this.getElement(i, j);
                                        res.setElement(i,j, value);
                                        tmp.setElement(i,j, value);
                                }
                        }

                        for(int i = 1; i < deg; ++i) {
                                res = res.product(tmp);
                        }
                }
                return res;
        }

        
        public String toString() {
                StringBuffer sb = new StringBuffer();

                for(int i = 0; i < this.size; ++i) {
                        sb.append("[ ");
                        for(int j = 0; j < this.size; ++j) {
                                sb.append(this.getElement(i, j)).append(" ");
                        }
                        sb.append("]");
                        sb.append("\n");
                }

                return sb.substring(0);
        }
}


class MyExceptionMatrix extends Exception {
        
        private int idError;
        private String message;

        public MyExceptionMatrix(int value, String message) {
                idError = value;
                this.message = message;
        }

        public int getIdNumber() {
                return idError;
        }

        public String getMessage() {
                return message;
        }
}


class Main {

        public static void fillingSize(SquareMatrix mat) {
                Scanner sc = new Scanner(System.in); 
                int sizeMatr = 0;

                System.out.println("Enter matrix size: ");
                
                while(!sc.hasNextInt()) {
                        System.out.println("Enter an integer!");
                        sc.next();
                }

                sizeMatr = sc.nextInt();
                mat.setSize(sizeMatr);
                System.out.println();

                //Выделение памяти в экзмемпляре класса для значений
                mat.memoryAllocation(sizeMatr);
        }


        public static void fillingCells(SquareMatrix mat) {
                Scanner sc = new Scanner(System.in); 
                int value = 0;
                
                System.out.println(mat);
                System.out.println("Enter matrix values: ");

                for(int i = 0; i < mat.getSize(); ++i) {
                        for(int j = 0; j < mat.getSize(); ++j) {
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
                
                int start = 1;
                int size = 5;

                SquareMatrix firstMatr = new SquareMatrix(size, start);
                SquareMatrix secondMatr = new SquareMatrix();
                SquareMatrix resultMatr = new SquareMatrix();

                System.out.println(firstMatr);



                /*
                Считывание размера матрицы в экземпляр класса,
                с последующей записью значений в ее поля.
                */

               /* SquareMatrix firstMatr = new SquareMatrix();
                SquareMatrix secondMatr = new SquareMatrix();
                SquareMatrix resultMatr = new SquareMatrix();

                fillingSize(firstMatr);
                fillingCells(firstMatr);

                fillingSize(secondMatr);
                fillingCells(secondMatr);

                try {
                        resultMatr = firstMatr.sum(secondMatr);

                        System.out.println("Sum result:");
                        System.out.println(resultMatr);
                }
                catch(RuntimeException ex) {
                        ex.printStackTrace();
                        System.out.println();
                }

                
                try {
                        resultMatr = firstMatr.product(secondMatr);

                        System.out.println("Product result:");
                        System.out.println(resultMatr);
                }
                catch(RuntimeException ex) {
                        ex.printStackTrace();
                        System.out.println();
                }
                
                
                int degMatr = fillingDegree();

                try {
                        resultMatr = firstMatr.exponentiation(degMatr);

                        System.out.println("The result of exponentiation: ");
                        System.out.println(resultMatr);
                }
                catch(MyExceptionMatrix ex) {
                        if(ex.getIdNumber() == -1) {
                                System.out.println(ex.getMessage());
                                System.out.println();
                        }
                        else if(ex.getIdNumber() == 0) {
                                System.out.println(ex.getMessage());
                                System.out.println("==> Result = " + 1);
                        }
                }
         */   
        }
}