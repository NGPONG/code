using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 泛型委托
{
    public delegate T1 MyDel<T1,T2>();
    class Program
    {
        static void Main(string[] args)
        {

        }

        public static Student Test() { return new Student(); }
    }

    public class Person
    {

    }
    public class Student : Person
    {

    }
}
