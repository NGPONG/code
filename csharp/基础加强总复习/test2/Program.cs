using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test2
{
    class Program
    {
        static void Main(string[] args)
        {
            //Path.Combine：两个字符串连接成路径
            //AppDomain.CurrentDomain.BaseDirectory：获取当前执行程序集的绝对路径
            string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "1.txt");

            Console.WriteLine(path);
            Console.ReadLine();
        }
    }
}
