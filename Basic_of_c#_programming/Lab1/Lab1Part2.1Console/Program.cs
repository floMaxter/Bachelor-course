using System;
using System.Linq;

namespace Lab1Part2._1Console
{
    class Program
    {
        static void Main(string[] args)
        {
            Test1();
        }

        static void Test1()
        {
            Console.InputEncoding = System.Text.Encoding.Unicode;
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            Console.Write("Enter your name: ");
            String name = Console.ReadLine();
            Console.Write("Enter your surname: ");
            String surname = Console.ReadLine();
            if (!(isCorrectData(name) && isCorrectData(surname)))
            {
                Console.WriteLine("Invalid data");
                return;
            }

            int lenghtMessage = Math.Max(name.Length, surname.Length);
            char[] nameSymbolArr = new char[name.Length];
            char[] surnameSymbolArr = new char[surname.Length];
            char[] resultSymbolArr = new char[lenghtMessage];
            for (int i = 0; i < name.Length; i++)
            {
                nameSymbolArr[i] = name[i];
            }
            for(int i = 0; i < surname.Length; i++)
            {
                surnameSymbolArr[i] = surname[i];
            }
            for (int i = 0; i < lenghtMessage; i++)
            {
                if(i >= name.Length)
                {
                    resultSymbolArr[i] = (char)surnameSymbolArr[i];
                } else if(i >= surname.Length)
                {
                    resultSymbolArr[i] = (char)nameSymbolArr[i];
                } else
                {
                    resultSymbolArr[i] = (char)(nameSymbolArr[i] | surnameSymbolArr[i]);
                }
            }

            printMessageUTF16(nameSymbolArr);
            printMessageUnicode(nameSymbolArr);
            printMessageUTF16(surnameSymbolArr);
            printMessageUnicode(surnameSymbolArr);
            printMessageUTF16(resultSymbolArr);
            printMessageUnicode(resultSymbolArr);
        }

        static bool isCorrectData(String message)
        {
            return message.All(Char.IsLetter);
        }

        static void printMessageUTF16(char[] message)
        {
            for(int i = 0; i < message.Length; i++)
            {
                Console.Write(message[i] + " ");
            }
            Console.WriteLine();
        }
        static void printMessageUnicode(char[] message)
        {
            for(int i = 0; i < message.Length; i++)
            {
                Console.Write((int)message[i] + " ");
            }
            Console.WriteLine();
        }
    }
}
