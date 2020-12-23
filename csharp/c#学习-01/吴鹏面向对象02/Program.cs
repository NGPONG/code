using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏面向对象02
{
    class Program
    {
        static void Main(string[] args)
        {
            Person[] perArry = new Person[10];
            Random r = new Random();
            int number;
            for (int i = 0; i < perArry.Length; i++)
            {
                number = r.Next(1, 6);
                switch (number)
                {
                    case 1:
                        perArry[i] = new Person();
                        perArry[i].PersonSayHello();
                        break;
                    case 2:
                        perArry[i] = new Student();
                        Student stu = perArry[i] as Student;
                        stu.StudentSayHello();
                        break;
                    case 3:
                        perArry[i] = new Driver();
                        Driver dr = perArry[i] as Driver;
                        dr.DriverSayHello();

                        break;
                    case 4:
                        perArry[i] = new Programmer();
                        Programmer pro = perArry[i] as Programmer;
                        pro.ProgrammerSayHello();

                        break;
                    case 5:
                        perArry[i] = new Teacher();
                        Teacher tea = perArry[i] as Teacher;
                        tea.TeacherSayHello();
                        break;
                }
            }
            Console.ReadLine();

            
        }
    }
    public class Person
    {
        public void PersonSayHello()
        {
            Console.WriteLine("你是人类");
        }
    }
    public class Student : Person
    {
        private int _id;
        public int Id
        {
            get { return _id; }
            set { _id = value; }
        }
        public void StudentSayHello()
        {
            Console.WriteLine("你是学生");
        }
    }
    public class Driver : Person
    {
        private int _drivetime;
        public int Drivetime
        {
            get { return _drivetime; }
            set { _drivetime = value; }
        }
        public void DriverSayHello()
        {
            Console.WriteLine("你是司机");
        }
    }
    public class Programmer : Person
    {
        public void ProgrammerSayHello()
        {
            Console.WriteLine("你是程序员");
        }
    }
    public class Teacher : Person
    {
        public void TeacherSayHello()
        {
            Console.WriteLine("你是老师");
        }
    }
}
