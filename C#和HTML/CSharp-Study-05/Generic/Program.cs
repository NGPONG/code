using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generic
{
    public delegate int GenericHandler<T>(T value1,T value2);

    class Program
    {
        static void Main(string[] args)
        {
            var commandString = new CommandMethod<string>();
            var strResult = commandString.GetMaxLength(new string[] { "测试一下", "23333333","666" }, commandString.GetMaxString);

            var commandInt = new CommandMethod<int>();
            var intResult = commandInt.GetMaxLength(new int[] { 1, 2, 3, 4, 5, 6, 7, 8 }, commandInt.GetMaxInt);

            Console.ReadLine();
        }
    }

    public interface IPerson<T>
    {
        T Name(T value);
    }

    public class Student<T> : IPerson<int>
    {
        public int Name(int value)
        {
            throw new NotImplementedException();
        }
    }

    public class Person
    {

    }

    public class MyClass
    {
    }

    public interface ITest { }

    public class GenericClassTest<T>
        where T : class,new()
    {

    }

    public class CommandMethod<T>
    {
        public T GetMaxLength(T[] arrary,GenericHandler<T> handler)
        {
            T max = arrary[0];

            for (int i = 0; i < arrary.Length; i++)
            {
                if (handler(arrary[i], max) > 0)
                {
                    max = arrary[i];
                }
            }

            return max;
        }

        public int GetMaxInt(int value1, int value2)
        {
            return value1 - value2;
        }

        public int GetMaxString(string value1, string value2)
        {
            return value1.Length - value2.Length;
        }
    }
}
