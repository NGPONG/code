using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习题_16_20
{
    class Program
    {
        static void Main(string[] args)
        {
            //16. 用方法来实现：请计算出一个整型数组的平均值{ 1, 3, 5, 7, 93, 33, 4, 4, 6, 8, 10 }
            //      要求：计算结果如果有小数，则显示小数点后两位（四舍五入）
            //Console.WriteLine(average(1, 3, 5, 7, 93, 33, 4, 4, 6, 8, 10));
            //Console.ReadLine();

            //17. 请通过冒泡排序法对整数数组{ 1, 3, 5, 7, 90, 2, 4, 6, 8, 10 }实现升序排序
            //int[] numbers = { 1, 3, 5, 7, 90, 2, 4, 6, 8, 10 };
            //for (int i = 0; i < numbers.Length - 1; i++)
            //{
            //    for (int j = 0; j < numbers.Length - 1 - i; j++)
            //    {
            //        if (numbers[j] < numbers[j + 1])
            //        {
            //            int number;
            //            number = numbers[j];
            //            numbers[j] = numbers[j + 1];
            //            numbers[j + 1] = number;
            //        }
            //    }
            //}
            //Console.ReadLine();


            //18. 为教师编写一个程序，该程序使用一个数组存储30个学生的考试成绩
            //      并给各个数组元素指定一个1-100的随机值
            //      然后计算平均成绩。
            //int sum = 0;
            //int[] num = new int[30];
            //Random r = new Random();
            //for (int i = 0; i < num.Length; i++)
            //{
            //    num[i] = r.Next(1, 101);
            //    sum += num[i];
            //}
            //Console.WriteLine(sum/num.Length);
            //Console.ReadLine();

            //19. 有如下字符串：
            //     【"患者：“大夫，我咳嗽得很重。”     大夫：“你多大年记？”     患者：“七十五岁。”     大夫：“二十岁咳嗽吗”患者：“不咳嗽。”     大夫：“四十岁时咳嗽吗？”     患者：“也不咳嗽。”     大夫：“那现在不咳嗽，还要等到什么时咳嗽？”"】
            //       需求：请统计出该字符中“咳嗽”二字的出现次数，以及每次“咳嗽”出现的索引位置。
            //string str = "患者：“大夫，我咳嗽得很重。”     大夫：“你多大年记？”     患者：“七十五岁。”     大夫：“二十岁咳嗽吗”患者：“不咳嗽。”     大夫：“四十岁时咳嗽吗？”     患者：“也不咳嗽。”     大夫：“那现在不咳嗽，还要等到什么时咳嗽？”";
            //string strFind = "咳嗽";
            //List<int> list = new List<int>();
            //int i = str.IndexOf(strFind);
            //list.Add(i);
            //while (true)
            //{
            //    i = str.IndexOf(strFind, i + 1);
            //    if (i == -1)
            //    {
            //        break;
            //    }
            //    list.Add(i);
            //}
            //Console.WriteLine("“咳嗽”一共出现了{0}次", list.Count);
            //for (int j = 0; j < list.Count; j++)
            //{
            //    Console.WriteLine(list[j] );
            //}
            //Console.ReadLine();

            //20. 将字符串"  hello      world,你  好 世界   !    "两端空格去掉
            //      并且将其中的所有其他空格都替换成一个空格
            //      输出结果为："hello world,你 好 世界 !"
            //string str = "  hello      world,你  好 世界   !        ";
            //string[] strs = str.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //string strNew = "";
            //for (int i = 0; i < strs.Length; i++)
            //{
            //    strNew += strs[i];
            //}
            //Console.WriteLine(strNew);
            //Console.ReadLine();

        }
        public static string average(params int[] number) 
        {
            double sum = 0;
            for (int i = 0; i < number.Length; i++)
            {
                sum += number[i];
            }
            double average = sum / number.Length;
            string str = average.ToString();
            if (str.Contains('.'))
            {
                string[] strs = str.Split(new char[] { '.' }, StringSplitOptions.RemoveEmptyEntries);
                if (strs[1].Length >= 2)
                {
                    string strNew = strs[1].Substring(0, 2);
                    return strs[0] + "." + strNew;
                }
                else
                {
                    string strNew = strs[1].Substring(0, 1);
                    return strs[0] + "." + strNew;
                }
            }
            else
            {
                return str;
            }

        }
    }
}
