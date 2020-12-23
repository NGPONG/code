using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 索引器
{
    class Program
    {
        static void Main(string[] args)
        {
            Test te = new Test();
            te[0] = 1;
            te[1] = 2;
            Console.WriteLine(te[0]);
            Console.WriteLine(te[1]);
            Console.ReadLine();
        }
    }
    public class Test 
    {
        //申明一个数组
        public int[] nums = new int[100];
        //申明一个索引器，实现方法和属性类似
        //语法为：访问修饰符 数组类型  this  [int index]
        public int this[int index] 
        {
            get { return nums[index]; }
            set { nums[index] = value; }
        }
    }
}
