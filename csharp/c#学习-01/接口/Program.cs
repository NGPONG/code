using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口
{
    class Program
    {
        static void Main(string[] args)
        {
            //鸵鸟不会飞  麻雀会飞  企鹅不会飞  大雁会飞
            Brid[] bri = { new TuoBrid(), new MqBrid(), new QqBrid(), new DayanBrid() };
            for (int i = 0; i < bri.Length; i++)
            {
                bri[i].Fly();
            }

            IEatable[] eat = { new TuoBrid(), new MqBrid(), new QqBrid(), new DayanBrid() };
            for (int i = 0; i < eat.Length; i++)
            {
                eat[i].Eat();
            }
            Console.ReadLine();

        }
    }
    public interface IEatable 
    {
        void Eat();
    }
    public class Brid
    {
        public virtual void Fly() 
        {
            Console.WriteLine("鸟都会飞");
        }
    }
    public class TuoBrid :Brid,IEatable
    {
        public override void Fly()
        {
            Console.WriteLine("鸵鸟不会飞");
        }

        public void Eat()
        {
            Console.WriteLine("鸵鸟不吃");
        }
    }
    public class MqBrid : Brid,IEatable
    {
        public override void Fly()
        {
            Console.WriteLine("麻雀会飞");
        }

        public void Eat()
        {
            Console.WriteLine("麻雀吃");
        }
    }
    public class QqBrid : Brid ,IEatable
    {
        public override void Fly()
        {
            Console.WriteLine("企鹅不会飞");
        }

        public void Eat()
        {
            Console.WriteLine("企鹅吃");
        }
    }
    public class DayanBrid : Brid ,IEatable
    {
        public override void Fly()
        {
            Console.WriteLine("大雁会飞");
        }

        public void Eat()
        {
            Console.WriteLine("大雁不吃");
        }
    }
}
