using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 扩展方法
{
    class Program
    {
        static void Main(string[] args)
        {
            MyInterface student = new Student();
            // 派生类所实现接口的函数
            student.SayHello();
            // 扩展方法扩展MyInterface的函数
            student.SayHelloByExtention();

            Person person = new Person() { Name = "吴鹏" };
            // 该类型的实例函数
            person.DoSomething();
            // 扩展方法所扩展Person类型的函数，虽然其方法名与该类已存在的实例方法一致，然后签名不同所以该扩展方法可被发现
            person.DoSomething("balabalabalabala");
        }
    }

    public interface MyInterface
    {
        void SayHello();
    }

    public class Student : MyInterface
    {
        public void SayHello()
        {
            Console.WriteLine("你好，我是实现接口MyInterface中的方法");
        }
    }

    public static class MethodExtention
    {
        /// <summary>
        /// 扩展 MyInterface
        /// </summary>
        /// <param name="interface"></param>
        public static void SayHelloByExtention(this MyInterface @interface)
        {
            Console.WriteLine("我是扩展接口MyInterface的方法");
        }

        /// <summary>
        /// 扩展 Person
        /// </summary>
        /// <param name="person"></param>
        /// <param name="sayWord"></param>
        public static void DoSomething(this Person person, string sayWord)
        {
            Console.WriteLine($"{person.Name}说：{sayWord}");
        }
    }

    public class Person
    {
        public string Name { get; set; }

        public void DoSomething()
        {
            Console.WriteLine("hahahahhahah");
        }
    }
}
