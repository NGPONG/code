using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 字符串string
{
    class Program
    {
        static void Main(string[] args)
        {
            //string str = "1234567";
            //char[] charStrs = str.ToCharArray();
            //charStrs[0] = '你';
            //str = new string(charStrs);
            //Console.WriteLine(str);
            //Console.ReadLine();

            //string str = "abc";
            //string str2 = "ABC";
            //Console.WriteLine(str.Equals(str2, StringComparison.OrdinalIgnoreCase));
            //Console.ReadLine();

            string str = "e123qwee123qwwere31eqweer13qweqwe";
            List<int> list = new List<int>();
            int i = str.IndexOf('e');
            list.Add(i);
            while (true)
            {
                i = str.IndexOf('e', i + 1);
                if (i == -1)
                {
                    break;
                }
                list.Add(i);
            }
            for (int j = 0; j < list.Count; j++)
            {
                Console.WriteLine(list[j]+1);
            }
            Console.ReadLine();
        }
    }
}
