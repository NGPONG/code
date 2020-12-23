using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业02
{
    class Program
    {
        static void Main(string[] args)
        {
            //定义汽车类Vehicle属性（brand(品牌),color（颜色））方法run
            //子类卡车(Truck) 属性weight载重  方法拉货
            //轿车 (Car) 属性passenger载客数量  方法载客
            Truck tru = new Truck("宝马", "黑色", 100);
            tru.Run();
            tru.laHuo();
            Car ca = new Car("奔驰", "黄色", 3);
            ca.Run();
            ca.zaiKe();
            Console.ReadLine();

        }

    }
    public class Vehicle 
    {
        public string Brand { get; set; }
        public string Color { get; set; }
        public void Run() 
        {
            Console.WriteLine("汽车会动");
        }
        public Vehicle(string brand, string color) 
        {
            this.Brand = brand;
            this.Color = color;
        }
    }

    public class Truck : Vehicle 
    {
        public int Weight { get; set; }
        public Truck(string brand, string color, int weight)
            : base(brand, color) 
        {
            this.Weight = weight;
        }
        public void laHuo() 
        {
            Console.WriteLine("我可以拉货，汽车是{0}牌子的，是{1}颜色，可以拉{2}吨",base.Brand,base.Color,this.Weight);
        }
    }
    public class Car : Vehicle 
    {
        public int Passenger { get; set; }
        public Car(string brand, string color, int passenger)
            : base(brand, color) 
        {
            this.Passenger = passenger;
        }
        public void zaiKe() 
        {
            Console.WriteLine("我可以载客，汽车是{0}牌子的，是{1}颜色，可以载{2}个人",base.Brand,base.Color,this.Passenger);
        }
    }
}
