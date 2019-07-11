using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业05
{
    class Program
    {
        static void Main(string[] args)
        {
            //计算形状Shape(圆Circle，矩形Square ，正方形Rectangle)的面积、周长
            Shape spCircle = new Circle(5);
            Console.WriteLine(spCircle.getGrith());
            Console.WriteLine(spCircle.getAcreage());

            Shape spSquare = new Square(5, 8);
            Console.WriteLine(spSquare.getGrith());
            Console.WriteLine(spSquare.getAcreage());

            Shape spRectangle = new Rectangle(7);
            Console.WriteLine(spRectangle.getGrith());
            Console.WriteLine(spRectangle.getAcreage());

            Console.ReadLine();
        }
    }
    public abstract class Shape 
    {
        public abstract double getGrith();
        public abstract double getAcreage();
    }
    public class Circle : Shape
    {
        public Circle(double r) 
        {
            this.R = r;
        }
        public double R { get; set; }
        public override double getGrith()
        {
            return 2 * 3.14 * this.R;
        }

        public override double getAcreage()
        {
            return 3.14 * this.R * this.R;
        }
    }

    public class Square : Shape
    {
        public Square(double height, double width) 
        {
            this.Height = height;
            this.width = width;
        }
        public double Height { get; set; }
        public double width { get; set; }
        public override double getGrith()
        {
            return this.Height * 2 + this.width * 2;
        }

        public override double getAcreage()
        {
            return this.Height * this.width;
        }
    }

    public class Rectangle : Shape
    {
        public Rectangle(double height) 
        {
            this.Height = height;
        }
        public double Height { get; set; }
        public override double getGrith()
        {
            return 4 * this.Height;
        }

        public override double getAcreage()
        {
            return this.Height * this.Height;
        }
    }



}
