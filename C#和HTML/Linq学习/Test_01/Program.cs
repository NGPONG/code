using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace Test_01
{
    class Program
    {
        static void Main(string[] args)
        {
            List<PersonType> personTypes = new List<PersonType>()
            {
                new PersonType(){ PersonTypeId=1,PersonTypeName="黄种人" },
                new PersonType(){ PersonTypeId = 2,PersonTypeName="白种人" },
                new PersonType(){ PersonTypeId = 3,PersonTypeName="黑种人" }
            };

            List<Student> students = new List<Student>()
            {
                new Student(){ StudentId=1, StudentName="张三", PersonTypeId=1 },
                new Student(){ StudentId=2, StudentName="李四", PersonTypeId=1 },
                new Student(){ StudentId=3, StudentName="吴鹏", PersonTypeId=2 },
                new Student(){ StudentId=4, StudentName="小明", PersonTypeId=3 },
                new Student(){ StudentId=5, StudentName="黑炭", PersonTypeId=3 },
            };

            var query = from pt in personTypes
                        join stu in students on pt.PersonTypeId equals stu.PersonTypeId
                        select pt;


            Func<int> Func = () => 10;
            Expression<Func<Student,bool>> Expression = (Student stu) =>  stu.PersonTypeId==1;
        }
    }

    public class PersonType
    {
        public int PersonTypeId { get; set; }
        public string PersonTypeName { get; set; }
    }
    public class Student
    {
        public int StudentId { get; set; }
        public string StudentName { get; set; }
        public int PersonTypeId { get; set; }
    }
}
