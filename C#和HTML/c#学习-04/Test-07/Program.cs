using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_07
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var name = Process.GetProcesses("DESKTOP-R4QQ2JG");

                var names = Process.GetProcessesByName("ShadowsocksR-dotnet4.0");
                foreach (var item in name)
                {
                    Console.WriteLine(item.ProcessName);
                }
            }
            catch (Exception ex)
            {
                string str = "123";
            }

            Console.ReadLine();
        }
    }
}
