using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace File类
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fsRead = File.OpenRead(@"C:\Users\Administrator\Desktop\bookName.txt")) 
            {
                byte[] byts = new byte[1024 * 1024 * 5];
                int index = fsRead.Read(byts, 0, byts.Length);
                string str = Encoding.Default.GetString(byts, 0, index);
                Console.WriteLine(str);
            }
            Console.ReadLine();
        }
    }
}
