using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class Decrease:SaleMoney
    {
        public double Enough
        {
            get;
            set;
        }
        public double Decreases
        {
            get;
            set;
        }

        public Decrease(double engugh, double decreases) 
        {
            this.Enough = engugh;
            this.Decreases = decreases;
        }

        public override double saleMoney(double allMoney)
        {
            if (allMoney > Enough)
            {
                return allMoney - ((allMoney / Enough) * Decreases);
            }
            else 
            {
                return allMoney;
            }
        }
    }
}
