using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST_04
{
    public delegate void DelTest();
    class Program
    {
        static void Main(string[] args)
        {
            Student stu = new Student();
            DelTest del = stu.Initialization;

            del();

            Console.WriteLine(stu.MyName);
            Console.WriteLine(stu.MyAge);

            Console.ReadKey();
        }
    }

    public class Person
    {
        public string MyName { get; set; }

        public int MyAge { get; set; }

        public void Initialization()
        {
            this.MyName = "吴鹏";
            this.MyAge = 21;
        }
    }

    public class Student : Person
    {
            
    }
}
