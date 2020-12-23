using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 多态__抽象类
{
    class Program
    {
        static void Main(string[] args)
        {
            Shape[] sha = { new Squre(10, 5), new Circular(5) };
            for (int i = 0; i < sha.Length; i++) 
            {
            Console.WriteLine("面积为：{0}",sha[i].acreage());
            }
            for (int i = 0; i <sha.Length ; i++)
			{
                Console.WriteLine("周长为：{0}",sha[i].girth());
			}
            Console.ReadLine();
            
        }
    }
    public abstract class Shape 
    {
        private double _length;
        public double Length 
        {
            get { return _length; }
            set { _length = value; }
        }
        private double _height;
        public double Height 
        {
            get { return _height; }
            set { _height = value; }
        }
        private double _r;
        public double R 
        {
            get { return _r; }
            set { _r = value; }
        }

        public abstract double girth();

        public abstract double acreage();
    }
    public class Squre : Shape 
    {
        public Squre(double height,double length) 
        {
            base.Length = length;
            base.Height = height;
        }

        public override double acreage()
        {
            return base.Length * base.Height;
        }

        public override double girth()
        {
            return base.Height * 2 + base.Length * 2;
        }
    }
    public class Circular : Shape 
    {
        public Circular(double r) 
        {
            base.R = r;
        }

        public override double acreage()
        {
            return 2 * Math.PI * base.R;
        }

        public override double girth()
        {
            return Math.PI * base.R * base.R;
        }
       
    }
}
