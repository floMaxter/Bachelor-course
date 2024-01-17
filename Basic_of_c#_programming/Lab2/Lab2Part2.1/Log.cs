using System;
using System.IO;
using System.Text;

namespace Lab2Part2._1
{
    public class Log
    {
        public Log(String message, Exception ex, String pathToFile)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("Lab2.cs ").Append(DateTime.Now.ToShortDateString()).Append(", ").Append(DateTime.Now.ToLongTimeString()).Append(": ");
            sb.Append(message).Append(ex.ToString());

            using (StreamWriter streamWriter = File.AppendText(pathToFile))
            {
                streamWriter.WriteLine(sb.ToString());
            }
        }
    }
}
