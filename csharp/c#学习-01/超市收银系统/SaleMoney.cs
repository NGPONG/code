using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{
    public class SaleMoney:MoneyFather
    {
        public double Discount
        {
            get;
            set;
        }
        public SaleMoney(double discount) 
        {
            this.Discount = discount;
        }
        public override double GetMoney(double sumMoney)
        {
            return sumMoney * Discount;
        }
    }
}
