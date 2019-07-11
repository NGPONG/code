using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 多态__虚方法
{
    class Program
    {
        static void Main(string[] args)
        {
            //Person per = new Chinese();
            //per.SayHello();
            //Console.ReadLine();

            Animal[] ani = { new Dog(), new Cat(),new Animal()};
            for (int i = 0; i < ani.Length; i++) 
            {
                ani[i].SayHello();
            }
            Console.ReadLine();
        }
    }


    public class Animal 
    {
        public virtual void SayHello() 
        {
            Console.WriteLine("动物会叫！");
        }
    }
    public class Dog:Animal
    {
        public override void SayHello() 
        {
            Console.WriteLine("狗狗会叫！");
        }
    }
    public class Cat : Animal 
    {
        public override void SayHello() 
        {
            Console.WriteLine("猫咪也会叫！");
        }
    }
    public class Person 
    {
        public virtual void SayHello() 
        {
            Console.WriteLine("我是人类");
        }
    }
    public class Chinese :Person
    {
        public override void SayHello() 
        {
            Console.WriteLine("我是中国人");
        }
    }
    public class Japanese : Person 
    {
        public override void SayHello() 
        {
            Console.WriteLine("我是日本人");
        }
    }
}
