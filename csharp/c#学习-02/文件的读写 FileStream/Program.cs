using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 文件的读写_FileStream
{
    class Program
    {
        static void Main(string[] args)
        {
            //using (FileStream fsRead = new FileStream(@"C:\Users\Administrator\Desktop\1.wmv", FileMode.Open, FileAccess.Read))
            //{
                //    using (FileStream fsWrite = new FileStream(@"C:\Users\Administrator\Desktop\new.wmv", FileMode.Create, FileAccess.Write)) 
                //    {
                //        byte[] byts = new byte[1024 * 1024 * 5];
                //        while (true)
                //        {
                //            int i = fsRead.Read(byts, 0, byts.Length);
                //            if (i == 0)
                //            {
                //                break;
                //            }
                //            else 
                //            {
                //                fsWrite.Write(byts, 0, i);
                //            }
                //        }
                //    }
                //}
                //Console.WriteLine("写入成功");
                //Console.ReadLine();

                using (StreamReader sr = new StreamReader(@"C:\Users\Administrator\Deskto\bookName.txt", Encoding.Default))
                {
                    Console.WriteLine(sr.ReadLine());
                }
                Console.ReadKey(true);
            }
        }
    }
}

