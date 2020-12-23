using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ProOperation;

namespace ProMult
{
    public class Mult:Operation
    {
        public Mult(int numberone, int numbertwo)
            : base(numberone, numbertwo) 
        {
            
        }
        public override string Type
        {
            get { return "*"; }
        }

        public override int GetResult()
        {
            return NumberOne * NumberTwo;
        }
    }
}
