using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TEST_01
{
    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Chinese();
            per.SayHello();

            Console.ReadKey();
        }
    }

    public class Person
    {
        public virtual void SayHello()
        {
            Console.WriteLine("我是人类！");
        }
    }

    public class Chinese : Person
    {
        public override void SayHello()
        {
            Console.WriteLine("我是中国人！");

            // 调用父类中的SayHello方法，实现子类已经重写了父类的虚方法的情况下，也能够调用自己本身的方法的实现
            base.SayHello();
        }
    }
}
