using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 多态___模拟移动硬盘盘u盘mp3练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入你想插入的设备\n1.MP3  2.移动硬盘  3.U盘");
            string choice = Console.ReadLine();
            int i;
            bool falg = int.TryParse(choice,out i);
            switch (i) 
            {
                case 1:
                    Computer cpu = new Computer(new MP3());
                    cpu.CpuRead();
                    cpu.CpuWrite();
                    break;
                case 2:
                    cpu = new Computer(new Disk());
                    cpu.CpuRead();
                    cpu.CpuWrite();
                    break;
                case 3:
                    cpu = new Computer(new Udisk());
                    cpu.CpuRead();
                    cpu.CpuWrite();
                    break;
            }
            //Computer cpu = new Computer(new Udisk());
            //cpu.CpuRead();
            //cpu.CpuWrite();
            Console.ReadLine();
        }
    }

    public abstract class Storage 
    {
        public abstract void Read();
        public abstract void Write();
    }
    public class MP3:Storage
    {
        public override void Read()
        {
            Console.WriteLine("MP3正在储存数据");
        }
        public override void Write()
        {
            Console.WriteLine("MP3正在写入数据");
        }
        public void PlayMusic() 
        {
            Console.WriteLine("MP3正在播放music~");
        }
    }
    public class Disk : Storage 
    {
        public override void Write()
        {
            Console.WriteLine("移动硬盘正在储存数据");
        }
        public override void Read()
        {
            Console.WriteLine("移动硬盘正在写入数据");
        }
    }
    public class Udisk : Storage 
    {
        public override void Read()
        {
            Console.WriteLine("U盘正在读取数据");
        }
        public override void Write()
        {
            Console.WriteLine("U盘正在写入数据");
        }
    }


    public class Computer 
    {
        public Computer(Storage sto)
        {
            this.Sto = sto;
        }

        private Storage _sto;
        public Storage Sto 
        {
            get { return _sto; }
            set { _sto = value; }
        }
        public void CpuRead() 
        {
            Sto.Read();
        }
        public void CpuWrite() 
        {
            Sto.Write();
        }
    }

}
