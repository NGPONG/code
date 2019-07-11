using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace 序列化和反序列化
{
    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Person();
            per.Name = "张三";
            per.Age = 18;
            using (FileStream fsRead = new FileStream(@"C:\Users\Administrator\Desktop\new.txt",FileMode.OpenOrCreate,FileAccess.Read)) 
            {
                BinaryFormatter bf = new BinaryFormatter();
                bf.Deserialize(fsRead);
            }
            Console.WriteLine("反序列化完成");
            Console.ReadLine();
            
        }
    }
    [Serializable] 
    public class Person 
    {
        private string _name;
        public string Name 
        {
            get { return _name; }
            set { _name = value; }
        }
        private int _age;
        public int Age 
        {
            get { return _age; }
            set { _age = value; }
        }
    }
}
