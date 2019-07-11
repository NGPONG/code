using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业04
{
    class Program
    {
        static void Main(string[] args)
        {
            //动物Animal   都有吃Eat和叫Bark的方法
            //狗Dog和猫Cat叫的方法不一样.父类中没有默认的实现所哟考虑用抽象方法
            Animal ani = new Dog();
            ani.Eat();
            ani.Bark();
            Animal anicat = new Cat();
            anicat.Eat();
            anicat.Bark();
            Console.ReadLine();
        }
    }
    public abstract class Animal 
    {
        public abstract void Eat();
        public abstract void Bark();
    }

    public class Dog : Animal 
    {

        public override void Eat()
        {
            Console.WriteLine("狗像个傻逼一样吃");
        }

        public override void Bark()
        {
            Console.WriteLine("狗会汪汪叫");
        }
    }

    public class Cat : Animal
    {
        public override void Eat()
        {
            Console.WriteLine("猫会温柔的吃");
        }

        public override void Bark()
        {
            Console.WriteLine("猫会喵喵叫");
        }
    }

}
