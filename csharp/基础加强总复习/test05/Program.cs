using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test05
{
    class Program
    {
        static void Main(string[] args)
        {
            Test te1 = new Test() { Age = 10, Name = "123" };
            Console.WriteLine(te1.Name + te1.Age);
            Test te2 = te1;
            te2.Name = "改了";
            te2.Age = 100;
            Console.WriteLine(te1.Name + te2.Age);

            Console.ReadKey(true);
        }
    }

    public class Test 
    {
        public int Age { get; set; }
        public string Name { get; set; }
    }
}
