using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 练习题_21_25
{
    class Program
    {
        static void Main(string[] args)
        {
            //21. 制作一个控制台小程序
            //      要求：用户可以在控制台录入每个学生的姓名，当用户输入quit（不区分大小写）时，程序停止接受用户的输入
            //      并且显示出用户输入的学生的个数，以及每个学生的姓名
            //List<string> list = new List<string>();
            //while (true)
            //{
            //    Console.WriteLine("请输入姓名");
            //    string str = Console.ReadLine();
            //    if (str.ToUpper() == "QUITE")
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        list.Add(str);
            //    }
            //}
            //Console.WriteLine("你一共录入了：{0}名学生，姓名分别为：", list.Count);
            //for (int i = 0; i < list.Count; i++)
            //{
            //    Console.WriteLine(list[i]);
            //}
            //Console.ReadLine();

            //22. 如上题
            //      再增加一个显示姓“王”的同学的个数，此处不考虑复姓问题
            //List<string> list = new List<string>();
            //List<string> listWang = new List<string>();
            //while (true)
            //{
            //    Console.WriteLine("请输入姓名");
            //    string str = Console.ReadLine();
            //    if (str.ToUpper() == "QUITE") 
            //    {
            //        break;
            //    }
            //    else if (str.Substring(0, 1) == "王")
            //    {
            //        listWang.Add(str);
            //        list.Add(str);
            //    }
            //    else 
            //    {
            //        list.Add(str);
            //    }
            //}
            //Console.WriteLine("你一共录入了：{0}名学生，分别为：", list.Count);
            //for (int i = 0; i < list.Count; i++)
            //{
            //    Console.WriteLine(list[i]);
            //}
            //Console.WriteLine("姓王的学生有：{0}名，分别为：", listWang.Count);
            //for (int i = 0; i < listWang.Count; i++)
            //{
            //    Console.WriteLine(listWang[i]);
            //}
            //Console.ReadLine();

            //23. 请将字符串数组{ "中国", "美国", "巴西", "澳大利亚", "加拿大" }中的内容反转
            //      然后输出反转后的数组
            string[] strs = { "中国", "美国", "巴西", "澳大利亚", "加拿大" ,"土耳其"};
            for (int i = 0; i < strs.Length/2; i++)
            {
                string temp = "";
                temp = strs[i];
                strs[i] = strs[strs.Length - 1 - i];
                strs[strs.Length - 1 - i] = temp;
            }
            for (int i = 0; i < strs.Length; i++)
            {
                Console.WriteLine(strs[i]);
            }
            Console.ReadLine();

            //24. 创建一个Person类，属性：姓名、性别、年龄；方法：SayHi() 
            //      再创建一个Employee类继承Person类，扩展属性Salary,重写SayHi方法
            //Person per = new Employee(3000, "吴鹏", '男', 21);//new Person();
            //per.SayHi();
            //Console.WriteLine(per.Name);
            //Console.ReadLine();

            //25. 请编写一个类：ItcastClass,该类中有一个私有字段_names
            //      数据类型为：字符串数组，长度为5，并且有5个默认的姓名
            //      要求：为ItcastClass类编写一个索引器，要求该索引器能够通过下标来访问_names中的内容。
            ItcastClass ic = new ItcastClass();
            ic.Indexer(4);
            Console.ReadLine();
        }
    }
    public class ItcastClass 
    {
        private string[] _name = new string[] { "张三", "李四", "王五", "赵六", "田七" };
        public void Indexer(int i) 
        {
            Console.WriteLine(_name[i]);
        }
    }
    public class Person 
    {
        public string Name { get; set; }
        public char Gender { get; set; }
        public int Age { get; set; }
        public virtual void SayHi() 
        {
            Console.WriteLine("我是父类！");
        }
        public Person(string name) 
        {
            this.Name = name;
        }
    }
    public class Employee : Person 
    {
        public int Salary { get; set; }
        public Employee(int salary,string name,char gender,int age) 
            :base(name)
        {
            this.Salary = salary;
            this.Gender = gender;
            this.Age = age;
        }
        public override void SayHi()
        {
            Console.WriteLine("我是子类！重写了父类的方法！我叫：{0}，性别为：{1}，今年：{2}岁，我的工资是：{3}"
                ,this.Name,this.Gender,this.Age,this.Salary);
        }
    }
}
