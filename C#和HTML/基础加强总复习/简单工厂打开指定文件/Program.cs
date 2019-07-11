using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 简单工厂打开指定文件
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入文件的目录");
            string filepath = Console.ReadLine();
            Console.WriteLine("请输入文件名");
            string filename = Console.ReadLine();
            BaseFile bf = GetFile(filepath, filename);
            if (bf != null)
            {
                bf.GetProcess();
                Console.ReadLine();
            }
            else 
            {
                Console.WriteLine("您输入的文件名有误或没找到，按任意键程序结束");
                Console.ReadKey();
            }
       }

        public static BaseFile GetFile (string filepath,string filename)
        {
            BaseFile bf = null;
            switch (Path.GetExtension(filename)) 
            {
                case ".txt":
                    bf = new TxtFile(filepath, filename);
                    break;
                case ".jpg":
                    bf = new JpgFile(filepath, filename);
                    break;
                case ".avi":
                    bf = new AviFile(filepath, filename);
                    break;
            }
            return bf;
        }
    }

    public class BaseFile 
    {
        public string FilePath { get; set; }
        public string FileName { get; set; }

        public void GetProcess() 
        {
            //封装我们要打开的文件的路径，但并不是打开这个文件
            ProcessStartInfo psi = new ProcessStartInfo(this.FilePath + "\\" + this.FileName);
            //创建进程Process的对象
            Process pro = new Process();
            //告诉进程对象要打开文件的信息
            pro.StartInfo = psi;
            //调用函数打开
            pro.Start();
        }

        public BaseFile(string filePath, string fileName) 
        {
            this.FilePath = filePath;
            this.FileName = fileName;
        }
    }

    public class TxtFile :BaseFile
    {
        public TxtFile(string filepath, string filename)
            : base(filepath, filename) {
        
        }
    }

    public class JpgFile : BaseFile 
    {
        public JpgFile(string filepath, string filename)
            : base(filepath, filename) {
        
        }
    }

    public class AviFile : BaseFile 
    {
        public AviFile(string filepath, string filename)
            : base(filepath, filename) {
        
        }
    }
}
