using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test04
{
    public delegate string DelTest(string name);

    class Program
    {
        static void Main(string[] args)
        {
            DelTest del = delegate(string name)
                                  {
                                      return name;
                                  };

        }
    }
}
