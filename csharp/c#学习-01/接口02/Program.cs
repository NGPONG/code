using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口02
{
    class Program
    {
        static void Main(string[] args)
        {
            IWalkable walk = new Student();
            walk.Walk();
            Console.ReadLine();
        }
    }
    public abstract class Person :IWalkable
    {
        public void Walk()  //实现接口
        {
            Console.WriteLine("人类实现了接口中的方法！");
        }
    }
    public class Student : Person 
    {
    
    }
    public interface IWalkable 
    {
        void Walk();
    }
}
