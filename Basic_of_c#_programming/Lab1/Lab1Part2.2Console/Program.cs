using System;
using System.Linq;

/*
 * 1. Дано натуральное число:
- найти количество четных цифр числа;
- определить, верно ли, что данная цифра А встречается в числе более двух
раз (А вводить с клавиатуры).
2. Найти все четырехзначные числа, у которых сумма крайних цифр равна
сумме средних цифр, а само число делится на 6 и 27.

 */

namespace Lab1Part2._2
{
    class Program
    {
        static void Main(string[] args)
        {
            Test1();
            Test2();
        }

        static void Test1()
        {
            String inputString = String.Empty;
            Console.Write("Enter number: ");
            inputString = Console.ReadLine();
            if (!isCorrectData(inputString))
            {
                Console.WriteLine("Invalid data!");
                return;
            }
            int value = Convert.ToInt32(inputString);

            Console.Write("Enter A number in: ");
            inputString = Console.ReadLine();
            if (!isCorrectData(inputString))
            {
                Console.WriteLine("Invalid data!");
                return;
            }
            int valueA = Convert.ToInt32(inputString);

            int temp = value;
            int counterEvenNumber = 0;
            int counterForA = 0;
            while (temp != 0)
            {
                int digitOfNumber = temp % 10;
                if (digitOfNumber == valueA)
                {
                    counterForA++;
                }
                if (digitOfNumber % 2 == 0)
                {
                    counterEvenNumber++;
                }
                temp /= 10;
            }
            Console.WriteLine("Even numbers = " + counterEvenNumber);
            Console.WriteLine("Digit A is contained in the number " + counterForA + " times");
        }

        private static bool isCorrectData(String data)
        {
            if (data.Equals(String.Empty))
            {
                return false;
            }
            if(data[0].Equals('0'))
            {
                return false;
            }

            return data.All(Char.IsDigit);
        }

        static void Test2()
        {
            int counter = 0;
            for (int i = 1000; i < 9999; i++)
            {
                if ((i % 6) == 0 && (i % 27) == 0)
                {
                    if (conditionCheking(i))
                    {
                        Console.WriteLine(i);
                        counter++;
                    }
                }
            }
            Console.WriteLine("Amount = " + counter);
        }

        static bool conditionCheking(int number)
        {
            int valueIndex0 = number / 1000;
            int valueIndex1 = number / 100 % 10;
            int vaelueIndex2 = number % 100 / 10;
            int valueIndex3 = number % 10;
            if (valueIndex0 + valueIndex3 == valueIndex1 + vaelueIndex2)
                return true;
            return false;
        }
    }
}