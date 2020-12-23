using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    enum Gender 
    {
        男性,
        女性

    }
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Gender sex = Gender.女性;
                Console.WriteLine("请输入你的性别");
                sex = (Gender)(Enum.Parse(typeof(Gender), "男性"));
                Console.WriteLine((int)sex);
            }
            catch 
            {
                Console.WriteLine("您输入的有误");
            }
            Console.ReadLine();
        }
    }
}
