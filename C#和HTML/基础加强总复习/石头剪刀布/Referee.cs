using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    class Referee
    {
        public int PlayerNum { 
            get;
            set;
        }

        public int ComputerNum { 
            get;
            set;
        }

        public Referee(int playernum, int computernum) 
        {
            this.PlayerNum = playernum;
            this.ComputerNum = computernum;
        }

        public string GerResult() 
        {
            string str = null;
            if (PlayerNum - ComputerNum == -1 || PlayerNum - ComputerNum == 2) 
            {
                str = "玩家赢";
            }
            else if (ComputerNum - PlayerNum == -1||ComputerNum - PlayerNum == 2)
            {
                str = "电脑赢";
            }
            else 
            {
                str = "平手";
            }
            return str;
        }
    }
}
