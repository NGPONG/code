using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习题_11_15
{
    class Program
    {
        static void Main(string[] args)
        {
            //11. 用方法来实现：计算1-100之间的所有奇数的和
            //List<int> list = new List<int>();
            //for (int i = 1; i <= 100; i++)
            //{
            //    if (i % 2 != 0) 
            //    {
            //        list.Add(i);
            //    }
            //}
            //int sum = 0;
            //for (int i = 0; i < list.Count; i++)
            //{
            //    sum += list[i];
            //}
            //Console.WriteLine(sum);
            //Console.ReadLine();

            //12. 用方法来实现：判断一个给定的整数是否为“质数”
            //Console.WriteLine("请输入一个数字，判断是否为质数");
            //int a = int.Parse(Console.ReadLine());
            //bool flag = true;
            //if (a == 1)
            //{
            //    flag = false;
            //}
            //else
            //{
            //    for (int i = 2; i < a; i++)
            //    {
            //        if (a % i == 0)
            //        {
            //            flag = false;
            //            break;
            //        }
            //        else
            //        {
            //            flag = true;
            //        }
            //    }
            //}
            //switch (flag)
            //{
            //    case true:
            //        Console.WriteLine("这个数字是质数");
            //        break;
            //    case false:
            //        Console.WriteLine("这个数字不是质数");
            //        break;
            //}
            //Console.ReadLine();


            //13. 用方法来实现：计算1-100之间的所有质数（素数）的和
            Console.WriteLine(computePrime());
            Console.ReadLine();

            //15. 用方法来实现：
            //      有一个字符串数组：{ "马龙", "迈克尔乔丹", "雷吉米勒", "蒂姆邓肯", "科比布莱恩特" }
            //      请输出最长的字符串
            //Console.WriteLine(equalStringLength("马龙", "迈克尔乔丹", "雷吉米勒", "蒂姆邓肯", "科比布莱恩特"));
            //Console.ReadLine();
        }

        /// <summary>
        /// 计算字符串数组最长的一个
        /// </summary>
        /// <param name="strs"></param>
        /// <returns></returns>
        public static string equalStringLength(params string[] strs) 
        {
            List<int> list = new List<int>();
            for (int i = 0; i < strs.Length; i++)
            {
                list.Add(strs[i].Length);
            }
            for (int i = 1; i < list.Count; i++)
            {
                for (int r = 0; r < list.Count - i; r++)
                {
                    if (list[r] < list[r + 1]) 
                    {
                        int a;
                        a = list[r];
                        list[r] = list[r + 1];
                        list[r + 1] = a;
                    }
                }
            }
            string str = "";
            for (int i = 0; i < list.Count; i++)
            {
                if (list[0] == strs[i].Length) 
                {
                    str = strs[i];
                }
            }
            return str;
        }

        /// <summary>
        /// 求1-100之间的质数
        /// </summary>
        /// <returns></returns>
        public static int computePrime()
        {
            List<int> list = new List<int>();
            bool flag = true;
            for (int i = 2; i <= 100; i++)
            {
                for (int n = 2; n < i; n++)
                {
                    if (i % n == 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        flag = true;
                    }
                }
                if (flag == true)
                {
                    list.Add(i);
                }
            }
            int sum = 0;
            for (int i = 0; i < list.Count; i++)
            {
                sum += list[i];
            }
            return sum;
        }




    }
}
