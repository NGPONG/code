using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏_面向对象
{
    class Ticket
    {
        public Ticket(int distance) 
        {
            if (distance < 0)
            {
                throw new Exception("不能输入负数");
            }
            else
            {
                this.distance = distance;
            }
        }


        private int distance;
        public int Distance 
        {
            get { return distance; }
        }



        private int price;
        public int Price 
        {
            get 
            {
                if (this.distance <= 100)
                {
                    this.price = this.distance;
                }
                else if (this.distance > 100 && this.distance <= 200)
                {
                    this.price = (int)(this.distance * 0.95);
                }
                else if (this.distance > 200 && this.distance <= 300)
                {
                    this.price = (int)(this.distance * 0.9);
                }
                else
                {
                    this.price = (int)(this.distance * 0.8);
                }
                return price;
            }
        }


        public void ShowTicket() 
        {
            Console.WriteLine("距离为：{0}\n价格为：{1}",distance,Price);
        }

        

    }
}
