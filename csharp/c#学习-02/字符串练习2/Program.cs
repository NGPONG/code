using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串练习2
{
    class Program
    {
        static void Main(string[] args)
        {
            //练习5：123-456---789-----123-2把类似的字符串中重复符号去掉，既得到123-456-789-123-2
            //string str = "123-456---789-----123-";
            //string[] strArrary = str.Split(new char[] { '-' }, StringSplitOptions.RemoveEmptyEntries);
            //str = string.Join("-", strArrary);
            //Console.WriteLine(str);
            //Console.ReadLine();

            //练习6：从文件路径中提取出文件名(包含后缀) 。比如从c:\a\b.txt中提取出b.txt这个文件名出来。
            //以后还会学更简单的方式：“正则表达式”
            //项目中我们用微软提供的：Path.GetFileName();（更简单。）
            //string str = @"C:\Users\Administrator\Desktop\bookName.txt";
            //int i = str.LastIndexOf("\\");
            //string strPath =  str.Substring(i + 1);
            //Console.WriteLine(strPath);
            //Console.ReadLine();
            
            //练习7
            //string str = "192.168.10.5[port=21,type=ftp]";
            //string strIP = "";
            //string strPort = "";
            //string strType = "";
            //if (str.Contains("type="))
            //{
            //    int n = str.LastIndexOf('=');
            //    strType = str.Substring(n + 1);
            //    string[] strChanges = strType.Split(new char[] { ']' }, StringSplitOptions.RemoveEmptyEntries);
            //    strType = strChanges[0];
            //}
            //else
            //{
            //    strType = "http";
            //}
            //int i = str.IndexOf('5');
            //strIP = str.Substring(0, i + 1);
            //int j = str.IndexOf('=');
            //strPort = str.Substring(j + 1, 2);
            //Console.WriteLine("IP地址为{0}的服务器的{1}端口提供的服务为{2}", strIP, strPort, strType);
            //Console.ReadLine();
            
            //练习8.
            //string[] strSalary = File.ReadAllLines(@"C:\Users\Administrator\Desktop\Salary.txt", Encoding.Default);
            //string[] strName = new string[strSalary.Length];
            //string[] strMoney = new string[strSalary.Length];
            //for (int i = 0; i < strSalary.Length; i++)
            //{
            //    string[] strArrary = strSalary[i].Split(new char[] { '|' }, StringSplitOptions.RemoveEmptyEntries);
            //    strName[i] = strArrary[0];
            //    strMoney[i] = strArrary[1];
            //}

            //int[] nums = new int[strMoney.Length];
            //for (int i = 0; i < strMoney.Length; i++)
            //{
            //    int salary = int.Parse(strMoney[i]);
            //    salary += 500;
            //    nums[i] = salary;
            //    strMoney[i] = salary.ToString();
            //}

            //int max = nums[0];
            //string maxName = "";
            //int min = nums[0];
            //string minName = "";
            //int average = 0;
            //for (int i = 0; i < nums.Length; i++)
            //{
            //    if (nums[i] > max)
            //    {
            //        max = nums[i];
            //        maxName = strName[i];
            //    }
            //    if (nums[i] < min)
            //    {
            //        min = nums[i];
            //        minName = strName[i];
            //    }
            //    average += nums[i];
            //}
            //average = average / nums.Length;
            //Console.WriteLine("最高工资为：{0}，他的工资是{1}", maxName, max);
            //Console.WriteLine("最低工资为：{0}，他的工资是{1}", minName, min);
            //Console.WriteLine("平均工资为：{0}", average);
            //Console.WriteLine("所有人的工资为：");
            //for (int i = 0; i < strSalary.Length; i++)
            //{
            //    Console.WriteLine(strName[i] + "|" + strMoney[i]);
            //}
            //Console.ReadLine();

            //创建计时器对象
            Stopwatch sp = new Stopwatch();
            //计时器开始计时
            sp.Start();
            //计时器结束计时
            sp.Stop();
            //获取计时时间
            sp.Elapsed;

            Console.ReadLine();
        }
    }
}
