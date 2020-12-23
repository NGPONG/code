using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏面向对象03
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList list = new ArrayList();
            list.Add("123");
            list.Add(false);
            list.Add(new Person());
            list.Add(new char[] { '吴', '鹏' });
            list.Add(list);

            for (int i = 0; i < list.Count; i++) 
            {
                if (list[i] is Person) 
                {
                    ((Person)list[i]).PersonSayHello();
                }
                else if (list[i] is char[]) 
                {
                    for (int j = 0; j < ((char[])list[i]).Length; j++) 
                    {
                        Console.Write(((char[])list[i])[j]);
                    }
                    Console.WriteLine();
                }
                else if (list[i] is ArrayList)
                {
                    for (int n = 0; n < (list[i] as ArrayList).Count; n++)
                    {
                        if (((ArrayList)list[i])[n] is Person) 
                        {
                            ((Person)((ArrayList)list[i])[n]).PersonSayHello();
                        }
                        else if ((list[i] as ArrayList)[n] is char[])
                        {
                            for (int z = 0; z < (((char[])((list[i] as ArrayList)[n]))).Length; z++)
                            {
                                Console.Write((((char[])((list[i] as ArrayList)[n])))[z]);
                            }
                            Console.WriteLine();
                        }
                        else 
                        {
                            Console.WriteLine((list[i] as ArrayList)[n]);
                        }
                    }
                }
                else 
                {
                    Console.WriteLine(list[i]);
                }
            }
            Console.ReadLine();
        }
    }
    public class Person 
    {
        public void PersonSayHello() 
        {
            Console.WriteLine("大家好！我是Person类");
        }
    }
}
