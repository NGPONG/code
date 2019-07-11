using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory_文件夹类
{
    class Program
    {
        static void Main(string[] args)
        {
            ////创建文件夹
            //Directory.CreateDirectory(@"C:\Users\Administrator\Desktop\New");
            ////删除文件夹
            //Directory.Delete(@"C:\Users\Administrator\Desktop\New", true);
            ////剪切文件夹
            //Directory.Move(@"C:\Users\Administrator\Desktop\New", @"c:\ew");
            ////获取文件夹下所有文件的目录
            //string[] file = Directory.GetFiles(@"C:\Users\Administrator\Desktop\New", "*.txt");
            ////获取文件夹下所有文件夹的路径
            //string[] file = Directory.GetDirectories(@"e:\a");

            Console.WriteLine(Directory.Exists(@"e:\a"));
            Console.ReadKey();


        }
    }
}
