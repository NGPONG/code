using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 抽象类练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal[] anis = new Animal[] { new Dog(), new Cat(), new Pick() };
            Animal ani = null;
            for (int i = 0; i < anis.Length; i++)
            {
                ani = anis[i];
                ani.Eat();
                ani.Sleep();
                ani.Bark();
            }
            Console.ReadLine();
        }
    }

    public abstract class Animal 
    {
        public abstract void Bark();
        public abstract void Eat();
        public abstract void Sleep();
    }

    public class Dog : Animal
    {
        public override void Bark()
        {
            Console.WriteLine("狗会旺旺叫");
        }

        public override void Eat()
        {
            Console.WriteLine("狗吃狗粮");
        }

        public override void Sleep()
        {
            Console.WriteLine("狗在睡觉");
        }
    }

    public class Cat : Animal
    {
        public override void Bark()
        {
            Console.WriteLine("猫会喵喵叫");
        }

        public override void Eat()
        {
            Console.WriteLine("猫吃猫粮");
        }

        public override void Sleep()
        {
            Console.WriteLine("猫在睡觉");
        }
    }

    public class Pick : Animal 
    {
        public override void Bark()
        {
            Console.WriteLine("猪会齁齁叫");
        }

        public override void Eat()
        {
            Console.WriteLine("猪吃猪食");
        }

        public override void Sleep()
        {
            Console.WriteLine("猪经常睡觉");
        }
    }


}
