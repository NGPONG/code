using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    enum gameResult
    {
        玩家赢,
        电脑赢,
        平手
    }
    class Referee
    {
        public string Result(int playerNum, int computerNum) 
        {
            string str = "";
            if (playerNum - computerNum == -1 || playerNum - computerNum == 2) 
            {
                str = gameResult.玩家赢.ToString();
            }
            else if (playerNum - computerNum == 0)
            {
                str = gameResult.平手.ToString();
            }
            else 
            {
                str = gameResult.电脑赢.ToString();
            }
            return str;
        }
    }
}
