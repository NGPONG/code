using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 使用泛型委托求任意数组的最大值
{
    public delegate int DelGetMax<T>(T t1,T t2);
    class Program
    {
        static void Main(string[] args)
        {
            //int max = GetMax<int>(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, (int n1, int n2) => { return n1 - n2; });

            string[] strs = {"12312312","asldijqowdoj","eburfiowerbqfo","dwjsadfqwieru"};
            int[] ints =  { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            string max = GetMax<string>(strs, (str1, str2) => { return str1.Length - str2.Length; });

            Console.WriteLine(max);
            Console.ReadLine();
        }

        public static T GetMax<T>(T[] arrary,DelGetMax<T> del)
        {
            T max = arrary[0];
            for (int i = 0; i < arrary.Length; i++)
            {
                if (del(max, arrary[i])<0) 
                {
                    max = arrary[i];
                }
            }
            return max;
        }
    }
}
