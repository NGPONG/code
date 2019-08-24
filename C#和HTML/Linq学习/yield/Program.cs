using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace yield
{
    class Program
    {
        static void Main(string[] args)
        {
            // 通过 foreach 语法糖来为 yield 所返回的迭代器模式进行迭代工作
            foreach (var item in GetIterationSampleByPro)
            {
                Console.WriteLine(item);
            }

            // 传统的方式为 yield 所返回的迭代器模式进行迭代工作
            var enumeratoer = GetIterationSample(true).GetEnumerator();
            while (enumeratoer.MoveNext())
            {
                Console.WriteLine(enumeratoer.Current);
            }
        }

        /// <summary>
        /// 迭代访问器
        /// </summary>
        public static IEnumerable<string> GetIterationSampleByPro
        {
            get
            {
                yield return "GetIterationSampleByPro：Hello，World";

                for (int i = 0; i < 3; i++)
                {
                    yield return $"GetIterationSampleByPro：Is the {i.ToString()} time continue to work!";
                }
            }
        }
        /// <summary>
        /// 迭代方法
        /// </summary>
        /// <returns></returns>
        public static IEnumerable<string> GetIterationSample(bool isBreak)
        {
            yield return "GetIterationSample：Hello，World";

            if(isBreak)
                yield break;
            else
                yield return "GetIterationSample：It's continue to work!";
        }
    }
}
