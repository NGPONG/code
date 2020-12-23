using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    class Player
    {
        public int PlayerFist(string lblTest) 
        {
            int num = 0;
            switch (lblTest) 
            {
                case "石头":
                    num = 0;
                    break;
                case "剪刀":
                    num = 1;
                    break;
                case "布":
                    num = 2;
                    break;
            }
            return num;
        }
    }
}
