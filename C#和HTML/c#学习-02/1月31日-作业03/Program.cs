using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业03
{
    class Program
    {
        static void Main(string[] args)
        {
            //员工类、部门经理类（部门经理也是员工，所以要继承自员工类。员工有上班打卡的方法。用类来模拟
            object[] objs = { new Employee(), new Manager(), new Programmer() };
            Employee emp = null;
            for (int i = 0; i < objs.Length; i++)
            {
                emp = (Employee)objs[i];
                emp.sayHello();
            }
            Console.ReadLine();
        }
    }
    public class Employee 
    {
        public virtual void sayHello() 
        {
            Console.WriteLine("员工需要打卡");
        }
    }

    public class Manager : Employee 
    {
        public override void sayHello()
        {
            Console.WriteLine("经理需要打卡");
        }
    }

    public class Programmer : Employee 
    {
        public override void sayHello()
        {
            Console.WriteLine("程序员需要打卡");
        }
    }
}
