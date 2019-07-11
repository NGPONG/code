using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 泛型的应用
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 10;
            int a = test<int>(i);
        }

        public static T test<T>(T value) 
        {
            //一个自定义类型的数组
            T[] arraryT = new T[5];
            return value;
        }
    }
}
