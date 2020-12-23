using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_04
{
    class Program
    {
        static void Main(string[] args)
        {
            IterationSample sample = new IterationSample();
        }
    }

    public class IterationSample : IEnumerable<int>
    {
        public int MyProperty { get; set; }
        public IEnumerator<int> GetEnumerator()
        {
            try
            {
                yield return 1;
                yield return 2;
                yield return 3;
                yield return 4;
                yield return 5;
            }
            finally
            {

            }

            try
            {
                yield break;
            }
            catch (Exception)
            {
                yield break;
            }
            finally
            {
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return this.GetEnumerator();
        }
    }


}
