using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_03
{
    class Program
    {
        static void Main(string[] args)
        {
            // 多态的方式创建一个抽象类，并且完成其构造函数的调用
            Animal animal = new MaleCat("黑炭", "鱼");
        }
    }

    /// <summary>
    /// 根抽象类
    /// </summary>
    public abstract class Animal
    {
        // 实例成员
        public string AnimalName { get; set; }

        // 构造函数
        public Animal(string AnimalName)
        {
            this.AnimalName = AnimalName;
        }

        // 抽象成员
        public abstract void Say();
        public abstract void Eat();
    }

    public abstract class Cat : Animal
    {
        // 实例成员
        public string Food { get; set; }

        public Cat(string AnimalName,string food)
            : base(AnimalName)
        {
            this.Food = food;
        }

        // 抽象类与抽象类之间的继承会传递其所重写的根抽象类的抽象成员
        // 重写根抽象类的一个成员后，在该抽象类的派生类就不需要继续重写当前所重写的根抽象类的成员
        public override void Eat()
        {
            Console.WriteLine($"猫吃{this.Food}");
        }
    }

    public class MaleCat : Cat
    {
        public MaleCat(string AnimalName, string food) 
            : base(AnimalName, food) { }

        public override void Say()
        {
            Console.WriteLine($"{base.AnimalName}说：喵喵喵，我是一只公猫");
        }
    }
}
