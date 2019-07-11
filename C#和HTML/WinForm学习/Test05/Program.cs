using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test05
{
    class Program
    {
        static void Main(string[] args)
        {
            ////获取当前系统中的所有运行中的进程名
            //Process[] pros = Process.GetProcesses();
            //foreach (var item in pros)
            //{
            //    Console.WriteLine(item.ProcessName);
            //    //删除进程，会导致蓝屏
            //    item.Kill();
            //}

            ////获取当前系统中目前在运行的进程名
            //Console.WriteLine(Process.GetCurrentProcess().ProcessName);

            ////打开某个进程
            //Process.Start("notepad.exe");

        }
    }
}
