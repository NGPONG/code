using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace NGPONG.BookShop.TEST
{
    class Program
    {
        public string Band { get; set; }
        static void Main(string[] args)
        {
            Program program = new Program();
            program.Band = "123";
            PropertyInfo info = program.GetType().GetProperty("Band");
            info.SetValue(program, "123123");
        }
    }

    public class Person 
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }
}
