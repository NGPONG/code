using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 文件流
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fsRead = new FileStream(@"F:\扬中科.net\第1季C#编程基础\【传智播客.Net培训—C#编程基础】1C#基础1.avi", FileMode.Open, FileAccess.Read)) 
            {
                using (FileStream fsWrite = new FileStream(@"C:\Users\Administrator\Desktop\新建文件夹\new.avi", FileMode.Create, FileAccess.Write)) 
                {
                    byte[] buff = new byte[1024 * 1024 * 5];
                    while (true)
                    {
                        int r = fsRead.Read(buff, 0, buff.Length);
                        if (r == 0) 
                        {
                            break;
                        }
                        fsWrite.Write(buff, 0, r);
                        Console.WriteLine(fsWrite.Length);
                    }
                }
            }
            Console.ReadLine();
        }
    }
}
