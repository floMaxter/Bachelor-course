using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace MatchLibrary
{
    public class Class1
    {
        public static MatchCollection Find(string str, string signature)
        {
            Regex regex = new Regex(signature, RegexOptions.IgnoreCase);
            if (str != null)
            {
                MatchCollection matches = regex.Matches(str);
                return matches;
            }
            else
            {
                return null;
            }
        }

        public static MatchCollection Time(string str)
        {
            string timeSignature = "([01]?[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]";
            Regex regex = new Regex(timeSignature);
            if (str != null)
            {
                MatchCollection matches = regex.Matches(str);
                return matches;
            }
            else
                return null;
        }
    }
}
