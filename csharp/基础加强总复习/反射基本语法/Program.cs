using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace 反射基本语法
{
    class Program
    {
        static void Main(string[] args)
        {
            //获取程序集 Common.dll 的绝对路径
            string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Common.dll");
            //通过 Assembly 去载入程序集
            Assembly ass = Assembly.LoadFile(path);

            //获取程序集中的指定的类型
            Type typ = ass.GetType("Common.Person");

            //通过该类的Type类型，创建该类的对象
            object oPerson = Activator.CreateInstance(typ, 21, "吴鹏");

            //通过该类的Type类型，获取该类的指定函数
            MethodInfo  mfi = oPerson.GetType().GetMethod("Method");
            //通过mfi执行该函数
            mfi.Invoke(oPerson, null);
            
            //通过该类的Type类型，获取该类的指定属性
            PropertyInfo prof = oPerson.GetType().GetProperty("Age");
            //获取该指定属性prof的具体的值
            object oPersonName = prof.GetValue(oPerson, null);


            //MethodInfo mif = oPerson.GetType().GetMethod("Method");
            //mif.Invoke(oPerson, null);
            

            //Console.WriteLine(oPersonName);

            Console.ReadLine();



        }
    }

    public class Student
    {
        public int Age { get; set; }

        public string Name { get; set; }
    }
}
