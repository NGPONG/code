using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_08
{
    class Program
    {
        List<string> strTags = new List<string>();

        static void Main(string[] args)
        {
            var str = "This is Dan's ";
            str = str.Insert(str.IndexOf("'"),"'");
            Console.WriteLine(str);

            Console.ReadLine();
        }
    }
}
