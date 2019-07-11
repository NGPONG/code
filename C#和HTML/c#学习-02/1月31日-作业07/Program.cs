using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业07
{
    class Program
    {
        static void Main(string[] args)
        {
            //橡皮rubber鸭子、木wood鸭子、真实的鸭子realduck
            //三个鸭子都会游泳，而橡皮鸭子和真实的鸭子都会叫，只是叫声不一样，橡皮鸭子“唧唧”叫，真实地鸭子“嘎嘎”叫，木鸭子不会叫
            Dark[] darks = { new ReadDark(), new XpDark(), new MuDark() };
            Dark dar = null;
            for (int i = 0; i < darks.Length; i++)
            {
                dar = darks[i];
                dar.Bark();
                dar.Swim();
            }
            Console.ReadLine();
        }
    }
    public abstract class Dark 
    {
        public void Swim()
        {
            Console.WriteLine("我会游泳");
        }
        public abstract void Bark();
    }
    public class ReadDark:Dark 
    {
        public override void Bark()
        {
            Console.WriteLine("真鸭子嘎嘎叫");
        }
    }
    public class XpDark : Dark
    {
        public override void Bark()
        {
            Console.WriteLine("橡皮鸭子唧唧叫");
        }
    }

    public class MuDark : Dark
    {
        public override void Bark()
        {
            Console.WriteLine("木鸭子不会叫");
        }
    }


}
