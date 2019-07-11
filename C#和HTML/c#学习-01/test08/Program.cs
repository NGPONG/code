using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test08
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建ProcessStartInfo类，指定打开文件的路径
            ProcessStartInfo psi = new ProcessStartInfo(@"C:\Users\Administrator\Desktop\bookName.txt");
            //调用Process类的start方法
            Process.Start(psi);
        }
    }
    public abstract class Person 
    {
        public abstract void SayHello();
    }

    public class Student : Person
    {
        public override void SayHello()
        {
            Console.WriteLine("我是子类的打招呼！");
        }
    }

}
