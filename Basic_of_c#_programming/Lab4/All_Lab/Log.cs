using System;
using System.IO;
using System.Text;

namespace Lab2Part2._1
{
    public class Log
    {
        String path = @"D:\Studies\Прога\Lab2\Lab2Part2.1\Log.txt";
        public Log(String message, Exception ex, String pathToFile)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(DateTime.Now.ToShortDateString()).Append(", ").Append(DateTime.Now.ToLongTimeString()).Append(": ");
            sb.Append(message).Append(ex.ToString());

            using (StreamWriter streamWriter = new StreamWriter(pathToFile, true))
            {
                streamWriter.WriteLine(sb.ToString());
            }
        }

        public Log(String message, Exception ex)
        {

            StringBuilder sb = new StringBuilder();
            sb.Append(DateTime.Now.ToShortDateString()).Append(", ").Append(DateTime.Now.ToLongTimeString()).Append(": ");
            sb.Append(message).Append(ex.ToString());

            using (StreamWriter streamWriter = new StreamWriter(path, true))
            {
                streamWriter.WriteLine(sb.ToString());
            }
        }
    }
}
