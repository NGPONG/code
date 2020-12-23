using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 多态_存储设备练习
{
    class Program
    {
        static void Main(string[] args)
        {
            //把U盘、移动硬盘、MP3放在桌子上（初始化）
            MobileDisk md = new MobileDisk();
            MP3 mp3 = new MP3();
            UDisk ud = new UDisk();

            //把移动设备插到电脑上
            Computer cpu = new Computer(mp3);
            cpu.CpuRead();
            cpu.CpuWrite();
            Computer cpu2 = new Computer(ud);
            cpu2.CpuRead();
            cpu2.CpuWrite();
            Computer cpu3 = new Computer(md);
            cpu3.CpuRead();
            cpu3.CpuWrite();

            Console.ReadLine();
        }
    }

    public abstract class MobileStorage 
    {
        public abstract void Read();
        public abstract void Write();

    }

    public class UDisk :MobileStorage
    {
        public override void Read()
        {
            Console.WriteLine("U盘在读取数据");
        }

        public override void Write()
        {
            Console.WriteLine("U盘在写入数据");
        }
    }

    public class MobileDisk : MobileStorage
    {
        public override void Read()
        {
            Console.WriteLine("移动硬盘在读取数据");
        }

        public override void Write()
        {
            Console.WriteLine("移动硬盘在写入数据");
        }
    }

    public class MP3 : MobileStorage
    {
        public override void Read()
        {
            Console.WriteLine("MP3在读取数据");
        }

        public override void Write()
        {
            Console.WriteLine("MP3在写入数据");
        }

        public void PlayMusic() 
        {
            Console.WriteLine("MP3在放音乐");
        }
    }

    public class Computer 
    {
        public MobileStorage MS { get; set; }

        public Computer(MobileStorage ms) 
        {
            this.MS = ms;
        }

        public void CpuRead() 
        {
            this.MS.Read();
        }

        public void CpuWrite() 
        {
            this.MS.Write();
        }
    }

}
