using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
namespace DOM方法创建XML文档对象
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Student> list = new List<Student>() { new Student("吴鹏", 21, '男', 1), new Student("小红", 18, '女', 2), new Student("张三", 30, '男', 3) };
            //创建XML文档对象
            XmlDocument doc = new XmlDocument();
            //创建XML文档的描述信息，并添加进doc文档对象中
            XmlDeclaration dec = doc.CreateXmlDeclaration("1.0","utf-8",null);
            doc.AppendChild(dec);
            //创建XML文档的根节点
            XmlElement person = doc.CreateElement("Person");
            doc.AppendChild(person);

            for (int i = 0; i < list.Count; i++)
            {
                //student节点
                XmlElement student = doc.CreateElement("Student");
                student.SetAttribute("studentID", list[i].ID.ToString());
                person.AppendChild(student);

                XmlElement name = doc.CreateElement("Name");
                name.InnerXml = list[i].Name;
                student.AppendChild(name);

                XmlElement age = doc.CreateElement("Age");
                age.InnerXml = list[i].Age.ToString();
                student.AppendChild(age);

                XmlElement gender = doc.CreateElement("Gender");
                gender.InnerXml = list[i].Gender.ToString();
                student.AppendChild(gender);
            }

            doc.Save("person.xml");
            Console.WriteLine("创建成功");
            Console.ReadLine();
        }
    }
    public class Student 
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public char Gender { get; set; }
        public int ID { get; set; }

        public Student(string name, int age, char gender, int id) 
        {
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
            this.ID = id;
        }
    }
}
