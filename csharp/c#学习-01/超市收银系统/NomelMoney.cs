using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{
    public class NomelMoney:MoneyFather
    {
        public override double GetMoney(double sumMoney)
        {
            return sumMoney;
        }
    }
}
