using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习题_6_10
{
    class Program
    {
        static void Main(string[] args)
        {
            //6. 声明两个变量：int n1 = 10, n2 = 20;要求将两个变量交换
            //    最后输出n1为20,n2为10
            //    扩展（*）：不使用第三个变量如何交换？
            int n1 = 10;
            int n2 = 20;
            n2 = n1 + n2;
            n1 = n2 - n1;
            n2 = n2 - n1;
            Console.WriteLine("{0},{1}", n1, n2);
            Console.ReadLine();

            //7. 用方法来实现：将上题封装一个方法来做
            //    提示：方法有两个参数n1,n2,在方法中将n1与n2进行交换，使用ref（*）
            int a = 10;
            int b = 20;
            changeN1N2(ref a, ref b);

            //8. 请用户输入一个字符串
            //    计算字符串中的字符个数，并输出。
            Console.WriteLine("请输入一段字符串");
            string str = Console.ReadLine();
            Console.WriteLine(str.Length);
            Console.ReadLine();

            //9. 用方法来实现：计算两个数的最大值
            //    思考：方法的参数？返回值？
            //    扩展（*）：计算任意多个数间的最大值
            Console.WriteLine(maxNumbers(30, 2, 8, 41, 69, 73, 55, 19, 82, 13, 0));
            Console.ReadLine();

            //10.用方法来实现：计算1-100之间的所有整数的和
            int sum = 0;
            for (int i = 1; i <= 100; i++)
            {
                sum += i;
            }
            Console.WriteLine(sum);
            Console.ReadLine();

        }
        public static int maxNumbers(params int[] number) 
        {
            int max = number[0];
            for (int i = 0; i < number.Length; i++)
            {
                if (number[i] > max) 
                {
                    max = number[i];
                }
            }
            return max;
        }

        /// <summary>
        /// 计算两个数的最大值
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public static int maxNumber(int a,int b) 
        {
            return a > b ? a : b;
        }
        public static void changeN1N2(ref int n1,ref int n2) 
        {
            n2 = n1 + n2;
            n1 = n2 - n1;
            n2 = n2 - n1;
        }
    }
}
