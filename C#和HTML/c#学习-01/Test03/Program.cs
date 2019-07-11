using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test03
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 10;
            int n = 0;
            Test(i);
            Console.WriteLine(n);
            Console.ReadLine();
        }
        public static void Test(int n) 
        {
            n += 10;
        }
    }
}
