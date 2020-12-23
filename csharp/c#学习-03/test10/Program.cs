using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test10
{
    class Program
    {
        static void Main(string[] args)
        {
            Teacher te = new Teacher();

            TestMethod(te);
        }

        public static void TestMethod(Teacher teacher) 
        {
            int i = 1;
            i++;
        }
    }

    public class Teacher 
    {
        public string Name { get; set; }
    }

    public class Student :Teacher
    {
        
    }
}
