using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 自定义事件
{
    public delegate void DelReminder();
    class Program
    {
        static void Main(string[] args)
        {
            Demo de = new Demo();
            de.EventHandler += DemoFunction;
            de.EventHandler2 += DemoFunction2;

            while (true)
            {
                de.Str = Console.ReadLine();
            }
        }

        public static void DemoFunction() 
        {
            Console.WriteLine("属性的值给改变了！");
        }

        public static void DemoFunction2() 
        {
            Console.WriteLine("属性的值没给改变！");
        }
    }

    public class Demo 
    {
        public event DelReminder EventHandler;

        public event DelReminder EventHandler2;

        private string _str;
        public string Str 
        {
            get 
            {
                return this._str;
            }
            set 
            {
                if (value != this._str)
                {
                    this._str = value;
                    EventHandler();
                }
                else 
                {
                    EventHandler2();
                }
            }
        }
    }
}
