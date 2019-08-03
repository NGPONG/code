using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.ProRoot;

namespace 抽象工厂.ProChild
{
    public abstract class Cat : Animal
    {
        public override void Eat()
        {
            Console.WriteLine("猫吃鱼");
        }
    }
}
