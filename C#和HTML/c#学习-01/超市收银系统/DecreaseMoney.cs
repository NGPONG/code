using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统
{
    class DecreaseMoney:MoneyFather
    {
        public DecreaseMoney(double enough,double decrease) 
        {
            this.Enough = enough;
            this.Decrease = decrease;
        }
        public double Enough
        {
            get;
            set;
        }
        public double Decrease
        {
            get;
            set;
        }

        public override double GetMoney(double sumMoney)
        {
            if (sumMoney > this.Enough)
            {
                sumMoney = (int)(sumMoney - (sumMoney / this.Enough) * this.Decrease);
                return sumMoney;
            }
            else 
            {
                return sumMoney;
            }

            
        }
    }
}
