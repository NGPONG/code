using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StreamReaderWriter复习
{
    class Program
    {
        static void Main(string[] args)
        {
            //using (StreamReader sr = new StreamReader(@"C:\Users\Administrator\Desktop\bookName.txt", Encoding.Default)) 
            //{
            //    while (sr.EndOfStream == false)
            //    {
            //        Console.WriteLine(sr.ReadLine());
            //    }
            //}
            //Console.ReadKey(true);

            //覆盖文件
            //using (StreamWriter sw = new StreamWriter(@"C:\Users\Administrator\Desktop\new.txt")) 
            //{
            //    sw.Write("123123123");
            //}
            //Console.ReadLine();

            //追加文本
            //using (StreamWriter sw = new StreamWriter(@"C:\Users\Administrator\Desktop\new.txt", true)) 
            //{
            //    sw.Write("覆盖文本");
            //}
            //Console.WriteLine("覆盖文本成功");
            //Console.ReadLine();
        }
    }
}
