using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 使用委托求任意数组之间的最大值
{
    public delegate int DelCompare(object o1,object o2);
    class Program
    {
        static void Main(string[] args)
        {
            object[] nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
            //DelCompare del = new DelCompare(CompareInt);
            //object o = GetMax(nums, del);

            object[] strings = { "12132343", "qwer", "asdfg", "zxcvbn" };
            Console.WriteLine(GetMax(strings, delegate(object o1, object o2) 
            {
                string n1 = (string)o1;
                string max = (string)o2;
                return n1.Length - max.Length;
            }));
            Console.ReadLine();

            
        }
        public static object GetMax(object[] objs,DelCompare del) 
        {
            object max = objs[0];
            for (int i = 0; i < objs.Length; i++)
            {
                if (del(objs[i],max)>0) 
                {
                    max = objs[i];
                }
            }
            return max;
        }
        public static int CompareInt(object o1, object o2) 
        {
            int n1 = (int)o1;
            int max = (int)o2;
            return n1 - max;
        }

        public static int CompareString(object o1, object o2) 
        {
            string str1 = (string)o1;
            string max = (string)o2;
            return str1.Length - max.Length;
        }
    }
}
