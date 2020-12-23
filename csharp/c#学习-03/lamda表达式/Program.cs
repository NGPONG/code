using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lamda表达式
{
    public delegate string DelTest(string name);
    class Program
    {
        static void Main(string[] args)
        {
            //普通lamda用法
            //(显式类型参数列表) => {语句}，lambda表达式最冗长版本
            DelTest del = (string name) => { return name; };
            Console.WriteLine(del("吴鹏"));

            //单一表达式作为主体
            //(显式类型参数列表) => 表达式
            DelTest del1 = (string name) => name;
            Console.WriteLine(del("吴鹏"));

            //隐式类型的参数列表
            //(隐式类型参数列表) => 表达式
            DelTest del2 = (name) => name;
            Console.WriteLine("吴鹏");

            //单一参数的快捷语法
            //参数名 => 表达式
            DelTest del3 = name => name;
            Console.WriteLine("吴鹏");
            Console.WriteLine();
            Console.WriteLine();

            //以下为list中RemoveAll需要一个委托方法的两种写法
            //1. 使用匿名函数
            List<int> list = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            list.RemoveAll(delegate(int n)
            {
                return n > 5;
            });
            //2. 使用lamda表达式
            list.RemoveAll((int n) => { return n > 5; });
            foreach (var item in list)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();


        }
        public static string Test2(string name, DelTest del) 
        {
           return del(name);
        }
    }
}
