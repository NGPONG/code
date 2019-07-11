using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            int number;
            Test(out number);
            Console.WriteLine(number);
            Console.ReadLine();
        }
        static void Test(out int number) 
        {
            number = 100;
        }
    }
}
