using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业06
{
    class Program
    {
        static void Main(string[] args)
        {
            //鸟-麻雀sparrow['spærəu] ，鸵鸟ostrich['ɔstritʃ] ，企鹅penguin['pengwin] ，鹦鹉parrot['pærət] 
            //鸟能飞,鸵鸟，企鹅不能
            IFlyable[] ifs = { new Sparrow(), new Ostrich(), new Penguin(), new Parrot() };
            IFlyable fly = null;
            for (int i = 0; i < ifs.Length; i++)
            {
                fly = ifs[i];
                fly.Fly();
            }
            Console.ReadLine();
        }
    }
    public interface IFlyable 
    {
        void Fly();
    }
    public class Sparrow : IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("麻雀能飞");
        }
    }

    public class Ostrich:IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("鸵鸟不能飞");
        }
    }

    public class Penguin : IFlyable
    {
        public void Fly()
        {
            Console.WriteLine("企鹅不能飞");
        }
    }

    public class Parrot : IFlyable 
    {
        public void Fly()
        {
            Console.WriteLine("鹦鹉能飞");
        }
    }


}
