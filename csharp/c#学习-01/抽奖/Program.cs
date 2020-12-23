using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 抽奖
{
    class Program
    {
        static void Main(string[] args)
        {
            //各物品的概率保存在数组里
            float[] area = new float[4]{
                0.980f,
                0.550f,
                0.230f,
                0.010f
            };

            //单次测试
            //Console.WriteLine(Get(area));

            //批量测试
            int[] result = new int[4]{
                0,
                0,
                0,
                0
            };
            for (int i = 0; i < 1770000; i++)    //为了比对结果方便，这里循环的次数是总概率的1000倍
            {
                int n = Get(area);      //本次抽奖结果
                result[n]++;            //统计抽到的次数
            }
            Console.WriteLine("结果：");
            foreach (int times in result)
            {
                Console.WriteLine(times);
            }
        }

        /// <summary>
        /// 获取抽奖结果
        /// </summary>
        /// <param name="prob">各物品的抽中概率</param>
        /// <returns>返回抽中的物品所在数组的位置</returns>
        private static int Get(float[] prob)
        {
            int result = 0;
            int n = (int)(prob.Sum() * 1000);           //计算概率总和，放大1000倍
            Random r = rnd;
            float x = (float)r.Next(0, n) / 1000;       //随机生成0~概率总和的数字

            for (int i = 0; i < prob.Count(); i++)
            {
                float pre = prob.Take(i).Sum();         //区间下界
                float next = prob.Take(i + 1).Sum();    //区间上界
                if (x >= pre && x < next)               //如果在该区间范围内，就返回结果退出循环
                {
                    result = i;
                    break;
                }
            }
            return result;
        }
        private static Random rnd = new Random();
    }

}