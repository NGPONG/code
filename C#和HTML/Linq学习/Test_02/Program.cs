using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Test_02
{
    class Program
    {
        static void Main(string[] args)
        {
            Student[] StudentArrary = new Student[3]
            {
                new Student() { Name = "王清培", Age = 24, Sex = "男", Address = "江苏南京" },
                new Student() { Name = "陈玉和", Age = 23, Sex = "女", Address = "江苏盐城" },
                new Student() { Name = "金源", Age = 22, Sex = "女", Address = "江苏淮安" }
            };

            ParameterExpression parameter = Expression.Parameter(typeof(Student), "qwe");//表示二元运算符的左边参数名称
                                                                                         //表示"stu"参数的"stu.Name"中的Name属性，Name属性必须是反射获取的元数据才行，这样框架就才可以找到它
            MemberExpression property = Expression.MakeMemberAccess(parameter, typeof(Student).GetMember("Name")[0]);
            //表示常量值
            Console.WriteLine("请输入要查询人的名称：");
            ConstantExpression name = Expression.Constant(Console.ReadLine());//从用户输入流中读取值
            BinaryExpression binary = Expression.MakeBinary(ExpressionType.Equal, property, name);//拼接==运算符的左边、右边
                                                     
            //完整的表达式是Lambda才对
            LambdaExpression lambda = Expression.Lambda(binary, parameter);

            Person per = new Person();
            Student student = new Student();
        }

    }
    public static class ExtentionMethods
    {
        public static void SaySomething(this Person person)
        {
            Console.WriteLine("Hello,World!");
        }
    }

    public class Person
    {

    }
    public class Student:Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Sex { get; set; }
        public string Address { get; set; }
    }
}
