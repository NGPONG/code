using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test10
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Demo.Name;

            int num = Demo.Age;
            string str2 = Demo.Name;
            Console.ReadLine();
        }
    }

    public class Demo 
    {
        public static string Name = "我是静态资源";
        public static int Age = 1;
        static Demo() 
        {
            Console.WriteLine("Hello");
        }
    }
}
