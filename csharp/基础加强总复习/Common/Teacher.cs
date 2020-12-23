using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Common
{
    public class Teacher
    {
        public string Name { get; set; }

        public int Age { get; set; }

        public void Method() 
        {
            Console.WriteLine("Teacher类的方法");
        }
    }
}
