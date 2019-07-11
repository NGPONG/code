using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test01
{
    public delegate int DelMax<T>(T t1,T max);
    public delegate string DelGet(string str);
    class Program
    {
        static void Main(string[] args)
        {
            int max = GetMax<int>(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, new DelMax<int>(GetMaxInt));
            Console.WriteLine(max);
            Console.ReadLine();
        }
        public static T GetMax<T>(T[] arrary,DelMax<T> del) 
        {
            T max = arrary[0];
            for (int i = 0; i < arrary.Length; i++)
            {
                if(del(arrary[i],max)>0)
                {
                    max = arrary[i];
                }
            }
            return max;
        }

        public static int GetMaxInt(int n1,int max)
        {
            return n1 -max;
        }
    }
}
