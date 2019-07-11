using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProOperation
{
    public class Minus:Operation
    {
        public override double GetOperation(double n1, double n2)
        {
            return n1 - n2;
        }
    }
}
