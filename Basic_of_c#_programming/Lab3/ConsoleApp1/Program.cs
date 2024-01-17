using System;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            
            for(int i = 0; i < 1; i++)
            {
                sb.Append(fibonacci(i)).Append(" ");
                sb2.Append(sb.ToString()).AppendLine();
            }


            Console.WriteLine(sb2.ToString());
        }

        public static int fibonacci(int iteration)
        {
            if(iteration == 0)
            {
                return 0;
            }
            if(iteration == 1)
            {
                return 1;
            }
            else
            {
                int res = fibonacci(iteration - 1) + fibonacci(iteration - 2);
                return res;
            }
        }
    }
}
