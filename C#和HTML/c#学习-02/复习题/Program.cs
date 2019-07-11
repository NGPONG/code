using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 复习题
{
    class Program
    {
        static void Main(string[] args)
        {
            //1. 判断输入的是否为邮箱
            //Console.WriteLine("请输入");
            //string str = Console.ReadLine();
            //if (str.Contains("@") && str.Contains(".com"))
            //{
            //    Console.WriteLine("是邮箱地址");
            //}
            //else 
            //{
            //    Console.WriteLine("不是邮箱地址");
            //}
            //Console.ReadLine();

            //2. 输出最长的字符串
            //string[] strs = { "马龙", "迈克尔乔丹", "雷吉米勒", "蒂姆邓肯", "科比布莱恩特" };
            //int max = strs[0].Length;
            //string strName = "";
            //for (int i = 0; i < strs.Length; i++)
            //{
            //    if (strs[i].Length > max) 
            //    {
            //        max = strs[i].Length;
            //        strName = strs[i];
            //    }
            //}
            //Console.WriteLine("最长名字为：{0}",strName);
            //Console.ReadLine();

            //3. 反转数组
            string[] strs = { "中国", "美国", "巴西", "澳大利亚", "加拿大" };
            for (int i = 0; i < strs.Length/2; i++)
            {
                string temp = null;
                temp = strs[i];
                strs[i] = strs[strs.Length - 1 - i];
                strs[strs.Length - 1 - i] = temp;
            }
            for (int i = 0; i < strs.Length; i++)
            {
                Console.WriteLine(strs[i]);
            }
            Console.ReadKey(true);

        }
    }
}
