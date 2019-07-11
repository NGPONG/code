using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 泛型集合
{
    class Program
    {
        static void Main(string[] args)
        {
            //1. 找出两个集合中重复的元素，去掉并组成一个新的集合
            //List<string> list1 = new List<string>() { "a", "b", "c", "d", "e" };
            //List<string> list2 = new List<string>() { "d", "e", "f", "g", "h" };

            //for (int i = 0; i < list2.Count; i++)
            //{
            //    if (list1.Contains(list2[i])) 
            //    {
            //        list1.Remove(list2[i]);
            //    }
            //}
            //list1.AddRange(list2);

            //for (int i = 0; i < list1.Count; i++)
            //{
            //    Console.WriteLine(list1[i]);
            //}
            //Console.ReadLine();

            //2. 随机生成10哥 1-100之间的数放在List中，要求不能重复且都是偶数
            //Random r = new Random();
            //List<int> list = new List<int>();
            //for (int i = 0; i < 50; i++)
            //{
            //    int num = r.Next(1, 101);
            //    if (num % 2 == 0 && !list.Contains(num))
            //    {
            //        list.Add(num);
            //    }
            //    else 
            //    {
            //        i--;
            //        continue;
            //    }
            //}
            //list.Sort();
            //Console.ReadLine();

            //3. 分拣数组中的元素，奇数放在一个集合，偶数放在一个集合，最后合并成一个集合，要求奇数在前偶数在后
            //int[] nums = new int[100];
            //for (int i = 0; i < 100; i++)
            //{
            //    nums[i] = i+1;
            //}
            //List<int> listJi = new List<int>();
            //List<int> listOu = new List<int>();
            //List<int> list = new List<int>();

            //for (int i = 0; i < nums.Length; i++)
            //{
            //    if (nums[i] % 2 == 0)
            //    {
            //        listOu.Add(nums[i]);
            //    }
            //    else
            //    {
            //        listJi.Add(nums[i]);
            //    }
            //}
            //list.AddRange(listJi);
            //list.AddRange(listOu);

            //Console.ReadLine();
        }
    }
}
