using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 泛型委托求任意数组之间的最大值
{
    public delegate int DelMax<T>(T t1,T t2);
    class Program
    {
        static void Main(string[] args)
        {
            int max = GetMax<int>(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 },GetMaxInt);
            Console.WriteLine(max);
            Console.ReadLine();

        }
        public static T GetMax<T>(T[] arrary,DelMax<T> del) 
        {
            T max = arrary[0];
            for (int i = 0; i < arrary.Length; i++)
            {
                if (del(arrary[i],max)>0) 
                {
                    max = arrary[i];
                }
            }
            return max;
        }
        public static int GetMaxInt(int n1,int max) 
        {
            return n1 - max;
        }
        public static int GetMaxString(string str1, string max) 
        {
            return str1.Length - max.Length;
        }

    }
}
