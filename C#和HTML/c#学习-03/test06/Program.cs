using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test06
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();
            dic.Add(1, 1);
            dic.Add(2, 2);
            dic.Add(3, 3);

            foreach (KeyValuePair<int,int> item in dic)
            {
                dic[item.Key] = 1;
            }

            Console.ReadLine();
        }
    }
}
