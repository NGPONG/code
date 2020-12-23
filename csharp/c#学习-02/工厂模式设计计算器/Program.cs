using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 工厂模式设计计算器
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("请输入第一个运算的数字");
                int num1 = int.Parse(Console.ReadLine());
                Console.WriteLine("请输入第二个运算的数字");
                int num2 = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("请输入需要运算的运算符");
                string opr = Console.ReadLine();
                Operator ope = getNumber(opr, num1, num2);
                int result = ope.getMethod();
                Console.WriteLine("结果为：{0}",result);
            }
        }
        public static Operator getNumber(string opr, int num1, int num2) 
        {
            Operator ope = null;
            switch (opr) 
            {
                case "+":
                    ope = new Add(num1, num2);
                    break;
                case "-":
                    ope = new Reduce(num1, num2);
                    break;
                case "*":
                    ope = new Ride(num1, num2);
                    break;
                case "/":
                    ope = new Divide(num1, num2);
                    break;
            }
            return ope;
        }
    }
    public abstract class Operator 
    {
        public int Num1 { get; set; }
        public int Num2 { get; set; }
        public abstract int getMethod();
    }
    public class Add :Operator
    {
        public Add(int num1, int num2)
        {
            base.Num1 = num1;
            base.Num2 = num2;
        }
        public override int getMethod()
        {
            return base.Num1 + base.Num2;
        }
    }
    public class Reduce : Operator 
    {
        public Reduce(int num1, int num2) 
        {
            base.Num1 = num1;
            base.Num2 = num2;
        }
        public override int getMethod()
        {
            return base.Num1 - base.Num2;
        }
    }
    public class Ride : Operator
    {
        public Ride(int num1, int num2) 
        {
            base.Num1 = num1;
            base.Num2 = num2;
        }
        public override int getMethod()
        {
            return base.Num1 * base.Num2;
        }
    }
    public class Divide : Operator
    {
        public Divide(int num1, int num2) 
        {
            base.Num1 = num1;
            base.Num2 = num2;
        }
        public override int getMethod()
        {
            return base.Num1 / base.Num2;
        }
    }


}
