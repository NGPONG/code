using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 自动属性和普通属性
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
    public class Person 
    {
        public Person(int age) //通过构造函数对自动属性默认添加的私有字段进行限定和保护
        {
            if (age > 100)
            {
                this.Age = 0;
            }
            else
            {
                this.Age = age;
            }
        }
        public int Age  //自动属性
        {
            get;
            set;
        }
        public void SayHello() 
        {
            Console.WriteLine("我叫{0},今年{1}岁了",this.Name,this.Age);
        }
    }
}
