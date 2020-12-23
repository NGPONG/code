using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 索引器
{
    class Program
    {
        static void Main(string[] args)
        {
            MyArrary arrary = new MyArrary();
            arrary[0] = 10;
        }
    }

    public class MyArrary
    {
        private int[] nums = new int[100];
        public int Length { get; set; }
        public int this[int index]
        {
            get
            {
                return nums[index];
            }
            set
            {
                nums[index] = value;
            }
        }
    }
}
