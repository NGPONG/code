using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 面向对象作业
{
    class Program
    {
        static void Main(string[] args)
        {
            //Son son = new Son("吴", 0m, "O型");
            //Daughter dau = new Daughter("吴", 0m, "O型");
            //son.PlayGame();
            //dau.Dance();
            //Console.ReadLine();

            //Truck tru = new Truck();
            //tru.Weight = 100;
            //tru.Run();
            //tru.LaHuo();

            //Vehicle vei = new Vehicle();
            //vei.Passenage = 10;
            //vei.Run();
            //vei.ZaiKe();
            //Console.ReadLine();


            Shape sha = new Circle(4);
            Console.WriteLine(sha.GetGirth());
            Console.WriteLine(sha.GetAcreage());

            Shape sha1 = new Square(5, 10);
            Console.WriteLine(sha1.GetGirth());
            Console.WriteLine(sha1.GetAcreage());

            Shape sha2 = new Rectangle(10);
            Console.WriteLine(sha2.GetGirth());
            Console.WriteLine(sha2.GetAcreage());

            Console.ReadLine();

        }
    }

    public abstract class Shape
    {
        public abstract double GetGirth();

        public abstract double GetAcreage();
    }

    public class Circle : Shape
    {
        public double R { get; set; }

        public Circle(double r)
        {
            this.R = r;
        }
        public override double GetGirth()
        {
            return 2 * Math.PI * this.R;
        }

        public override double GetAcreage()
        {
            return Math.PI * this.R * this.R;
        }
    }

    public class Square : Shape
    {
        public double Length { get; set; }

        public double Height { get; set; }

        public Square(double lenght, double height)
        {
            this.Length = lenght;
            this.Height = height;
        }

        public override double GetGirth()
        {
            return 2 * (this.Length + this.Height);
        }

        public override double GetAcreage()
        {
            return this.Height * this.Height;
        }
    }

    public class Rectangle : Shape
    {
        public double Height { get; set; }

        public Rectangle(double height)
        {
            this.Height = height;
        }
        public override double GetGirth()
        {
            return this.Height * 4;
        }

        public override double GetAcreage()
        {
            return this.Height * this.Height;
        }
    }

    public class Father
    {
        public string LastName { get; set; }
        public decimal Property { get; set; }
        public string BloodType { get; set; }

        public Father(string lastname, decimal property, string bloodtype)
        {
            this.LastName = lastname;
            this.Property = property;
            this.BloodType = bloodtype;
        }
    }

    public class Son : Father
    {
        public Son(string lastname, decimal property, string bloodtype)
            : base(lastname, property, bloodtype)
        {

        }

        public void PlayGame()
        {
            Console.WriteLine("我姓{0}，财产为{1}，血型为{2}，我爱玩游戏", base.LastName, base.Property, base.BloodType);
        }
    }

    public class Daughter : Father
    {
        public Daughter(string lastname, decimal property, string bloodtype)
            : base(lastname, property, bloodtype)
        {

        }

        public void Dance()
        {
            Console.WriteLine("我姓{0}，财产为{1}，血型为{2}，我爱跳舞", base.LastName, base.Property, base.BloodType);
        }
    }

    public class Car
    {
        public string Brand { get; set; }
        public string Color { get; set; }

        public void Run()
        {
            Console.WriteLine("汽车都会走");
        }
    }

    public class Truck : Car
    {
        public int Weight { get; set; }
        public void LaHuo()
        {
            Console.WriteLine("卡车还会拉货，可以拉{0}吨", this.Weight);
        }
    }

    public class Vehicle : Car
    {
        public int Passenage { get; set; }

        public void ZaiKe()
        {
            Console.WriteLine("我可以载客，可以载{0}人", this.Passenage);
        }
    }

}
