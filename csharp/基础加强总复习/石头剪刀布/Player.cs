using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 石头剪刀布
{
    class Player
    {
        /// <summary>
        /// 1代表石头 2代表剪刀 3代表布
        /// </summary>
        public int PlayerFirst {
            get; 
            set; 
        }

        public Player(string playerfirst) 
        {
            switch (playerfirst) 
            {
                case "石头":
                    this.PlayerFirst = 1;
                    break;
                case "剪刀":
                    this.PlayerFirst = 2;
                    break;
                case "布":
                    this.PlayerFirst = 3;
                    break;
            }
        }
    }
}
