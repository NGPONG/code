using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace path类复习
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = @"C:\Users\Administrator\Desktop\bookName.txt";
            Console.WriteLine("文件名为：{0}，后缀名为：{1}，所在目录为：{2}",Path.GetFileNameWithoutExtension(str),Path.GetExtension(str),Path.GetDirectoryName(str));
            Console.ReadLine();
        }
    }
}
