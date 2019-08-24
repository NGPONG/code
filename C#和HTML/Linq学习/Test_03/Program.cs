using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_03
{
    class Program
    {
        static void Main(string[] args)
        {
            var enumerator = GetItems().GetEnumerator();

            int i = 0;
            while (enumerator.MoveNext())
            {
                if (i == 2)
                    break;
                Console.WriteLine(enumerator.Current);

                i++;
            }

            int str = enumerator.Current;
            Console.WriteLine(enumerator.Current);
        }

        public static IEnumerable<int> GetItems()
        {
            if (1 < 2)
            {
                yield return 1;
                yield return 2;
                yield return 3;
                yield return 4;
            }
            else
            {
                yield return 5;
                yield return 6;
            }
            yield return 7;
        }

    }
}
