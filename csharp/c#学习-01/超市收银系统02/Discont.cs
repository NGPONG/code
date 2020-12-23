using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class Discont : SaleMoney
    {
        public double Disconts
        {
            get;
            set;
        }
        public Discont(double discont) 
        {
            this.Disconts = discont;
        }
        public override double saleMoney(double allMoney)
        {
            return allMoney * Disconts;
        }
    }
}
