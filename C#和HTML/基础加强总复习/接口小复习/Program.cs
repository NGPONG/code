using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口小复习
{
    class Program
    {
        static void Main(string[] args)
        {
            //麻雀会飞 企鹅不会飞 鸵鸟不会飞 鹦鹉会飞 飞机会飞
        }

    }
    public interface IFlyable 
    {
        void Fly();
    }
    public class Bird 
    {
        public string Wings { get; set; }

    }

    public class MaQue:Bird,IFlyable
    {

        public void Fly()
        {
            Console.WriteLine("麻雀会飞");
        }
    }
    public class QQ :Bird,IFlyable
    {
        
    }

    public class TuoNiao : Bird, IFlyable 
    {

    }

    public class YingWu : Bird, IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("鹦鹉会飞");
        }
    }
    public class Plane : IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("飞机会飞");
        }
    }


}
