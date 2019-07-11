using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class Nomal:SaleMoney
    {
        public override double saleMoney(double allMoney)
        {
            return allMoney;
        }
    }
}
