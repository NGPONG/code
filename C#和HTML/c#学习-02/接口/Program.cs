using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口
{
    class Program
    {
        static void Main(string[] args)
        {
            IWalkable iw = new Student();
            iw.walk();
            Console.ReadLine();
        }
    }
    public interface IWalkable 
    {
        void walk();
    }
    public class Person : IWalkable
    {

        public void walk()
        {
            Console.WriteLine("人类会走路");
        }
    }

    public class Student
    {
    }

}
