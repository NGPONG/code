using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 多播委托
{
    public delegate string DelTest(string name);
    class Program
    {
        static void Main(string[] args)
        {
            DelTest del = Test1;
            del += Test2;
            del += Test3;
            del = Test1;
            del("吴鹏");
            Console.ReadLine();
        }
        public static string Test1(string name) 
        {
            Console.WriteLine(name+"1");
            return name;
        }

        public static string Test2(string name) 
        {
            Console.WriteLine(name+"2");
            return name;
        }
        public static string Test3(string name) 
        {
            Console.WriteLine(name+"3");
            return name;
        }
    }
}
