using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 事件_类型安全的委托
{
    public delegate void DelTest();
    class Program
    {
        static void Main(string[] args)
        {
            Test te1 = new Test();
            te1.EventDel += te1_EventDel;//注册一个事件--委托指向一个函数

            //te1.EventDel(); //我们不能在注册事件后直接调用事件，这是不允许的，因为事件是一个类型安全的委托，不能够被随意调用

            te1.test();

            Console.ReadLine();
        }

        /// <summary>
        /// 处理事件的方法
        /// </summary>
        static void te1_EventDel()
        {
            Console.WriteLine("哈哈哈");
        }

    }

    /// <summary>
    /// 发布者类
    /// </summary>
    public class Test 
    {
        //关键字event，类型为我们所声明的委托类型，类似一个字段
        public event DelTest EventDel;//声明事件

        /// <summary>
        /// 触发事件的方法
        /// </summary>
        public void test()
        {
            Console.ReadKey(true);//按下任意键后触发 EventDel() 事件

            EventDel();
        }
    }
}
