import java.util.Scanner;

class Sort {

	public static void ArrayOutput(int arr[], int size) {
		for(int i = 0; i < size; ++i) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static int MaxElement(int first, int second) {
		return first > second ? first : second;
	}

	public static void SwapElement(int first, int second) {
		int tmp = second;
		second = first;
		first = tmp;
	}

	public static void BubbleSort(int arr[], int size) {
		
		System.out.println("This is BubbleSort");
		System.out.println();

		int count = 1;
		int tmp = 0;

		for(int i = size - 1; i > 0; --i) {
			for(int j = 0; j < i; ++j) {
				if(arr[j] > arr[j + 1]) {
					//SwapElement(arr[j], arr[j + 1]);
					tmp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = tmp;
				}
				if(count <= 5) {
					ArrayOutput(arr, size);
				} 
				count++;
			}
		}
	}

	static int flag = 1;
	public static int QuickSort(int arr[], int leftPoint, int rightPoint) {
		
		if(flag == 1) {
		System.out.println("This is QuickSort");
		System.out.println();
		flag = 0;
		}
		
		if(leftPoint >= rightPoint) {
			return 1;
		}

		int size = rightPoint - leftPoint + 1;
		int mid = leftPoint + size / 2;
		int refer = arr[mid];
		int i = leftPoint;
		int j = rightPoint;

		while(i <= j) {
			while(arr[i] < refer) {
				++i;
			}

			while(arr[j] > refer) {
				--j;
			}

			if(i <= j) {
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;

				++i;
				--j;
			}
		}

		ArrayOutput(arr, size);

		if(leftPoint < j) {
			QuickSort(arr, leftPoint, j);
		}
		
		if(rightPoint > i) {
			QuickSort(arr, i, rightPoint);
		}

		return 0;
	}
	
	public static int[] MergeSort(int arr[], int buf[], int leftPoint, int rightPoint) {

		if(leftPoint == rightPoint) {
			buf[leftPoint] = arr[leftPoint];
			return buf;
		}

		int size = rightPoint - leftPoint + 1;
		//int mid = leftPoint + size / 2;
			
		int mid = leftPoint + (rightPoint - leftPoint) / 2;


		int leftBuf[] = new int[size];
		leftBuf = MergeSort(arr, buf, leftPoint, mid);


		int rightBuf[] = new int[size];
		rightBuf = MergeSort(arr, buf, mid + 1, rightPoint);

		int target[] = new int[size];
		target = leftBuf == rightBuf ? buf : arr;

		int leftCur = leftPoint;
		int rightCur = mid + 1;

		for(int i = leftPoint; i <= rightPoint; ++i) 
		{
			if(leftCur <= mid && rightCur <= rightPoint) 
			{
				if(leftBuf[leftCur] < rightBuf[rightCur]) 
				{
					target[i] = leftBuf[leftCur];
					++leftCur;
				}
				else
				{
					target[i] = rightBuf[rightCur];
					++rightCur;
				}
			}
			else if(leftCur <= mid)
			{
				target[i] = leftBuf[leftCur];
				++leftCur;
			}
			else
			{
				target[i] = rightBuf[rightCur];
				++rightCur;
			}
		}
		return target;
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the size array: ");
		
		while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
		}

		int sizeArray = sc.nextInt();
		int arr[] = new int[sizeArray];
		System.out.println();

		
		System.out.print("Enter array values: ");

		for(int i = 0; i < sizeArray; ++i) {
			while(!sc.hasNextInt()) {
			System.out.println("Enter an integer!");
			sc.next();
			}

			arr[i] = sc.nextInt();
		}

		//BubbleSort(arr, sizeArray);
		//QuickSort(arr, 0, sizeArray - 1);
		//ArrayOutput(arr, sizeArray);

		int bufArray[] = new int[sizeArray];
		int resArray[] = new int[sizeArray];

		resArray = MergeSort(arr, bufArray, 0, sizeArray - 1);

		ArrayOutput(resArray, sizeArray);


	}
}