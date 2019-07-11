using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 工厂设计模式打开指定文件
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入你想进入的磁盘");
            string disk = Console.ReadLine();
            Console.WriteLine("请输入你想打开的文件");
            string filename = Console.ReadLine();
            string file = Path.GetExtension(filename);
            getFile(disk, file).openFile(filename);
            Console.ReadLine();
        }
        public static CommonFile getFile(string disk, string file) 
        {
            CommonFile cf = null;
            switch (file) 
            {
                case ".txt":
                    cf = new TxtFile(disk);
                    break;
                case ".jpg":
                    cf = new JpgFile(disk);
                    break;
                case ".wmv":
                    cf = new WmvFile(disk);
                    break;
            }
            return cf;
        }
        
    }
    public abstract class CommonFile 
    {
        public string Disk
        {
            get;
            set;
        }
        public abstract void openFile(string filename);
    }

    public class TxtFile :CommonFile
    {
        public TxtFile(string disk) 
        {
            base.Disk = disk;
        }
        public override void openFile(string filename)
        {
            Process.Start(new ProcessStartInfo(base.Disk + filename));
        }
    }

    public class JpgFile : CommonFile
    {
        public JpgFile(string disk) 
        {
            base.Disk = disk;
        }
        public override void openFile(string filename)
        {
            Process.Start(new ProcessStartInfo(base.Disk + "\\" + filename));
        }
    }

    public class WmvFile : CommonFile
    {
        public WmvFile(string disk) 
        {
            base.Disk = disk;
        }
        public override void openFile(string filename)
        {
            Process.Start(new ProcessStartInfo(base.Disk + "\\" + filename));
        }
    }



}
