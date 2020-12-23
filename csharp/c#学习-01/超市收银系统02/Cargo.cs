using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 超市收银系统02
{
    public class Cargo
    {
        public string Name
        {
            get;
            set;
        }
        public string ID
        {
            get;
            set;
        }
        public double Price
        {
            get;
            set;
        }

        public Cargo(string name,string id,double price) 
        {
            this.Price = price;
            this.Name = name;
            this.ID = id;
        }
    }
}
