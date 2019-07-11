using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    enum Fistenum
    {
        石头,
        剪刀,
        布
    }
    class Computer
    {
        Random r = new Random();

        public string Fist { get; set; } 
        
        public int computerFist() 
        {
            int num = r.Next(0, 3);
            switch (num) 
            {
                case 0:
                    this.Fist = Fistenum.石头.ToString();
                    break;
                case 1:
                    this.Fist = Fistenum.剪刀.ToString();
                    break;
                case 2:
                    this.Fist = Fistenum.布.ToString();
                    break;
            }
            return num;
        }
    }
}
