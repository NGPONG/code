using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Person
    {
        public int number;

        private string name;
        public string Name 
        {
            get { return name; }
            set { name = value; }
        }

        private int age;
        public int Age 
        {
            get { return age; }
            set { age = value; }
        }

        private char sex;
        public char Sex 
        {
            get { return sex; }
            set { sex = value; }
        }

        public void SayHI() 
        {
            Console.WriteLine("这个是父类中的打招呼方式，大家好，我叫{0}，今年{1}岁了，我是{2}生",Name,Age,Sex);
        }
    }
}
