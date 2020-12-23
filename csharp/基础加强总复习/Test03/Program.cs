using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test03
{
    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Student();
            Console.WriteLine(per.Type);
            Console.ReadLine();
        }
    }
    public interface ITestable 
    {
    }
    public abstract class Person 
    {
        public abstract string Type
        {
            get;
        }
    }
    public class Student :Person
    {
        public override string Type
        {
            get { return "+"; }
        }
    }
}
