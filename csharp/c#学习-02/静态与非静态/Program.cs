using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 静态与非静态
{
    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Person();
            //Person._age = 10;
            Console.ReadKey();
        }
    }
    public class Person 
    {
        static Person() 
        {
            Console.WriteLine("你好！");
        }

        public Person() 
        {
            
        }

        //public static int _age;

        //public static char _gender;

        public string _name = "张三";

    }
}
