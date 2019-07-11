using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    class Computer
    {
        Random r = new Random();
        public int ComputerFirst{
            get;
            set;
        }

        public Computer() 
        {
            this.ComputerFirst = r.Next(1, 4);
        }

        public string CpuLbl() 
        {
            string str = null;
            switch (this.ComputerFirst) 
            {
                case 1:
                    str = "石头";
                    break;
                case 2:
                    str = "剪刀";
                    break;
                case 3:
                    str = "布";
                    break;
            }
            return str;
        }
    }
}
