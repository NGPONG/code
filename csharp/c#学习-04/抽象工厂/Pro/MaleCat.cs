using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using 抽象工厂.ProChild;

namespace 抽象工厂.Pro
{
    public class MaleCat : Cat
    {
        public override void Gender()
        {
            Console.WriteLine("这是一只公猫");
        }
    }
}
