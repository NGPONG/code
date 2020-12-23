using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace test07
{
    class Program
    {
        static void Main(string[] args)
        {
            Demo de = new Demo();
            //de.Name = "123";
            //de.Age = 321;
            byte[] buff = new byte[1024 * 1024 * 5];
            MemoryStream ms = new MemoryStream(buff);

            BinaryFormatter bf1 = new BinaryFormatter();
            bf1.Serialize(ms, de);
            //byte[] byts = ms.GetBuffer();

            Console.WriteLine(buff.Length); 
            
            Console.ReadLine();

        }
    }

    [Serializable]
    public class Demo 
    {
        public int Age {get; set; }
        public string Name { get; set; }
    }
}
