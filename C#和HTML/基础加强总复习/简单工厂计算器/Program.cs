using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProOperation;

namespace 简单工厂计算器
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("请输入第一个计算的数字");
                int n1 = int.Parse(Console.ReadLine());
                Console.WriteLine("请输入第二个运算的数字");
                int n2 = int.Parse(Console.ReadLine());
                Console.WriteLine("请输入运算符");
                string count = Console.ReadLine();

                Operation ope = GetNum(count);
                double result = ope.GetOperation(n1, n2);

                Console.WriteLine("运算结果为：" + result);
                Console.ReadLine();
            }
        }

        public static Operation GetNum(string count) 
        {
            Operation ope = null;
            switch (count) 
            {
                case "+":
                    ope = new Add();
                    break;
                case "-":
                    ope = new Minus();
                    break;
                case "*":
                    ope = new Multipy();
                    break;
                case "/":
                    ope = new Eliminate();
                    break;
            }
            return ope;
        }
    }
}
