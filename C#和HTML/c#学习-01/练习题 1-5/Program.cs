using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习题_1_5
{
    class Program
    {
        static void Main(string[] args)
        {
            //1. 编写一段程序，运行时向用户提问“你考了多少分？（0~100）”
            //    接受输入后判断其等级并显示出来
            //    判断依据如下：等级={优 （90~100分）；良 （80~89分）；中 （60~69分）；差 （0~59分）；}

            //Console.WriteLine("你考了多少分？（0~100）");
            //int r;
            //int.TryParse(Console.ReadLine(), out r);
            //if (r <= 100 && r >= 90)
            //{
            //    Console.WriteLine("你的评级为：优秀");
            //}
            //else if (r >= 80)
            //{
            //    Console.WriteLine("你的评级为：良好");
            //}
            //else if (r < 70 && r >= 60)
            //{
            //    Console.WriteLine("你的评级为：中等");
            //}
            //else if (r < 60 && r >= 0)
            //{
            //    Console.WriteLine("你的评级为：偏差");
            //}
            //else
            //{
            //    Console.WriteLine("你的评级为：一般");
            //}
            //Console.ReadKey(true);

            //2. 编程输出九九乘法表
            //    矩形
            //for (int i = 1; i < 10; i++)
            //{
            //    for (int r = 1; r < 10; r++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", i, r, i * r);
            //    }
            //    Console.WriteLine();
            //}
            //Console.WriteLine();
            //    //梯形
            //int n = 2;
            //for (int i = 1; i < 10; i++)
            //{
            //    for (int r = 1; r < n; r++)
            //    {
            //        Console.Write("{0}x{1}={2}\t", r, i, i * r);
            //    }
            //    Console.WriteLine();
            //    n++;
            //}
            //Console.ReadKey(true);

            //3. 定义长度50的数组
            //    随机给数组赋值,并可以让用户输入一个数字n
            //    按一行n个数输出数组

            //int[] num = new int[50];
            //Random r = new Random();
            //for (int i = 0; i < num.Length; i++)
            //{
            //    num[i] = r.Next(0, 10);
            //}
            //Console.WriteLine("请输入一个数字");
            //int a = Convert.ToInt32(Console.ReadLine());
            //Console.WriteLine();
            //for (int i = 0; i < num.Length; i++)
            //{
            //    Console.Write(num[i] + " ");
            //    if ((i + 1) % a == 0)
            //    {
            //        Console.WriteLine();
            //    }
            //}
            //Console.ReadLine();

            //4. 编写一个函数,接收一个字符串
            //    把用户输入的字符串中的第一个字母转换成小写然后返回
            //    骆驼命名法
            //string str = "AaSsDd";
            //string strNew = camelName(str);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

            //5. 编写一个函数,接收一个字符串
            //    把用户输入的字符串中的第一个字母转换成大写然后返回
            //    帕斯卡命名法
            //string str = "aaSsDd";
            //string strNew = pascalName(str);
            //Console.WriteLine(strNew);
            //Console.ReadLine();

        }
        /// <summary>
        /// 骆驼命名法
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public static string camelName(string str) 
        {
            string stringChange1 = str.Substring(0, 1);
            string stringChange2 = str.Substring(1);
            return stringChange1.ToLower() + stringChange2;
        }
        /// <summary>
        /// 帕斯卡命名法
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public static string pascalName(string str) 
        {
            string stringChange1 = str.Substring(0, 1);
            string stringChange2 = str.Substring(1);
            return stringChange1.ToUpper() + stringChange2;
        }
    }
}
