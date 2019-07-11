using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 接口登记案例
{
    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Person();
            Car car = new Car();
            Decimal dec = new Decimal();
            House house = new House();

            IRegisterable[] rts = new IRegisterable[] { per, car, dec, house };

            foreach (var item in rts)
            {
                CheckIn(item);
            }
            Console.ReadLine();
        }
        public static void CheckIn(IRegisterable rt) 
        {
            rt.Register();
        } 
    }
    public interface IRegisterable 
    {
        void Register();
    }

    public class Person : IRegisterable
    {
        public void Register()
        {
            Console.WriteLine("户口本需要登记");
        } 
    }

    public class House : IRegisterable
    {
        public void Register()
        {
            Console.WriteLine("房产需要登记");
        }
    }

    public class Car : IRegisterable
    {
        public void Register()
        {
            Console.WriteLine("汽车需要登记");
        }
    }

    public class Decimal : IRegisterable
    {
        public void Register()
        {
            Console.WriteLine("财产需要登记");
        }
    }



}
