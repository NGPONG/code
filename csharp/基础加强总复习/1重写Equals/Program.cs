using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1重写Equals
{
    class Program
    {
        static void Main(string[] args)
        {
            //Equals默认比较的是对象所引用的地址
            //我们可以重写属于Object类的该方法

            Person per = new Person() { Name = "张三" };
            Person per2 = new Person() { Name = "张三" };
            Console.WriteLine(per.Equals(per2));
            Console.ReadLine();
        }
    }
    public class Person 
    {
        public string Name { get; set; }

        /// <summary>
        /// 重写了Object类的Equals的函数
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public override bool Equals(object obj)
        {
            Person perObject = obj as Person;
            if (this.Name == perObject.Name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
