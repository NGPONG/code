using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Student:Person
    {
        private string hobby;
        public string Hobby 
        {
            get { return hobby; }
            set { hobby = value; }
        }
        public void SayHello() 
        {
            Console.WriteLine("大家好，我叫{0}，我今年{1}岁了，爱好是{2}",Name,Age,Hobby);
        }
    }
}
